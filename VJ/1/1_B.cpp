#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;

bool map1[40][40][40];
bool vis[40][40][40];
int L,R,C;
int Sl,Sr,Sc,El,Er,Ec;

struct state
{
	int l,r,c;
	int num;

	state() {}
	state(int x,int y,int z,int n):l(x),r(y),c(z),num(n) {}
};

bool judge(int x,int y,int z)
{
	if(x<=0||x>L||y<=0||y>R||z<=0||z>C)
		return 0;

	if(map1[x][y][z]==0)
		return 0;

	if(vis[x][y][z])
		return 0;

	vis[x][y][z]=1;
	return 1;
}

int bfs()
{
	queue <state> que;
	state temp;
	int tl,tr,tc;

	que.push(state(Sl,Sr,Sc,0));

	while(!que.empty())
	{
		temp=que.front();
		que.pop();

		if(temp.l==El&&temp.r==Er&&temp.c==Ec)
			return temp.num;

		tl=temp.l;
		tr=temp.r;
		tc=temp.c;

		if(judge(tl-1,tr,tc))
			que.push(state(tl-1,tr,tc,temp.num+1));
		if(judge(tl+1,tr,tc))
			que.push(state(tl+1,tr,tc,temp.num+1));
		if(judge(tl,tr-1,tc))
			que.push(state(tl,tr-1,tc,temp.num+1));
		if(judge(tl,tr+1,tc))
			que.push(state(tl,tr+1,tc,temp.num+1));
		if(judge(tl,tr,tc-1))
			que.push(state(tl,tr,tc-1,temp.num+1));	
		if(judge(tl,tr,tc+1))
			que.push(state(tl,tr,tc+1,temp.num+1));
	}

	return -1;
}

int main()
{
	char s[50];
	int ans;

	ios::sync_with_stdio(false);

	while(cin>>L>>R>>C)
	{
		memset(vis,0,sizeof(vis));

		if(!L&&!R&&!C)
			break;

		for(int i=1;i<=L;++i)
			for(int j=1;j<=R;++j)
			{
				cin>>s;
				for(int k=1;k<=C;++k)
					switch(s[k-1])
					{
						case 'S':
							Sl=i;
							Sr=j;
							Sc=k;
							map1[i][j][k]=1;
							break;
						case 'E':
							El=i;
							Er=j;
							Ec=k;
							map1[i][j][k]=1;
							break;
						case '.':
							map1[i][j][k]=1;
							break;
						case '#':
							map1[i][j][k]=0;
							break;
					}
			}

		ans=bfs();

		if(ans!=-1)
			cout<<"Escaped in "<<ans<<" minute(s).\n";
		else
			cout<<"Trapped!\n";
	}

	return 0;
}
