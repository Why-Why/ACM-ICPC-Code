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

char s[500];
int len;

int getans(int len,char s[])
{
	int cou=0;
	char temp;

	if((s[0]<='9' && s[0]>='0'))
	{
		temp=s[len];
		s[len]=0;

		int ret;

		sscanf(s,"%d",&ret);

		s[len]=temp;

		return ret;
	}
	else if(s[0]=='a')
	{
		temp=s[len-1];
		s[len-1]=0;

		int p;
		cou=0;

		for(p=4;s[p];++p)
		{
			if(s[p]=='(')
				++cou;
			else if(s[p]==')')
				--cou;

			if(s[p]==',' && cou==0)
				break;
		}

		s[p]=0;
		
		int a=getans(p-4,s+4);
		int b=getans(len-1-p-1,s+p+1);

		s[p]=',';
		s[len-1]=temp;

		return a+b;
	}
	else
	{
		temp=s[len-1];
		s[len-1]=0;

		int p;
		cou=0;

		for(p=4;s[p];++p)
		{
			if(s[p]=='(')
				++cou;
			else if(s[p]==')')
				--cou;

			if(s[p]==',' && cou==0)
				break;
		}

		s[p]=0;

		int a=getans(p-4,s+4);
		int b=getans(len-1-p-1,s+p+1);

		s[p]=',';
		s[len-1]=temp;

		if(s[1]=='a')
			return max(a,b);
		else
			return min(a,b);
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
		len=strlen(s);

		printf("%d\n",getans(len,s));
	}
	
	return 0;
}
