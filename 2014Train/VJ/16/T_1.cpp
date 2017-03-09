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

const int MaxN=2000006;

char Mt[MaxN*2];
int Mp[MaxN*2];

int Manacher(int len,char s[])
{
	int Mx=0,id=0,l=0;
	int ret=0;

	Mt[l++]='$';
	Mt[l++]='#';

	for(int i=0;i<len;++i)
	{
		Mt[l++]=s[i];
		Mt[l++]='#';
	}

	Mt[l]=0;

	for(int i=1;i<l;++i)
	{
		if(Mx>i)
			Mp[i]=min(Mp[2*id-i],Mx-i);
		else
			Mp[i]=1;

		while(Mt[i+Mp[i]]==Mt[i-Mp[i]])
			++Mp[i];

		if(Mp[i]+i>Mx)
		{
			Mx=Mp[i]+i;
			id=i;
		}

		if(Mp[i]-1>ret)
			ret=Mp[i]-1;
	}

	return ret;
}

struct Trie
{
	int qian,hou;
	int qend,hend;
};

struct Edge
{
	int to,next;
	char c;
};

Edge E[MaxN*4];
int head[3*MaxN],Ecou;
Trie sta[3*MaxN];

int slen;
char s[MaxN];

void insert()
{
	Trie *t=root;

	for(int i=0;i<slen;++i)
	{
		if(t->next1[s[i]-'a']==0)
			t->next1[s[i]-'a']=&sta[++Tcou];

		t=t->next1[s[i]-'a'];

		if(Mp[i+slen+2]+i==slen)
			++(t->qian);
	}

	++(t->qend);

	t=root;

	for(int i=slen-1;i>=0;--i)
	{
		if(t->next1[s[i]-'a']==0)
			t->next1[s[i]-'a']=&sta[++Tcou];

		t=t->next1[s[i]-'a'];

		if(Mp[i+1]-1==i)
			++(t->hou);
	}

	++(t->hend);
}

long long getans()
{
	long long ret=0;
	bool ok;
	Trie *p=root;

	ok=1;

	for(int i=0;i<slen;++i)
	{
		if(p->next1[s[i]-'a']==0)
		{
			ok=0;
			break;
		}

		p=p->next1[s[i]-'a'];
		
		if(i!=slen-1 && Mp[i+slen+2]+i==slen)
			ret+=p->hend;
	}

	if(ok)
		ret+=p->hou;

	p=root;
	ok=1;

	for(int i=slen-1;i>=0;--i)
	{
		if(p->next1[s[i]-'a']==0)
		{
			ok=0;
			break;
		}

		p=p->next1[s[i]-'a'];

		if(i && Mp[i+1]-1==i)
			ret+=p->qend;
	}

	if(ok)
		ret+=p->qian;

	return ret;
}

void show(Trie *p,int dep)
{
	for(int i=0;i<26;++i)
		if(p->next1[i])
		{
			cout<<dep<<' ';
			cout<<char('a'+i)<<'|'<<(p->next1[i]->qian)<<'|'<<(p->next1[i]->hou)<<endl;
			show(p->next1[i],dep+1);
		}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int n;
	int temp;
	long long ans=0;
	
	scanf("%d",&n);

	for(int i=0;i<n;++i)
	{
		scanf("%d %s",&slen,s);

		temp=Manacher(slen,s);
		ans+=getans();

		if(temp==slen)
			++ans;

		insert();
	}

	cout<<ans<<endl;
	
	return 0;
}
