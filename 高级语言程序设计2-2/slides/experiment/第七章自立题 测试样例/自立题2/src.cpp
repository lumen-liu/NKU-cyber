#include<iostream>
using namespace std;


class CStudent { //ѧ���� CStudent 
	unsigned long reg_num; //���ݳ�Ա��ע��� 
	char *name; //���ݳ�Ա������ 
	float math, eng, comp; //���ݳ�Ա����ѧ��Ӣ�������ɼ� 
public: //���г�Ա���� 
	float sum(); //�����ſ��ܳɼ��ĺ��� sum 
	float average(); //�����ſ�ƽ���ɼ��ĺ��� average 
	void display(); //��ʾѧ��������Ϣ�ĺ��� display 
	void setData(unsigned long r, char* n, float m, float e, float c);
	//����ѧ��������Ϣ�ĺ��� setData 
};

float CStudent::sum() {
	return this->math+this->eng+this->comp;
}
float CStudent::average() {
	return (this->math + this->eng + this->comp)/3;
}
void CStudent::display() {
	cout << this->reg_num << " " << this->name << " " << this->math << " " << this->eng << " " << this->comp << endl;
}
void CStudent::setData(unsigned long r, char* n, float m, float e, float c) {
	this->reg_num = r;
	this->name = n;
	this->math = m;
	this->eng = e;
	this->comp = c;
}
//
//int main() {
//	CStudent stu[150];
//	unsigned long r;
//	float m;
//	float e;
//	float c;
//	int n;
//	const char *name;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		name = new char();
//		cin>>r>>(char*)name>>m>>e>>c;
//		stu[i].setData(r,(char*)name, m, e, c);
//	}
//	int max = -1;
//	int max_index = 0;
//	for (int i = 0; i < n; i++) {
//		cout << stu[i].sum() << " " << stu[i].average() << endl;
//		if (max < stu[i].sum()) {
//			max = stu[i].sum();
//			max_index = i;
//		}
//	}
//	stu[max_index].display();
//
//}

/*
3
100001 ma 78 86 90
100002 li 85 91 88
100003 hu 82 89 88

*/