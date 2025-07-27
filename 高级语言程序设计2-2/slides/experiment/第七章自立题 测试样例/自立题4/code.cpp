#include <iostream>
using namespace std;

class matrix {
public:
    int r, c; //r行c列的矩阵
    int** mem; //矩阵数据
    matrix(int a,int b); //二参构造函数，分配a行b列的mem动态数组存放数据
    ~matrix(); //析构函数，释放 mem 动态数组

    matrix operator+ (matrix & m); //矩阵加
    matrix operator- (matrix & m); //矩阵减
    matrix operator* (matrix & m); //矩阵乘
    matrix operator~ (); //矩阵转置
    void display(); //输出矩阵
};

matrix::matrix(int a, int b) {
    r = a;
    c = b;
    if(r ==0 || c==0){
        mem = NULL;
    } else {
        mem = new int*[r];
        for(int i=0;i<r;i++){
            mem[i] = new int[c];
        }
    }
}

matrix::~matrix() {
    if(mem != NULL) {
        for(int i=0;i<r;i++){
            delete[] mem[i];
        }
        delete[] mem;
    }

}

matrix matrix::operator+(matrix &m) {
    matrix res(r,c);
    if(r!=m.r || c!=m.c){
        matrix tmp(0,0);
        res = tmp;
    }else {
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                res.mem[i][j] = mem[i][j] + m.mem[i][j];
            }
        }
    }
    return res;
}

matrix matrix::operator-(matrix &m) {
    matrix res(r,c);
    if(r!=m.r || c!=m.c){
        matrix tmp(0,0);
        res = tmp;
    } else {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                res.mem[i][j] = mem[i][j] - m.mem[i][j];
            }
        }
    }
    return res;
}

matrix matrix::operator*(matrix &m) {
    // 如果两个矩阵不能相乘
    matrix res(r,m.c);
    if(c != m.r){
        matrix tmp(0,0);
        res = tmp;
    } else {
        for(int i=0;i<r;i++){
            for(int j=0;j<m.c;j++){
                int tmp =0;
                for(int x=0;x<c;x++){
                    tmp = tmp + mem[i][x] * m.mem[x][j];
                }
                res.mem[i][j] = tmp;
            }
        }
    }
    return res;
}

matrix matrix::operator~() {
    matrix res(c,r);

    for(int i=0;i<c;i++){
        for(int j=0;j<r;j++){
            res.mem[i][j] = mem[j][i];
        }
    }
    return res;
}

void matrix::display() {
    if(r==0){
        cout << "err" << endl;
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c-1;j++){
            cout << mem[i][j] << " ";
        }
        cout << mem[i][c-1] << endl;
    }
}

int main() {
    int r1,c1,r2,c2;
    cin >> r1 >> c1 >> r2 >> c2;

    // 创建matrix对象
    matrix x(r1,c1);
    matrix y(r2,c2);

    // 读取矩阵数据
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            cin >> x.mem[i][j];
        }
    }

    for(int i=0;i<r2;i++){
        for(int j=0;j<c2;j++){
            cin >> y.mem[i][j];
        }
    }

    (x+y).display();
    cout << endl;
    (x-y).display();
    cout << endl;
    (x*y).display();
    cout <<endl;
    (~x).display();

    return 0;
}
