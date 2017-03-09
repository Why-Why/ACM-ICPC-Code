#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

int N,K;
int rem[100005];

void bfs()
{
	queue <int> que;
	int t;

	que.push(N);
	rem[N]=0;
	
	while(!que.empty())
	{
		t=que.front();
		que.pop();

		if(t==K)
			return;

		if(t*2<=100000&&rem[t*2]==-1)
		{
			rem[t*2]=rem[t]+1;
			que.push(t*2);
		}
		if(t+1<=100000&&rem[t+1]==-1)
		{
			rem[t+1]=rem[t]+1;
			que.push(t+1);
		}
		if(t-1>=0&&rem[t-1]==-1)
		{
			rem[t-1]=rem[t]+1;
			que.push(t-1);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);

	while(cin>>N>>K)
	{
		memset(rem,-1,sizeof(rem));

		if(K<=N)
			cout<<N-K<<endl;
		else
		{
			bfs();
			cout<<rem[K]<<endl;
		}
	}

	return 0;
}
