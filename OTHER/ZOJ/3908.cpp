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
// Created Time  : 2016年04月22日 星期五 00时39分05秒
// File Name     : 3908.cpp

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

const int MaxN=10005;

int N,M,K;
int rem[MaxN];

struct State {
	int a,b;
	long long s;

	bool operator < (const State & y) const {
		return s<y.s;
	}

	State(long long x,int y,int z):s(x),a(y),b(z) {}
	State() {}
};

priority_queue <State> que;
int num[100005];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	State temp;
	int T,a;

	scanf("%d",&T);
	while(T--) {
		scanf("%d %d %d",&N,&M,&K);
		memset(rem,0,sizeof(rem));
		for(int i=1;i<=N;++i) {
			scanf("%d",&a);
			num[i]=a;
			++rem[a];
		}
		sort(num+1,num+N+1);
		N=unique(num+1,num+N+1)-num-1;

		int t;

		while(!que.empty()) que.pop();
		for(int i=0;i<=10000;++i) {
			if(rem[i]==0) continue;
			t=min(i,K-i);
			if(t<0) break;
			t=upper_bound(num+1,num+N+1,t)-num-1;

			que.push(State(i*t,i,t));
		}

		long long ans=0;
		while(!que.empty()) {
			temp=que.top();
			que.pop();

			if(temp.a==temp.b) {
				if(rem[temp.a]>=2) {
					--M;
					rem[temp.a]-=2;
					ans+=temp.s;
					que.push(temp);
				}
				else {
					if(temp.b>0) {
						--temp.b;
						temp.s=temp.b*temp.a;
						que.push(temp);
					}
				}
			}
			else {
				if(rem[temp.a]>=1 && rem[temp.b]>=1) {
					--M;
					--rem[temp.a];
					--rem[temp.b];
					ans+=temp.s;
					que.push(temp);
				}
				else {
					if(temp.b>0) {
						--temp.b;
						temp.s=temp.b*temp.a;
						que.push(temp);
					}
				}
			}
			
			if(M<=0) break;
		}

		printf("%lld\n",ans);
	}
	
	return 0;
}
