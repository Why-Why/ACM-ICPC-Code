#include<iostream>
#include<cstring>

using namespace std;

const int INF=1e7;

short map1[205][205];
int que[40005],las,fir;
int ans[205][205];
int ans1[205][205];
int N,M;
int couKFC,Si,Sj,Ei,Ej;

bool judge(int x,int y,int (*rem)[205])
{
	if(x<=0||y<=0||x>N||y>M)
		return 0;

	if(rem[x][y]!=INF)
		return 0;

	if(map1[x][y]==0)
		return 0;

	return 1;
}

void bfs(int x,int y,int (*rem)[205])
{
	las=fir=0;
	int cou=0;
	int temp,t1,t2;

	que[las++]=x*1000+y;
	rem[x][y]=0;

	while(las-fir)
	{
		temp=que[fir++];
		t1=temp/1000;
		t2=temp%1000;
		temp=rem[t1][t2];

		if(map1[t1][t2]==2)
			++cou;

		if(cou>=couKFC)
			return;

		--t1;
		if(judge(t1,t2,rem))
		{
			rem[t1][t2]=temp+1;
			que[las++]=t1*1000+t2;
		}	
		t1+=2;
		if(judge(t1,t2,rem))
		{
			rem[t1][t2]=temp+1;
			que[las++]=t1*1000+t2;
		}	
		--t1;
		--t2;
		if(judge(t1,t2,rem))
		{
			rem[t1][t2]=temp+1;
			que[las++]=t1*1000+t2;
		}	
		t2+=2;
		if(judge(t1,t2,rem))
		{
			rem[t1][t2]=temp+1;
			que[las++]=t1*1000+t2;
		}
	}
}

int slove()
{
	bfs(Si,Sj,ans);
	bfs(Ei,Ej,ans1);

	int minn=INF;

	for(int i=1;i<=N;++i)
		for(int j=1;j<=M;++j)
			if(map1[i][j]==2)
				if(minn>ans[i][j]+ans1[i][j])
					minn=ans[i][j]+ans1[i][j];

	return minn*11;
}

int main()
{
	ios::sync_with_stdio(false);

	char c;

	while(cin>>N>>M)
	{
		couKFC=0;

		for(int i=1;i<=N;++i)
			for(int j=1;j<=M;++j)
			{
				cin>>c;
				ans[i][j]=ans1[i][j]=INF;

				switch(c)
				{
					case 'Y':
						map1[i][j]=1;
						Si=i;
						Sj=j;
						break;
					case 'M':
						map1[i][j]=1;
						Ei=i;
						Ej=j;
						break;
					case '.':
						map1[i][j]=1;
						break;
					case '#':
						map1[i][j]=0;
						break;
					case '@':
						map1[i][j]=2;
						++couKFC;
						break;
				}
			}

		cout<<slove()<<endl;
	}

	return 0;
}
