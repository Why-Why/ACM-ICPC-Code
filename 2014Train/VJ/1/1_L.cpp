#include<iostream>
#include<cstring>

using namespace std;

int vis[110][110];
int ans;
int M,N;
int fir,las,que[10005];

bool judge(int x,int y)
{
	if(x<=0||y<=0||x>M||y>N)
		return 0;

	if(vis[x][y]==0)
		return 0;

	return 1;
}

void bfs(int x,int y)
{
	int temp,t1,t2;

	que[las++]=x*1000+y;
	vis[x][y]=0;

	while(las-fir)
	{
		temp=que[fir++];

		t1=temp/1000;
		t2=temp%1000;

		--t1;
		if(judge(t1,t2))
		{
			vis[t1][t2]=0;
			que[las++]=t1*1000+t2;
		}
		t1+=2;
		if(judge(t1,t2))
		{
			vis[t1][t2]=0;
			que[las++]=t1*1000+t2;
		}	
		--t1;
		--t2;
		if(judge(t1,t2))
		{
			vis[t1][t2]=0;
			que[las++]=t1*1000+t2;
		}	
		t2+=2;
		if(judge(t1,t2))
		{
			vis[t1][t2]=0;
			que[las++]=t1*1000+t2;
		}
		t2-=2;
		--t1;
		if(judge(t1,t2))
		{
			vis[t1][t2]=0;
			que[las++]=t1*1000+t2;
		}	
		t1+=2;
		if(judge(t1,t2))
		{
			vis[t1][t2]=0;
			que[las++]=t1*1000+t2;
		}	
		t2+=2;
		if(judge(t1,t2))
		{
			vis[t1][t2]=0;
			que[las++]=t1*1000+t2;
		}	
		t1-=2;
		if(judge(t1,t2))
		{
			vis[t1][t2]=0;
			que[las++]=t1*1000+t2;
		}
	}
}

void slove()
{
	ans=0;
	fir=las=0;
	
	for(int i=1;i<=M;++i)
		for(int j=1;j<=N;++j)
			if(vis[i][j])
			{
				++ans;
				bfs(i,j);
			}
}

int main()
{
	ios::sync_with_stdio(false);
	
	char c;

	for(cin>>M>>N;M;cin>>M>>N)
	{
		for(int i=1;i<=M;++i)
			for(int j=1;j<=N;++j)
			{
				cin>>c;
				vis[i][j]=c=='@'?1:0;
			}

		slove();
		cout<<ans<<endl;
	}

	return 0;
}
