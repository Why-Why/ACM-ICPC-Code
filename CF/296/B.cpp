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

int n;
char s[200005],t[200005];
int rem[30][30];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int ans=0,cou=0;
	int a,b;

	scanf("%d",&n);

	scanf("%s %s",s+1,t+1);

	for(int i=1;i<=n;++i)
	{
		if(s[i]!=t[i])
			++cou;
		else
			continue;

		if(ans==2)
			continue;
		
		if(rem[t[i]-'a'][s[i]-'a'])
		{
			ans=2;
			a=rem[t[i]-'a'][s[i]-'a'];
			b=i;
		}

		if(ans==2)
			continue;

		for(int j=0;j<26;++j)
			if(rem[t[i]-'a'][j])
			{
				ans=1;
				a=rem[t[i]-'a'][j];
				b=i;
				break;
			}
			else if(rem[j][s[i]-'a'])
			{
				ans=1;
				a=rem[j][s[i]-'a'];
				b=i;
				break;
			}

		rem[s[i]-'a'][t[i]-'a']=i;
	}		

	if(ans==0)
	{
		cout<<cou<<endl;
		cout<<-1<<' '<<-1<<endl;
	}
	else
	{
		cout<<cou-ans<<endl;
		cout<<a<<' '<<b<<endl;
	}
	
	return 0;
}
