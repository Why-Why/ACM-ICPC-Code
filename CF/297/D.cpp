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

const int step[8][2]={{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};

int n,m;
bool map1[2010][2010];
bool vis[2010][2010];

bool judge(int x,int y)
{
	if(map1[x][y]+map1[x+1][y]+map1[x][y+1]+map1[x+1][y+1]==1)
	{
		map1[x][y]=map1[x+1][y]=map1[x][y+1]=map1[x+1][y+1]=0;
		return 1;
	}

	return 0;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	char s[2020];
	int temp;

	scanf("%d %d",&n,&m);

	for(int i=1;i<=n;++i)
	{
		scanf("%s",s+1);

		for(int j=1;j<=m;++j)
			if(s[j]=='*')
				map1[i][j]=1;
	}

	queue <int> que;

	for(int i=1;i<n;++i)
		for(int j=1;j<m;++j)
			if(judge(i,j))
			{
				vis[i][j]=1;
				que.push(i*10000+j);
			}

	int x,y;
	int ni,nj;

	while(!que.empty())
	{
		temp=que.front();
		que.pop();

		x=temp/10000;
		y=temp%10000;

		//map1[x][y]=map1[x+1][y]=map1[x][y+1]=map1[x+1][y+1]=0;

		for(int i=0;i<8;++i)
		{
			ni=x+step[i][0];
			nj=y+step[i][1];

			if(ni>=n || ni<1 || nj>=m || nj<1)
				continue;

			if(vis[ni][nj]==0 && judge(ni,nj))
			{
				vis[ni][nj]=1;
				que.push(ni*10000+nj);
			}
		}
	}

	for(int i=1;i<=n;++i,printf("\n"))
		for(int j=1;j<=m;++j)
			printf("%c",(map1[i][j] ? '*' : '.'));
	
	return 0;
}
