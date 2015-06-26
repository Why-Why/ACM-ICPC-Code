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
	int x,y,t;

	state() {}
	state(int _x,int _y,int _t)
	{
		x=_x;
		y=_y;
		t=_t;
		dep=_dep;
	}
};

int map1[15][15];
int vis[15][15][10];
int N,M,P;
int Sx,Sy,Ex,Ey;
state que[20000];
int first,last;

int bfs()
{
	state temp;
	int x,y,t;

	first=last=0;

	que[last++]=State(x,y,t);
	vis[Sx][Sy][0]=1;

	while(last-first)
	{
		temp=que[first++];

		x=temp.x;
		y=temp.y;
		t=temp.t;

		
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	char s[20];

	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d %d",&N,&M,&P);

		for(int i=1;i<=N;++i)
		{
			scanf("%s",s+1);

			for(int j=1;j<=M;++j)
				if(s[j]=='*')
					map1[i][j]=1;
				else
					if(s[j]=='.')
						map1[i][j]=0;
					else if(s[j]=='@')
						Sx=i,Sy=j;
					else
						Ex=i,Ey=j;
		}

		int ans=bfs();

		if(ans!=-1)
			printf("%d\n",ans);
		else
			printf("YouBadbad\n");
	}
	
	return 0;
}
