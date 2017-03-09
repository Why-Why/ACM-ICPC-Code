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

char s[MaxN];
int node[MaxN][26];
int fnode[MaxN][26];
int cou=0;
int slen;

void maketrie()
{
	int p=0;

	for(int i=slen-1;i>=0;--i)
	{
		if(node[p][s[i]-'a']==0)
			node[p][s[i]-'a']=++cou;
		
		if(Mp[i+1]-1==i)
			++fnode[p][s[i]-'a'];

		p=node[p][s[i]-'a'];
	}

	p=0;

	for(int i=0;i<slen;++i)
	{
		if(node[p][s[i]-'a']==0)
			node[p][s[i]-'a']=++cou;

		if(Mp[i+slen+2]-1==slen-i-1)
			++fnode[p][s[i]-'a'];

		p=node[p][s[i]-'a'];
	}
}

long long getans()
{
	int p=0;

	for(int i=0;i<slen-1;++i)
	{
		if(node[p][s[i]-'a']==0)
			return 0;

		p=node[p][s[i]-'a'];
	}

	return fnode[p][s[slen-1]-'a'];
}

void show()
{
	for(int j=0;j<=cou;++j,cout<<endl)
		for(int i=0;i<26;++i)
			cout<<node[j][i]<<'|'<<fnode[j][i]<<' ';
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int n;
	int len;
	int temp;
	long long ans=0;

	scanf("%d",&n);

	for(int i=1;i<=n;++i)
	{
		scanf("%d %s",&slen,s);

		temp=Manacher(slen,s);

		ans+=getans();
		maketrie();

		if(temp==slen)
			++ans;

		cout<<ans<<endl;
		show();

		cout<<endl<<endl;
	}

//	show();

	cout<<ans<<endl;
	
	return 0;
}
