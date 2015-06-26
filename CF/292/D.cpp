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

const int step[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

int n,m;
int map1[2010][2010];
int fang[2010][2010];
int ans[2010][2010];
char s[2010];
int que[4000006];
int que1[4000006];
int first,last;
int first1,last1;

bool judge(int x,int y)
{
	if(x<1 || y<1 || x>n || y>m)
		return 0;

	return 1;
}

int BFS(int x,int y)
{
	int temp;
	int cou=0;
	int tx,ty,nx,ny,nx1,ny1;

	first=last=0;
	first1=last1=0;

	que[last++]=x*3000+y;
	map1[x][y]=-1;
	
	while(last-first)
	{
		temp=que[first++];
		tx=temp/3000;
		ty=temp%3000;
		++cou;

		for(int i=0;i<4;++i)
		{
			nx=tx+step[i][0];
			ny=ty+step[i][1];

			if(!judge(nx,ny))
				continue;

			if(map1[nx][ny]!=1)
				++fang[tx][ty];

			if(map1[nx][ny]==0)
			{
				que[last++]=nx*3000+ny;
				map1[nx][ny]=-1;
			}
		}

		if(fang[tx][ty]==1)
			que1[last1++]=tx*3000+ty;
	}

	if(cou&1)
		return 0;

	int cou1=0;

	while(last1-first1)
	{
		temp=que1[first1++];
		tx=temp/3000;
		ty=temp%3000;

		if(ans[tx][ty])
			continue;

		for(int i=0;i<4;++i)
		{
			nx=tx+step[i][0];
			ny=ty+step[i][1];
			
			if(!judge(nx,ny))
				continue;

			if(ans[nx][ny]==0 && map1[nx][ny]!=1)
			{
				ans[tx][ty]=i+1;

				cou1+=2;
				
				if(i<2)
					ans[nx][ny]=(!i)+1;
				else
					ans[nx][ny]=(!(i-2))+3;

				for(int j=0;j<4;++j)
				{
					nx1=nx+step[j][0];
					ny1=ny+step[j][1];

					if(!judge(nx1,ny1))
						continue;

					if(ans[nx1][ny1]==0 && map1[nx1][ny1]!=1)
					{
						--fang[nx1][ny1];

						if(fang[nx1][ny1]==0)
							return 0;

						if(fang[nx1][ny1]==1)
							que1[last1++]=nx1*3000+ny1;
					}
				}

				break;
			}
		}
	}

	if(cou1<cou)
		return 0;

	return 1;
}

bool slove()
{
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(map1[i][j]==0)
				if(!BFS(i,j))
					return 0;

	return 1;
}

void printans()
{
	char c;

	for(int i=1;i<=n;++i,printf("\n"))
		for(int j=1;j<=m;++j)
			if(map1[i][j]==1)
				printf("*");
			else
			{
				switch(ans[i][j])
				{
					case 1:
						c='^';
						break;
					case 2:
						c='v';
						break;
					case 3:
						c='<';
						break;
					case 4:
						c='>';
						break;
				}

				printf("%c",c);
			}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d",&n,&m);

	for(int i=1;i<=n;++i)
	{
		scanf("%s",s+1);

		for(int j=1;j<=m;++j)
			if(s[j]=='.')
				map1[i][j]=0;
			else
				map1[i][j]=1;
	}

	if(!slove())
		printf("Not unique\n");
	else
		printans();
	
	return 0;
}
