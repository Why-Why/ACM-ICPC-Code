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

int s,d;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int temp;
	long long sum;

	while(~scanf("%d %d",&s,&d))
	{
		temp=(5*d)/(s+d);

		if(temp*(s+d)==5*d)
			--temp;

		if(temp==4)
			sum=10LL*s-2LL*d;
		else if(temp==3)
			sum=8LL*s-4LL*d;
		else if(temp==2)
			sum=6LL*s-6LL*d;
		else if(temp==1)
			sum=3LL*s-9LL*d;
		else
			sum=-1;

		if(sum<0)
			printf("Deficit\n");
		else
			printf("%lld\n",sum);
	}
	
	return 0;
}
