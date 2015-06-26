#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>

using namespace std;

int n,k;
int map1[10][10];
int remi[10],remj[10];
int ans;
int cou;

bool judge(int x,int y)
{
	for(int i=0;i<cou;++i)
		if(remj[i]==y)
			return 0;

	return 1;
}

void dfs(int cur,int hang)
{
	if(cur==k)
	{
		++ans;
		return;
	}

	for(int i=hang;i<=n;++i)
	{
		if(n-i+1<k-cur)
			break;

		for(int j=1;j<=n;++j)
			if(map1[i][j]&&judge(i,j))
			{
				remi[cou]=i;
				remj[cou++]=j;
				dfs(cur+1,i+1);
				--cou;
			}
	}
}

int main()
{
	char c,s[20];
	
	ios::sync_with_stdio(false);

	for(cin>>n>>k;n!=-1&&k!=-1;cin>>n>>k)
	{
		ans=0;
		cou=0;
		for(int i=1;i<=n;++i)
		{
			cin>>s;

			for(int j=1;j<=n;++j)
			{
				c=s[j-1];
				if(c=='#')
					map1[i][j]=1;
				else
					map1[i][j]=0;
			}
		}

		dfs(0,1);

		cout<<ans<<endl;
	}

	return 0;
}
