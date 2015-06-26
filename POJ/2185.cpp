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

const int MaxR=10004;
const int MaxC=80;

int next1[MaxR];
int next2[MaxC];
int R,C;

bool equal(char a[],char b[],int len)
{
	for(int i=0;i<len;++i)
		if(a[i]!=b[i])
			return 0;

	return 1;
}

void EKMP_pre1(int m,char s[][MaxC],int next[])
{
	int p=0,a=1,L;

	next[0]=m;
	while(p+1<m && equal(s[p],s[p+1],C))
		++p;
	next[1]=p;

	for(int k=2;k<m;++k)
	{
		L=next[k-a];
		p=next[a]+a-(next[a]!=0);

		if(k+L-1<p)
			next[k]=L;
		else
		{
			++p;
			while(p<m && equal(s[p],s[p-k],C))
				++p;

			next[k]=p-k;
			a=k;
		}
	}
}

void EKMP_pre2(int m,char s[][MaxR],int next[])
{
	int p=0,a=1,L;

	next[0]=m;
	while(p+1<m && equal(s[p],s[p+1],R))
		++p;
	next[1]=p;

	for(int k=2;k<m;++k)
	{
		L=next[k-a];
		p=next[a]+a-(next[a]!=0);

		if(k+L-1<p)
			next[k]=L;
		else
		{
			++p;
			while(p<m && equal(s[p],s[p-k],R))
				++p;

			next[k]=p-k;
			a=k;
		}
	}
}

char s1[MaxR][MaxC];
char s2[MaxC][MaxR];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d",&R,&C);

	getchar();
	for(int i=0;i<R;++i,getchar())
		for(int j=0;j<C;++j)
			s1[i][j]=s2[j][i]=getchar();

	EKMP_pre1(R,s1,next1);
	EKMP_pre2(C,s2,next2);

	int len1=R,len2=C;

	for(int i=1;i<R;++i)
		if(next1[i]+i==R)
		{
			len1=i;
			break;
		}

	for(int i=1;i<C;++i)
		if(next2[i]+i==C)
		{
			len2=i;
			break;
		}

	cout<<len1*len2<<endl;
	
	return 0;
}
