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
// Created Time  : 2016年04月08日 星期五 23时53分06秒
// File Name     : C.cpp

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

const int MaxN=300005;

int N,K;
int num[MaxN];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int L=1,sum=0;
	int ans=0;
	int remL=0,remR=0;

	scanf("%d %d",&N,&K);
	for(int i=1;i<=N;++i) {
		scanf("%d",num+i);
		if(!num[i]) ++sum;
		while(sum>K) if(num[L++]==0) --sum;
		if(ans<i-L+1) {
			ans=i-L+1; remL=L,remR=i;
		}
	}

	printf("%d\n",ans);
	for(int i=1;i<=N;++i)
		if(i>=remL && i<=remR) printf("1 ");
		else printf("%d ",num[i]);
	puts("");
	
	return 0;
}
