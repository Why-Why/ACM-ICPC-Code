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

const int MaxM=1000006;

int next1[MaxM];

void KMP_pre(int m,char s[])
{
	int i=0,j=-1;

	next1[0]=-1;

	while(i<m)
	{
		while(j!=-1 && s[i]!=s[j])
			j=next1[j];

		++i;
		++j;

		next1[i]=j;
	}
}

char s[MaxM];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int m;
	int cas=1;

	while(~scanf("%d",&m) && m)
	{
		scanf("%s",s);

		KMP_pre(m,s);

		printf("Test case #%d\n",cas++);

		for(int i=1;i<=m;++i)
			if(next1[i]*2>=i && i%(i-next1[i])==0)
				printf("%d %d\n",i,i/(i-next1[i]));

		printf("\n");
	}
	
	return 0;
}
