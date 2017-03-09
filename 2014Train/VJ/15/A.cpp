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
// Created Time  : 2016年09月19日 星期一 20时19分12秒
// File Name     : A.cpp

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

const int MaxN=21;
const int base=237568;
const int basenum=2520;

int num[MaxN];
long long dp[MaxN][(1<<18)+1];
int vis[MaxN][(1<<18)+1],flag;

inline int judge(int sta) {
	int a=sta&1,b=(sta>>1)&7,c=(sta>>4)&63;

	if(sta&(1<<10)) if(b%2) return 0;
	if(sta&(1<<11)) if(c%3) return 0;
	if(sta&(1<<12)) if(b%4) return 0;
	if(sta&(1<<13)) if(a) return 0;
	if(sta&(1<<14)) if(b%2 || c%3) return 0;
	if(sta&(1<<15)) if(c%7) return 0;
	if(sta&(1<<16)) if(b) return 0;
	if(sta&(1<<17)) if(c%9) return 0;

	return 1;
}

/*
void show(int sta) {
	for(int i=0;i<1;++i)
		if(sta&(1<<i)) cout<<1;
		else cout<<0;
	cout<<' ';
	for(int i=1;i<4;++i)
		if(sta&(1<<i)) cout<<1;
		else cout<<0;
	cout<<' ';
	for(int i=4;i<10;++i)
		if(sta&(1<<i)) cout<<1;
		else cout<<0;
	cout<<' ';
	for(int i=10;i<18;++i)
		if(sta&(1<<i)) cout<<1;
		else cout<<0;
	puts("");
}
*/

/*
long long mt8[MaxN],mt63[MaxN],p10[MaxN];

long long solve(int m8,int m63,int p) {
	//cout<<m8<<' '<<m63<<' '<<p<<endl;

	int a=mt8[p+1]*m8%8;
	int b=mt63[p+1]*m63%63;

	a=(8-a)%8;
	b=(63-b)%63;

	int c=(945*a+2080*b)%basenum;
	return (p10[p+1]-1-c)/basenum+1;
}
*/

long long dfs(int pos,int sta,bool lim) {
	if(pos<0) return judge(sta);

	if(!lim && vis[pos][sta]==flag) return dp[pos][sta];


	long long ret=0;
	int u=lim ? num[pos] : 9,t,b,c;

	/*
	if((sta&base)==base && !lim) {
		ret=solve((sta>>1)&7,(sta>>4)&63,pos);
		goto end;
	}
	*/

	for(int i=0;i<=u;++i) {
		t=sta;
		if(i>=2) t|=(1<<(i+8));
		if(i%5) t|=1;
		else if(t&1) t^=1;

		b=(sta>>1)&7;
		c=(sta>>4)&63;

		b=(b*10+i)%8;
		c=(c*10+i)%63;

		t=(t&(~(14)))|(b<<1);
		t=(t&(~(63<<4)))|(c<<4);

		ret+=dfs(pos-1,t,lim && i==num[pos]);
	}

end:

	if(!lim) dp[pos][sta]=ret,vis[pos][sta]=flag;
	return ret;
}

/*
map <long long,long long> rem;
map <long long,long long> ::iterator iter;
typedef pair<long long,long long> pii;
*/

inline long long getans(long long x) {
	if(!x) return 1;

	//long long tx=x;
	//iter=rem.find(tx);
	//if(iter!=rem.end()) return iter->second;

	int dep=0;
	for(;x;x/=10) num[dep++]=x%10;

	long long ret=dfs(dep-1,0,1);
	return ret;

	//rem.insert(pii(tx,ret));
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	/*
	mt8[0]=mt63[0]=p10[0]=1;
	for(int i=1;i<MaxN;++i) {
		p10[i]=p10[i-1]*10;
		mt8[i]=mt8[i-1]*10%8;
		mt63[i]=mt63[i-1]*10%63;
	}
	*/

	int T;
	long long a,b;

	++flag;
	scanf("%d",&T);
	while(T--) {
		scanf("%I64d %I64d",&a,&b);
		--a;
		printf("%I64d\n",getans(b)-getans(a));
	}

	return 0;
}
