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
// Created Time  : 2016年03月17日 星期四 20时49分16秒
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

int ans[111][111];
int a,b,N;

void update(int a,int b,int begin,int flag) {
	int p=begin;

	for(int i=1;i<=a;++i)
		for(int j=(i-flag)%2+1;j<=b;j+=2) {
			if(p>N) return;
			ans[i][j]=p;
			p+=2;
			if(p>N) return;
		}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int c1,c2,h1,h2;
	scanf("%d %d %d",&N,&a,&b);

	c1=(a*b+1)>>1;
	c2=a*b-c1;
	h1=(N+1)>>1;
	h2=N-h1;

	if(c1>=h1 && c2>=h2) {
		update(a,b,1,1);
		update(a,b,2,0);
	}
	else {
		swap(c1,c2);
		if(c1>=h1 && c2>=h2) {
			update(a,b,2,1);
			update(a,b,1,0);
		}
		else {
			puts("-1");
			return 0;
		}
	}

	for(int i=1;i<=a;++i,puts(""))
		for(int j=1;j<=b;++j)
			printf("%d ",ans[i][j]);
	
	return 0;
}
