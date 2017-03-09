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
// Created Time  : 2017年01月08日 星期日 17时18分40秒
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

const int MaxN=105;

int N;
int num[MaxN];
int dp[MaxN];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int ans=0;

	scanf("%d",&N);
	for(int i=1;i<=N;++i) {
		scanf("%d",num+i);
		if(num[i]) ++ans;
	}

	if(ans==0) puts("NO");
	else {
		puts("YES");
		printf("%d\n",ans);

		int last=1,t=0;
		for(int i=1;i<=N;++i)
			if(num[i]) {
				++t;

				if(t==ans) printf("%d %d\n",last,N);
				else printf("%d %d\n",last,i);
				last=i+1;
			}
	}

	return 0;
}
