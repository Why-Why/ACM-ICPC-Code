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

const int MaxC=26;

struct Trie
{
	int word;
	int num;		// 是几个字符串的前缀。
	Trie *next[MaxC];

	Trie()
	{
		word=-1;
		num=0;
		for(int i=0;i<MaxC;++i)
			next[i]=NULL;
	}
};

Trie *root;

void Init_Trie()
{
	root=new Trie;			/////
}

void Insert(char s[],int flag)
{
	Trie *p=root;

	for(int i=0;s[i];++i)
	{
		if(p->next[s[i]-'a']==NULL)
			p->next[s[i]-'a']=new Trie;

		p=p->next[s[i]-'a'];
		++(p->num);				/////
	}

	p->word=flag;

}

int Query(char s[])
{
	Trie *p=root;

	for(int i=0;s[i];++i)
	{
		if(p->next[s[i]-'a']==NULL)
			return -1;
		p=p->next[s[i]-'a'];
	}

	return p->word;
}

void Delete_Trie(Trie *r)
{
	for(int i=0;i<MaxC;++i)
		if(r->next[i])
			Delete_Trie(r->next[i]);
	
	delete r;
}

char s1[100005][12];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int t;
	char s[30];
	char s2[12];
	int i;

	Init_Trie();

	for(i=0,gets(s);s[0];gets(s),++i)
	{
		sscanf(s,"%s %s",s1[i],s2);
		Insert(s2,i);
	}

	while(gets(s))
	{
		t=Query(s);
		
		if(t==-1)
			printf("eh\n");
		else
			printf("%s\n",s1[t]);
	}

	Delete_Trie(root);
	
	return 0;
}
