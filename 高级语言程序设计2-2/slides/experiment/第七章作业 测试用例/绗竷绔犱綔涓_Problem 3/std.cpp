#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
int x;
vector<int> ans;
bool vis[10005];
bool check(int x){
	for(int i=2;i<x;++i)
		if(x%i==0)return false;
	return true;
}
int main(){
	freopen("5.in","r",stdin);
	freopen("5.out","w",stdout);
	while(scanf("%d",&x)!=EOF){
		if(x<=1)break;
		if(!check(x))break;
		if(vis[x])continue;
		ans.emplace_back(x);vis[x]=true;
	}
	sort(ans.begin(),ans.end());
	for(auto&a:ans)cout<<a<<' ';
}