#include<iostream>
#include<string.h>
using namespace std;
class Date
{
public:
    void SetDate(int y,int m,int d)
    {
        Year=y;
        Month=m;
        Day=d;
    }
    void PrintDate()
    {
        cout<<Year<<"/"<<Month<<"/"<<Day;
    }
    Date():Year(0),Month(0),Day(0) {}
    Date(int y,int m,int d):Year(y),Month(m),Day(d) {}
    int Year,Month,Day;
};
class Time
{
public:
    void SetTime(int h,int m,int s)
    {
        Hours=h;
        Minutes=m;
        Seconds=s;
    }
    void PrintTime()
    {
        cout<<Hours<<":"<<Minutes<<":"<<Seconds;
    }
    Time():Hours(0),Minutes(0),Seconds(0) {}
    Time(int h,int m,int s):Hours(h),Minutes(m),Seconds(s) {}
    int Hours,Minutes,Seconds;
};
class DateTime: public Date,public Time
{
public:
    DateTime():Date(),Time() {};
    DateTime(int y,int mo,int d,int h,int mi,int s):Date(y,mo,d),Time(h,mi,s) {}
    void PrintDateTime()
    {
        PrintDate();
        cout<<" ";
        PrintTime();
    }
    void incrementSeconds(int s)
    {
        int H = Hours;
        int M = Minutes;
        int S = Seconds;

        int tempD=0;
        int tempH=0;
        int tempM=0;
        int tempS=0;
        if(s >= 86400){
            tempD = s/86400;
            s = s%86400;
        }
        if(s >= 3600){
            tempH = s/3600;
            s = s%3600;
        }
        if(s >= 60){
            tempM = s/60;
            s = s%60;
        }
        tempS = tempS + s;

        int temp = 0;

        if(S + tempS >= 60){
            temp = 1;
            S = S + tempS - 60;
        }else{
            temp = 0;
            S = S + tempS;
        }
        if(M + tempM + temp>= 60){
            temp = 1;
            M = M + tempM + temp - 60;
        }else{
            temp = 0;
            M = M + tempM + temp;
        }
        if(H + tempH + temp>= 24){
            temp = 1;
            H = H + tempH + temp - 24;
        }else{
            temp = 0;
            H = H + tempH + temp;
        }
        tempD = tempD + temp;

        Hours = H;
        Minutes = M;
        Seconds = S;
        incrementDays(tempD);
    }
    void incrementDays(int days){
        int _day = Day;
        int _month = Month;
        int _year = Year;
        _day += days;
        while (_day > GetDayByYearAndMonth(_year, _month))
        {
            _day =_day - GetDayByYearAndMonth(_year,_month);
            _month += 1;
            if (_month > 12)
            {
                ++_year;
                _month = 1;
            }
        }

        Day = _day;
        Month = _month;
        Year = _year;
    }
private:
    bool IsLeapYear(int year)
    {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    int GetDayByYearAndMonth(int year, int month)//判断返回的月份的天数
    {


        int MonthDay[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        if (IsLeapYear(year) && month == 2)
        {
            return 29;
        }
        else
        {
            return MonthDay[month];
        }
    }
};
int main()
{
    DateTime dt_a;
    int n;
    cin>>n;
    string functionName;
    while(n--){
        cin >> functionName;
        if(functionName == "SetTime"){
            int a,b,c;
            cin>>a>>b>>c;
            dt_a.SetTime(a,b,c);
        }else if(functionName == "PrintTime"){
            dt_a.PrintTime();
            cout<<endl;
        }else if(functionName == "SetDate"){
            int a,b,c;
            cin>>a>>b>>c;
            dt_a.SetDate(a,b,c);
        }else if(functionName == "PrintDate"){
            dt_a.PrintDate();
            cout<<endl;
        }else if(functionName == "PrintDateTime"){
            dt_a.PrintDateTime();
            cout<<endl;
        }else if(functionName == "incrementSeconds"){
            int s;
            cin>>s;
            dt_a.incrementSeconds(s);
        }else{
            cout<<"没有这个函数！"<<endl;
        }
    }
    return 0;
}
