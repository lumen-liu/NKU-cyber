#include <iostream> 
using namespace std;
class myStrCla { //�Զ����� myStrCla 
	char str[101]; //����ַ����������ַ��������� 100 ���ַ��� 
	int len; //��ǰ�ַ����ľ��峤�� 
public:
	myStrCla(char* s) {
		len = 0;
		while (*(s + len) != '\0') {
			str[len] = *(s + len);
			len += 1;
		}

	}; //���캯������ s �����ַ��� str �ĳ�ֵ 
	void strOut() {
		for (int i = 0; i < len; i++) {
			cout << str[i];
		}
		cout <<endl;
	}; //��Ļ����ַ��� str 
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
	}; //str ���Ƿ�Ϊ�����Ĵ����������뷴����ͬ�Ĵ��� 
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