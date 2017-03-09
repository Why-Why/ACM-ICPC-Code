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
// Created Time  : 2017年03月03日 星期五 13时16分10秒
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

struct State {
	int u2,u3,num;
	int val;

	State() {}
	State(int a,int b,int c,int d):u2(a),u3(b),num(c),val(d) {}
};

int ans[100000];
bool vis[4][3][100000];
State que[12*100000+5];
int first,last;

inline int toSwap(int t[],int p) {
	swap(t[p],t[p+1]);
	int ret=0;
	for(int i=5;i>=1;--i) ret=ret*10+t[i];
	return ret;
}

inline int toAdd(int t[],int p) {
	t[p]=(t[p]+1)%10;
	int ret=0;
	for(int i=5;i>=1;--i) ret=ret*10+t[i];
	return ret;
}

inline int toMul(int t[],int p) {
	t[p]=(t[p]*2)%10;
	int ret=0;
	for(int i=5;i>=1;--i) ret=ret*10+t[i];
	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	memset(ans,0x3f,sizeof(ans));

	ans[12345]=0;
	vis[0][0][12345]=1;

	first=last=0;
	que[last++]=State(0,0,12345,0);

	State t,tt;
	int tn;
	int ts[10],tts[10];

	while(last-first) {
		t=que[first++];
		for(int i=1;i<=5;++i,t.num/=10) tts[i]=t.num%10;

		for(int i=1;i<5;++i) {
			for(int i=1;i<=5;++i) ts[i]=tts[i];
			tn=toSwap(ts,i);

			if(vis[t.u2][t.u3][tn]==0) {
				vis[t.u2][t.u3][tn]=1;
				ans[tn]=min(ans[tn],t.val+1);
				que[last++]=State(t.u2,t.u3,tn,t.val+1);
			}
		}

		if(t.u2<3) {
			for(int i=1;i<=5;++i) {
				for(int i=1;i<=5;++i) ts[i]=tts[i];
				tn=toAdd(ts,i);

				if(vis[t.u2+1][t.u3][tn]==0) {
					vis[t.u2+1][t.u3][tn]=1;
					ans[tn]=min(ans[tn],t.val+1);
					que[last++]=State(t.u2+1,t.u3,tn,t.val+1);
				}
			}
		}

		if(t.u3<2) {
			for(int i=1;i<=5;++i) {
				for(int i=1;i<=5;++i) ts[i]=tts[i];
				tn=toMul(ts,i);

				if(vis[t.u2][t.u3+1][tn]==0) {
					vis[t.u2][t.u3+1][tn]=1;
					ans[tn]=min(ans[tn],t.val+1);
					que[last++]=State(t.u2,t.u3+1,tn,t.val+1);
				}
			}
		}
	}

	int x;
	while(~scanf("%d",&x)) {
		if(ans[x]==0x3f3f3f3f) ans[x]=-1;
		printf("%d\n",ans[x]);
	}

	return 0;
}
