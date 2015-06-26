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

long long ans;
char s[100];

void change1()
{
	long long t;
	int cou=0;

	while(ans)
	{
		t=ans%26;

		if(t==0)
			t=26;

		s[cou++]='A'+t-1;

		ans=(ans-1)/26;
	}

	for(int i=cou-1;i>=0;--i)
		printf("%c",s[i]);
	printf("\n");
}

void change2()
{
	ans=0;
	int len=strlen(s);
	long long temp;

	for(int i=0;i<len;++i)
	{
		temp=s[i]-'A'+1;

		ans=ans*26+temp;
	}
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

		if(s[0]<='9' && s[0]>='0')
		{
			sscanf(s,"%lld",&ans);

			change1();

		//	printf("%s\n",s);
		}
		else
		{
			change2();

			printf("%lld\n",ans);
		}
	}
	
	return 0;
}
