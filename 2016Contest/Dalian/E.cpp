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
// Created Time  : 2016年11月13日 星期日 18时16分38秒
// File Name     : E.cpp

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
		const static int MaxL=40;
		const static int Mod=10000;
		const static int Dlen=4;

		int num[MaxL/Dlen+1],len;

		void changeStoNum(const char *);

	public:
		BigNum() { len=1; memset(num,0,sizeof(num)); }
		BigNum(long long);
		BigNum(const char *s) { changeStoNum(s); }

		BigNum operator + (const BigNum &) const;
		BigNum operator - (const BigNum &) const;
		BigNum operator * (const BigNum &) const;
		BigNum operator / (const int) const;
		bool operator > (const BigNum &a) const;
		int operator % (const int m) const;

		void scan();
		void print();
};

BigNum::BigNum(long long x)
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
}

void BigNum::scan()
{
	char x[MaxL];

	scanf("%s",x);
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

////////////////////////////

long long N;
BigNum tans;

inline long long getN(long long M,long long p) {
	long long t=M>>(p+1);
	if(((t<<(p+1))|(1LL<<p))<=M) ++t;

	return t;
}

inline int getW(long long x) {
	int ret=0;
	for(;!(x&1);x>>=1) ++ret;
	return ret;
}

inline long long getD(long long x,long long p) {
	long long t=x>>(p+1),tt;

	tt=(t<<(p+1))|(1LL<<p);
	if(tt>=x) return tt;

	++t;
	tt=(t<<(p+1))|(1LL<<p);
	return tt;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int Q;
	long long a,b,c,t,ans;

	while(~scanf("%lld %d",&N,&Q)) {
		while(Q--) {
			scanf("%lld %lld",&a,&b);
			if(a==1) {
				scanf("%lld",&c);
				//ans=0;
				tans=0LL;

				for(int i=0;i<61;++i) {
					t=getN(c,i)-getN(b-1,i);
					//cerr<<"# "<<t<<' '<<(1LL<<i)*t<<endl;
					//ans+=(1LL<<i)*t;
					tans=tans+(1LL<<i)*t;
				}

				//printf("%lld\n",tans);
				tans.print();
				puts("");
			}
			else {
				ans=0;

				for(int i=getW(b);i<61;++i) {
					t=getD(b,i);
					if(t<=N && t-b+1<=(1LL<<i)) ++ans;
				}

				printf("%lld\n",ans);
			}
		}
	}

	return 0;
}
