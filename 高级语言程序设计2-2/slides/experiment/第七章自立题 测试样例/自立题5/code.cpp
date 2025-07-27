#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class MyCalcu1{
public:
    string expression; //后缀表达式
    MyCalcu1(string exp);
    void process(); // 内部计算并输出后缀表达式的计算结果
};

MyCalcu1::MyCalcu1(string exp) {
    expression = exp;
}

// 判断是否为正常的实数
bool isNumber(string s) {
    bool sign = 0;
    bool num = 0;
    bool dec = 0;
    int point = 0;

    int n = s.size();
    for (int i = 0; i < n; ++i) {
        if (s[i] == '+' || s[i] == '-') {
            //不能出现两个符号
            if (sign) {
                return false;
            }
            //如果符号位在最开始
            if (i == 0) {
                sign = 1;
            }
                //符号不能出现在其他位置
            else {
                return false;
            }
        }
        else if (s[i] == '.') {
            //只能存在一个点
            if (point) {
                return false;
            }
            point = 1;
        }
        else if (s[i] >= '0' && s[i] <= '9') {
            //如果有小数点，当前数字就是小数位，小数位有效
            if (point) {
                dec = 1;
            }
                //否则就是整数位，整数位有效
            else {
                num = 1;
            }
        }
        else {
            //其他字符直接返回
            return false;
        }
    }
    //返回是否构成了有效的整数或者小数
    return num || dec;
}

void MyCalcu1::process() {
    stack<double> stack;
    vector<string> vec;

    // 按照空格对表达式进行拆分
    string tmp = "";
    int exp_size = expression.size();
    for(int i=0;i<exp_size;i++){
        if(expression[i]!=' '){
            tmp += expression[i];
        } else {
            vec.push_back(tmp);
            tmp = "";
        }
    }
    vec.push_back(tmp);

    // 开始进行计算
    int vec_size = vec.size();
    for(int i=0;i<vec_size;i++){
        string str = vec[i];

        // 是数字直接放进栈中
        if(isNumber(str)){
            stack.push(stod(str));
        }
            // 是否是运算符
        else if(str=="+" || str == "-" || str == "*" || str == "/"){
            // 取不出数字进行计算 表明表达式出错了
            if(stack.size()<2) {
                cout << "err" << endl;
                return;
            }

            double b = stack.top();
            stack.pop();
            double a = stack.top();
            stack.pop();

            if(str == "+"){
                a+=b;
            } else if(str == "-"){
                a-=b;
            } else if(str == "*"){
                a*=b;
            } else if(str == "/"){
                a/=b;
            }
            stack.push(a);
        }
            // 出现其他字符 出错
        else {
            cout << "err" << endl;
            return;
        }
    }

    if(stack.size()==1){
        cout << stack.top() << endl;
    } else {
        cout << "err" << endl;
    }
}


int main() {
    string exp;
    getline(cin,exp);
    MyCalcu1 cal(exp);

    cal.process();

    return 0;
}
