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

char s[2000];
int num;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int T,cas=1;
	int ans,sum;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&num);
		scanf("%s",s);

		ans=sum=0;

		for(int i=0;i<=num;++i)
		{
			if(sum<i)
			{
				ans+=i-sum;
				sum+=i-sum;
			}

			sum+=s[i]-'0';
		}

		printf("Case #%d: %d\n",cas++,ans);
	}
	
	return 0;
}
