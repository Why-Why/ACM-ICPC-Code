#include<iostream>
#include<cstring>
#include<cmath>

#define max(a,b) (a>b ? a:b)

using namespace std;

const int INF=10e8;

int N;
int X[210],Y[210];
double ans[210];
bool vis[210];

void Dijkstra()
{
	int k;
	double minn,len;

	for(int i=1;i<=N;++i)
	{
		vis[i]=0;
		ans[i]=INF;
	}
	ans[1]=0;

	for(int i=1;i<=N;++i)
	{
		k=-1;
		minn=INF;

		for(int j=1;j<=N;++j)
			if(!vis[j] && ans[j]<minn)
			{
				minn=ans[j];
				k=j;
			}

		if(k==-1)
			break;

		vis[k]=1;

		for(int j=1;j<=N;++j)
		{
			len=sqrt((double(X[k])-X[j])*(X[k]-X[j])+(double(Y[k])-Y[j])*(Y[k]-Y[j]));
		
			if(!vis[j] && max(len,ans[k])<ans[j])
				ans[j]=max(len,ans[k]);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cout.setf(ios::fixed);
	cout.precision(3);

	int cas=1;

	for(cin>>N;N;cin>>N,++cas)
	{
		for(int i=1;i<=N;++i)
			cin>>X[i]>>Y[i];

		Dijkstra();

		cout<<"Scenario #"<<cas<<endl;
		cout<<"Frog Distance = "<<ans[2]<<endl<<endl;
	}

	return 0;
}
