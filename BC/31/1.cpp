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

const int MaxN=100005;

int n,k;
int x[MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	long long ans;
	int p1,p2;
	cin>>T;

	while(T--)
	{
		scanf("%d %d",&n,&k);

		for(int i=0;i<n;++i)
			scanf("%d",&x[i]);

		sort(x,x+n);

		p1=ans=0;
		p2=1;

		while(p1<n)
		{
			while(p2<n && x[p2]-x[p1]<=k)
				++p2;
			ans+=(long long)(p2-p1-1);
			++p1;
		}

		cout<<ans<<endl;
	}

	return 0;
}
