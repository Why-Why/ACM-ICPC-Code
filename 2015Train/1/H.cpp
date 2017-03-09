#include<iostream>
#include<cstring>

using namespace std;

const int INF=10e7;

int D[110][110];
int N;

void floyd()
{
	for(int k=1;k<=N;++k)
		for(int i=1;i<=N;++i)
			for(int j=1;j<=N;++j)
				D[i][j]=min(D[i][j],D[i][k]+D[k][j]);
}

int main()
{
	ios::sync_with_stdio(false);

	int a,b,c;
	int maxn;
	int ans,ansp;

	for(cin>>N;N;cin>>N)
	{
		for(int i=1;i<=N;++i)
			for(int j=1;j<=N;++j)
				if(i!=j)
					D[i][j]=INF;
				else
					D[i][j]=0;

		for(int i=1;i<=N;++i)
		{
			cin>>a;

			for(int j=1;j<=a;++j)
			{
				cin>>b>>c;
				D[i][b]=c;
			}
		}

		ans=INF;
		maxn=-INF;

		floyd();

		for(int i=1;i<=N;++i)
		{
			maxn=-INF;
			for(int j=1;j<=N;++j)
				if(D[i][j]>maxn)
					maxn=D[i][j];

			if(maxn<ans)
			{
				ans=maxn;
				ansp=i;
			}
		}

		if(ans==INF)
			cout<<"disjoint\n";
		else
			cout<<ansp<<' '<<ans<<endl;
			
	}

	return 0;
}
