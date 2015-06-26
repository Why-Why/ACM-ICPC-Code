#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>

using namespace std;

bool map1[1005][1005];
int rem[1005][1005];
int Frem[1005][1005];
int N,M;
int Si,Sj,Fi[1000006],Fj[1000006];
int cou;

bool judge(int x,int y,int temp)
{
	if(x<=0||y<=0||x>N||y>M)
		return 0;

	if(!map1[x][y])
		return 0;
	
	if(rem[x][y])
		return 0;

	if(Frem[x][y]>-1&&temp>=Frem[x][y])					//!!!
		return 0;

	return 1;
}

bool judge1(int x,int y)
{
	if(x<=0||y<=0||x>N||y>M)
		return 0;

	if(!map1[x][y])
		return 0;

	if(Frem[x][y]!=-1)
		return 0;

	return 1;
}

int slove()
{
	queue <int> que;
	int temp,t1,t2;

	que.push(Si*1010+Sj);
	rem[Si][Sj]=1;

	while(!que.empty())
	{
		temp=que.front();
		que.pop();

		t1=temp/1010;
		t2=temp%1010;
		temp=rem[t1][t2];

		if(t1==1||t2==1||t1==N||t2==M)
			return temp;

		--t1;
		if(judge(t1,t2,temp))
		{
			que.push(t1*1010+t2);
			rem[t1][t2]=temp+1;
		}
		t1+=2;
		if(judge(t1,t2,temp))
		{
			que.push(t1*1010+t2);
			rem[t1][t2]=temp+1;
		}
		--t1;
		--t2;
		if(judge(t1,t2,temp))
		{
			que.push(t1*1010+t2);
			rem[t1][t2]=temp+1;
		}
		t2+=2;
		if(judge(t1,t2,temp))
		{
			que.push(t1*1010+t2);
			rem[t1][t2]=temp+1;
		}
	}

	return -1;
}

void init()
{
	queue <int> que;
	int temp,t1,t2;
	for(int i=0;i<cou;++i)
	{
		que.push(Fi[i]*1010+Fj[i]);
		Frem[Fi[i]][Fj[i]]=0;
	}

	while(!que.empty())
	{
		temp=que.front();
		que.pop();

		t1=temp/1010;
		t2=temp%1010;
		temp=Frem[t1][t2];

		--t1;
		if(judge1(t1,t2))
		{
			que.push(t1*1010+t2);
			Frem[t1][t2]=temp+1;
		}
		t1+=2;
		if(judge1(t1,t2))
		{
			que.push(t1*1010+t2);
			Frem[t1][t2]=temp+1;
		}
		--t1;
		--t2;	
		if(judge1(t1,t2))
		{
			que.push(t1*1010+t2);
			Frem[t1][t2]=temp+1;
		}
		t2+=2;
		if(judge1(t1,t2))
		{
			que.push(t1*1010+t2);
			Frem[t1][t2]=temp+1;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);

	int T;
	int ans;
	char c;
	cin>>T;

	while(T--)
	{
		cou=0;
		cin>>N>>M;
		for(int i=1;i<=N;++i)
			for(int j=1;j<=M;++j)
			{
				rem[i][j]=0;
				Frem[i][j]=-1;
				cin>>c;
				if(c=='#'||c=='F')
					map1[i][j]=0;
				else
					map1[i][j]=1;

				if(c=='J')
					Si=i,Sj=j;
				if(c=='F')
				{
					Fi[cou]=i;
					Fj[cou++]=j;
				}
			}

		init();

		ans=slove();

		if(ans==-1)
			cout<<"IMPOSSIBLE\n";
		else
			cout<<ans<<endl;
	}

	return 0;
}
