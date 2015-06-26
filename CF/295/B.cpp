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

int vis[100010];

int bfs(int n,int m)
{
	queue <int> que;
	int t;

	if(n>=m)
		return n-m;

	que.push(n);
	vis[n]=1;

	while(!que.empty())
	{
		t=que.front();
		que.pop();

		if(t==m)
			return vis[t]-1;

		if(t-1>0 && vis[t-1]==0)
		{
			que.push(t-1);
			vis[t-1]=vis[t]+1;
		}
		if(t*2<100000 && vis[t*2]==0)
		{
			que.push(t*2);
			vis[t*2]=vis[t]+1;
		}
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	int n,m;

	cin>>n>>m;

	cout<<bfs(n,m)<<endl;

	return 0;
}
