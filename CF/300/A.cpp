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

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	cin>>s;
	len=strlen(s);

	char s2[]="CODEFORCES";
	int len2=strlen(s2);
	char temp;
	char *ppp;

	for(int i=0;i<len2;++i)
	{
		temp=s2[i];
		s2[i]=0;

		ppp=strstr(s,s2);
		s2[i]=temp;

		if(ppp && strstr(ppp+i,s2+i))
		{
			cout<<"YES\n";
			return 0;
		}
	}

	cout<<"NO\n";
	
	return 0;
}
