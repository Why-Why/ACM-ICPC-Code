#include<iostream>
#include<cstring>

using namespace std;

int fa[100005];
bool vis[100005];

int find(int x)
{
	if(fa[x]==x)
		return x;

	fa[x]=find(fa[x]);

	return fa[x];
}

int main()
{
	ios::sync_with_stdio(false);

	int a,b;

	bool ok=1;

	while(cin>>a>>b)
	{
		if(a==-1&&b==-1)
			break;

		ok=1;
		
		for(int i=1;i<=100000;++i)
		{
			fa[i]=i;
			vis[i]=0;
		}

		while(a!=0 || b!=0)
		{
			vis[a]=vis[b]=1;

			if(!ok)
			{
				cin>>a>>b;
				continue;
			}

			if(find(a)==find(b))
			{
				ok=0;
				continue;
			}

			fa[find(a)]=find(b);

			cin>>a>>b;
		}

		int rem=-1;

		if(ok)
			for(int i=1;i<=100000;++i)
				if(vis[i])
					if(rem==-1)
						rem=find(i);
					else if(find(i)!=rem)
					{
						ok=0;
						break;
					}

		if(ok)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}

	return 0;
}
