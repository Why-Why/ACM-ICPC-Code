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

const int mod=1000000000+7;

char s[100005];
long long ans;

void getans(int cou,int n)
{
	ans=1;

	for(int i=1;i<=n;++i)
		ans=(ans*cou)%mod;

	cout<<ans<<endl;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int n;
	int rem[5]={0};

	cin>>n>>s;

	for(int i=0;i<n;++i)
		switch(s[i])
		{
			case 'A':
				++rem[1];
				break;
			case 'C':
				++rem[2];
				break;
			case 'G':
				++rem[3];
				break;
			case 'T':
				++rem[4];
		}

	int maxn=-1;

	for(int i=1;i<=4;++i)
		if(rem[i]>maxn)
			maxn=rem[i];

	
	int cou=0;
	for(int i=1;i<=4;++i)
		if(rem[i]==maxn)
			++cou;

	getans(cou,n);

	return 0;
}
