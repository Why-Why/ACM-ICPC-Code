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

int N;
int num[100005];
long long ans=0;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d",&N);

	for(int i=1;i<=N;++i)
		scanf("%d",&num[i]);

	sort(num+1,num+N+1);

	int base=-1;
	int cou=0;
	int rem[5];

	for(int i=N;i>=1;--i)
	{
		if(num[i]==base || num[i]==base-1)
		{
			base=-1;
			rem[cou++]=num[i];
		}
		else
		{
			base=num[i];
		}

		if(cou==2)
		{
			ans+=((long long)(rem[0]))*rem[1];
			cou=0;
		}
	}

	cout<<ans<<endl;
	
	return 0;
}
