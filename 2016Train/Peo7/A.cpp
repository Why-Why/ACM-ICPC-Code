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
// Created Time  : 2016年05月01日 星期日 12时55分01秒
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

bool OK;

// 高精度。
// 输入：scan，=。
// 输出：print，getNum。
// 运算：+，＊，-，/，%，> 。
// 不支持负数。

class BigNum
{
	public:
		const static int MaxL=1004;
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

	OK=0;

	for(int i=len-1;i>=0;--i)
	{
		ret.num[i]=(num[i]+down*Mod)/b;
		down=num[i]+down*Mod-ret.num[i]*b;
	}

	if(down) OK=1;

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

const int MaxN=1005;

BigNum A,B,X,Y;
int N;
int a[MaxN],b[MaxN],x[MaxN],y[MaxN];

bool judge(int k) {
	for(int i=0;i<N;++i)
		if((a[i]^b[i])!=(x[(i+k)%N]^y[(i+k)%N])) return 0;
	return 1;
}

bool judge() {
	for(int i=0;i<N;++i) if(judge(i)) return 1;
	return 0;
}

inline void chu(BigNum & t,int num[]) {
	for(int i=0;i<N;++i) num[i]=0;
	int cou=N-1;
	while(t>0) {
		t=t/2;
		num[cou--]=OK;
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	scanf("%d",&T);

	while(T--) {
		scanf("%d",&N);
		A.scan();
		X.scan();
		B.scan();
		Y.scan();
		A=A-1;
		X=X-1;
		B=B-1;
		Y=Y-1;

		chu(A,a);
		chu(B,b);
		chu(X,x);
		chu(Y,y);

		printf("Case %d: ",cas++);
		if(judge()) puts("Yes");
		else puts("No");
	}
	
	return 0;
}
