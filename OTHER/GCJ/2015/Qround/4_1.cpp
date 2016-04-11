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

		if((R*C)%X==0 && max(R,C)>=X && min(R,C)>=(X+1)/2)
			ok=1;

		if(X%4==0 && min(R,C)<(X+1)/2+1)
			ok=0;

		printf("Case #%d: ",cas++);

		if(ok)
			printf("GABRIEL\n");
		else
			printf("RICHARD\n");
	}
	
	return 0;
}
