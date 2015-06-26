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
	int next[MaxNode][26],val[MaxNode];
	int Tcou,root;

	int newNode()
	{
		++Tcou;

		memset(next[Tcou],0,sizeof(next[Tcou]));
		val[Tcou]=0;

		return Tcou;
	}

	void init()
	{
		Tcou=-1;
		root=newNode();
	}

	Trie()
	{
		init();
	}

	void insert(int len,char s[])
	{
		int p=0;

		for(int i=0;i<len;++i)
		{
			if(next[p][s[i]-'a']==0)
				next[p][s[i]-'a']=newNode();

			p=next[p][s[i]-'a'];
			++val[p];
		}

//		++val[p];
	}

	int match(int len,char s[])
	{
		int p=0;

		for(int i=0;i<len;++i)
		{
			if(next[p][s[i]-'a']==0)
				return 0;

			p=next[p][s[i]-'a'];
		}

		return val[p];
	}
};

Trie trie;
char s[MaxNode];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(gets(s) && s[0])
	{
		trie.insert(strlen(s),s);
	}

	while(gets(s))
	{
		printf("%d\n",trie.match(strlen(s),s));
	}
	
	return 0;
}
