#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int trie[400005][26];
char ans[100005][12];
int dui[400005];
int rem=0;
char temps[12];

int getTrie()
{
	int len=strlen(temps);
	int temp=0;

	for(int i=0;i<len;++i)
	{
		if(trie[temp][temps[i]-'a']==0)
			trie[temp][temps[i]-'a']=++rem;
	
		temp=trie[temp][temps[i]-'a'];
	}

	return temp;
}

int findTrie(char *s)
{
	int temp=0,len=strlen(s);

	for(int i=0;i<len;++i)
	{
		if(trie[temp][s[i]-'a']==0)
			return 0;

		temp=trie[temp][s[i]-'a'];
	}

	return temp;
}

int main()
{
	ios::sync_with_stdio(false);

	char s[24];

	int cou=0;

	while(cin.getline(s,23))
	{
		if(s[0]==0)
			break;

		sscanf(s,"%s %s",ans[++cou],temps);

		dui[getTrie()]=cou;
	}

	ans[0][0]='e';
	ans[0][1]='h';
	ans[0][2]=0;

	while(cin>>s)
	{
		cout<<ans[dui[findTrie(s)]]<<endl;
	}

	return 0;
}
