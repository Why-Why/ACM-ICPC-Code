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
// Created Time  : 2016年03月19日 星期六 00时45分30秒
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

int start,end;

inline int zhuan(char s[]) {
	int ret=0;
	for(int i=0;s[i];++i) {
		ret<<=2;
		if(s[i]=='X') ret|=0;
		else ret|=(s[i]-'A'+1);
	}
	return ret;
}

int ans[1000];

bool judge(int from,int to) {
	if(ans[to]) return 0;
	int cou[4]={};
	int rem[4];
	int rrr[4];
	int r1,r2;
	for(int i=3;i>=0;--i) {
		rem[i]=to&3;
		to>>=2;
		++cou[rem[i]];

		rrr[i]=from&3;
		from>>=2;

		if(rem[i]==0) r1=i;
		if(rrr[i]==0) r2=i;
	}

	for(int i=0;i<4;++i) if(cou[i]!=1) return 0;

	if(min(r1,r2)==0 && max(r1,r2)==3) return 0;
	if(min(r1,r2)==1 && max(r1,r2)==2) return 0;
	if(r1==r2) return 0;

	rrr[r2]=rrr[r1];
	rrr[r1]=0;

	for(int i=0;i<4;++i) if(rrr[i]!=rem[i]) return 0;
	return 1;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	char s[10];
	int temp;

	scanf("%s",s);
	scanf("%s",s+2);
	start=zhuan(s);

	scanf("%s",s);
	scanf("%s",s+2);
	end=zhuan(s);
	
	queue<int>que;
	que.push(start);
	ans[start]=1;

	while(!que.empty()) {
		temp=que.front();
		que.pop();

		for(int i=0;i<256;++i)
			if(judge(temp,i)) {
				que.push(i);
				ans[i]=1;
			}
	}

	if(ans[end]) puts("YES");
	else puts("NO");
	
	return 0;
}
