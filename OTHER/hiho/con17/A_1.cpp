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
// Created Time  : 2015年12月27日 星期日 19时59分22秒
// File Name     : A_1.cpp

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

const int mod=2147483641;
const int MaxN=10005;
const int MaxS=100005;

const unsigned long long seed=1313;

struct HASHMAP {
	static const int HASH=1000003;

	int head[HASH],Hcou,next[MaxN];
	unsigned long long key[MaxN];
	int rem[MaxN];

	void init() {
		Hcou=0;
		memset(head,-1,sizeof(head));
	}

	void insert(unsigned long long k,int id) {
		int h=k%HASH;
		for(int i=head[h];i!=-1;i=next[i])
			if(key[i]==k) return;
		next[Hcou]=head[h];
		rem[Hcou]=id;
		key[Hcou]=k;
		head[h]=Hcou++;
	}

	int find(unsigned long long k) {
		int h=k%HASH;
		for(int i=head[h];i!=-1;i=next[i])
			if(key[i]==k) return rem[i];
		return -1;
	}

	unsigned long long hash(char s[]) {
		unsigned long long ret=0;
		for(int i=0;s[i];++i)
			ret=(ret*seed%mod+s[i])%mod;
		return ret;
	}
}sta;

unsigned long long base[MaxS];

void init() {
	base[0]=1;
	for(int i=1;i<MaxS;++i)
		base[i]=(base[i-1]*seed)%mod;
}

char s[MaxS];
int len;
unsigned long long rem[MaxS];

int vis[MaxN],flag;

void chuli() {
	rem[0]=(s[0]*base[len-1])%mod;
	for(int i=1;i<len;++i)
		rem[i]=((s[i]*base[len-1-i])%mod+rem[i-1])%mod;
}

int getans() {
	++flag;
	len=strlen(s);
	int ret=0;
	chuli();

	int d;
	unsigned long long ttt=0,t;

	for(int i=len-1;i>=0;--i) {
		for(char c='a';c<='z';++c) {
			t=(((rem[i]*seed)%mod+(c*base[len-1-i])%mod)%mod+ttt)%mod;
			d=sta.find(t);
			if(d!=-1 && vis[d]!=flag) {
				vis[d]=flag;
				++ret;
			}
		}
		(ttt+=(s[i]*base[len-1-i])%mod)%=mod;
	}
	for(char c='a';c<='z';++c) {
		t=((c*base[len])%mod+ttt)%mod;
		d=sta.find(t);
		if(d!=-1 && vis[d]!=flag) {
			vis[d]=flag;
			++ret;
		}
	}
	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	init();

	int N,M;
	while(~scanf("%d %d",&N,&M)) {
		sta.init();
		for(int i=1;i<=N;++i) {
			scanf("%s",s);
			sta.insert(sta.hash(s),i);
		}

		while(M--) {
			scanf("%s",s);
			printf("%d\n",getans());
		}
	}
	
	return 0;
}
