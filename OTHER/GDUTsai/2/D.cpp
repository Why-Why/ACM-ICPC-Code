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

long long gcd(long long a,long long b)
{
	if(a==0)
		return b;

	return gcd(b%a,a);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	int T;
	long long N,M,D;
	long long ans;
	long long L;

	cin>>T;

	while(T--)
	{
		ans=0;

		cin>>N>>M;
		D=M/N;

		if(N>M || M%N)
			ans=0;
		else
		{
			for(long long i=1;i*i<=D;++i)
			{
				if(D%i==0)
					if(gcd(i,D/i)==1)
						++ans;
			}
		}

		cout<<ans<<endl;
	}

	return 0;
}
