#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

bool rem[10005];
int rans[10005];

void getPrime()
{
	for(int i=2;i<10000;++i)
		if(rem[i]==0)
			for(int j=i*2;j<10000;j+=i)
				rem[j]=1;	
}

int bfs(int S,int E)
{
	memset(rans,-1,sizeof(rans));

	queue<int> que;
	int t;
	int temp;

	que.push(S);
	rans[S]=0;

	while(!que.empty())
	{
		t=que.front();
		que.pop();

		if(t==E)
			return rans[E];

		for(int i=1;i<=9;++i)
		{
			temp=t%1000+i*1000;
			if(rans[temp]==-1&&rem[temp]==0)
			{
				rans[temp]=rans[t]+1;
				que.push(temp);
			}
		}
		for(int i=0;i<=9;++i)
		{
			temp=t%100+100*i+(t/1000)*1000;
			if(rans[temp]==-1&&rem[temp]==0)
			{
				rans[temp]=rans[t]+1;
				que.push(temp);
			}
		}
		for(int i=0;i<=9;++i)
		{
			temp=t%10+10*i+(t/100)*100;
			if(rans[temp]==-1&&rem[temp]==0)
			{
				rans[temp]=rans[t]+1;
				que.push(temp);
			}
		}
		for(int i=0;i<=9;++i)
		{
			temp=(t/10)*10+i;
			if(rans[temp]==-1&&rem[temp]==0)
			{
				rans[temp]=rans[t]+1;
				que.push(temp);
			}
		}
	}

	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	
	getPrime();

	int T;
	int a,b;
	int ans;

	cin>>T;

	while(T--)
	{
		cin>>a>>b;

		ans=bfs(a,b);

		if(ans==-1)
			cout<<"Impossible\n";
		else
			cout<<ans<<endl;
	}

	return 0;
}
