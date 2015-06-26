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

int n,m;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;
	int temp;
	int ans;

	while(~scanf("%d %d",&n,&m))
	{
		ans=10e8;

		for(int i=1;i<=m;++i)
		{
			scanf("%d %d",&a,&b);

			if(n%a==0)
				temp=n/a;
			else
				temp=n/a+1;

			ans=min(ans,temp*b);
		}

		printf("%d\n",ans);
	}
	
	return 0;
}
