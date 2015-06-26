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

const int MaxNode=1000000;

struct Trie
{
	int next[MaxNode][26];
	vector <int> val[MaxNode];
	int Tcou,root;

	int newNode()
	{
		++Tcou;
		memset(next[Tcou],0,sizeof(next[Tcou]));
		val[Tcou].clear();

		return Tcou;
	}

	Trie()
	{
		Tcou=-1;
		root=newNode();
	}

	void insert(int len,char s[],int num)
	{
		int p=root;

		for(int i=0;i<len;++i)
		{
			if(next[p][s[i]-'a']==0)
				next[p][s[i]-'a']=newNode();

			p=next[p][s[i]-'a'];
		}

		val[p].push_back(num);
	}

	int match(int len,char s[])
	{
		int p=root;

		for(int i=0;i<len;++i)
		{
			if(next[p][s[i]-'a']==0)
				return 0;

			p=next[p][s[i]-'a'];
		}

		return p;
	}

	void insert1(int len,char s[],int num)
	{
		int p=0;

		for(int i=len-1;i>=0;--i)
		{
			if(next[p][s[i]-'a']==0)
				next[p][s[i]-'a']=newNode();

			p=next[p][s[i]-'a'];
		}

		val[p].push_back(num);
	}
};

int n,m;
char s[1000000];
Trie tree1,tree2;

bool getans()
{
	int len=strlen(s);
	int p1,p2;

	p1=tree1.match(len,s);
	p2=tree2.match(len,s);

	cout<<p1<<endl<<p2<<endl;

	sort(tree1.val[p1].begin(),tree1.val[p1].end());
	sort(tree2.val[p2].begin(),tree2.val[p2].end());

	int L1=tree1.val[p1].size(),L2=tree2.val[p2].size();
	int t1=0,t2=0;

	while(t1<L1 && t2<L2)
	{
		if(tree1.val[p1][t1]==tree2.val[p2][t2])
			return 1;
		else if(tree1.val[p1][t1]<tree2.val[p2][t2])
			++t1;
		else
			++t2;
	}

	return 0;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d",&n,&m);

	for(int i=1;i<=n;++i)
	{
		scanf("%s",s);
		int len=strlen(s);
		tree1.insert(len,s,i);
		tree2.insert1(len,s,i);
	}

	while(m--)
	{
		scanf("%s",s);

		if(getans())
			printf("YES\n");
		else
			printf("NO\n");
	}
	
	return 0;
}
