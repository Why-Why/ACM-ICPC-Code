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

struct state
{
	int id,val;

	bool operator < (const state &b) const
	{
		return val<b.val;
	}
};

state sta[110];
int n,m;
char s[110][60];

int getval(char s[])
{
	int ret=0;

	for(int i=0;i<m;++i)
		for(int j=i+1;j<m;++j)
			if(s[j]<s[i])
				++ret;

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d %d",&m,&n))
	{
		for(int i=1;i<=n;++i)
		{
			scanf("%s",s[i]);
			sta[i].id=i;
			sta[i].val=getval(s[i]);
		}

		sort(sta+1,sta+n+1);

		for(int i=1;i<=n;++i)
			printf("%s\n",s[sta[i].id]);
	}
	
	return 0;
}
