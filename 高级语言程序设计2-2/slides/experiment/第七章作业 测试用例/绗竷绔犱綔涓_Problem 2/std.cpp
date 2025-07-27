#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int gcd(int x,int y){return y?gcd(y,x%y):x;}
struct Frac{
	int a,b;
	Frac(int x=0,int y=0):a(x),b(y){}
	void Simp(){
		if(!a||!b)return;
		int g(gcd(a,b));
		a/=g,b/=g;
		if(b<0)a*=-1,b*=-1;
	}
	Frac operator+(const Frac &x){
		Frac ret;
		ret.b=b*x.b;
		ret.a=b*x.a+a*x.b;
		ret.Simp();
		return ret;
	}
	Frac operator-(const Frac &x){
		Frac ret;
		ret.b=b*x.b;
		ret.a=a*x.b-b*x.a;
		ret.Simp();
		return ret;
	}
	Frac operator*(const Frac &x){
		Frac ret;
		ret.b=b*x.b;
		ret.a=a*x.a;
		ret.Simp();
		return ret;
	}
	Frac operator/(const Frac &x){
		Frac ret;
		ret.b=b*x.a;
		ret.a=a*x.b;
		ret.Simp();
		return ret;
	}
	Frac operator=(const Frac &x){
		a=x.a,b=x.b;
		return *this;
	}
	void pp(){
		a+=b;
		Simp();
	}
	void rev(){
		a^=b^=a^=b;
		Simp();
	}
	void display(){
		if(!a||b==1){cout<<a<<endl;}
		else{cout<<a<<'/'<<b<<endl;}
	}
};
int n;
char tmp;
int main(){
	freopen("5.in","r",stdin);
	freopen("5.out","w",stdout);
	cin>>n;
	for(int i=1,opt,a1,b1,a2,b2;i<=n;++i){
		cin>>opt>>a1>>tmp>>b1;
		if(opt<=4)cin>>a2>>tmp>>b2;
		if(opt<=4){
			Frac f1(a1,b1),f2(a2,b2),ret;
			if(opt==1){
				ret=f1+f2;
			}
			else if(opt==2){
				ret=f1-f2;
			}
			else if(opt==3){
				ret=f1*f2;
			}
			else{
				ret=f1/f2;
			}
			ret.display();
		}
		else{
			Frac f(a1,b1);
			if(opt==5)f.pp();
			else f.rev();
			f.display();
		}
	}
}