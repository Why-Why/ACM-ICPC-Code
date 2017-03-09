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

const int MaxN=1000006;

char s[MaxN*2];
int Wa[MaxN],Wb[MaxN];
int len;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%s",s))
	{
		len=strlen(s);

		for(int i=0;i<len;++i)
			s[len+i]=s[i];
		s[len+len]=0;

	
	}
	
	return 0;
}
