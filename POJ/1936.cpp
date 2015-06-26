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

const int MaxN=100005;

char s[MaxN],t[MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int p;
	bool ok;

	while(~scanf("%s %s",s,t))
	{
		p=0;
		ok=0;

		for(int i=0;t[i];++i)
			if(t[i]==s[p])
			{
				++p;

				if(!s[p])
				{
					ok=1;
					break;
				}
			}

		if(ok)
			puts("Yes");
		else
			puts("No");
	}
	
	return 0;
}
