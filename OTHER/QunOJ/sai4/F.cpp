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

char s[200];
int len;

bool judge(int x,int L)
{
	char s1[200],s2[200];

	for(int i=0;i<L;++i)
	{
		s1[i]=s[x+i];
		s2[L-1-i]=s[x+i];
	}

	s1[L]=0;
	s2[L]=0;

	if(strstr(s,s1) && strstr(s,s2))
		return 1;

	return 0;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%s",s);
		len=strlen(s);

		for(int i=len;i>=1;--i)
			for(int j=0;j+i-1<len;++j)
				if(judge(j,i))
				{
					for(int k=0;k<i;++k)
						printf("%c",s[j+k]);
					printf("\n");
					goto end1;
				}
end1:;
	}
	
	return 0;
}
