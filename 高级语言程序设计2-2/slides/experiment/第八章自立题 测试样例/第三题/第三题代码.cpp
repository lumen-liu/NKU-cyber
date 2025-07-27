
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

class base {  //base类，它将作为其他几个类的基类
    double price;  //单价
    char place[20];  //产地
public:
    base() {  //无参构造函数
        price = 0;
        strcpy(place, "");
    }
    base(double pr, char* pl) {  //二参构造参数
        price = pr;
        strcpy(place, pl);
    }
    void set_bace(double pr, char* pl) {  //按所设数据生成对象
        price = pr;
        strcpy(place, pl);
    }
    void input() {  //输入base类对象的有关数据
        cin >> price >> place;
    }
    double get_price() { return price; }  //获取对象的price
    char* get_place() { return place; }  //获取对象的place
};
class shirt :public base {  //派生类shirt（衬衣）
    char material[20];  //增加“布料”数据
public:
    shirt() :base() {  //派生类构造函数，无参
        strcpy(material, "");
    }
    shirt(double pr, char* pl, char* mat)  //派生类构造函数，负责其基类的初始化
        :base(pr, pl) {
        strcpy(material, mat);
    }
    void set_shirt(double pr, char* pl, char* mat) {  //按所设数据生成派生类对象
        set_bace(pr, pl);
        strcpy(material, mat);
    }
    void input() {  //输入对象数据
        base::input();
        cin >> material;
    }
    char* get_material() { return material; }  //获取对象的material
};
const int MAXSIZE = 100;
class shirt_storage {  //衬衣仓库类shirt_storage
    int count;  //库存量初始化为0
    shirt shelf[MAXSIZE];  //衬衣货架shelf，存放一批衬衣
    bool shelf_pos_blank[MAXSIZE];  //货位是否为空的标记数据shelf_pos_blank
public:
    shirt_storage() {
        count = 0;   //库存量初始化为0
        for (int i = 0; i < MAXSIZE; i++) {  //初始时，衬衣货架的各货位均置为0
            shelf_pos_blank[i] = true;
        }
    }
    void in_something(int add_cnt) {  //商品的入库
        int add_cnt_temp = add_cnt;
        int index_temp = 0;
        for (int i = 1; i < MAXSIZE; i++) {
            if (add_cnt_temp > 0) {
                if (shelf_pos_blank[i]) {  // 判断货位是否为空
                    if (add_cnt_temp == add_cnt) {
                        shelf[i].input();
                        index_temp = i;
                    }
                    else
                    {
                        shelf[i] = shelf[index_temp];
                    }
                    shelf_pos_blank[i] = false;
                    add_cnt_temp -= 1;
                    count++;
                }
            }
        }
    }
    void out_number(double pr, char* pl, char* mat) {  //计算商品数量
        int number = 0;
        for (int i = 0; i < MAXSIZE; i++) {
            if (!shelf_pos_blank[i]) {  // 判断货位是否为空
                if (!strcmp(shelf[i].get_place(), pl)) {
                    if (shelf[i].get_price() == pr) {
                        if (!strcmp(shelf[i].get_material(), mat)) {
                            number += 1;
                        }
                    }
                }
            }
        }
        cout << number << endl;
    }
    void out_something(int del_cnt, double pr, char* pl, char* mat) {  //商品的出库
        int del_cnt_temp = del_cnt;
        for (int i = 0; i < MAXSIZE; i++) {
            if (del_cnt_temp > 0) {
                if (!shelf_pos_blank[i]) {  // 判断货位是否为空
                    if (!strcmp(shelf[i].get_place(), pl)) {
                        if (shelf[i].get_price() == pr) {
                            if (!strcmp(shelf[i].get_material(), mat)) {
                                shelf_pos_blank[i] = true;
                                del_cnt_temp -= 1;
                            }
                        }
                    }
                }
            }
        }
        if (del_cnt_temp == 0) {
            cout << "next" << endl;
            count -= del_cnt;
        }
        else
        {
            if (del_cnt_temp == del_cnt) {
                cout << "wrong" << endl;
            }
            else
            {
                cout << "out " << del_cnt - del_cnt_temp << endl;
            }
        }

    }
    double total_price() {  //商品总价格的计算
        double total = 0;
        for (int i = 0; i < MAXSIZE; i++) {  //货架shelf中各单价求和
            if (!shelf_pos_blank[i]) {  //如何货架非空
                total += shelf[i].get_price();
            }
        }
        return total;
    }
};

int main() {  //主函数，对所定义的类进行使用
    shirt_storage shiSto;  //衬衣仓库类的对象shiSto
    const char* in = "in";
    const char* out = "out";
    const char* num = "num";
    const char* price = "price";

    char ask[20];  //入库或出库
    int ask_num;  //入库或出库的衬衣数量
    double ask_price;  //入库或出库的衬衣价格
    char ask_place[20];  //产地
    char ask_material[20];  //材料

    while (true)
    {
        cin >> ask;
        if (!strcmp(ask, in)) {
            cin >> ask_num;
            if (ask_num > 0) {
                shiSto.in_something(ask_num);  //2件另一品种的Tianjin衬衣入库
            }
            else
            {
                cout << "wrong" << endl;
            }
        }
        if (!strcmp(ask, out)) {
            cin >> ask_num;
            cin >> ask_price >> ask_place >> ask_material;
            if (ask_num > 0) {
                shiSto.out_something(ask_num, ask_price, ask_place, ask_material);  //3件Tianjin衬衣出库
            }
            else
            {
                cout << "wrong" << endl;
            }
        }
        if (!strcmp(ask, num)) {
            cin >> ask_price >> ask_place >> ask_material;
            shiSto.out_number(ask_price, ask_place, ask_material);  //3件Tianjin衬衣出库
        }
        if (!strcmp(ask, price)) {
            cout << shiSto.total_price() << endl;  //当前的衬衣裤总价格
            return 0;
        }
    }
}
