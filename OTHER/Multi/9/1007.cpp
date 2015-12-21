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
// Created Time  : 2015年08月18日 星期二 15时17分54秒
// File Name     : 1007.cpp

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

const int MaxN=110;
const int INF=0x3f3f3f3f;

int N,M;
int map1[MaxN][MaxN];
int dp[MaxN][MaxN];
int rem[MaxN][MaxN];
int sum[MaxN][MaxN];

int zong[MaxN][MaxN][MaxN];
int rzong[MaxN][MaxN][MaxN];

void init()
{
	int t1,t2,t3;
	int m1,m2,m3,m,rm1,rm2;
	int S;
	int ttt;

	for(int i=2;i<=N;++i)
	{
		S=sum[i-1][M]+sum[i][M];

		for(int j=1;j<=M;++j)
		{
			ttt=1;
			m1=sum[i-1][M]-sum[i-1][j]+sum[i][M]-sum[i][j-1];
			m3=INF;
			for(int k=j-1;k>=1;--k)
			{
				m2=sum[i-1][k]+sum[i][k-1];
				if((j-k)&1)
				{
					m=min(m1,min(m2,m3));
					zong[i][j][k]=S-m;
					if(m==m1) rzong[i][j][k]=-1;
					else if(m==m2) rzong[i][j][k]=-2;
					else rzong[i][j][k]=rm2;

					if(m3>map1[i-ttt][k])
					{
						m3=map1[i-ttt][k];
						rm2=k;
						rm1=i-ttt;
					}
					ttt=1-ttt;
				}
				else
					zong[i][j][k]=S;
			}

			ttt=1;
			m2=sum[i-1][j-1]+sum[i][j];
			m3=INF;
			for(int k=j+1;k<=M;++k)
			{
				m1=sum[i-1][M]-sum[i-1][k-1]+sum[i][M]-sum[i][k];
				if((k-j)&1)
				{
					m=min(m1,min(m2,m3));
					zong[i][j][k]=S-m;
					if(m==m1) rzong[i][j][k]=-1;
					else if(m==m2) rzong[i][j][k]=-2;
					else rzong[i][j][k]=rm2;;

					if(m3>map1[i-ttt][k])
					{
						m3=map1[i-ttt][k];
						rm1=i-ttt;
						rm2=k;
					}
					ttt=1-ttt;
				}
				else zong[i][j][k]=S;
			}

			m1=sum[i-1][M]-sum[i-1][j-1]+sum[i][M]-sum[i][j-1];
			m2=sum[i-1][j]+sum[i][j];
			zong[i][j][j]=max(m1,m2);
			if(m1>m2) rzong[i][j][j]=2;
			else rzong[i][j][j]=1;
		}
	}
}

inline int getsum(int hang,int l1,int l2)
{
	if(l1>l2)
		swap(l1,l2);

	return sum[hang][l2]-sum[hang][l1-1];
}

int ans[MaxN*MaxN];
int anscou;

void zhao(int hang,int l1,int l2)
{
	if((l2-l1)&1)
	{
		if(l2>l1)
		{
			if(rzong[hang][l1][l2]==-1)
			{
				for(int i=1;i<l1;++i)
					ans[anscou++]='L';
				ans[anscou++]='D';
				for(int i=1;i<=l1;++i)
					ans[anscou++]='R';
				char c='U';
				for(int i=1;i<l2-l1;++i)
				{
					ans[anscou++]=c;
					ans[anscou++]='R';
					if(c=='U') c='D';
					else c='U';
				}
				ans[anscou++]='D';
			}
			else if(rzong[hang][]l1][l2]==-2)
			{
				char c='D';
				for(int i=1;i<=l2-l1;++i)
				{
					ans[anscou++]=c;
					ans[anscou++]='R';
					if(c=='U') c='D';
					else c='U';
				}
				for(int i=l2;i<M;++i)
					ans[anscou++]='R';
				ans[anscou++]='D';
				for(int i=l2;i<M;++i)
					ans[anscou++]='L';
			}
			else
			{
				for(int i=1;i<l1;++i)
					ans[anscou++]='L';
				ans[anscou++]='D';
				for(int i=1;i<=l1;++i)
					ans[anscou++]='R';

				char c='U';
				for(int i=1;i<l2-l1;++i)
				{
					if(rzong[hang][l1][l2]!=l1+i)
					{
						ans[anscou++]=c;
						if(c=='U') c='D';
						else c='U';
					}

					ans[anscou++]='R';
				}

				for(int i=l2;i<M;++i)
					ans[anscou++]='R';
				ans[anscou++]='D';
				for(int i=l2;i<M;++i)
					ans[anscou++]='L';
			}
		}
	}
}

void show()
{
	anscou=0;
	int p2=M;
	int t1,t2;
	char c;

	for(int i=N;i>=1;)
	{
		t1=p2;
		t2=rem[i][p2];

		if(t2<0)
		{
			zhao(i,-t2,t1);
			ans[anscou++]=-t2;

			p2=-t2;
			i-=2;
		}
		else
		{
			if(t1>t2) swap(t1,t2),c='R';
			else c='L';

			for(int j=t1;j<t2;++j)
				ans[anscou++]=c;
			ans[anscou++]='D';

			p2=rem[i][p2];

			--i;
		}
	}

	for(int i=anscou-2;i>=0;--i)
		printf("%c",ans[i]);
	puts("");
}

inline int getzong(int hang,int l1,int l2)
{
	return zong[hang][l1][l2];
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int t,t1,a;

	while(~scanf("%d %d",&N,&M))
	{
		for(int i=1;i<=N;++i)
		{
			sum[i][0]=0;
			for(int j=1;j<=M;++j)
				scanf("%d",&map1[i][j]),sum[i][j]=sum[i][j-1]+map1[i][j],dp[i][j]=-1;
		}

		init();


		for(int i=1;i<=M;++i)
			dp[1][i]=dp[1][i-1]+map1[1][i],rem[1][i]=1;
		for(int i=1;i<=M;++i)
		{
			dp[2][i]=zong[2][1][i];
			rem[2][i]=-1;
		}
		for(int i=3;i<=N;++i)
			for(int j=1;j<=M;++j)
			{
				for(int k=1;k<=M;++k)
				{
					t=dp[i-1][k]+getsum(i,j,k);
					t1=dp[i-2][k]+getzong(i,k,j);

			//		cout<<dp[i-2][k]<<' '<<zong[i][k][j]<<endl;

					if(t>=t1) a=k;
					else a=-k,t=t1;

					if(t>dp[i][j])
					{
						dp[i][j]=t;
						rem[i][j]=a;
					}
				}
			}

//		for(int i=1;i<=N;++i,cout<<endl)
//			for(int j=1;j<=M;++j)
//				cout<<dp[i][j]<<' ';

		printf("%d\n",dp[N][M]);
		show();
	}
	
	return 0;
}
