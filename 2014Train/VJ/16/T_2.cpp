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

const int MaxN=2000010;

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

	Mt[l++]=0;

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

int slen,zlen;
char s[MaxN];
char zs[MaxN*2];
int zp=0;

int next1[MaxN][26];
int end[MaxN],val[MaxN];
int Tcou=0;

void insert()
{
	int p=0;

	for(int i=slen-1;i>=0;--i)
	{
		if(next1[p][s[i]-'a']==0)
		{
			next1[p][s[i]-'a']=++Tcou;
			memset(next1[Tcou],0,sizeof(next1[Tcou]));
			end[Tcou]=val[Tcou]=0;
		}

		p=next1[p][s[i]-'a'];

		if(Mp[i+1]-1==i)
			++val[p];
	}

	++end[p];
}

long long getans()
{
	int p=0;
	bool ok;
	long long ret=0;

	ok=1;

	for(int i=0;i<slen;++i)
	{
		if(next1[p][s[i]-'a']==0)
		{
			ok=0;
			break;
		}

		p=next1[p][s[i]-'a'];

		if(i!=slen-1 && Mp[i+slen+2]+i==slen)
			ret+=end[p];
	}

	if(ok)
		ret+=val[p];

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int n;
	long long ans;

	while(~scanf("%d",&n))
	{
		Tcou=0;
		zlen=0;
		zp=0;
		ans=0;
		memset(next1[0],0,sizeof(next1[0]));
		end[0]=val[0]=0;
	
		while(n--)
		{
			scanf("%d %s",&slen,s);

			for(int i=0;i<slen;++i,++zlen)
				zs[zlen]=s[i];
			zs[zlen++]='@';

			Manacher(slen,s);
			insert();
		}

		zs[zlen]=0;

		while(zp<zlen)
		{
			slen=0;
	
			for(int i=0;zs[zp+i]!='@';++i,++slen)
				s[i]=zs[zp+i],s[i+1]=0;

			Manacher(slen,s);
			ans+=getans();

			zp=zp+slen+1;
		}

		cout<<ans<<endl;
	}
	
	return 0;
}
