#include<iostream>
#include<cstring>

using namespace std;

int d[50004][20];
int D[50004][20];
int n;
int A[50004];

void init()
{
	int a;

	for(int i=1;i<=n;++i)
	{
		cin>>a;
		d[i][0]=D[i][0]=a;
	}

	for(int j=1;(1<<j)<=n;++j)
		for(int i=1;i+(1<<j)-1<=n;++i)
		{
			d[i][j]=min(d[i][j-1],d[i+(1<<(j-1))][j-1]);
			D[i][j]=max(D[i][j-1],D[i+(1<<(j-1))][j-1]);
		}
}

int RMQ(int L,int R)
{
	int k=0;

	while((1<<(k+1))<=R-L+1) ++k;

	return max(D[L][k],D[R-(1<<k)+1][k])-min(d[L][k],d[R-(1<<k)+1][k]);
}

int main()
{
	ios::sync_with_stdio(false);

	int q;
	int a,b;

	cin>>n>>q;
	{
		init();

		for(int i=1;i<=q;++i)
		{
			cin>>a>>b;

			cout<<RMQ(a,b)<<endl;
		}
	}

	return 0;
}
