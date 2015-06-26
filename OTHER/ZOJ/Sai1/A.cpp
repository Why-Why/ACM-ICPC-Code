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
int num[200];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&n);

		for(int i=1;i<=n;++i)
			scanf("%d",&num[i]);

		sort(num+1,num+n+1);

		if(num[1]!=num[2])
		{
			printf("%d\n",num[1]);
			continue;
		}

		printf("%d\n",num[n]);
	}
	
	return 0;
}
