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

char s[20][300];

void chuli(int x)
{
	int cou[10]={0};
	char ts[100];

	for(int i=0;s[x-1][i];++i)
		++cou[s[x-1][i]-'0'];

	for(int i=0;i<=9;++i)
		if(cou[i])
		{
			int j;
			for(j=0;s[x][j];++j);

			sprintf(s[x]+j,"%d%d",cou[i],i);
		}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%s",s[0]) && s[0][0]!='-')
	{
		for(int i=1;i<=15;++i)
			s[i][0]=0;

		for(int i=1;i<=15;++i)
			chuli(i);

		for(int k=0;k<=15;++k)
		for(int i=k+1;i<=15;++i)
			if(strcmp(s[k],s[i])==0)
			{
				if(i==1)
					printf("%s is self-inventorying \n",s[0]);
				else if(i-k!=1)
					printf("%s enters an inventory loop of length %d \n",s[0],i-k);
				else
					printf("%s is self-inventorying after %d steps \n",s[0],i-1);

				goto end;
			}

		printf("%s can not be classified after 15 iterations\n",s[0]);

end:;
	}
	
	return 0;
}
