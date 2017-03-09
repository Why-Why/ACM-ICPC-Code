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

struct state
{
	char s[20];
	int id;

	bool operator < (const state &a)
	{
		return strcmp(s,a.s);
	}
};

int fang[500][2][30];
int fcou[500][2];
int vis[17000];
int cou=0;
int N;
char ss[500][200];

set <string> sta;
set <string> :: iterator it;

void change(char s[],int k)
{
	int len=strlen(s);
	int p=0;

	for(int i=0;i<len;++i)
		if(s[i]=='=' || s[i]=='+')
		{
			s[i]=0;
			sta.insert(&s[p]);
			p=i+1;
		}
}

void build()
{
	char *s;
	int flag=0;

	for(int i=1;i<=N;++i)
	{
		int len=strlen(ss[i]);
		s=ss[i];
		int p=0;
		for(int j=0;j<len;++j)
			if(s[i]=='+' || s[i]=='=')
			{
				s[i]=0;
				it=sta.find(&s[p]);
				fang[i][flag][fcou[i][flag]++]=(int)(it-sta.begin());
				p=j+1;

				if(s[i]=='=')
					++flag;
			}
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d",&N);

	char s[200];
	int anscou=0;

	for(int i=1;i<=N;++i)
	{
		scanf("%s",ss[i]);
		change(ss[i],i);
	}

	build();

	bool ok=0,flag;

	do
	{
		ok=0;
		for(int i=1;i<=N;++i)
		{
			flag=1;
			for(int j=0;j<fcou[i][0];++j)
				if(vis[j]==0)
				{
					flag=0;
					break;
				}

			if(flag)
			{
				for(int j=0;j<fcou[i][1];++j)
					if(!vis[j])
					{
						vis[j]=1;
						++anscou;
					}
				ok=1;
			}
		}
	}while(ok);

	cout<<anscou<<endl;
	cou=sta.size();
	for(int i=0;i<cou;++i)
		if(vis[sta[i].id]==1)
			cout<<(sta[i].s)<<endl;
	
	return 0;
}
