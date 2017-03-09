#include<iostream>
#include<cstring>
#include<cmath>
#include<queue>
#include<iomanip>

using namespace std;

const int step[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

int N,M;
int ZX1,ZY1,ZX2,ZY2;
int X1,X2,Y1,Y2;
int map1[1000][1000];

inline int abs1(int x)
{
	if(x<0)
		x=-x;

	return x;
}

bool judge(int x,int y,int D,bool t)
{
	if(x<=0||y<=0||x>N||y>M)
		return 0;

	if(map1[x][y]==-1)
		return 0;

	if(t)
	{
		if(map1[x][y]>0)
			return 0;
	}
	else
	{
		if(map1[x][y]<0)
			return 0;
	}

	if(D>=min((abs1(x-ZX1)+abs1(y-ZY1)-1)/2+1,(abs1(x-ZX2)+abs1(y-ZY2)-1)/2+1))
		return 0;

	return 1;
}

int bfs()
{
	int temp1,temp2,t1,t2,t3,t4,D;
	int xt,yt;
	queue <int> que1,que2;
	bool qu=1;

	que1.push(X1*1000+Y1);
	que2.push(X2*1000+Y2);

	while(!que1.empty()&&!que2.empty())
	{
		
		temp1=que1.front();
	
		if(qu)
			que1.pop();

		t1=temp1/1000;
		t2=temp1%1000;

		D=map1[t1][t2];
		if(D==-1)
			D=0;

		qu=1;

		if(D/3+1>=min((abs1(t1-ZX1)+abs1(t2-ZY1)-1)/2+1,(abs1(t1-ZX2)+abs1(t2-ZY2)-1)/2+1))
		{
			map1[t1][t2]=-1;
			continue;
		}

		if(D%3==0)
		{
			temp2=que2.front();
			que2.pop();

			if(D/3+1>=min((abs1(t3-ZX1)+abs1(t4-ZY1)-1)/2+1,(abs1(t3-ZX2)+abs1(t4-ZY2)-1)/2+1))
			{
				map1[t3][t4]=-1;
				qu=0;

				continue;
			}

			t3=temp2/1000;
			t4=temp2%1000;
		}

		for(int i=0;i<4;++i)
		{
			xt=t1+step[i][0];
			yt=t2+step[i][1];

			if(judge(xt,yt,D/3+1,1))
			{
				if(map1[xt][yt]<-1)
					return 1+D/3;

				map1[xt][yt]=D+1;
				que1.push(xt*1000+yt);
			}
		}

		if(D%3==0)
		{
			for(int i=0;i<4;++i)
			{
				xt=t3+step[i][0];
				yt=t4+step[i][1];

				if(judge(xt,yt,D/3+1,0))
				{
					if(map1[xt][yt]>0)
						return D/3+1;
	
					map1[xt][yt]=-9;
					que2.push(xt*1000+yt);
				}
			}
		}
	}

	return -1;
}

void solve()
{
	cout<<bfs()<<endl;
}

int main()
{
	ios::sync_with_stdio(false);

	int T;
	char c;
	cin>>T;

	while(T--)
	{
		cin>>N>>M;
		ZX1=0;

		for(int i=1;i<=N;++i)
			for(int j=1;j<=M;++j)
			{
				cin>>c;

				if(c=='.')
					map1[i][j]=0;
				else if(c=='X')
					map1[i][j]=-1;
				else if(c=='Z')
				{
					map1[i][j]=-1;

					if(ZX1)
					{
						ZX2=i;
						ZY2=j;
					}
					else
					{
						ZX1=i;
						ZY1=j;
					}
				}
				else if(c=='M')
				{
					map1[i][j]=-1;

					X1=i;
					Y1=j;
				}
				else
				{
					map1[i][j]=-1;

					X2=i;
					Y2=j;
				}
			}

		solve();
	}

	return 0;
}
