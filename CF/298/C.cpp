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

long long s,A;
int d[1000000];
int n;

inline long long max1(long long a,long long b)
{
	if(a>b)
		return a;

	return b;
}

inline long long min1(long long a,long long b)
{
	if(a<b)
		return a;

	return b;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	ios::sync_with_stdio(false);

	cin>>n>>A;

	long long temp1,temp2;

	s=0;

	for(int i=1;i<=n;++i)
	{
		cin>>d[i];
		s+=(long long)d[i];
	}

	for(int i=1;i<=n;++i)
	{
		temp1=max1(1,A-(s-d[i]));
		temp2=min1(d[i],A-(n-1));

		if(temp2>=temp1)
			cout<<d[i]-(temp2-temp1+1)<<' ';
		else
			cout<<d[i]<<' ';
	}

	cout<<endl;
	
	return 0;
}
