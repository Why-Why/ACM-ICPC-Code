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
// Created Time  : 2015年10月06日 星期二 10时28分17秒
// File Name     : A.cpp

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

const int MaxN=710;

struct Edge
{
	int to,next;
};

Edge E[MaxN<<1];
int head[MaxN],Ecou;
int val[MaxN];

int du[MaxN];

int N;

void init()
{
	Ecou=0;
	memset(head,-1,sizeof(head));
}

void addEdge(int u,int v)
{
	++du[v];
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

int cou=0;
int ans[MaxN];

int dfs(int u,int pre)
{
	int size=0;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre)
			size+=dfs(E[i].to,u);

	if(val[u]==1 && pre!=-1) ++val[pre];
	else if(val[u]==2 && pre!=-1 && val[pre]==1 && N-size-1>1) val[pre]+=2;
	else ans[cou++]=val[u];

	return size+1;
}


// 高精度。
// 输入：scan，=。
// 输出：print，getNum。
// 运算：+，＊，-，/，%，> 。
// 不支持负数。

class BigNum
{
	public:
		const static int MaxL=300;
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
		bool operator > (const BigNum &a) const;
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

bool BigNum::operator > (const BigNum &b) const
{
	if(len!=b.len)
		return len>b.len;

	for(int i=len-1;i>=0;--i)
		if(num[i]!=b.num[i])
			return num[i]>b.num[i];

	return 0;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d",&N);

	int a,b;
	init();
	for(int i=1;i<=N;++i) val[i]=1;

	for(int i=1;i<N;++i)
	{
		scanf("%d %d",&a,&b);
		addEdge(a,b);
		addEdge(b,a);
	}

	if(N==1)
	{
		puts("1");
		return 0;
	}

	for(int i=1;i<=N;++i)
		if(du[i]>1)
		{
			dfs(i,-1);
			break;
		}

	BigNum zans=1;
	for(int i=0;i<cou;++i) zans=zans*ans[i];
	zans.print();
	puts("");
	
	return 0;
}
