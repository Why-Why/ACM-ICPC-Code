#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<cmath>

using namespace std;

struct TAI
{
	int x,y,fang,t,v;
};

struct state
{
	short x,y,D;
	int F;

	state() {}
	state(int a,int b,int c,int d):x(a),y(b),D(c),F(d) {}

	friend bool operator < (state a,state b)
	{
		return a.F>b.F;
	}
};

const int step[5][2]={{-1,0},{1,0},{0,-1},{0,1},{0,0}};

TAI ta[103];
int M,N,K,D;
int xp,yp;
bool rem[103][103][1003];

void initTa()
{
	for(int c=1;c<=K;++c)
	{
		if(ta[c].fang==1)
		{
			for(int i=ta[c].x-1;i>=0;--i)
				if(rem[i][ta[c].y][0])
					break;
				else
				{
					if((ta[c].x-i)%ta[c].v==0)
						for(int q=(ta[c].x-i)/ta[c].v;q<=D;q+=ta[c].t)
							rem[i][ta[c].y][q]=1;
				}
		}
		else if(ta[c].fang==3)
		{
			for(int i=ta[c].x+1;i<=M;++i)
				if(rem[i][ta[c].y][0])
					break;
				else
				{
					if((i-ta[c].x)%ta[c].v==0)
						for(int q=(i-ta[c].x)/ta[c].v;q<=D;q+=ta[c].t)
							rem[i][ta[c].y][q]=1;
				}
		}
		else if(ta[c].fang==2)
		{
			for(int j=ta[c].y+1;j<=N;++j)
				if(rem[ta[c].x][j][0])
					break;
				else
				{
					if((j-ta[c].y)%ta[c].v==0)
						for(int q=(j-ta[c].y)/ta[c].v;q<=D;q+=ta[c].t)
							rem[ta[c].x][j][q]=1;
				}
		}
		else
		{
			for(int j=ta[c].y-1;j>=0;--j)
				if(rem[ta[c].x][j][0])
					break;
				else
				{
					if((ta[c].y-j)%ta[c].v==0)
						for(int q=(ta[c].y-j)/ta[c].v;q<=D;q+=ta[c].t)
							rem[ta[c].x][j][q]=1;
				}
		}
	}
}

bool judge(int x,int y,int D)
{
	if(x<0||y<0||x>M||y>N)
		return 0;

	if(rem[x][y][D]||rem[x][y][0])
		return 0;

	return 1;
}

inline int getH(int x,int y)
{
	return abs(x-M)+abs(y-N);
}

int bfs()
{
	int temp,t1,t2,H;
	state tsta;
	priority_queue <state> que;

	que.push(state(0,0,0,0));

	while(!que.empty())
	{
		tsta=que.top();
		que.pop();

		temp=tsta.D;
		t1=tsta.x;
		t2=tsta.y;

		if(temp>D)
			continue;

		if(t1==M&&t2==N)
			return temp;

		for(int i=0;i<5;++i)
			if(judge(t1+step[i][0],t2+step[i][1],temp+1))
			{
				H=getH(t1+step[i][0],t2+step[i][1]);
				if(temp+1+H<=D)
				{
					que.push(state(t1+step[i][0],t2+step[i][1],temp+1,temp+1+getH(t1+step[i][0],t2+step[i][1])));
					rem[t1+step[i][0]][t2+step[i][1]][temp+1]=1;
				}
			}
	}

	return 0;
}

void solve()
{
	int ans=bfs();

	if(ans)
		cout<<ans<<endl;
	else
		cout<<"Bad luck!\n";
}

int main()
{
	ios::sync_with_stdio(false);

	char c;
	int a,b,e,d;

	while(cin>>M>>N>>K>>D)
	{
		memset(rem,0,sizeof(rem));

		xp=yp=0;

		for(int i=1;i<=K;++i)
		{
			cin>>c>>ta[i].t>>ta[i].v>>ta[i].x>>ta[i].y;

			rem[ta[i].x][ta[i].y][0]=1;

			if(c=='N')
				ta[i].fang=1;
			else if(c=='E')
				ta[i].fang=2;
			else if(c=='S')
				ta[i].fang=3;
			else
				ta[i].fang=4;
		}

		initTa();

		solve();
	}

	return 0;
}
