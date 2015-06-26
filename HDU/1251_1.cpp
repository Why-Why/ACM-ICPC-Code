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

const int MaxN=1000000;

struct Trie
{
	char ch[MaxN];
	int val[MaxN];
	int next[MaxN],right[MaxN];
	int Tcou;

	void init()
	{
		Tcou=0;
		val[0]=0;
		next[0]=right[0]=-1;
	}

	void insert(int len,char s[])
	{
		bool ok;
		int u=0,v;

		for(int i=0;i<len;++i)
		{
			ok=0;

			for(v=next[u];v!=-1;v=right[v])
			{
				if(ch[v]==s[i])
				{
					ok=1;
					break;
				}
			}

			if(!ok)
			{
				v=++Tcou;
				right[v]=next[u];
				next[u]=v;
				next[v]=-1;
				ch[v]=s[i];
				val[v]=0;
			}

			u=v;
		}

		++val[u];
	}

	int match(int len,char s[])
	{
		bool ok=0;
		int u=0,v;

		for(int i=0;i<len;++i)
		{
			ok=0;

			for(v=next[u];v!=-1;v=right[v])
			{
				if(ch[v]==s[i])
				{
					ok=1;
					break;
				}
			}

			if(!ok)
				return 0;

			u=v;
		}

		return val[u];
	}
};

char s[MaxN];
Trie trie;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	trie.init();

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
