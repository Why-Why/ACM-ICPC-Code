#include<iostream>
#include<cstring>
#include<queue>
#include<ctime>
#include<cstdio>

using namespace std;

int map1[15][15];
int rem[15][15];
int N,M;
int minans;
int cou;

bool judge(int ti,int tj)
{
	if(ti<=0||tj<=0||ti>N||tj>M)
		return 0;

	return 1;
}

void bfs(int si,int sj,int st)
{
	queue <int> que;
	int temp,ti,tj;

	que.push(si*100+sj);
	map1[si][sj]=st;

	while(!que.empty())
	{
		temp=que.front();
		que.pop();

		ti=temp/100;
		tj=temp%100;

		if(judge(ti-1,tj)&&map1[ti-1][tj]==0)
		{
			que.push((ti-1)*100+tj);
			map1[ti-1][tj]=st;
		}
		if(judge(ti+1,tj)&&map1[ti+1][tj]==0)
		{
			que.push((ti+1)*100+tj);
			map1[ti+1][tj]=st;
		}
		if(judge(ti,tj-1)&&map1[ti][tj-1]==0)
		{
			que.push(ti*100+tj-1);
			map1[ti][tj-1]=st;
		}
		if(judge(ti,tj+1)&&map1[ti][tj+1]==0)
		{
			que.push(ti*100+tj+1);
			map1[ti][tj+1]=st;
		}
	}

}

int bfs1(int i1,int j1,int i2,int j2)
{
	int cou1=0,cou2=0;
	int temp,ti,tj;
	int base,base1;
	queue <int> que1;
	queue <int> que2;

	que1.push(i1*100+j1);
	que2.push(i2*100+j2);
	rem[i1][j1]=0;
	rem[i2][j2]=0;

	while(!que1.empty()||!que2.empty())
	{
		if(!que1.empty())
		{
			temp=que1.front();
			que1.pop();

			ti=temp/100;
			tj=temp%100;
			base=rem[ti][tj];
			if(base>minans)
				return minans;

			--ti;
			if(judge(ti,tj)&&map1[ti][tj]==1&&rem[ti][tj]==-1)
			{
				que1.push(ti*100+tj);
				rem[ti][tj]=base+1;
			}
			ti+=2;
			if(judge(ti,tj)&&map1[ti][tj]==1&&rem[ti][tj]==-1)
			{
				que1.push(ti*100+tj);
				rem[ti][tj]=1+base;
			}
			--ti;
			--tj;
			if(judge(ti,tj)&&map1[ti][tj]==1&&rem[ti][tj]==-1)
			{
				que1.push(ti*100+tj);
				rem[ti][tj]=1+base;
			}
			tj+=2;
			if(judge(ti,tj)&&map1[ti][tj]==1&&rem[ti][tj]==-1)
			{
				que1.push(ti*100+tj);
				rem[ti][tj]=1+base;
			}
		}

		if(!que2.empty())
		{
			temp=que2.front();
			que2.pop();

			ti=temp/100;
			tj=temp%100;
			base1=rem[ti][tj];
			if(base1>minans)
				return minans;

			--ti;
			if(judge(ti,tj)&&map1[ti][tj]==1&&rem[ti][tj]==-1)
			{
				que2.push(ti*100+tj);
				rem[ti][tj]=1+base1;
			}
			ti+=2;
			if(judge(ti,tj)&&map1[ti][tj]==1&&rem[ti][tj]==-1)
			{
				que2.push(ti*100+tj);
				rem[ti][tj]=1+base1;
			}
			--ti;
			--tj;
			if(judge(ti,tj)&&map1[ti][tj]==1&&rem[ti][tj]==-1)
			{
				que2.push(ti*100+tj);
				rem[ti][tj]=1+base1;
			}
			tj+=2;
			if(judge(ti,tj)&&map1[ti][tj]==1&&rem[ti][tj]==-1)
			{
				que1.push(ti*100+tj);
				rem[ti][tj]=1+base1;
			}

		}
	}

	return max(base1,base);
}

int bfs2(int si,int sj,int st)
{
	int base;
	queue<int> que;
	int temp,t1,t2;

	que.push(si*100+sj);
	rem[si][sj]=0;

	while(!que.empty())
	{
		temp=que.front();
		que.pop();

		t1=temp/100;
		t2=temp%100;
		base=rem[t1][t2];
		if(base>minans)
			return minans;

		++t1;
		if(judge(t1,t2)&&map1[t1][t2]==st&&rem[t1][t2]==-1)
		{
			que.push(t1*100+t2);
			rem[t1][t2]=1+base;
		}
		t1-=2;
		if(judge(t1,t2)&&map1[t1][t2]==st&&rem[t1][t2]==-1)
		{
			que.push(t1*100+t2);
			rem[t1][t2]=1+base;
		}
		++t1;
		--t2;
		if(judge(t1,t2)&&map1[t1][t2]==st&&rem[t1][t2]==-1)
		{
			que.push(t1*100+t2);
			rem[t1][t2]=1+base;
		}
		t2+=2;
		if(judge(t1,t2)&&map1[t1][t2]==st&&rem[t1][t2]==-1)
		{
			que.push(t1*100+t2);
			rem[t1][t2]=1+base;
		}
	}

	return base;
}

int slove()
{
	cou=0;

	memset(rem,-1,sizeof(rem));
	for(int i=1;i<=N;++i)
		for(int j=1;j<=M;++j)
			if(map1[i][j]==0)
			{
				++cou;
				if(cou==3)
					return -1;

				bfs(i,j,cou);

			}

	int temp,temp1;
	minans=10e8;

	if(cou==0)
		return 0;

	if(cou==1)
	{
		for(int xi=1;xi<=N;++xi)
			for(int xj=1;xj<=M;++xj)
				for(int yi=1;yi<=N;++yi)
					for(int yj=1;yj<=M;++yj)
						if(map1[yi][yj]==1&&map1[xi][xj]==1)
						{
							memset(rem,-1,sizeof(rem));

							temp=bfs1(xi,xj,yi,yj);

							if(minans>temp)
								minans=temp;
						}

		return minans;
	}
	else
	{
		for(int xi=1;xi<=N;++xi)
			for(int xj=1;xj<=M;++xj)
				for(int yi=1;yi<=N;++yi)
					for(int yj=1;yj<=M;++yj)
						if(map1[xi][xj]!=map1[yi][yj]&&map1[xi][xj]+map1[yi][yj]==3)
						{
							memset(rem,-1,sizeof(rem));

							temp=bfs2(xi,xj,map1[xi][xj]);
							temp1=bfs2(yi,yj,map1[yi][yj]);

							temp=max(temp,temp1);
							if(minans>temp)
								minans=temp;
						}

		return minans;
	}
}

int main()
{
	freopen("in.txt","r",stdin);

	ios::sync_with_stdio(false);

	int T;
	char c;
	int ans;
	cin>>T;

	for(int cas=1;cas<=T;++cas)
	{
		cin>>N>>M;

		for(int i=1;i<=N;++i)
			for(int j=1;j<=M;++j)
			{
				cin>>c;
				if(c=='#')
					map1[i][j]=0;
				else
					map1[i][j]=-1;
			}

		ans=slove();

		cout<<"Case "<<cas<<": ";
		if(ans==-1)
			cout<<-1<<endl;
		else
			cout<<ans<<endl;
	}

	return 0;
}
