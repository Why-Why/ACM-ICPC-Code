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

char map1[60][60];
int ans[200][200];
bool vis[100][100];
int N;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d",&N);
	int cou=0,tcou;

	for(int i=1;i<=N;++i)
	{
		scanf("%s",map1[i]+1);

		for(int j=1;j<=N;++j)
			if(map1[i][j]=='x')
				++cou;
	}

	bool ok=1;

	for(int dx=1-N;dx<=N-1;++dx)
		for(int dy=1-N;dy<=N-1;++dy)
		{
			ok=1;
			tcou=0;

			for(int i=1;i<=N;++i)
				for(int j=1;j<=N;++j)
					if(map1[i][j]=='o' && i+dx>=1 && j+dy>=1 && i+dx<=N && j+dy<=N)
						if(map1[i+dx][j+dy]=='.')
						{
							ok=0;
							break;
						}

			if(ok)
			{
				ans[N+dx][N+dy]=1;

				for(int i=1;i<=N;++i)
					for(int j=1;j<=N;++j)
						if(map1[i][j]=='o' && i+dx>=1 && i+dx<=N && j+dy>=1 && j+dy<=N)
							if(vis[i+dx][j+dy]==0 && map1[i+dx][j+dy]=='x')
							{
								vis[i+dx][j+dy]=1;
								++tcou;
							}

				cou-=tcou;
			}
		}

	if(cou==0)
	{
		cout<<"YES\n";

		for(int i=1;i<=N+N-1;++i,printf("\n"))
			for(int j=1;j<=N+N-1;++j)
				if(i==N && j==N)
					printf("o");
				else
					printf("%c",ans[i][j] ? 'x' : '.');
	}
	else
		cout<<"NO\n";
	
	return 0;
}
