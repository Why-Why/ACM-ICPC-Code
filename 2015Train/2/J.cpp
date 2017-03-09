#include<iostream>
#include<cstring>

using namespace std;

int map1[6][6];
int ans1[6][6],ans2[6][6];

bool judge1()
{
	for(int j=1;j<=4;++j)
		if((map1[4][j]+ans1[4][j]+ans1[3][j]+ans1[4][j-1]+ans1[4][j+1])%2)
			return 0;

	return 1;
}

bool judge2()
{
	for(int j=1;j<=4;++j)
		if((map1[4][j]+ans2[4][j]+ans2[3][j]+ans2[4][j-1]+ans2[4][j+1])%2==0)
			return 0;

	return 1;
}

void solve()
{
	int cou1=0,cou2=0;
	int cou=10e7;

	for(int i=0;i<16;++i)
	{
		cou1=cou2=0;

		for(int j=1;j<=4;++j)
		{
			ans1[1][j]=ans2[1][j]=((1<<(j-1))&i)?1:0;
			if(ans1[1][j])
			{
				++cou1;
				++cou2;
			}
		}

		for(int i=2;i<=4;++i)
			for(int j=1;j<=4;++j)
			{
				if((map1[i-1][j]+ans1[i-2][j]+ans1[i-1][j-1]+ans1[i-1][j+1]+ans1[i-1][j])%2)
					ans1[i][j]=1,++cou1;
				else
					ans1[i][j]=0;

				if((map1[i-1][j]+ans2[i-2][j]+ans2[i-1][j-1]+ans2[i-1][j+1]+ans2[i-1][j])%2)
					ans2[i][j]=0;
				else
					ans2[i][j]=1,++cou2;
			}

		if(judge1()&&cou1<cou)
			cou=cou1;
		if(judge2()&&cou2<cou)
			cou=cou2;
	}

	if(cou<10e7)
		cout<<cou<<endl;
	else
		cout<<"Impossible"<<endl;
}

int main()
{
	char c;

	while(cin>>c)
	{
		memset(ans1,0,sizeof(ans1));
		memset(ans2,0,sizeof(ans2));
		memset(map1,0,sizeof(map1));

		map1[1][1]=c=='b'?1:0;

		for(int i=2;i<=4;++i)
		{
			cin>>c;
			map1[1][i]=c=='b'?1:0;
		}

		for(int i=2;i<=4;++i)
			for(int j=1;j<=4;++j)
			{
				cin>>c;
				map1[i][j]=c=='b'?1:0;
			}

		solve();
	}

	return 0;
}
