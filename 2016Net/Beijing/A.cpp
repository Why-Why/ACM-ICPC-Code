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
// Created Time  : 2016年09月24日 星期六 14时39分30秒
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

string rem[33];
int N;

char s[1000];

void show(const char ts[],int cou) {
	strcpy(s,ts);

	int p=0,last=0;
	char tc;

	while(s[p]) {
		last=p;
		while(s[p] && s[p]!='/') ++p;

		tc=s[p];
		s[p]=0;

		for(int i=0;i<cou;++i) cout<<"    ";
		++cou;
		if(s[last]==120) ++last;
		cout<<s+last<<endl;

		s[p]=tc;
		if(tc==0) break;
		++p;
	}
}

void getans() {
	sort(rem,rem+N);
	N=unique(rem,rem+N)-rem;

	const char * s1,* s2;

	show(rem[0].data(),0);
	for(int i=1;i<N;++i) {
		s1=rem[i-1].data();
		s2=rem[i].data();

		int j,cou=0,last=-1;
		for(j=0;s1[j] && s2[j] && s1[j]==s2[j];++j)
			if(s1[j]=='/') ++cou,last=j;

		//for(int j=0;j<cou;++j) cout<<"    ";
		show(s2+last+1,cou);
	}
}

char ttt[1000],t2[1000];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	ios::sync_with_stdio(false);

	int cas=1;

	N=0;
	while(cin.getline(ttt,1000)) {
		int pos=-1;

		for(int i=strlen(ttt)-1;i>=0;--i)
			if(ttt[i]=='/') {
				pos=i;
				break;
			}

		int ccc=0;
		for(int i=0;i<=pos;++i) t2[ccc++]=ttt[i];
		t2[ccc++]=120;
		for(int i=pos+1;ttt[i];++i)
			t2[ccc++]=ttt[i];
		t2[ccc]=0;

		rem[N]=string(t2);

		//cout<<rem[N]<<endl;

		if(rem[N]==string("x0")) {
			//printf("Case %d:\n",cas++);
			cout<<"Case "<<cas++<<":"<<endl;
			getans();
			N=-1;
		}
		++N;
	}

	return 0;
}
