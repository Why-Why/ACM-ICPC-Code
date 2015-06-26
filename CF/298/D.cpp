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

int n;
vector <int> a[300000];
int p[300000];
int ans[300000];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int temp;

	scanf("%d",&n);

	for(int i=1;i<=n;++i)
	{
		scanf("%d",&temp);

		a[temp].push_back(i);
	}

	int cou=0;
	int w=0;
	int acou=0;

	while(1)
	{
		if(a[w].size()-p[w]==0)
		{
			w-=3;

			while(a[w].size()-p[w]==0 && w>=0)
				w-=3;

			if(w<0)
				break;
		}

		ans[cou++]=a[w][p[w]++];

		if(cou==n)
			break;

		++w;
	}

	if(cou!=n)
	{
		printf("Impossible\n");
	}
	else
	{
		printf("Possible\n");

		for(int i=0;i<cou;++i)
			printf("%d ",ans[i]);
		printf("\n");
	}
	
	return 0;
}
