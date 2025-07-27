#include <iostream> 
using namespace std;
class myStrCla { //自定义类 myStrCla 
	char str[101]; //存放字符串（假设字符串不超过 100 个字符） 
	int len; //当前字符串的具体长度 
public:
	myStrCla(char* s) {
		len = 0;
		while (*(s + len) != '\0') {
			str[len] = *(s + len);
			len += 1;
		}

	}; //构造函数，由 s 带来字符串 str 的初值 
	void strOut() {
		for (int i = 0; i < len; i++) {
			cout << str[i];
		}
		cout <<endl;
	}; //屏幕输出字符串 str 
	bool strIsPal() {
		int first = 0, last = len - 1;
		while (last >= first) {
			if (str[last] != str[first]) {
				return false;
			}
			last--;
			first++;
		}
		return true;
	}; //str 串是否为“回文串”（正读与反读相同的串） 
};


//int main() {
//	char s[101];
//	cin >> s;
//	myStrCla obj1(s);
//	obj1.strOut();
//	if (obj1.strIsPal())
//		cout << "True" << endl;
//	else
//		cout << "False" << endl;
//}