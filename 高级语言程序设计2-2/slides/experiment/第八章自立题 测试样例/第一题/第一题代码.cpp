#include<iostream>
#include<string.h>
using namespace std;
class Clock
{
private:
    int H=0;
    int M=0;
    int S=0;
public:
    void SetTime(int h,int m,int s)
    {
        this->H = h;
        this->M = m;
        this->S = s;
    }
    void ShowTime()
    {
        cout<<"Now:"<<H<<":"<<M<<":"<<S<<endl;
    }

};

class AlarmClock:public Clock
{
private:
    int AH=0;
    int AM=0;
public:
    void SetAlarm(int AH,int AM)
    {
        this->AH = AH;
        this->AM = AM;
    }
    void ShowAlarm()
    {
        cout<<"AlarmTime:"<<AH<<":"<<AM<<endl;
    }
};


int main()
{
    AlarmClock A;
    int n;
    cin>>n;
    string functionName;
    while(n--){
        cin >> functionName;
        if(functionName == "SetTime"){
            int a,b,c;
            cin>>a>>b>>c;
            A.SetTime(a,b,c);
        }else if(functionName == "ShowTime"){
            A.ShowTime();
        }else if(functionName == "SetAlarm"){
            int a,b;
            cin>>a>>b;
            A.SetAlarm(a,b);
        }else if(functionName == "ShowAlarm"){
            A.ShowAlarm();
        }else{
            cout<<"没有这个函数！"<<endl;
        }
    }
    return 0;
}
