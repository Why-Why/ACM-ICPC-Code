#include<iostream>
#include<cstring>

using namespace std;

bool vis[1000006];
long long ans[1000006];
int prime[100000];
int Gcd[1000006];
int rem[10000];
int cou=0;

void getprime()
{
	for(int i=2;i<=1000000;++i)
		if(vis[i]==0)
		{
			prime[cou++]=i;
			for(int j=i*2;j<=1000000;j+=i)
				vis[j]=1;
		}
}

void getGCD()
{
	long long temp;
	long long sum=0;

	for(int i=3;i<=1000000;++i)
	{
		int ccou=0;

		if(vis[i]==0)
			temp=i;
		else
		{
			for(int j=0;prime[j]<=i;++j)
				if(i%prime[j]==0)
				{
					temp=Gcd[i/prime[j]];
					break;
				}
		}

		Gcd[i]=temp;
	}
	
}

void getANS()
{
	long long sum=0;

	for(int i=3;i<=1000000;++i)
	{
		sum+=Gcd[i];
		ans[i]=sum;
	}
}

int main()
{
	getprime();
	getGCD();
	getANS();
	
	int n;

	ios::sync_with_stdio(false);

	while(cin>>n)
		cout<<ans[n]<<endl;

	return 0;
}
