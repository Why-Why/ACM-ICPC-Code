#include<iostream>
#include<cstring>

using namespace std;

int trie[100005][20];
int rem[100005];
int n;
char s[20];
int cou;

bool build()
{
	int L=strlen(s);
	int p=0;
	bool ok=0;

	for(int i=0;i<L;++i)
	{
		if(trie[p][s[i]-'0']==0)
		{
			ok=1;
			trie[p][s[i]-'0']=++cou;
		}

		p=trie[p][s[i]-'0'];

		if(ok==0 && rem[p])
			return 0;
	}

	rem[p]=1;

	return ok;
}

int main()
{
	ios::sync_with_stdio(false);

	int T;
	bool ok;
	cin>>T;

	while(T--)
	{
		cin>>n;
		ok=1;
		memset(trie,0,sizeof(trie));
		memset(rem,0,sizeof(rem));
		cou=0;

		for(int i=1;i<=n;++i)
		{
			cin>>s;

			if(ok==0)
				continue;

			if(build()==0)
				ok=0;
		}

		if(ok)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}


	return 0;
}
