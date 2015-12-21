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
// Created Time  : 2015年09月25日 星期五 18时37分38秒
// File Name     : D.cpp

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

const int MaxN=52;

int rem[MaxN][MaxN][5010];
int rvis[MaxN][MaxN][5010],flag=0;
int cou[MaxN][MaxN];
bool vis[MaxN][MaxN];
char s[MaxN];

void init()
{
	++flag;
	memset(cou,0,sizeof(cou));
	for(int i=0;i<MaxN;++i)
		for(int j=0;j<MaxN;++j)
			vis[i][j]=0;
}

inline int zhuan(char c)
{
	if(c=='I') return 1;
	if(c=='V') return 5;
	if(c=='X') return 10;
	if(c=='L') return 50;
	if(c=='C') return 100;
}

void getans(int L,int R)
{
	if(vis[L][R]) return;
	vis[L][R]=1;
	if(L==R)
	{
		rem[L][R][0]=zhuan(s[L]);
		cou[L][R]=1;
		return;
	}

	int t1,t2;

	for(int k=L;k<R;++k)
	{
		getans(L,k);
		getans(k+1,R);

		for(int i=0;i<cou[L][k];++i)
			for(int j=0;j<cou[k+1][R];++j)
			{
				t1=rem[L][k][i];
				t2=rem[k+1][R][j];

				if(t1>=t2)
				{
					if(rvis[L][R][t1+t2]<flag)
					{
						rem[L][R][cou[L][R]++]=t1+t2;
						rvis[L][R][t1+t2]=flag;
					}
				}
				else
				{
					if(rvis[L][R][t2-t1]<flag)
					{
						rem[L][R][cou[L][R]++]=t2-t1;
						rvis[L][R][t2-t1]=flag;
					}
				}
			}
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int cas=1;
	int len;

	while(~scanf("%s",s+1) && s[1]!='0')
	{
		init();
		len=strlen(s+1);
		getans(1,len);
		printf("Case %d:",cas++);
		sort(rem[1][len],rem[1][len]+cou[1][len]);
		for(int i=0;i<cou[1][len];++i)
			printf(" %d",rem[1][len][i]);
		puts("");
	}
	
	return 0;
}
