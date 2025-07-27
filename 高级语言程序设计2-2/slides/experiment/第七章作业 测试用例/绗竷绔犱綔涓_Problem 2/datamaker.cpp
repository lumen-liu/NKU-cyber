#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<ctime>
using namespace std;
int n;
int main(){
	srand(time(NULL));
	freopen("5.in","w",stdout);
	n=5;cout<<n<<endl;
	for(int i=1,opt,a1,b1,a2,b2;i<=n;++i){
		opt=rand()%6+1;
		a1=rand()%100+1,b1=rand()%100+1,a2=rand()%100+1,b2=rand()%100+1;
		cout<<opt;
		if(opt>=1&&opt<=4){
			cout<<' '<<a1<<'/'<<b1<<' '<<a2<<'/'<<b2<<endl;
		}
		else{
			cout<<' '<<a1<<'/'<<b1<<endl;
		}
	}
}