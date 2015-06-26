#include<iostream>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;

const int MaxN=100005;

int L1[MaxN],R[MaxN],T[MaxN];
int yong[MaxN];
int fa[MaxN],fabian[MaxN];
int duan[MaxN],ge[MaxN];
vector <int> bian[MaxN];
int N,M;

void bfs()
{
	int t;
	int t1,L;
	int t2,jin;
	queue <int> que;

	que.push(1);
	duan[1]=0;
	fa[1]=1;

	while(!que.empty())
	{
		t=que.front();
		que.pop();

		L=bian[t].size();

		for(int i=0;i<L;++i)
		{
			t1=bian[t][i];
			t2=L1[t1]+R[t1]-t;
			
			if(T[t1]==0)
				jin=1;
			else
				jin=0;

			if(duan[t2]==-1 || (duan[t2]==duan[t]+1 && ge[t2]>ge[t]+jin))
			{
				que.push(t2);
				duan[t2]=duan[t]+1;
				ge[t2]=ge[t]+jin;
				fa[t2]=t;
				fabian[t2]=t1;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);

	cin>>N>>M;
	
	for(int i=0;i<=N;++i)
		duan[i]=-1;

	for(int i=1;i<=M;++i)
	{
		cin>>L1[i]>>R[i]>>T[i];

		bian[L1[i]].push_back(i);
		bian[R[i]].push_back(i);
	}

	bfs();

	int ans1=0;

	for(int i=N;i!=1;i=fa[i])
	{
		if(T[fabian[i]])
		{
			yong[fabian[i]]=1;
			++ans1;
		}
		else
			yong[fabian[i]]=-1;
	}

	for(int i=1;i<=M;++i)
		if(yong[i]==0)
			if(T[i]==0)
				++ans1;

	cout<<M-ans1<<endl;

	for(int i=1;i<=M;++i)
		if((yong[i]==0 && T[i])||(yong[i]==-1))
			cout<<L1[i]<<' '<<R[i]<<' '<<1-T[i]<<endl;

	return 0;
}
