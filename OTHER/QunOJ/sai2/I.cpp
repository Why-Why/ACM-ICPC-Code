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

char ans[100][20];
char base[20];
int couans;
int step[20];
int coustep;
bool vis[20];
char temps[20];

void change(char s[],int t)
{
	char temp[20];

	if(t==1)
	{
		strcpy(temp,s);
		s[0]=temp[2];
		s[1]=temp[5];
		s[2]=temp[8];
		s[3]=temp[1];
		s[5]=temp[7];
		s[6]=temp[0];
		s[7]=temp[3];
		s[8]=temp[6];
	}
	
	if(t==2)
	{
		strcpy(temp,s);
		s[0]=temp[6];
		s[1]=temp[3];
		s[2]=temp[0];
		s[3]=temp[7];
		s[5]=temp[1];
		s[6]=temp[8];
		s[7]=temp[5];
		s[8]=temp[2];
	}

	if(t==3)
	{
		strcpy(temp,s);
		s[0]=temp[2];
		s[2]=temp[0];
		s[3]=temp[5];
		s[5]=temp[3];
		s[6]=temp[8];
		s[8]=temp[6];
	}

	if(t==4)
	{
		strcpy(temp,s);
		s[0]=temp[6];
		s[1]=temp[7];
		s[2]=temp[8];
		s[6]=temp[0];
		s[7]=temp[1];
		s[8]=temp[2];
	}
}

int remans[20];

void slove(int lie[])
{
	bool ok=1;
	char temp[20];

	strcpy(temp,base);

	for(int i=0;i<coustep;++i)
		change(temp,step[remans[i]]);

	for(int i=0;i<couans;++i)
		if(strcmp(ans[i],temp)==0)
		{
			ok=0;
			break;
		}

	if(ok)
	{
		strcpy(ans[couans],temp);
		++couans;
	}
}

void dfs(int d)
{
	if(d==coustep)
	{
		slove(remans);
		return;
	}

	for(int i=0;i<coustep;++i)
		if(!vis[i])
		{
			remans[d]=i;
			vis[i]=1;
			dfs(d+1);
			vis[i]=0;
		}
}

void getans()
{
	memset(vis,0,sizeof(vis));

	dfs(0);

	printf("%d\n",couans);
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int a,b,c,d;

	scanf("%d",&T);

	while(T--)
	{
		couans=coustep=0;

		scanf("%s",base);
		scanf("%d %d %d %d",&a,&b,&c,&d);

		for(int i=0;i<a;++i)
			step[coustep++]=1;
		for(int i=0;i<b;++i)
			step[coustep++]=2;
		for(int i=0;i<c;++i)
			step[coustep++]=3;
		for(int i=0;i<d;++i)
			step[coustep++]=4;

		if(coustep==0)
		{
			printf("1\n");
			continue;
		}

		getans();
	}
	
	return 0;
}
