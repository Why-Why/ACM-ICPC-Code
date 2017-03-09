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

const int MaxM = 200005;

void EKMP_pre(int m, char s[], int next[])
{
int p = 0, a = 1, L;
next[0] = m;
while (p + 1<m && s[p] == s[p + 1]) ++p;
next[1] = p;
for (int k = 2; k<m; ++k)
{
L = next[k - a];
p = next[a] + a - (next[a] != 0);
/////
if (k + L - 1<p) next[k] = L;
else
{
++p;
while (p<m && s[p] == s[p - k]) ++p;
next[k] = p - k; a = k;
}
}
}

int next1[MaxM],next2[MaxM];
char s1[MaxM],s2[MaxM];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int len1,len2;
	int ans;
	int i;

	while(~scanf("%s %s",s1,s2))
	{
		ans=0;
		len1=strlen(s1);
		len2=strlen(s2);

		memset(next1,0,sizeof(next1));
		memset(next2,0,sizeof(next2));

		EKMP_pre(len1,s1,next1);
		EKMP_pre(len2,s2,next2);

		for(i=0;i<min(len1,len2);++i)
		{
			if(s1[i]!=s2[i])
				break;

			if(i==0)
				continue;

			if(next1[i]+i==len1 && next2[i]+i==len2 && len1%i==0 && len2%i==0)
				++ans;
		}

		if(i==min(len1,len2))
			if(len1>len2)
			{
				if(next1[len2]+len2==len1 && len1%len2==0)
					++ans;
			}
			else
			{
				if(next2[len1]+len1==len2 && len2%len1==0)
					++ans;
			}

		printf("%d\n",ans);
	}
	
	return 0;
}
