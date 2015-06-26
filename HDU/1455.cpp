#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int rem[4000];
int num[60];
int N;
bool vis[60];
bool vis1[55];
int maxn,sum;
int res;

bool dfs(int zu,int las)
{
	if(zu>sum/res)
		return 1;

	for(int i=1;i<=N;++i)
		if(vis[i]==0&&vis1[num[i]]==0))
		{
			if(num[i]>las)
				return 0;
			
			if(num[i]==las)
			{
				memset(vis1,0,sizeof(vis1));

				vis[i]=1;
			
				if(dfs(zu+1,res))
					return 1;

				vis[i]=0;
			}

			if(num[i]<las&&rem[las-num[i]])
			{
				vis[i]=1;

				if(dfs(zu,las-num[i]))
					return 1;

				vis[i]=0;
			}
		}

	return 0;
}

bool judge(int x)
{
	res=x;

	memset(vis,0,sizeof(vis));
	vis[0]=1;
	num[0]=-1;

	return dfs(1,x);
}

int main()
{
	ios::sync_with_stdio(false);

	int a;
	num[0]=-1000;

	for(cin>>N;N;cin>>N)
	{
		memset(rem,0,sizeof(rem));
		memset(vis,0,sizeof(vis));
		maxn=0;
		sum=0;

		for(int i=1;i<=N;++i)
		{
			cin>>a;
			num[i]=a;
			vis[a]=1;
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

		sort(num+1,num+N+1);

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
