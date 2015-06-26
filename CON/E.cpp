#include<iostream>
#include<cstring>

using namespace std;

int N;
long long num[1010];
long long ans[1010];

void solve()
{
	long long maxn=-(1LL<<50);

	for(int i=1;i<=N;++i)
	{
		for(int j=1;j<i;++j)
		{
			if(num[j]<num[i]&&ans[j]+num[i]>ans[i])
				ans[i]=ans[j]+num[i];
		}

		if(ans[i]>maxn)
			maxn=ans[i];
	}	

	cout<<maxn<<endl;
}

int main()
{
	ios::sync_with_stdio(false);

	for(cin>>N;N;cin>>N)
	{
		for(int i=1;i<=N;++i)
		{
			cin>>num[i];
			ans[i]=num[i];
		}

		solve();
	}

	return 0;
}
