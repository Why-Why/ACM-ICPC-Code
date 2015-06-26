// ━━━━━━神兽出没━━━━━━
// 　　 ┏┓       ┏┓
// 　　┏┛┻━━━━━━━┛┻┓
// 　　┃           ┃
// 　　┃     ━     ┃
//     ████━████   ┃
// 　　┃           ┃
// 　　┃    ┻      ┃
// 　　┃           ┃
// 　　┗━┓       ┏━┛
// 　　  ┃       ┃
// 　　  ┃       ┃
// 　　　┃       ┗━━━┓
// 　　　┃           ┣┓
// 　　　┃           ┏┛
// 　　　┗┓┓┏━━━━━┳┓┏┛
// 　　　 ┃┫┫     ┃┫┫
// 　　　 ┗┻┛     ┗┻┛
//
// ━━━━━━感觉萌萌哒━━━━━━

// Author        : WhyWhy
// Created Time  : 2015年05月18日 星期一 11时40分48秒
// File Name     : C.cpp

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

struct Edge
{
	int to,next;
};

Edge E[10000*2];
int head[30],Ecou;

void init()
{
	memset(head,-1,sizeof(head));
	Ecou=0;
}

void addEdge(int u,int v)
{
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

char s[110][110];
int n;
int ans[30];
int que[100];
int first,last;
int ru[30];

bool tuopu()
{
	first=last=0;
	int cou=0;
	int t;

	for(int i=1;i<=26;++i)
		if(ru[i]==0)
			que[last++]=i;

	while(last-first)
	{
		t=que[first++];
		ans[cou++]=t;

		for(int i=head[t];i!=-1;i=E[i].next)
		{
			--ru[E[i].to];

			if(ru[E[i].to]==0)
				que[last++]=E[i].to;
		}
	}

	return cou==26;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	bool ok=0;

	init();

	scanf("%d",&n);

	for(int i=1;i<=n;++i)
		scanf("%s",s[i]);

	for(int i=2;i<=n;++i)
		for(int j=0;s[i-1][j];++j)
		{
			if(s[i][j]==0 && s[i-1][j])
			{
				ok=0;
				goto end;
			}

			if(s[i][j]!=s[i-1][j])
			{
				addEdge(s[i-1][j]-'a'+1,s[i][j]-'a'+1);
				++ru[s[i][j]-'a'+1];
				break;
			}
		}

	ok=tuopu();

end:

	if(ok)
	{
		for(int i=0;i<26;++i)
			printf("%c",'a'+ans[i]-1);
		puts("");
	}
	else
		puts("Impossible");
	
	return 0;
}
