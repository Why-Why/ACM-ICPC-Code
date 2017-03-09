#include<iostream>
#include<cstring>

using namespace std;

long long ans[300];

bool panduan(int a,int b)
{
	long long num=0;
	long long base=1;

	while(b)
	{
		if(b%2)
			num+=base;
		base*=10;
		b/=2;
	}

	if(num%a==0)
	{
		ans[a]=num;
		return 1;
	}

	return 0;
}

int main()
{
	int cou=0;
	for(int i=1;i<=200;i+=2)
		if(i%5)
		{
			for(int j=1;j<(1<<18);++j)
				if(panduan(i,j))
				{
					break;
				}
		}

	int k,rem;

	ios::sync_with_stdio(false);

	for(cin>>k;k;cin>>k)
	{
		rem=0;
		while(k%2==0)
		{
			k/=2;
			++rem;
		}
		while(k%5==0)
		{
			k/=5;
			++rem;
		}
		cout<<ans[k];
		for(int i=0;i<rem;++i)
			cout<<0;
		cout<<endl;
	}

	return 0;
}
