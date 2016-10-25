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
// Created Time  : 2016年05月22日 星期日 14时56分18秒
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

const int MaxN=100005;

int num[MaxN];
int N;

long long ans[MaxN];

inline void getans(int id) {
	long long minn=num[id],maxn=0;
	int tt1=0,tt2=0;

	for(int i=id;i<=N && num[i]>=num[id];++i) {
		maxn=max(maxn,(long long)num[i]);
		for(int j=id;j>=1 && num[j]>=num[id];--j) {
			maxn=max(maxn,(long long)num[j]);
			ans[i-j+1]=max(ans[i-j+1],maxn*minn);
			tt2=id-j+1;
		}

		tt1=i-id+1;
	}
	cerr<<tt1*tt2<<endl;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d",&N)) {
		for(int i=1;i<=N;++i) scanf("%d",num+i),ans[i]=0;
		for(int i=1;i<=N;++i) getans(i);
		for(int i=1;i<=N;++i) printf("%I64d\n",ans[i]);
	}
	
	return 0;
}
