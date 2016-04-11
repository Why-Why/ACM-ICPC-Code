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
// Created Time  : 2016年03月19日 星期六 02时07分10秒
// File Name     : E.cpp

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

const int MaxN=1000005;
const int mod=1000000007;

char s[MaxN];
int N,K;

long long rem[30];
long long d;

int last[30];

int zcou;
set<int>remz;

int remo[30],remocou=0;

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d",&N,&K);
	scanf("%s",s+1);

	d=0;
	zcou=K;
	for(int i=0;i<K;++i) remz.insert(i);
	memset(rem,-1,sizeof(rem));

	long long temp;

	for(int i=1;s[i];++i) {
		if(rem[s[i]-'a']==-1) {
			temp=d;
			d=(d<<1)+1;
			d%=mod;
			rem[s[i]-'a']=temp;
			last[s[i]-'a']=i;
			--zcou;
			remz.erase(s[i]-'a');
		}
		else {
			temp=d;
			d=(d<<1)-rem[s[i]-'a'];
			d=(d%mod+mod)%mod;			// !!!
			rem[s[i]-'a']=temp;
			last[s[i]-'a']=i;
		}
	}

	typedef pair<int,int> pii;
	pii ttt[30];
	int tttcou=0;

	for(int i=0;i<K;++i)
		if(rem[i]!=-1) {
			ttt[tttcou++]=pii(last[i],i);
		}
	sort(ttt,ttt+tttcou);

	for(int i=0;i<tttcou;++i)
		remo[remocou++]=ttt[i].second;

	int t;
	int p=0;

	for(int i=1;i<=N;++i) {
		if(zcou) {
			t=*remz.begin();
			remz.erase(t);
			--zcou;

			temp=d;
			d=(d<<1)+1;
			d%=mod;
			rem[t]=temp;

			remo[remocou++]=t;
		}
		else {
			t=remo[p++];
			if(p>=remocou) p=0;

			temp=d;
			d=(d<<1)-rem[t];
			d=(d%mod+mod)%mod;		// !!!
			rem[t]=temp;
		}
	}

	cout<<(d+1)%mod<<endl;
	
	return 0;
}
