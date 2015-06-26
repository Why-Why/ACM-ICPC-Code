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

int ans[100];
int cou=0;
char s[20];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int n;
	int t;

	scanf("%d %s",&n,s);

	for(int i=0;i<n;++i)
	{
		t=s[i]-'0';

		if(t<=1)
			continue;

		if((t&1 && t!=9) || t==2)
			ans[cou++]=t;
		
		if(t==4)
		{
			ans[cou++]=3;
			ans[cou++]=2;
			ans[cou++]=2;
		}

		if(t==6)
		{
			ans[cou++]=5;
			ans[cou++]=3;
		}

		if(t==8)
		{
			ans[cou++]=7;
			ans[cou++]=2;
			ans[cou++]=2;
			ans[cou++]=2;
		}

		if(t==9)
		{
			ans[cou++]=7;
			ans[cou++]=2;
			ans[cou++]=3;
			ans[cou++]=3;
		}
	}

	sort(ans,ans+cou);

	for(int i=cou-1;i>=0;--i)
		cout<<ans[i];
	cout<<endl;
	
	return 0;
}
