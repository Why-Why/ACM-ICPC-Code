#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int rem[4000];
int num[60];
bool vis[65];
int maxn,sum;
int N;

int find(int x)
{
	int L=1,R=N,M;

	while(R>L+1)
	{
		M=(L+R)/2;

		if(num[M]>x)
			L=M;
		else
			R=M;
	}

	return L;
}

bool dfs(int yong,int x)
{
	vis[yong]=1;

	if(x==num[yong])
		return 1;

	if(x==0)
		return 1;

	if(rem[x-num[yong]]==0)
		return 0;

	int k=find(x-num[yong]);

	for(int i=k;i<=N;++i)
		if(vis[i]==0&&x-num[yong]>=num[i])
			if(dfs(i,x-num[yong]))
				return 1;

	return 0;
}

bool judge(int x)
{
	memset(vis,0,sizeof(vis));

	for(int i=1;i<=N;++i)
		if(vis[i]==0)
			if(dfs(i,x)==0)
				return 0;

	return 1;
}

int main()
{
	ios::sync_with_stdio(false);

	int a;

	for(cin>>N;N;cin>>N)
	{
		memset(rem,0,sizeof(rem));
		maxn=0;
		sum=0;

		for(int i=1;i<=N;++i)
		{
			cin>>a;
			num[i]=a;
			rem[0]=1;
			for(int j=sum;j>=0;--j)
				if(rem[j])
				{
					rem[j+a]+=rem[j];
				}

			sum+=a;

			if(a>maxn)
				maxn=a;
		}

		sort(num+1,num+N+1,greater<int>());

		for(int i=maxn;i<=sum;++i)
			if(sum%i==0&&sum/i<=rem[i])
			{
				if(judge(i))
				{
					cout<<i<<endl;
					break;
				}
			}
	}

	return 0;
}
