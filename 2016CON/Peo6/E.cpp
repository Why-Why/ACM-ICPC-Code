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
// Created Time  : 2016年04月16日 星期六 15时56分11秒
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

const int MaxN=155;

int cou;
long long rrr[MaxN];

int N;
priority_queue <int,vector<int>,greater<int> > que;
int E;

long long sum1,sum2;

bool judge() {
	for(int i=1;i<=cou;++i) {
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,a,b;
	scanf("%d",&T);

	while(T--) {
		scanf("%d",&N);
		while(!que.empty()) que.pop();
		for(int i=1;i<=N;++i) scanf("%d",&a),que.push(a);
		cou=0;
		scanf("%d",&E);
		sum1=sum2=0;

		while(!que.empty()) {
			if(que.size()==1) break;
			a=que.top();
			que.pop();
			b=que.top();
			que.pop();

			rrr[++cou]=max(a,b)-min(a,b);
			if(rrr[cou]==0) --cou;
			sum1+=min(a,b);
			sum2+=max(a,b);

			que.push(a+b);
		}

		cout<<sum1<<' '<<sum2<<endl;

		if(E>b || E<a) { puts("No"); continue; }
		E-=a;

		if(judge()) puts("Yes");
		else puts("No");
	}
	
	return 0;
}
