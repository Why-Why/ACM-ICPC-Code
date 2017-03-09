#include<iostream>
#include<cstring>

using namespace std;

const int INF=10e8+10;

int sum[100005];
int ans,minn;
int minni,ansi1,ansi2;
int N;

void slove()
{
	minn=0;
	minni=0;
	ans=sum[1];
	ansi1=ansi2=1;

	for(int i=1;i<=N;++i)
	{
		if(sum[i]-sum[minni]>ans)
		{
			ans=sum[i]-sum[minni];
			ansi1=i;
			ansi2=minni+1;
		}

		if(sum[i]<minn)
		{
			minn=sum[i];
			minni=i;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);

	int T,temp;
	cin>>T;

	for(int cas=1;cas<=T;++cas)
	{
		cin>>N;
		sum[0]=0;
		for(int i=1;i<=N;++i)
		{
			cin>>temp;
			sum[i]=sum[i-1]+temp;
		}
		slove();

		if(cas!=1)
			cout<<endl;
		cout<<"Case "<<cas<<':'<<endl;
		cout<<ans<<' '<<ansi2<<' '<<ansi1<<endl;
	}

	return 0;
}
