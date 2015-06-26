#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int N,M;
long long num[100005];
long long sum;

bool getans(int mid)
{
	int cou=1;
	int sum1=0;

	for(int i=1;i<=N;++i)
	{
		if(num[i]>mid)
			return 0;

		if(sum1+num[i]>mid)
		{
			sum1=num[i];
			++cou;
		}
		else
			sum1+=num[i];
	}
	if(cou<=M)
		return 1;
	else
		return 0;
}

void solve()
{
	long long L=1,R=sum,Med;
	int temp;

	while(R>L+1)
	{
		Med=(L+R)/2;
		if(getans(Med))
			R=Med;
		else
			L=Med;
	}

	cout<<R<<endl;
}

int main()
{
	ios::sync_with_stdio(false);

	while(cin>>N>>M)
	{
		sum=0;

		for(int i=1;i<=N;++i)
		{
			cin>>num[i];
			sum+=num[i];
		}
		solve();
	}

	return 0;
}
