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
int cou=0;
int ans[1000006];

int getnum(int x)
{
	int wei=0;
	char num[10];
	int ret=0;

	while(x)
	{
		num[wei++]=x%10;
		x/=10;
	}

	bool ok=0;
	int tans[10];

	for(int i=wei-1;i>=0;--i)
	{
		if(num[i]>1)
			ok=1;

		if(ok || num[i]>=1)
			tans[i]=1;
		else
			tans[i]=0;
	}


	for(int i=wei-1;i>=0;--i)
		ret=ret*10+tans[i];
	return ret;
}

void getans(int n)
{
	if(n==0)
		return;

	ans[cou++]=getnum(n);
	n-=ans[cou-1];

	getans(n);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	cin>>N;

	getans(N);

	cout<<cou<<endl;

	for(int i=0;i<cou;++i)
		printf("%d ",ans[i]);
	cout<<endl;
	
	return 0;
}
