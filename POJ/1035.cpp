#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
	
using namespace std;

const int MaxN=160000;
const int MaxC=26;

struct Trie
{
	int next[MaxN][MaxC];
	int end[MaxN];
	int Tcou,root;

	int newNode()
	{
		++Tcou;

		memset(next[Tcou],0,sizeof(next[Tcou]));
		end[Tcou]=0;

		return Tcou;
	}

	void init()
	{
		Tcou=-1;
		root=newNode();
	}

	void insert(char s[],int id)
	{
		int p=0;

		for(int i=0;s[i];++i)
		{
			if(next[p][s[i]-'a']==0)
				next[p][s[i]-'a']=newNode();

			p=next[p][s[i]-'a'];
		}

		if(!end[p])
		end[p]=id;
	}

	int match(string &s)
	{
		int p=0;
		int len=s.size();

		for(int i=0;i<len;++i)
		{
			if(next[p][s[i]-'a']==0)
				return 0;

			p=next[p][s[i]-'a'];
		}

		return end[p];
	}
};

Trie tree;
char dic[10004][30];
string rem;
string t;
int ans[10004],anscou;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	ios::sync_with_stdio(false);

	int temp;

	tree.init();

	int dp=1;

	while(cin>>dic[dp] && dic[dp][0]!='#')
	{
		tree.insert(dic[dp],dp);
		++dp;
	}

	int p=0;
	int len;

	while(cin>>rem && rem[0]!='#')
	{
		anscou=0;

		if(tree.match(rem))
		{
			cout<<rem<<" is correct\n";
			continue;
		}

		cout<<rem<<':';

		for(int k=0;k<26;++k)
		{
			t=rem+char('a'+k);

			temp=tree.match(t);

			if(temp)
				ans[anscou++]=temp;
		}

		len=rem.size();

		for(int j=0;j<len;++j)
			for(int k=0;k<26;++k)
			{
				t=rem;
				t.insert(t.begin()+j,char(k+'a'));

				temp=tree.match(t);

				if(temp)
					ans[anscou++]=temp;
			}

		for(int j=0;j<len;++j)
		{
			t=rem;
			t.erase(t.begin()+j);

			temp=tree.match(t);

			if(temp)
				ans[anscou++]=temp;
		}

		for(int j=0;j<len;++j)
			for(int k=0;k<26;++k)
			{
				t=rem;
				t[j]=char('a'+k);

				temp=tree.match(t);

				if(temp)
					ans[anscou++]=temp;
			}

		if(anscou==0)
		{
			cout<<endl;
			continue;
		}

		sort(ans,ans+anscou);

		temp=1;

		for(int i=1;i<anscou;++i)
			if(ans[i]!=ans[i-1])
				ans[temp++]=ans[i];

		for(int i=0;i<temp;++i)
			cout<<' '<<dic[ans[i]];
		cout<<endl;
	}
	
	
	return 0;
}
