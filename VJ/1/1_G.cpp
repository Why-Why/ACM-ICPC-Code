#include<iostream>
#include<cstring>

using namespace std;

char End[210];
char Sta[210];
int Snum[210];
int C;

void change()
{
	for(int i=1;i<=2*C;++i)
		if(Snum[i]<=C)
			Snum[i]*=2;
		else
			Snum[i]=(Snum[i]-C)*2-1;
}

bool judge()
{
	for(int i=1;i<=C*2;++i)
		if(End[Snum[i]-1]!=Sta[i-1])
			return 0;

	return 1;
}

void slove()
{
	for(int i=1;i<=2*C;++i)
		Snum[i]=i;

	int ans=1;

	change();

	while(Snum[1]!=1)
	{
		if(judge())
		{
			cout<<ans<<endl;
			return;
		}

		change();
		++ans;
	}

	if(judge())
		cout<<ans<<endl;
	else
		cout<<-1<<endl;
}

int main()
{
	ios::sync_with_stdio(false);

	int T;
	char temp[110];
	cin>>T;

	for(int cas=1;cas<=T;++cas)
	{
		cin>>C;
		cin>>Sta;
		cin>>temp;
		strcat(Sta,temp);
		cin>>End;

		cout<<cas<<' ';
		slove();
	}

	return 0;
}
