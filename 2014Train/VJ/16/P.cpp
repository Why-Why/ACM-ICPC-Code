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

struct state
{
	unsigned long long n[2];
	int len;

	void debug()
	{
		cout<<len<<' ';
		
		for(int i=0;i<len;++i)
		{
			if(i<=50)
				cout<<((n[0]&(1LL<<i))!=0);
			else
				cout<<((n[1]&(1LL<<(i-51)))!=0);

			if(i==50)
				cout<<'|';
		}

		cout<<endl;
	}

	void getmin()
	{
		state temp=*this;
		state minn=temp;
		bool ok;
		
		for(int i=0;i<len;++i)
		{
			if(len<=51)
			{
				if(temp.n[0]&1)
					temp.n[0]=(temp.n[0]>>1LL)|(1LL<<(len-1));
				else
					temp.n[0]=(temp.n[0]>>1LL);
			}
			else
			{
				if(temp.n[0]&1)
					ok=1;
				else
					ok=0;

				temp.n[0]>>=1LL;

				if(temp.n[1]&1)
					temp.n[0]+=(1LL<<50LL);

				temp.n[1]>>=1LL;

				if(ok)
					temp.n[1]+=(1LL<<(len-52LL));
			}

	//		temp.debug();

			if(temp<minn)
				minn=temp;
		}

		*this=minn;

	//	this->debug();
	}

	state()
	{
		n[0]=n[1]=0;
		len=0;
	}

	state(char *s)
	{
		n[0]=n[1]=0;

		len=strlen(s);

		for(int i=0;i<len;++i)
			if(s[i]=='1')
				if(i<=50)
					n[0]+=(1LL<<i);
				else
					n[1]+=(1LL<<(i-51));

		getmin();
	}

	bool operator < (const state &x) const
	{
		if(len!=x.len)
			return len<x.len;

		if(n[1]!=x.n[1])
			return n[1]<x.n[1];

		return n[0]<x.n[0];
	}
};

char s[110];
int n;
state sta[10004];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d",&n))
	{
		for(int i=1;i<=n;++i)
		{
			scanf("%s",s);

			sta[i]=state(s);
		}

//		for(int i=1;i<=n;++i)
//			cout<<sta[i].n[0]<<' '<<sta[i].n[1]<<endl;

		sort(sta+1,sta+n+1);

		int ans=1;

		for(int i=2;i<=n;++i)
			if(sta[i-1]<sta[i])
				++ans;

		printf("%d\n",ans);
	}
	
	return 0;
}
