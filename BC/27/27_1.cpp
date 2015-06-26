#include<iostream>
#include<cstring>

#define max1(a,b,c) (max(a,max(b,c)))

using namespace std;

int num[5];
int n;

int main()
{
	int a,b,c;
	int T;

	ios::sync_with_stdio(false);

	cin>>T;

	while(T--)
	{
		cin>>n;

		for(int i=1;i<=n;++i)
		{
			cin>>a>>b>>c;

			num[i]=max1(a,b,c);
		}

		int temp=0;

		for(int i=1;i<=n;++i)
		{
			temp=0;

			for(int j=1;j<=n;++j)
				if(num[j]>num[i])
					++temp;

			cout<<temp+1;

			if(i<n)
				cout<<' ';
		}

		cout<<endl;
	}

	return 0;
}
