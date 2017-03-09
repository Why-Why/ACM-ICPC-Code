// ━━━━━━神兽出没━━━━━━
//      ┏┓       ┏┓
//     ┏┛┻━━━━━━━┛┻┓
//     ┃           ┃
//     ┃     ━     ┃
//     ████━████   ┃
//     ┃           ┃
//     ┃    ┻      ┃
//     ┃           ┃
//     ┗━┓       ┏━┛
//       ┃       ┃
//       ┃       ┃
//       ┃       ┗━━━┓
//       ┃           ┣┓
//       ┃           ┏┛
//       ┗┓┓┏━━━━━┳┓┏┛
//        ┃┫┫     ┃┫┫
//        ┗┻┛     ┗┻┛
//
// ━━━━━━感觉萌萌哒━━━━━━

// Author        : WhyWhy
// Created Time  : 2016年02月27日 星期六 14时32分56秒
// File Name     : D.cpp

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

const int MaxN=1005;
const int mod=1000000007;

typedef pair <int,long long> pii;
pii data[MaxN][505];
int dcou;
char s[MaxN];
long long temp[505];

int run(int x,int y,int &cou) {
	if(x==y) {
		memset(temp,0,sizeof(temp));
		++dcou;
		if(s[x]=='x') temp[1]=1,data[dcou][0]=pii(1,1);
		else temp[0]=s[x]-'0',data[dcou][0]=pii(0,s[x]-'0');
		cou=1;
		return dcou;
	}

	int kcou=0;
	int rem1=-1,rem2=-1;

	for(int i=x;i<=y;++i)
		if(s[i]=='(') ++kcou;
		else if(s[i]==')') --kcou;
		else if(kcou==0 && s[i]=='+') rem1=i;
		else if(kcou==0 && s[i]=='*') rem2=i;

	if(rem1==-1) rem1=rem2;
	if(rem1==-1) return run(x+1,y-1,cou);


	int a,b,acou,bcou;
	a=run(x,rem1-1,acou);
	b=run(rem1+1,y,bcou);

	memset(temp,0,sizeof(temp));
	if(s[rem1]=='+') {
		for(int i=0;i<acou;++i) (temp[data[a][i].first]+=data[a][i].second)%=mod;
		for(int i=0;i<bcou;++i) (temp[data[b][i].first]+=data[b][i].second)%=mod;
	}
	else {
		for(int i=0;i<acou;++i)
			for(int j=0;j<bcou;++j)
				(temp[data[a][i].first+data[b][j].first]+=(data[a][i].second*data[b][j].second)%mod)%=mod;
	}


	++dcou;
	cou=0;
	for(int i=504;i>=0;--i)
		if(temp[i])
			data[dcou][cou++]=pii(i,temp[i]);

	return dcou;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	scanf("%d",&T);
	while(T--) {
		dcou=0;
		scanf("%s",s);
		int cou;
		int t=run(0,strlen(s)-1,cou);
		bool start=0;
		for(int i=504;i>=0;--i)
			if(!start) {
				if(temp[i]) printf("%d",(int)temp[i]),start=1;
			}
			else printf(" %d",(int)temp[i]);
		if(start==0) printf("%d",0);
		puts("");
	}
	
	return 0;
}
