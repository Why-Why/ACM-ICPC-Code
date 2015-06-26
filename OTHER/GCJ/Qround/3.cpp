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

const int cheng[5][5]={{0,0,0,0,0},{0,1,2,3,4},{0,2,-1,4,-3},{0,3,-4,-1,2},{0,4,3,-2,-1}};

long long L,X;
char s[10005];
int num[10005];
int qian[10005],hou[10005];

int getpow(int x,int y)
{
	if(x==1)
		return 1;
	
	if(x==-1)
		if(y&1)
			return -1;
		else
			return 1;

	int flag;

	if(x<0 && y&1)
		flag=-1;
	else
		flag=1;

	x=abs(x);

	switch(y%4)
	{
		case 0:
			return flag;
			break;
		case 1:
			return flag*x;
			break;
		case 2:
			return -1*flag;
			break;
		case 3:
			return -1*flag*x;
			break;
	}
}

int getcheng(int a,int b)
{
	int flag;

	if(a*b<0)
		flag=-1;
	else
		flag=1;

	return flag*cheng[abs(a)][abs(b)];
}

long long getqian()
{
	int t;

	for(int i=0;i<4;++i)
	{
		t=getpow(qian[L-1],i);

		if(t==2)
			return i*L;

		for(int j=0;j<L;++j)
			if(getcheng(t,qian[j])==2)
				return i*L+j+1;
	}

	return -1;
}

long long gethou()
{
	int t;

	for(int i=0;i<4;++i)
	{
		t=getpow(hou[0],i);

		if(t==4)
			return i*L;

		for(int j=L-1;j>=0;--j)
			if(getcheng(hou[j],t)==4)
				return i*L+L-j;
	}

	return -1;
}

bool getans()
{
	long long a,b;

	qian[0]=num[0];

	for(int i=1;i<L;++i)
		qian[i]=getcheng(qian[i-1],num[i]);

	hou[L-1]=num[L-1];

	for(int i=L-2;i>=0;--i)
		hou[i]=getcheng(num[i],hou[i+1]);

	if(getpow(qian[L-1],X)!=-1)
		return 0;

	a=getqian();
	b=gethou();

	if(a!=-1 && b!=-1 && a+b<L*X)
		return 1;

	return 0;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);

	int T,cas=1;

	scanf("%d",&T);

	while(T--)
	{
		scanf("%lld %lld",&L,&X);

		scanf("%s",s);

		for(int i=0;i<L;++i)
			if(s[i]=='1')
				num[i]=1;
			else
				num[i]=s[i]-'g';

		printf("Case #%d: ",cas++);

		if(getans())
			printf("YES\n");
		else
			printf("NO\n");
	}
	
	return 0;
}
