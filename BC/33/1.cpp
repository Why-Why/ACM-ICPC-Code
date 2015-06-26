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

char s[300];
int ans[300];

int change(char c)
{
	if(c<='9')
		return c-'0';

	return c-'a'+10;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int n,B;
	int len;

	while(~scanf("%d %d",&n,&B))
	{
		memset(ans,0,sizeof(ans));

		while(n--)
		{
			scanf("%s",s);

			len=strlen(s);

			for(int i=len-1;i>=0;--i)
			{
				ans[len-i-1]+=change(s[i]);
				ans[len-i-1]%=B;
			}
		}

		int i;
		for(i=200;i>0;--i)
			if(ans[i]!=0)
				break;

		for(int j=i;j>=0;--j)
			if(ans[j]<10)
				printf("%d",ans[j]);
			else
				printf("%c",ans[j]-10+'a');
		printf("\n");
	}
	
	return 0;
}
