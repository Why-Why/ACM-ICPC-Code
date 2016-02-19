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
// Created Time  : 2015年12月27日 星期日 19时16分25秒
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

const int MaxN=100004;

struct HashMap
{
	const static int HASH=1000003;
	const static int MaxN=100005;

	int head[HASH],next[MaxN],Hcou;
	unsigned long long key[MaxN];			// 记录key值。
	int rem[MaxN];

	void init()
	{
		Hcou=0;
		memset(head,-1,sizeof(head));
	}

	int insert(unsigned long long val,int id)		// id不能为0。
	{
		int h=val % HASH;

		for(int i=head[h];i!=-1;i=next[i])
			if(val==key[i])
				return 0;

		rem[Hcou]=id;
		key[Hcou]=val;
		next[Hcou]=head[h];
		head[h]=Hcou++;

		return 1;
	}

	int find(unsigned long long k) {
		int h=k%HASH;

		for(int i=head[h];i!=-1;i=next[i])
			if(k==key[i]) return rem[i];
		return -1;
	}
}sta;

unsigned long long hash1(char num[])
{
	unsigned long long ret=0;
	unsigned long long seed=13131313;		// 13 131 1313 ...
	unsigned int mod=1000000007;

	for(int i=0;num[i];++i)
		ret=(ret*seed+num[i])%mod;

	return ret;
}

int N,M;
char s[100005];

int vis[MaxN],flag=1;

unsigned long long rem[100005];

int init() {
	int ret=0;

	unsigned long long ttt=0;
	unsigned long long seed=13131313;		// 13 131 1313 ...
	unsigned int mod=1000000007;

	for(int i=0;s[i];++i,++ret) {
		ttt=(ttt*seed+s[i])%mod;
		rem[i]=ttt;
	}
	return ret;
}

int getans() {
	++flag;
	int len=init();
	int ret=0;
	int dd;
	unsigned long long ttt=0,t=0;
	unsigned long long seed=13131313;		// 13 131 1313 ...
	unsigned int mod=1000000007;
	unsigned long long base=1;

	for(int i=len-1;i>=0;--i) {
		for(char c='a';c<='z';++c) {
			t=(rem[i]*base%mod*seed)%mod+c*base%mod+ttt;
			t=t%mod;
			dd=sta.find(t);
			if(dd!=-1 && vis[dd]!=flag) {
				vis[dd]=flag;
				++ret;
			}
		}
		(ttt+=base*s[i]%mod)%=mod;
		(base*=seed)%=mod;
	}
	for(char c='a';c<='z';++c) {
		t=c*base%mod+ttt;
		t=t%mod;
		dd=sta.find(t);
		if(dd!=-1 && vis[dd]!=flag) {
			vis[dd]=flag;
			++ret;
		}
	}
	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d",&N,&M);
	sta.init();
	while(N--) {
		scanf("%s",s);
		sta.insert(hash1(s),N+1);
	}

	while(M--) {
		scanf("%s",s);
		printf("%d\n",getans());
	}
	
	return 0;
}
