#include<iostream>
#include<cstdio>

using namespace std;

double F[100005][7];
int C[7][7];

double getans(int x,int b,int i)
{
	double ans=1;
	double base1=1,base2=1;

	for(int k=1;k<=b;++k)
		if(k<=b-i)
			ans*=(double)(x-1)/x;
		else
			ans/=(double)x;
	
	return ans;
}

int main()
{
	for(int i=0;i<=5;++i)
		C[i][0]=1;

	for(int i=1;i<=5;++i)
		for(int j=1;j<=i;++j)
			C[i][j]=C[i-1][j]+C[i-1][j-1];

	for(int x=1;x<=100000;++x)
		for(int b=1;b<=5;++b)
		{
			F[x][b]+=F[x-1][b]*getans(x,b,0);
			for(int i=1;i<=b;++i)
				F[x][b]+=((double)C[b][i]*(x+F[x-1][b-i])*getans(x,b,i));
		}
	
	int T;
	int x,b;
	cin>>T;

	for(int cas=1;cas<=T;++cas)
	{
		scanf("%d %d",&x,&b);

		printf("Case #%d: %.3f\n",cas,F[x][b]);
	}

	return 0;
}
