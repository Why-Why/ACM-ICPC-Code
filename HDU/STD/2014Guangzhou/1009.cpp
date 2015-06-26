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

const double INF=10e8;
const int MaxN=300;
const int MaxM=20;
const int MaxNode=MaxN*MaxM;

double area[300];

struct DLX
{
	int U[MaxNode],D[MaxNode],L[MaxNode],R[MaxNode],col[MaxNode],row[MaxNode];
	int H[MaxN],S[MaxM];
	int size,n,m;
	double ansnum;

	void init(int _n,int _m)
	{
		n=_n;
		m=_m;
		size=m;
		ansnum=-1;

		for(int i=0;i<=m;++i)
		{
			L[i]=i-1;
			R[i]=i+1;
			U[i]=D[i]=i;
			S[i]=0;
		}
		R[m]=0;
		L[0]=m;

		for(int i=1;i<=n;++i)
			H[i]=-1;
	}

	void Link(int r,int c)
	{
		col[++size]=c;
		++S[c];
		row[size]=r;
		U[size]=U[c];
		D[size]=c;
		D[U[c]]=size;
		U[c]=size;

		if(H[r]==-1)
			H[r]=L[size]=R[size]=size;
		else
		{
			L[size]=L[H[r]];
			R[size]=H[r];
			R[L[H[r]]]=size;
			L[H[r]]=size;
		}
	}

	void remove(int c)
	{
		L[R[c]]=L[c];
		R[L[c]]=R[c];

		for(int i=D[c];i!=c;i=D[i])
			for(int j=R[i];j!=i;j=R[j])
			{
				U[D[j]]=U[j];
				D[U[j]]=D[j];
				--S[col[j]];
			}
	}

	void resume(int c)
	{
		for(int i=U[c];i!=c;i=U[i])
			for(int j=L[i];j!=i;j=L[j])
			{
				U[D[j]]=D[U[j]]=j;
				++S[col[j]];
			}

		L[R[c]]=R[L[c]]=c;
	}

	void Dance(int d,double rem)
	{
		if(rem>ansnum)
			ansnum=rem;

		int c=R[0];

		for(int i=R[0];i;i=R[i])
			if(S[i]<S[c])
				c=i;

		remove(c);

		for(int i=D[c];i!=c;i=D[i])
		{
			for(int j=R[i];j!=i;j=R[j])
				remove(col[j]);

			Dance(d+1,rem+area[row[i]]);

			for(int j=L[i];j!=i;j=L[j])
				resume(col[j]);
		}

		resume(c);
	}
};

DLX dlx;
int N;
int num[20];

double getarea(int x,int y,int z)
{
	if(x+y<=z || y+z<=x || z+x<=y)
		return 0.0;

	double p=(x+y+z)/2.0;

	return sqrt(p*(p-x)*(p-y)*(p-z));
}

void pre()
{
	int cou=0;

	for(int i=1;i<=N;++i)
		for(int j=i+1;j<=N;++j)
			for(int k=j+1;k<=N;++k)
			{
				++cou;
				area[cou]=getarea(num[i],num[j],num[k]);

				dlx.Link(cou,i);
				dlx.Link(cou,j);
				dlx.Link(cou,k);
			}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d",&N) && N)
	{
		for(int i=1;i<=N;++i)
			scanf("%d",&num[i]);

		dlx.init(N*(N-1)*(N-2)/6,N);
		pre();

		dlx.Dance(0,0);

		printf("%.2f\n",dlx.ansnum);
	}
	
	return 0;
}
