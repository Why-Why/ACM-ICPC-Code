#include<iostream>
#include<cstring>

using namespace std;

double DP[10004];
int sum;
double P;
double numP[104];
int M[104];
int N;

void solve()
{
	for(int j=1;j<=sum;++j)
		DP[j]=100;
	DP[0]=0;

	for(int i=1;i<=N;++i)
		for(int j=sum;j>=M[i];--j)
			DP[j]=min(DP[j],1.0-(1.0-numP[i])*(1.0-DP[j-M[i]]));

	for(int i=sum;i>=0;--i)
		if(DP[i]<P)
		{
			cout<<i<<endl;
			return;
		}
}

int main()
{
	ios::sync_with_stdio(false);

	int T;
	cin>>T;

	while(T--)
	{
		cin>>P>>N;
		sum=0;

		for(int i=1;i<=N;++i)
		{
			cin>>M[i]>>numP[i];
			sum+=M[i];
		}

		solve();
	}

	return 0;
}
