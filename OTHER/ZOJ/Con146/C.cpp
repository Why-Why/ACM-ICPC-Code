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
// Created Time  : 2016年04月23日 星期六 15时38分48秒
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

int rem[7][7];
int ans1[7],ans2[7];

inline int find(int p,int x) {
	for(int i=1;i<=4;++i)
		if(rem[p][i]==x) return i;
}

void getans(int p,int d) {
	if(p==1) {
		if(d==1 || d==2) ans1[p]=2,ans2[p]=rem[p][2];
		else if(d==3) ans1[p]=3,ans2[p]=rem[p][3];
		else ans1[p]=4,ans2[p]=rem[p][4];
	}
	else if(p==2) {
		if(d==1) ans1[p]=find(p,4),ans2[p]=4;
		else if(d==2 || d==4) ans1[p]=ans1[p-1],ans2[p]=rem[p][ans1[p]];
		else if(d==3) ans1[p]=1,ans2[p]=rem[p][1];
	}
	else if(p==3) {
		if(d==1) ans1[p]=find(p,ans2[p-1]),ans2[p]=ans2[p-1];
		else if(d==2) ans1[p]=find(p,ans2[p-2]),ans2[p]=ans2[p-2];
		else if(d==3) ans1[p]=3,ans2[p]=rem[p][3];
		else ans1[p]=find(p,4),ans2[p]=4;
	}
	else if(p==4) {
		if(d==1) ans1[p]=ans1[p-3],ans2[p]=rem[p][ans1[p]];
		else if(d==2) ans1[p]=1,ans2[p]=rem[p][1];
		else ans1[p]=ans1[p-2],ans2[p]=rem[p][ans1[p]];
	}
	else {
		if(d==1 || d==2) {
			ans1[p]=find(p,ans2[d]);
			ans2[p]=ans2[d];
		}
		else if(d==3) ans1[p]=find(p,ans2[4]),ans2[p]=ans2[4];
		else ans1[p]=find(p,ans2[3]),ans2[p]=ans2[3];
	}

	printf("%d %d\n",ans1[p],ans2[p]);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	scanf("%d",&T);

	while(T--) {
		for(int i=1;i<=5;++i) {
			for(int j=0;j<5;++j)
				scanf("%d",&rem[i][j]);
			getans(i,rem[i][0]);
		}
	}
	
	return 0;
}
