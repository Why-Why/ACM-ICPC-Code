#include<iostream>
#include<cstring>

using namespace std;

int getans(int n)
{
	int base=1;

	for(int i=1;i<=n;++i)
		base=(base*i)%2009;

	return base;
}

int main()
{
	ios::sync_with_stdio(false);

	int N;

	while(cin>>N)
	{
		if(N>=41)
			cout<<0<<endl;
		else
			cout<<getans(N)<<endl;
	}

	return 0;
}
