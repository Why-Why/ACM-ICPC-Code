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
int flo[12][12][12][12];

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

void floyd()
{
	for(int i1=1;i1<=N;++i1)
		for(int i2=1;i2<=M;++i2)
			for(int j1=1;j1<=N;++j1)
				for(int j2=1;j2<=M;++j2)
					if(i1==j1&&i2==j2)
						flo[i1][i2][j1][j2]=0;
					else if((map1[i1][i2]>0&&map1[j1][j2]>0)&&((i1==j1&&(i2-j2==1||i2-j2==-1))||(i2==j2&&(i1-j1==1||i1-j1==-1))))
						flo[i1][i2][j1][j2]=1;
					else
						flo[i1][i2][j1][j2]=10e7;

	for(int k1=1;k1<=N;++k1)
		for(int k2=1;k2<=M;++k2)
            if(map1[k1][k2]>0)
			for(int i1=1;i1<=N;++i1)
				for(int i2=1;i2<=M;++i2)
				if(map1[i1][i2]>0)
					for(int j1=1;j1<=N;++j1)
						for(int j2=1;j2<=M;++j2)
							if(map1[j1][j2]>0)
								flo[i1][i2][j1][j2]=min(flo[i1][i2][j1][j2],flo[i1][i2][k1][k2]+flo[k1][k2][j1][j2]);
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
	int maxn=-10e8;
	minans=10e8;
	int minn[3]={10e8,10e8,10e8};

	if(cou==0)
		return 0;

	floyd();

	if(cou==2)
	{
		for(int i1=1;i1<=N;++i1)
			for(int i2=1;i2<=M;++i2)
				if(map1[i1][i2]>0)
			{
				maxn=-10e8;
				for(int j1=1;j1<=N;++j1)
					for(int j2=1;j2<=M;++j2)
						if(flo[i1][i2][j1][j2]<10e7&&flo[i1][i2][j1][j2]>maxn)
						{
							maxn=flo[i1][i2][j1][j2];
							if(maxn>minn[map1[i1][i2]])
								goto next1;
						}

			next1:
				if(maxn<minn[map1[i1][i2]])
					minn[map1[i1][i2]]=maxn;
			}

		return max(minn[1],minn[2]);
	}
	else
	{
		for(int i1=1;i1<=N;++i1)
			for(int i2=1;i2<=M;++i2)
				for(int j1=1;j1<=N;++j1)
					for(int j2=1;j2<=M;++j2)
						if(map1[i1][i2]>0&&map1[j1][j2]>0)
						{
							maxn=-10e8;
							for(int k1=1;k1<=N;++k1)
								for(int k2=1;k2<=M;++k2)
									if(map1[k1][k2]>0)
										if(min(flo[i1][i2][k1][k2],flo[j1][j2][k1][k2])>maxn)
										{
											maxn=min(flo[i1][i2][k1][k2],flo[j1][j2][k1][k2]);
											if(maxn>minans)
												goto next2;
										}

						next2:
							if(maxn<minans)
								minans=maxn;
						}

		return minans;
	}
}

int main()
{
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
