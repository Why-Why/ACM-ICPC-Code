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
// Created Time  : 2015年12月10日 星期四 00时18分57秒
// File Name     : B.cpp

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

char s[100005];
int X,Y;
bool vis[555][555]={};

void next(int &x,int &y,char c) {
	int nx=x,ny=y;
	if(c=='L') --ny;
	else if(c=='R') ++ny;
	else if(c=='U') --nx;
	else ++nx;
	if(nx>=1 && nx<=X && ny>=1 && ny<=Y) x=nx,y=ny;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int x0,y0;

	scanf("%d %d %d %d",&X,&Y,&x0,&y0);
	scanf("%s",s);
	int cou=0;

	printf("1");
	++cou;
	vis[x0][y0]=1;
	for(int i=1;s[i];++i) {
		next(x0,y0,s[i-1]);
		if(vis[x0][y0]) printf(" 0");
		else printf(" 1"),vis[x0][y0]=1,++cou;
	}
	printf(" %d\n",X*Y-cou);
	
	return 0;
}
