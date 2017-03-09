#include<iostream>
#include<cstdio>
#include<cstring>
#include<utility>

using namespace std;

int que[10000000],las,fir;

void showans(int x)
{
	int ans[500];
	int cou=0;

	while(x)
	{
		if(x&1)
			ans[cou++]=1;
		else
			ans[cou++]=0;

		x=x>>1;
	}

	for(int i=cou-1;i>=0;--i)
		cout<<ans[i];

	cout<<endl;
}

inline void getans(int n)
{
	las=fir=0;

	int cou=0;
	int temp;

	que[las++]=1;
	
	while(las-fir)
	{
		++cou;
		temp=que[fir++];

		if(!temp)
		{
			showans(cou);
			return;
		}

		que[las++]=(temp*10)%n;
		que[las++]=(temp*10+1)%n;
	}
}

int main()
{
	ios::sync_with_stdio(false);

	int n;

	for(cin>>n;n;cin>>n)
	{
		getans(n);
	}

	return 0;
}
