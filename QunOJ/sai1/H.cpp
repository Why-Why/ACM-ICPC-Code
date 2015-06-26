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

long long map1[400][400];
int W,H;
bool vis[400][400];

const int step[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

void bfs1(int x,int y)
{
	queue <int> que;
	int t,tx,ty,px,py;

	que.push(x*1000+y);
	vis[x][y]=1;

	while(!que.empty())
	{
		t=que.front();
		que.pop();

		tx=t/1000;
		ty=t%1000;

		for(int i=0;i<4;++i)
		{
			px=tx+step[i][0];
			py=ty+step[i][1];

			if(px>=0 && px<= H+1 && py>=0 && py<= W+1 && !vis[px][py] && map1[px][py]>=map1[tx][ty])
			{
				vis[px][py]=1;
				que.push(1000*px+py);
			}
		}
	}
}

bool vis1[400][400];

long long bfs2(int x,int y)
{
	long long base=0,minn=-1;
	long long cou=0;

	queue <int> que;
	int t,tx,ty,px,py;

	base+=map1[x][y];
	que.push(x*1000+y);
	vis1[x][y]=1;

	while(!que.empty())
	{
		t=que.front();
		que.pop();

		tx=t/1000;
		ty=t%1000;

		for(int i=0;i<4;++i)
		{
			px=tx+step[i][0];
			py=ty+step[i][1];

			if(px>0 && px<= H && py>0 && py<= W)
			{
				if(vis[px][py])
				{
					if(map1[px][py]<minn || minn==-1)
						minn=map1[px][py];
				}
				else if(vis1[px][py]==0)
				{
					vis1[px][py]=1;
					que.push(1000*px+py);
					base+=map1[px][py];
					++cou;
				}
			}
		}
	}
	++cou;
	return cou*minn-base;
}

long long getans()
{
	long long ret=0;
	int k=1;

	bfs1(0,0);

	for(int i=1;i<=H;++i)
		for(int j=1;j<=W;++j)
			if(!vis[i][j] && !vis1[i][j])
				ret+=bfs2(i,j);

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	long long ans;

	
	while(~scanf("%d %d",&W,&H))
	{
		memset(vis,0,sizeof(vis));
		memset(vis1,0,sizeof(vis1));
		memset(map1,0,sizeof(map1));

		for(int i=1;i<=H;++i)
			for(int j=1;j<=W;++j)
				cin>>map1[i][j];

		ans=getans();

		if(ans<0)
			ans=0;

		cout<<ans<<endl;
	}
	
	return 0;
}
