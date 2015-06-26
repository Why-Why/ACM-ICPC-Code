#include<iostream>
#include<algorithm>
#include<utility>

using namespace std;

typedef pair <int,int> pii;

int N,K;
pii num[110];
int remans[110];

int main()
{
	ios::sync_with_stdio(false);

	cin>>N>>K;

	for(int i=0;i<N;++i)
	{
		cin>>num[i].first;
		num[i].second=i+1;
	}

	sort(num,num+N);

	int ans=0;

	for(int i=0;i<N;++i)
	{
		if(K>=num[i].first)
		{
			remans[ans++]=num[i].second;
			K-=num[i].first;
		}
	}

	cout<<ans<<endl;

	for(int i=0;i<ans;++i)
		cout<<remans[i]<<' ';

	cout<<endl;

	return 0;
}
