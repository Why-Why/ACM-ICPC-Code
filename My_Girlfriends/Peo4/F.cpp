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
// Created Time  : 2015年11月29日 星期日 13时56分53秒
// File Name     : F.cpp

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

char map1[45][45];
int rem[45][45],flag=0;
int n,m;
int ans;

int que[200005];
int first,last;

const int step[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

inline bool judge(int x,int y) {
	return x>0 && y>0 && x<=n && y<=m;
}

void getans(int x,int y) {
	++flag;
	first=last=0;

	int tx,ty,ux,uy,temp,td=0;
	int ud;
	int ttt=0;

	que[last++]=x*100+y;
	rem[x][y]=flag;
	while(last-first) {
		temp=que[first++];
		td=temp/10000;
		temp-=td*10000;
		tx=temp/100;
		ty=temp-tx*100;

		ttt=max(ttt,td);

		if(ttt>=ans) return;

		for(int i=0;i<4;++i) {
			ux=tx+step[i][0];
			uy=ty+step[i][1];
			if(judge(ux,uy) && rem[ux][uy]!=flag) {
				rem[ux][uy]=flag;
				if(map1[ux][uy]!=map1[tx][ty]) ud=td+1;
				else ud=td;
				que[last++]=ux*100+uy+ud*10000;
			}
		}
	}

	ans=min(ans,ttt);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;++i) scanf("%s",map1[i]+1);

		ans=0x3f3f3f3f;
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
				getans(i,j);
		printf("%d\n",ans);
	}
	
	return 0;
}
