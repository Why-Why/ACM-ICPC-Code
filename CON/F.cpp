#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

char num[100];
char rem[20][100];

void change(int x)
{
	int cou[10]={0};
	int len=0;
	int L=strlen(rem[x-1]);

	for(int i=0;i<L;++i)
		++cou[rem[x-1][i]-'0'];

	for(int i=0;i<=9;++i)
		if(cou[i])
		{
	//		cout<<cou[i]<<i<<' ';
			if(cou[i]>=10)
			{
				rem[x][len++]=(cou[i]/10)+'0';
				cou[i]%=10;
			}

			rem[x][len++]=cou[i]+'0';

			rem[x][len++]=i+'0';
		}

	rem[x][len++]=0;

}

int solve()
{
	strcpy(rem[0],num);

	for(int i=1;i<=15;++i)
	{
		change(i);
		if(strcmp(rem[i],rem[i-1])==0)
			return i-1;

		for(int j=0;j<i;++j)
			if(strcmp(rem[i],rem[j])==0)
				return j-i;
	}

	return -1;
}

int main()
{
	ios::sync_with_stdio(false);

	int ans;

	for(cin>>num;num[0]!='-';cin>>num)
	{
		ans=solve();

		cout<<num;
		if(ans==-1)
			cout<<" can not be classified after 15 iterations"<<endl;
		else if(ans<-1)
			cout<<" enters an inventory loop of length "<<-ans<<endl;
		else if(!ans)
			cout<<" is self-inventorying"<<endl;
		else if(ans>0)
			cout<<" is self-inventorying after "<<ans<<" steps"<<endl;
	}

	return 0;
}
