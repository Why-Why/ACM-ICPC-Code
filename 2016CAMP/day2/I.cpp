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
// Created Time  : 2017年02月13日 星期一 17时27分03秒
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

const int MaxN=1000005;

int vis[MaxN],flag;
int fa[MaxN];
int du[MaxN];
int N;

queue <int> que,que2,que3;

int cou[MaxN];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int ans,sum,u,tmp,ok;

	while(~scanf("%d",&N)) {
		fa[1]=0;
		for(int i=1;i<=N;++i) du[i]=0;
		for(int i=2;i<=N;++i) scanf("%d",fa+i),++du[fa[i]];

		while(!que.empty()) que.pop();

		for(int i=1;i<=N;++i)
			if(du[i]==0) que.push(i);
		sum=que.size();

		ans=0;

		while(sum<N) {
			++flag;

			while(!que2.empty()) que2.pop();
			while(!que3.empty()) que3.pop();

			while(!que.empty()) {
				u=que.front();
				que.pop();
				--du[fa[u]];

				if(vis[fa[u]]!=flag) {
					vis[fa[u]]=flag;
					cou[fa[u]]=1;

					que3.push(fa[u]);
				}
				else ++cou[fa[u]];

				if(du[fa[u]]==0) que2.push(fa[u]);
			}

			if(que3.size()==N-sum) {
				tmp=cou[que3.front()];
				ok=1;

				while(!que3.empty()) {
					if(tmp!=cou[que3.front()]) ok=0;
					que3.pop();
				}

				if(ok) ++ans;
			}

			while(!que2.empty()) {
				u=que2.front();
				que2.pop();
				que.push(u);
			}
			sum+=que.size();
		}

		printf("%d\n",ans);
	}

	return 0;
}
