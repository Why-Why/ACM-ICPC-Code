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

int num[100005];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	int T;
	int n,k;
	long long ans;

	scanf("%d",&T);

	while(T--)
	{
		ans=0;
		scanf("%d %d",&n,&k);

		for(int i=0;i<n;++i)
			scanf("%d",&num[i]);

		sort(num,num+n);

		for(int i=0;i<k;++i)
			ans+=num[n-1-i];

		cout<<ans<<endl;
	}

	return 0;
}
