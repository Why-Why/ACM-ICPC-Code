#include<iostream>
#include<cstring>

using namespace std;

int rem[60];
int N;
int sum,maxn;
int cou;
int res;
int rem1[4000];

bool dfs(int zu,int las,int sta)
{
	if(zu>sum/res)
		return 1;

	for(int i=min(sta,las);i>=1;--i)
		if(rem[i])
		{
			--rem[i];

			++cou;

			if(i==las)
			{
				if(dfs(zu+1,res,maxn))
					return 1;
				
				++rem[i];
				return 0;
			}			
			else
			{
				if(dfs(zu,las-i,i))
					return 1;

				++rem[i];

				if(las==res)
					return 0;
			}
		}

	return 0;
}

bool judge(int x)
{
	res=x;

	return dfs(1,x,maxn);
}

int main()
{
	ios::sync_with_stdio(false);

	int a;

	for(cin>>N;N;cin>>N)
	{
		sum=0;
		maxn=0;
		memset(rem,0,sizeof(rem));
		memset(rem1,0,sizeof(rem1));
		rem1[0]=1;

		for(int i=0;i<N;++i)
		{
			cin>>a;
			
			if(a>maxn)
				maxn=a;

			sum+=a;
			++rem[a];
		}

		for(int i=maxn;i<=sum;++i)
			if(sum%i==0)
				if(judge(i))
				{
					cout<<i<<endl;
					break;
				}
	}

	return 0;
}
