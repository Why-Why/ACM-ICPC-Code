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
const int MaxL=100000*8;

struct Trie
{
	int next[MaxC];
	int num;
	int word;
};

Trie T[MaxL];
int Tp;

void Init_Trie()
{
	Tp=0;
	T[0].num=0;
	T[0].word=-1;

	for(int i=0;i<MaxC;++i)
		T[0].next[i]=-1;
}

void Insert(char s[],int flag)
{
	int p=0;

	for(int i=0;s[i];++i)
	{
		if(T[p].next[s[i]-'a']==-1)
		{
			++Tp;
			
			T[Tp].num=0;
			T[Tp].word=-1;
			for(int j=0;j<MaxC;++j)
				T[Tp].next[j]=-1;

			T[p].next[s[i]-'a']=Tp;
		}

		p=T[p].next[s[i]-'a'];
		++T[p].num;
	}

	T[p].word=flag;
}

int Query(char s[])
{
	int p=0;

	for(int i=0;s[i];++i)
	{
		if(T[p].next[s[i]-'a']==-1)
			return -1;

		p=T[p].next[s[i]-'a'];
	}

	return T[p].word;
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
	
	return 0;
}
