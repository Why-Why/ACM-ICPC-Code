#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>

using namespace std;

const int MaxN=110;
const long double eps=10e-8;
const int INF=10e8;

long double Matrix[MaxN][MaxN];

inline bool zero(long double x)
{
	return ((x<0 ? -x :x)<eps);
}

long double getDet(long double mat[][MaxN],int n)
{
	int sign=0;
	long double ret=1;

	for(int i=1;i<=n;++i)
	{
		if(zero(mat[i][i]))
		{
			int j;
			for(j=i+1;j<=n;++j)
				if(!zero(mat[j][i]))
					break;

			if(j>n)
				return 0;

			for(int k=1;k<=n;++k)
				swap(mat[i][k],mat[j][k]);
			++sign;
		}

		ret*=mat[i][i];

		for(int j=i+1;j<=n;++j)
			mat[i][j]/=mat[i][i];

		for(int j=i+1;j<=n;++j)
			for(int k=i+1;k<=n;++k)
				mat[j][k]-=mat[j][i]*mat[i][k];
	}

	if(sign & 1)
		return -ret;
	return ret;
}

long double getCouST(int cost[][MaxN],int n)
{
	int cou;

	for(int i=1;i<=n;++i)
	{
		cou=0;

		for(int j=1;j<=n;++j)
			if(i!=j)
			{
				Matrix[i][j]=(cost[i][j] ? -1 : 0);
				cou-=Matrix[i][j];
			}
		Matrix[i][i]=cou;
	}

	return getDet(Matrix,n-1);
}

int map1[MaxN][MaxN];

int main()
{
	int n,m,k;
	int a,b;

	while(~scanf("%d %d %d",&n,&m,&k))
	{
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				map1[i][j]=1;

		for(int i=1;i<=m;++i)
		{
			scanf("%d %d",&a,&b);

			map1[a][b]=map1[b][a]=0;
		}

		printf("%.0Lf\n",getCouST(map1,n));
	}

	return 0;
}
