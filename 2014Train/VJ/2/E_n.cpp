#include<iostream>
#include<cstring>

using namespace std;

const char step[]="ACGT";

char num[10][10];
int N;
unsigned int Enum;
int Deep;

int getH1(unsigned int x)
{
	int t1,t2;
	int maxn=-100;

	for(int i=0;i<N;++i)
	{
		t1=((Enum>>(i*4))&15);
		t2=((x>>(i*4))&15);

		maxn=max(t1-t2,maxn);
	}

	return maxn;
}

int getH(unsigned int x)
{
	int ans[4]={-10,-10,-10,-10};
	int temp[4];
	int t1,t2;

	for(int i=0;i<N;++i)
	{
		temp[0]=temp[1]=temp[2]=temp[3]=0;
		
		t1=((x>>(i*4))&15);
		t2=((Enum>>(i*4))&15);

		for(int j=t1;j<t2;++j)
		{
			if(num[i][j]=='A')
				++temp[0];
			else if(num[i][j]=='C')
				++temp[1];
			else if(num[i][j]=='G')
				++temp[2];
			else
				++temp[3];
		}

		for(int j=0;j<4;++j)
			ans[j]=max(ans[j],temp[j]);
	}

	return ans[0]+ans[1]+ans[2]+ans[3];
}

bool judge(int x,unsigned int &Ea)
{
	bool ok=0;
	int t1;

	for(int i=0;i<N;++i)
	{
		t1=((Ea>>(i*4))&15);

		if(num[i][t1]==step[x])
		{
			ok=1;
			Ea+=(1<<(i*4));
		}
	}

	return ok;
}

bool dfs(int D,unsigned int sta)
{
	int H=getH(sta);
	unsigned int temp=sta;

	if(D+H>Deep)
		return 0;

	if(sta==Enum)
		return 1;

	for(int i=0;i<4;++i)
		if(judge(i,sta))
		{
			if(dfs(D+1,sta))
				return 1;

			sta=temp;
		}

	return 0;
}

int solve()
{
	Deep=1;

	while(!dfs(0,0))
		++Deep;

	cout<<Deep<<endl;
}

int main()
{
	ios::sync_with_stdio(false);

	int T;
	cin>>T;

	while(T--)
	{
		cin>>N;
		Enum=0;

		for(int i=0;i<N;++i)
		{
			cin>>num[i];
			Enum+=strlen(num[i])*(1<<4*i);
		}

		solve();
	}

	return 0;
}
