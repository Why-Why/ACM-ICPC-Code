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
// Created Time  : 2017年02月13日 星期一 19时09分40秒
// File Name     : I_1.cpp

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

const int MaxN=1000006;

int N,fa[MaxN];
int du[MaxN];

int stk[MaxN],top;
int rem[MaxN],rcou;

int vis[MaxN],flag;
vector <int> cou[MaxN];

typedef unsigned int U;

U hnum[MaxN];

inline U cal(int p) {
	int len=cou[p].size();
	sort(cou[p].begin(),cou[p].end());

	U base=1331,ret=0;

	for(int i=0;i<len;++i)
		ret=ret*base+cou[p][i];

	return ret;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int have;

	while(~scanf("%d",&N)) {
		for(int i=1;i<=N;++i) du[i]=0,cou[i].clear();
		for(int i=2;i<=N;++i) {
			scanf("%d",fa+i);
			++du[fa[i]];
		}

		int ans=0;

		top=0;
		for(int i=2;i<=N;++i)
			if(!du[i]) {
				stk[top++]=i;
				hnum[i]=1;
			}
		have=N-top;

		while(have) {
			rcou=0;
			++flag;
			for(int i=0;i<top;++i) {
				--du[fa[stk[i]]];

				if(vis[fa[stk[i]]]!=flag) {
					vis[fa[stk[i]]]=flag;
					rem[rcou++]=fa[stk[i]];

					//cou[fa[stk[i]]]=1;
					//cou[fa[stk[i]]].clear();
					//cou[fa[stk[i]]].push_back(hnum[stk[i]]);
				}

				cou[fa[stk[i]]].push_back(hnum[stk[i]]);
			}

			top=0;

			if(have==rcou) {
				bool ok=1;
				U tmp=cal(rem[0]);
				hnum[rem[0]]=tmp;

				for(int i=1;i<rcou;++i) {
					if((hnum[rem[i]]=cal(rem[i]))!=tmp) ok=0;
				}

				if(ok) {
					++ans;

					for(int i=0;i<rcou;++i)
						cou[rem[i]].clear();
				}
			}
			else {
				for(int i=0;i<rcou;++i)
					if(du[rem[i]]==0) hnum[rem[i]]=cal(rem[i]);
			}

			for(int i=0;i<rcou;++i)
				if(du[rem[i]]==0) stk[top++]=rem[i];

			/*
			for(int i=0;i<rcou;++i) {
				if(du[rem[i]]==0) stk[top++]=rem[i];
				if(have!=rcou || (i && cou[rem[i]]!=cou[rem[i-1]])) ok=0;
			}
			*/

			have-=top;
		}

		printf("%d\n",ans);
	}

	return 0;
}
