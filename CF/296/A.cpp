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

long long ans=0;

void gcd(long long a,long long b)
{
	ans+=a/b;

	if(a%b==0)
		return;

	gcd(b,a%b);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	long long a,b;

	cin>>a>>b;

	gcd(max(a,b),min(a,b));

	cout<<ans<<endl;
	
	return 0;
}
