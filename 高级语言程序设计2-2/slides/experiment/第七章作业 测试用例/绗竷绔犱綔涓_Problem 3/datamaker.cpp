#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<ctime>
using namespace std;
int n;
bool is_not_prime[10005];
int cnt,prime[10005];
int main(){
	for(int i=2;i<=10000;++i){
		if(!is_not_prime[i])prime[++cnt]=i;
		for(int j=1;j<=cnt&&i*prime[j]<=10000;++j){
			is_not_prime[i*prime[j]]=true;
			if(i%prime[j]==0)break;
		}
	}
	freopen("5.in","w",stdout);
	srand(time(NULL));
	n=100;
	for(int i=1,opt,a;i<=n;++i){
		opt=rand()%100,a=rand()%cnt+1;
		if(!opt)a=-a,cout<<a<<' ';
		else if(opt==1)a=rand()%10000+1,cout<<a<<' ';
		else cout<<prime[a]<<' ';
	}
}