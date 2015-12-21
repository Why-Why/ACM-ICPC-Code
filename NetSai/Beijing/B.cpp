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
// Created Time  : 2015年09月21日 星期一 16时32分27秒
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

const int MaxN=50004;

char s[MaxN];
char LEFT[MaxN],RIGHT[MaxN];
char COPY[MaxN];
int coucp;
int pl,pr;
int pcp;
int sta;
int M;

void chuli(char c)
{
	if(c>='a' && c<='z')
	{
		pcp=-1;
		if(!sta && pl+pr>=M) return;						// !!!
		if(sta && pr==0 && pl>=M) return;					// !!!
		LEFT[pl++]=c;
		if(sta && pr) --pr;				// if pr==0 how ?

		return;
	}

	switch(c)
	{
		case 'L':
			if(pl) RIGHT[pr++]=LEFT[--pl];
			break;
		case 'R':
			if(pr) LEFT[pl++]=RIGHT[--pr];
			break;
		case 'S':
			pcp=-1;
			sta=!sta;
			break;
		case 'D':
			if(pcp==-1)
			{ if(pr) --pr; }
			else						// The pre will process ?
			{
				if(pl>pcp) pl=pcp;
				else if(pl<pcp) pr-=(pcp-pl);
				pcp=-1;
			}
			break;
		case 'B':
			pcp=-1;
			if(pl) --pl;
			break;
		case 'C':
			if(pcp==-1)
				pcp=pl;
			else
			{
				coucp=0;
				if(pl>pcp) for(int i=pcp;i<pl;++i) COPY[coucp++]=LEFT[i];
				else if(pl<pcp) for(int i=pr-1,j=pl;j<pcp;--i,++j) COPY[coucp++]=RIGHT[i];
				pcp=-1;
			}
			break;
		case 'V':
			pcp=-1;
			if(!sta)
			{
				if(pl+pr+coucp>M) return;
				for(int i=0;i<coucp;++i)
					LEFT[pl++]=COPY[i];
			}
			else						/////
			{
				if(pl+coucp>M) return;
				for(int i=0;i<coucp;++i)
					LEFT[pl++]=COPY[i];
				pr-=coucp;
				if(pr<0) pr=0;
			}
			break;
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %s",&M,s);
		pl=pr=0;
		pcp=-1;
		sta=0;
		coucp=0;
		for(int i=0;s[i];++i)
			chuli(s[i]);
		for(int i=0;i<pl;++i)
			printf("%c",LEFT[i]);
		for(int i=pr-1;i>=0;--i)
			printf("%c",RIGHT[i]);
		if(pl+pr==0)
			printf("NOTHING");
		puts("");
	}
	
	return 0;
}
