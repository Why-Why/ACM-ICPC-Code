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

const double eps=1e-8;

int sgn(double x)
{
	if(fabs(x)<eps)
		return 0;

	if(x<0)
		return -1;

	return 1;
}

double X[3100],Y[3100];
int N;

int getans(int a,int b)
{
	int da=0,xiao=0;
	double A,B,C;

	A=Y[b]-Y[a];
	B=-X[b]+X[a];
	C=Y[a]*(X[b]-X[a])-X[a]*(Y[b]-Y[a]);

	for(int i=1;i<=N;++i)
		if(sgn(A*X[i]+B*Y[i]+C)>0)
			++da;
		else if(sgn(A*X[i]+B*Y[i]+C)<0)
			++xiao;

	return min(da,xiao);
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int T,cas=1;
	int ans;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&N);

		for(int i=1;i<=N;++i)
			scanf("%lf %lf",&X[i],&Y[i]);

		printf("Case #%d:\n",cas++);

		for(int i=1;i<=N;++i)
		{
			ans=100000;

			for(int j=1;j<=N;++j)
				if(i!=j)
					ans=min(ans,getans(i,j));

			if(N==1)
				ans=0;

			printf("%d\n",ans);
		}
	}
	
	return 0;
}
