#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

short vis[2000000];
int base;
int a1,a2,a3,a4,a5;

bool find(int x)
{
	int L=0,R=cou-1,M;

	while(R>L)
	{
		M=(L+R)/2;

		if(vis[M]==x)
			return 1;

		if(vis[M]<x)
			L=M+1;
		else
			R=M-1;
	}

	if(vis[L]==x || vis[R]==x)
		return 1;
	else
		return 0;
}

void init()
{
	for(int i=-50;i<=50;++i)
		for(int j=-50;j<=50;++j)
			for(int k=-50;k<=50;++k)
			{
				if(i==0 || j==0 || k==0)
					continue;

				vis[cou++]=a1*i*i*i+a2*j*j*j+a3*k*k*k;
			}
//	for(int i=0;i<=50;++i)
//		for(int j=0;j<=50;++j)
//			for(int k=0;k<=50;++k)
//				vis[cou++]=a1*i*i*i+a2*j*j*j+a3*k*k*k;

}

int main()
{
	ios::sync_with_stdio(false);

	long long ans;

	while(cin>>a1>>a2>>a3>>a4>>a5)
	{
		ans=0;
		cou=0;

		init();

		for(int i=-50;i<=50;++i)
			for(int j=-50;j<=50;++j)
			{	
				if(i==0 || j==0)
					continue;
				if(find(-a4*i*i*i-a5*j*j*j))
					++ans;
			}

//		for(int i=0;i<=50;++i)
//			for(int j=0;j<=50;++j)
//				if(find(-a4*i*i*i-a5*j*j*j))
//					++ans;

		cout<<ans<<endl;
	}

	return 0;
}
