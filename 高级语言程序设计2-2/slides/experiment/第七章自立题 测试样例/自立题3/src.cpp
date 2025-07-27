#include<iostream>
using namespace std;


const int max_size = 10;
class queue {
private:
	float data[max_size]; //data �д�Ŷ��е�ʵ�����ݣ�maxsize Ϊ���ȶ������������ 
	int front, rear; //��β�±꣬�������ݷ��� data[front+1]�� data[rear]֮�� 
	int num;
public:
	queue(void); //���캯������ front=rear=-1��num=0����ζ�Ŷ���Ϊ�� 
	bool Empty(void); //�ж϶����Ƿ�Ϊ�գ����� num �Ƿ�Ϊ 0�� 
	bool Full(void); //�ж϶����Ƿ����������� num �Ƿ���� maxsize�� 
	void Add(float); //������β���������ݣ����뵽 data[rear+1]����num �� 1�� 
	float Delete(void);
};

queue::queue(void) {
	num = 0;
	front = rear = -1;
}

bool queue::Empty() {
	if (num == 0) {
		return true;
	}
	else {
		return false;
	}
}

bool queue::Full() {
	if (num == max_size) {
		return true;
	}
	else {
		return false;
	}
}

void queue::Add(float a) {
	num += 1;
	rear =(rear+1)%max_size;
	data[rear] = a;
}

float queue::Delete() {
	num -= 1;
	front = (front + 1) % max_size;
	return data[front];
}



int main() {
	queue q;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int op;
		cin >> op;
		if (op == 0) {
			float a;
			cin >> a;
			q.Add(a);
		}
		else if (op == 1) {
			cout << q.Delete() << endl;
		}
		else if (op == 2) {
			cout << q.Empty() << endl;
		}
		else if (op == 3) {
			cout << q.Full()<<endl;
		}

	}

}

/*
10
0 3
0 4
0 5
0 8
3
2
1
0 9
1
1
------
0
0
3
4
5


12
0 3
0 4
0 5
0 8
3
2
1
1
1
1
3
2
----
0
0
3
4
5
8
0
1


15
0 1
0 2
0 3
0 4
0 5
0 6
0 7
0 8
0 9
0 10.1
3
1
3
0 11.1
3
----
1
1
0
1







*/