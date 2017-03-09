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
// Created Time  : 2016年03月03日 星期四 16时43分56秒
// File Name     : I.cpp

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

const int MaxN=100005;

int N,K;
int rem[MaxN];
int num[MaxN];
int zuo[MaxN],you[MaxN];

struct State {
	int val,p,v;

	State(int a=0,int b=0,int c=0):val(a),p(b),v(c) {}
	bool operator < (const State & b) const {
		return val<b.val;
	}
};

priority_queue <State> que;

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	State temp;
	int ans;

	scanf("%d",&T);
	while(T--) {
		while(!que.empty()) que.pop();

		scanf("%d %d",&N,&K);

		if(N==0) {
			if(K<=1) puts("0");
			else if(K==2) puts("4");
			else printf("%d\n",1+2*(K-2)+3*(K-1));
			continue;
		}
		else if(N==1 && K) ans=K*2-1;
		else ans=K*2;

		zuo[0]=num[0]=0;
		for(int i=1;i<=N;++i) {
			scanf("%d",num+i);
			rem[i]=0;
			zuo[i]=i-1;
			you[i]=i+1;
			que.push(State(num[i]+num[i-1],i,0));
		}

		while(K) {
			temp=que.top();
			que.pop();
			if(temp.p!=-1 && temp.v<rem[temp.p]) continue;
			--K;
			ans+=temp.val;
			que.push(State(3,-1,0));
			if(temp.p==-1) continue;

			if(zuo[temp.p]) ++rem[zuo[temp.p]];
			++rem[temp.p];
			if(you[temp.p]<=N) ++rem[you[temp.p]];

			zuo[you[temp.p]]=zuo[zuo[temp.p]];
			you[zuo[zuo[temp.p]]]=you[temp.p];
			if(you[temp.p]<=N)
				que.push(State(num[you[temp.p]]+num[zuo[you[temp.p]]],you[temp.p],rem[you[temp.p]]));
		}
		printf("%d\n",ans);
	}
	
	return 0;
}
