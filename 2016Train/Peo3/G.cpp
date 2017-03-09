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
// Created Time  : 2016年03月05日 星期六 14时24分44秒
// File Name     : G.cpp

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

char s[111][55];
int cou;
int S[3];
char ans[3][55];
int sum;

typedef pair<int,int> pii;
pii rem[111];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	scanf("%d",&T);

	while(T--) {
		scanf("%d %d %d",S,S+1,S+2);
		sum=0;
		for(int k=0;k<3;++k) {
			for(int i=0;i<S[k];++i) {
				scanf("%s %d",s[i],&rem[i].first);
				rem[i].second=i;
			}
			sort(rem,rem+S[k]);
			sum+=rem[S[k]/2].first;
			strcpy(ans[k],s[rem[S[k]/2].second]);
		}

		printf("%d",sum);
		for(int i=0;i<3;++i) printf(" %s",ans[i]);
		puts("");
	}
	
	return 0;
}
