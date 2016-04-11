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

int X,R,C;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int T,cas=1;
	bool ok;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d %d",&X,&R,&C);

		ok=0;

		if(X==1)
			ok=1;

		if(X==2)
			if((R*C)%2==0)
				ok=1;

		if(X==3)
			if(R>=2 && C>=2 && (R*C)%3==0)
				ok=1;

		if(X==4)
			if(R*C==12 || R*C==16)
				ok=1;

		printf("Case #%d: ",cas++);

		if(ok)
			printf("GABRIEL\n");
		else
			printf("RICHARD\n");
	}
	
	return 0;
}
