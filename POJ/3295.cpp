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

inline int change(char c)
{
	switch(c)
	{
		case 'p':
			return 1;
		case 'q':
			return 2;
		case 'r':
			return 3;
		case 's':
			return 4;
		case 't':
			return 5;
		default:
			return 0;
	}
}

int num[10];
char s[500];

int getans(char s[])
{
	if(s[0]==0)
		return 0;

	if(change(s[0]))
		return num[change(s[0])];

	int a,b;
	int cou=1;
	
	a=getans(s+1);

	if(s[0]=='N')
		return 1-a;
	
	int i;
	
	for(i=1;s[i];++i)
	{	
		switch(s[i])
		{
			case 'A':
			case 'K':
			case 'C':
			case 'E':
				cou+=1;
				break;
			case 'N':
				break;
			default:
				--cou;
		}

		if(!cou)
			break;
	}

	b=getans(s+i+1);

	switch(s[0])
	{
		case 'A':
			return a||b;
		case 'K':
			return a&&b;
		case 'C':
			return !(a==1 && b==0);
		case 'E':
			return a==b;
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	bool ok;

	while(~scanf("%s",s) && s[0]!='0')
	{
		ok=1;

		for(int i=0;i<32;++i)
		{
			for(int j=0;j<5;++j)
				if(i&(1<<j))
					num[j+1]=1;
				else
					num[j+1]=0;

			if(1!=getans(s))
			{
				ok=0;
				break;
			}
		}

		if(ok)
			printf("tautology\n");
		else
			printf("not\n");
	}
	
	return 0;
}
