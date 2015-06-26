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

int change(char s[])
{
	int ret=0;
	int t;

	for(int i=0;s[i];++i)
	{
		if(s[i]<='9' && s[i]>='0')
			t=s[i]-'0';
		else if(s[i]=='-')
			continue;
		else if(s[i]=='Q' || s[i]=='Z')
			continue;
		else if(s[i]<='P')
		{
			t=(s[i]-'A')/3+2;
		}
		else
		{
			--s[i];
			t=(s[i]-'A')/3+2;
		}
		
		ret=ret*10+t;
	}

	return ret;
}

char s[10000];
int num[100005];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N;

	scanf("%d",&N);

	for(int i=1;i<=N;++i)
	{
		scanf("%s",s);
		num[i]=change(s);
	}

	sort(num+1,num+N+1);
	num[N+1]=-1;

	int cou=1;
	bool ok=0;

	for(int i=2;i<=N+1;++i)
		if(num[i]!=num[i-1])
		{
			if(cou>1)
			{
				printf("%03d-%04d %d\n",num[i-1]/10000,num[i-1]%10000,cou);
				ok=1;
			}
			
			cou=1;
		}
		else
			++cou;

	if(!ok)
		puts("No duplicates. \n");

	return 0;
}
