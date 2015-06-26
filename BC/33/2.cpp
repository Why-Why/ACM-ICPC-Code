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

long long n,mod;

void getans()
{
	long long ans=1,base=2;

	while(n)
	{
		if(n%2)
			ans=(ans*base)%mod;
		base*=base;
		base%=mod;
		n/=2;
	}

	ans-=2;
	ans%=mod;

	if(ans<0)
		ans+=mod;

	cout<<ans<<endl;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	ios::sync_with_stdio(false);

	while(cin>>n>>mod)
	{
		if(n==1)
			cout<<1%mod<<endl;
		else
			getans();
	}
	
	return 0;
}
