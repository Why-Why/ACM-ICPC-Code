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

unsigned long long a,b,c;
int A[70],B[70],C[70];

void c10to2(unsigned long long x,int s[])
{
	int p=0;

	while(x)
	{
		s[p++]=(x&1);
		x>>=1;
	}
}

unsigned long long c2to10(int s[])
{
	unsigned long long base=1,ans=0;

	for(int i=0;i<64;++i)
	{
		ans+=s[i]*base;
		base*=2;
	}

	return ans;
}

void getans(int x)
{
	bool ok=1;

	for(int i=x;i>=0;--i)
		if(!B[i])
		{
			ok=0;
			break;
		}

	if(ok)
		C[x]=1;
	else
		C[x]=0;

	for(int i=x-1;i>=0;--i)
		C[i]=1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int la,lb;

	while(cin>>a>>b)
	{
		memset(A,0,sizeof(A));
		memset(B,0,sizeof(B));

		c10to2(a,A);
		c10to2(b,B);

		for(int i=63;i>=0;--i)
			if(A[i]==B[i])
				C[i]=A[i];
			else
			{
				getans(i);
				break;
			}

		cout<<c2to10(C)<<endl;
	}

	return 0;
}
