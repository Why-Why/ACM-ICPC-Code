#include<iostream>
#include<cstring>

using namespace std;

int N,M,A,B;
int fang[110],Xr[110],Yr[110];
int map1[110][110];

bool judge(int a,int step)
{
	int x=Xr[a],y=Yr[a];

	if(fang[a]==0)
	{
		y+=step;

		for(int i=Yr[a]+1;i<=y&&i<=B;++i)
			if(map1[x][i])
			{
				cout<<"Robot "<<a<<" crashes into robot "<<map1[x][i]<<endl;
				return 0;
			}
	}
	else if(fang[a]==1)
	{
		x+=step;
		
		for(int i=Xr[a]+1;i<=x&&i<=A;++i)
			if(map1[i][y])
			{
				cout<<"Robot "<<a<<" crashes into robot "<<map1[i][y]<<endl;
				return 0;
			}
	}
	else if(fang[a]==2)
	{
		y-=step;
		
		for(int i=Yr[a]-1;i>=y&&i>0;--i)
			if(map1[x][i])
			{
				cout<<"Robot "<<a<<" crashes into robot "<<map1[x][i]<<endl;
				return 0;
			}
	}
	else
	{
		x-=step;

		for(int i=Xr[a]-1;i>=x&&i>0;--i)
			if(map1[i][y])
			{
				cout<<"Robot "<<a<<" crashes into robot "<<map1[i][y]<<endl;
				return 0;
			}
	}		

	if(x<=0||y<=0||x>A||y>B)
	{
		cout<<"Robot "<<a<<" crashes into the wall"<<endl;
		return 0;
	}

	map1[Xr[a]][Yr[a]]=0;
	map1[x][y]=a;
	Xr[a]=x;
	Yr[a]=y;

	return 1;
}

void solve()
{
	int a,b;
	char c;
	bool ok=0;

	for(int i=1;i<=M;++i)
	{
		cin>>a>>c>>b;

		if(ok)
			continue;

		if(c=='L')
		{
			fang[a]-=b;
			fang[a]%=4;
			if(fang[a]<0)
				fang[a]+=4;
		}
		else if(c=='R')
		{
			fang[a]+=b;
			fang[a]%=4;
		}
		else
			if(judge(a,b)==0)
				ok=1;
	}

	if(!ok)
		cout<<"OK\n";
}

int main()
{
	ios::sync_with_stdio(false);

	int T;
	char c;
	cin>>T;

	while(T--)
	{
		memset(map1,0,sizeof(map1));
		cin>>A>>B>>N>>M;

		for(int i=1;i<=N;++i)
		{
			cin>>Xr[i]>>Yr[i]>>c;

			map1[Xr[i]][Yr[i]]=i;
			
			if(c=='N')
				fang[i]=0;
			else if(c=='E')
				fang[i]=1;
			else if(c=='S')
				fang[i]=2;
			else
				fang[i]=3;
		}

		solve();
	}

	return 0;
}
