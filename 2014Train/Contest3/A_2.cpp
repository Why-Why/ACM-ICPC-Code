// ━━━━━━神兽出没━━━━━━
//      ┏┓       ┏┓
//     ┏┛┻━━━━━━━┛┻┓
//     ┃           ┃
//     ┃     ━     ┃
//     ████━████   ┃
//     ┃           ┃
//     ┃    ┻      ┃
//     ┃           ┃
//     ┗━┓       ┏━┛
//       ┃       ┃
//       ┃       ┃
//       ┃       ┗━━━┓
//       ┃           ┣┓
//       ┃           ┏┛
//       ┗┓┓┏━━━━━┳┓┏┛
//        ┃┫┫     ┃┫┫
//        ┗┻┛     ┗┻┛
//
// ━━━━━━感觉萌萌哒━━━━━━

// Author        : WhyWhy
// Created Time  : 2015年10月10日 星期六 17时22分42秒
// File Name     : A_2.cpp

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

class BigNum
{
	public:
		const static int MaxL=200;
		const static int Mod=10000;
		const static int Dlen=4;

		int num[MaxL/Dlen+1],len;

		void changeStoNum(const char *);

	public:
		BigNum() { len=1; memset(num,0,sizeof(num)); }
		BigNum(int);
		BigNum(const char *s) { changeStoNum(s); }

		BigNum operator + (const BigNum &) const;
		BigNum operator - (const BigNum &) const;
		BigNum operator * (const BigNum &) const;
		BigNum operator / (const int) const;
		bool operator < (const BigNum &a) const;
		int operator % (const int m) const;

		bool scan();
		void print();
};

BigNum::BigNum(int x)
{
	memset(num,0,sizeof(num));
	len=0;

	do
	{
		num[len++]=x-(x/Mod)*Mod;
		x/=Mod;

	}while(x);
}

void BigNum::changeStoNum(const char *x)
{
	int L=strlen(x);
	int temp,tp;
	int p=0;

	memset(num,0,sizeof(num));
	len=(L-1)/Dlen+1;

	for(int i=L-1;i>=0;i-=Dlen)
	{
		temp=0;
		tp=i-Dlen+1;

		if(tp<0)
			tp=0;

		for(int j=tp;j<=i;++j)
			temp=(temp<<3)+(temp<<1)+x[j]-'0';

		num[p++]=temp;
	}

	while(num[len-1]==0 && len>1)
		--len;
}

bool BigNum::scan()
{
	char x[MaxL];

	if(scanf("%s",x)==-1)
		return 0;

	changeStoNum(x);
}

void BigNum::print()
{
	printf("%d",num[len-1]);
	for(int i=len-2;i>=0;--i)
		printf("%04d",num[i]);
}

BigNum BigNum::operator + (const BigNum &b) const
{
	BigNum ret(*this);

	int L=max(b.len,len);

	for(int i=0;i<L;++i)
	{
		ret.num[i]+=b.num[i];

		if(ret.num[i]>=Mod)
		{
			++ret.num[i+1];
			ret.num[i]-=Mod;
		}
	}

	ret.len=L;

	if(ret.num[L])
		++ret.len;

	return ret;
}

BigNum BigNum::operator - (const BigNum &b) const		// 不支持负数，一定要是a>b。
{
	int L=this->len;
	int p;
	BigNum ret(*this);

	for(int i=0;i<L;++i)
	{
		if(ret.num[i]<b.num[i])
		{
			p=i+1;

			while(!ret.num[p])
				++p;

			--ret.num[p--];

			while(p>i)
				ret.num[p--]=Mod-1;

			ret.num[i]+=Mod-b.num[i];
		}
		else
			ret.num[i]-=b.num[i];
	}

	while(!ret.num[ret.len-1] && ret.len>1)
		--ret.len;

	return ret;
}

BigNum BigNum::operator * (const BigNum &b) const
{
	BigNum ret;
	int temp;

	ret.len=len+b.len;

	for(int i=0;i<len;++i)
		for(int j=0;j<b.len;++j)
		{
			ret.num[i+j]+=num[i]*b.num[j];

			if(ret.num[i+j]>=Mod)
			{
				temp=ret.num[i+j]/Mod;
				ret.num[i+j+1]+=temp;
				ret.num[i+j]-=temp*Mod;
			}
		}

	while(ret.num[ret.len-1]==0 && ret.len>1)
		--ret.len;

	return ret;
}

BigNum BigNum::operator / (const int b) const
{
	BigNum ret;
	int down=0;

	for(int i=len-1;i>=0;--i)
	{
		ret.num[i]=(num[i]+down*Mod)/b;
		down=num[i]+down*Mod-ret.num[i]*b;
	}

	ret.len=len;

	while(ret.num[ret.len-1]==0 && ret.len>1)
		--ret.len;

	return ret;
}

int BigNum::operator % (const int b) const
{
	int ret=0;

	for(int i=len-1;i>=0;--i)
		ret=((ret*Mod)%b+num[i])%b;

	return ret;
}

bool BigNum::operator < (const BigNum &b) const
{
	if(len!=b.len)
		return len<b.len;

	for(int i=len-1;i>=0;--i)
		if(num[i]!=b.num[i])
			return num[i]<b.num[i];

	return 0;
}

/////////////////////////////////////

const int MaxN=710;

struct Edge
{
	int to,next;
};

Edge E[MaxN<<1];
int head[MaxN],Ecou;

int N;

BigNum dp[MaxN][5];

void init()
{
	Ecou=0;
	memset(head,-1,sizeof(head));
}

void addEdge(int u,int v)
{
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

bool cmp(int a,int b)
{
	return dp[a][1]*dp[b][0]<dp[b][1]*dp[a][0];
}

bool cmp1(int a,int b)
{
	return dp[a][2]*dp[b][0]<dp[b][2]*dp[a][0];
}

int dfs(int u,int pre)
{
	int rem1=-1,rem2=-1,rem3=-1;
	int cou=0;
	int size=1;

	dp[u][1]=1;
	dp[u][4]=0;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre)
		{
			++cou;
			size+=dfs(E[i].to,u);
			dp[u][1]=dp[u][1]*dp[E[i].to][0];

			if(rem1==-1 || cmp(rem1,E[i].to))
			{
				rem2=rem1;
				rem1=E[i].to;
			}
			else if(rem2==-1 || cmp(rem2,E[i].to))
				rem2=E[i].to;

			if(rem3==-1 || cmp1(rem3,E[i].to))
				rem3=E[i].to;
		}

	BigNum m1=1,m2=1,m3=1;
	int v;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre)
		{
			v=E[i].to;
			if(v!=rem1) m1=m1*dp[v][0];
			if(v!=rem2 && v!=rem1) m2=m2*dp[v][0];
			if(v!=rem3) m3=m3*dp[v][0];
		}

	if(cou) dp[u][2]=m1*dp[rem1][1]*2;
	else dp[u][2]=0;
	if(cou>1) dp[u][3]=m2*dp[rem1][1]*dp[rem2][1]*3;
	else dp[u][3]=0;
	dp[u][4]=m3*dp[rem3][2]/2*3;

	dp[u][0]=size;
	for(int i=1;i<5;++i)
		if(dp[u][0]<dp[u][i])
			dp[u][0]=dp[u][i];

	return size;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b;
	scanf("%d",&N);
	init();
	for(int i=1;i<N;++i)
	{
		scanf("%d %d",&a,&b);
		addEdge(a,b);
		addEdge(b,a);
	}

	dfs(1,-1);

	dp[1][0].print();
	puts("");
	
	return 0;
}
