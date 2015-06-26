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

int ans[200];

void change(int x)
{
	int cou=0;

	while(x)
	{
		ans[cou++]=x%26;

		if(ans[cou-1]==0)
			ans[cou-1]=26;
		
		if(x%26)
			x=x/26;
		else
			x=x/26-1;
	}

	for(int i=cou-1;i>=0;--i)
		printf("%c",'A'+ans[i]-1);
	printf("\n");
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	int T,n;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d",&n);
		change(n);
	}

	return 0;
}
