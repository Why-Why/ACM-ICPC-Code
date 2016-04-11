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

int D,P;
priority_queue <int> que;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	int temp,ans,base;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&D);

		ans=1010;
		base=0;

		while(!que.empty())
			que.pop();

		for(int i=1;i<=D;++i)
		{
			scanf("%d",&P);
			que.push(P);
		}

		while(!que.empty())
		{
			temp=que.top();
			que.pop();

			ans=min(ans,base+temp);

			if(temp<=1)
				break;

			++base;
			que.push(temp/2);
			que.push(temp-temp/2);
		}

		printf("Case #%d: %d\n",cas++,ans);

		//cerr<<1<<endl;
	}
	
	return 0;
}
