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

// 高精度。
// 输入：scan，=。
// 输出：print，getNum。
// 运算：+，＊，-，/，取负号，%，> 。
// 注意：负数的话是num的每一位都是负的，不过输出时只输出一个负号。

class BigNum
{
	private:

	const static int MaxL=88;
	const static int Mod=10000;				// 数组每个元素保存 0-(Mod-1) 的值。
	const static int Dlen=4;

	int num[MaxL/Dlen+1],len;				// num的0处是最低位。

	public:

	BigNum() { len=1; memset(num,0,sizeof(num)); }
	BigNum(int);
	
	BigNum operator + (const BigNum &) const;
	BigNum operator * (const BigNum &) const;
	BigNum & operator = (const BigNum &);

	void add1()
	{
		int flag=1;
		int p=0;

		while(flag)
		{
			++num[p];
			flag=0;
			
			if(num[p]>=Mod)
			{
				num[p]-=Mod;
				flag=1;
			}

			++p;
		}

		if(num[len]>0)
			++len;
	}

	void add(const BigNum &b)
	{
		int flag=0;
		int p=0;
		int maxn=max(len,b.len);
		len=maxn;

		while(p<maxn || flag)
		{
			num[p]+=flag+b.num[p];

			flag=0;
			if(num[p]>=Mod)
			{
				num[p]-=Mod;
				flag=1;
			}

			++p;
		}

		if(num[len]>0)
			++len;
	}

	void print();
};

BigNum::BigNum(int x)
{
	memset(num,0,sizeof(num));
	len=0;

	do
	{
		num[len++]=x%Mod;
		x/=Mod;
	}while(x);
}

void BigNum::print()
{
	printf("%d",num[len-1]);

	for(int i=len-2;i>=0;--i)
		printf("%04d",abs(num[i]));
}

inline BigNum & BigNum::operator = (const BigNum &a)
{
	memset(num,0,sizeof(num));

	len=a.len;
	for(int i=0;i<len;++i)
		num[i]=a.num[i];

	return *this;
}

inline BigNum BigNum::operator + (const BigNum &a) const
{
	BigNum ret;
	
	ret.len=max(len,a.len);

	for(int i=0;i<ret.len;++i)
	{
		ret.num[i]+=num[i]+a.num[i];
		
		if(ret.num[i]>=Mod)
		{
			++ret.num[i+1];
			ret.num[i]-=Mod;
		}
	}
	if(ret.num[ret.len]>0)	++ret.len;

	return ret;
}

inline BigNum BigNum::operator * (const BigNum &a) const
{
	BigNum ret;

	ret.len=len+a.len;

	for(int i=0;i<len;++i)
		for(int j=0;j<a.len;++j)
		{
			ret.num[i+j]+=num[i]*a.num[j];
			ret.num[i+j+1]+=ret.num[i+j]/Mod;
			ret.num[i+j]%=Mod;
		}

	while(ret.num[ret.len-1]==0 && ret.len>1)	--ret.len;

	return ret;
}

int size;

struct Metrix
{
	BigNum num[110][110];

	void operator = (int x)
	{
		for(int i=1;i<=size;++i)
			for(int j=1;j<=size;++j)
				num[i][j]=0;

		if(x==1)
			for(int i=1;i<=size;++i)
				num[i][i]=1;
	}
};

const int MaxL=1000;

int MaxC;
int que[1000],first,last;
int zhuan[256];

struct AC_auto
{
	int next[MaxL][59],fail[MaxL];
	bool word[MaxL];
	int root,Tp;

	int Newnode()
	{
		for(int i=0;i<MaxC;++i)
			next[Tp][i]=-1;
		word[Tp++]=0;

		return Tp-1;
	}

	void Init(int M)
	{
		MaxC=M;
		Tp=0;
		root=Newnode();
		first=last=0;
	}

	void Insert(int s[])
	{
		int p=root;

		for(int i=0;s[i];++i)
		{
			if(next[p][zhuan[s[i]]]==-1)
				next[p][zhuan[s[i]]]=Newnode();
			p=next[p][zhuan[s[i]]];
		}

		word[p]=1;
	}

	void Build()
	{
		int p,temp;

		fail[root]=-1;
		que[last++]=root;

		while(last-first)
		{
			p=que[first++];

			for(int i=0;i<MaxC;++i)
				if(next[p][i]!=-1)
				{
					if(p==root)
						fail[next[p][i]]=root;
					else
					{
						temp=fail[p];

						while(temp!=-1)
						{
							if(next[temp][i]!=-1)
							{
								fail[next[p][i]]=next[temp][i];
								break;
							}

							temp=fail[temp];
						}

						if(temp==-1)
							fail[next[p][i]]=root;
					}

					que[last++]=next[p][i];
				}
		}
	}

	void getMet(Metrix &a)
	{
		int temp,temp1;
		bool ok;

		size=Tp;
		a=0;

		for(int i=0;i<Tp;++i)
			if(!word[i])
				for(int j=0;j<MaxC;++j)
				{
					temp=i;
					while(temp!=root && next[temp][j]==-1)
						temp=fail[temp];

					if(next[temp][j]==-1)
						temp=root;
					else
						temp=next[temp][j];

					temp1=temp;
					ok=1;

					while(temp!=-1)
					{
						if(word[temp])
						{
							ok=0;
							break;
						}

						temp=fail[temp];
					}

					if(ok)
						a.num[i+1][temp1+1].add1();
				}
	}
}myAC;

int N,M,P;
Metrix map1;
BigNum a;

inline void cheng(Metrix &a,const Metrix &b)
{
	Metrix t;
	t=0;

	for(int i=1;i<=size;++i)
		for(int j=1;j<=size;++j)
			for(int k=1;k<=size;++k)
				t.num[i][j].add(a.num[i][k]*b.num[k][j]);

	for(int i=1;i<=size;++i)
		for(int j=1;j<=size;++j)
			a.num[i][j]=t.num[i][j];
}

void powM(Metrix &a,int n)
{
	Metrix ans;
	ans=1;

	while(n)
	{
		if(n&1)
			cheng(ans,a);
		cheng(a,a);

		n>>=1;
	}

	BigNum ret=0;

	for(int i=1;i<=size;++i)
		ret.add(ans.num[1][i]);

	ret.print();
}

int s[100];
char ss[100];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int len;

	while(~scanf("%d %d %d",&N,&M,&P))
	{
		getchar();
		gets(ss);

		for(int i=0;i<N;++i)
			if(ss[i]<0)
				s[i]=ss[i]+256;
			else
				s[i]=ss[i];

		for(int i=0;i<N;++i)
			zhuan[s[i]]=i;

		myAC.Init(N);

		while(P--)
		{
			gets(ss);
			
			len=strlen(ss);

			for(int i=0;i<=len;++i)
				if(ss[i]<0)
					s[i]=ss[i]+256;
				else
					s[i]=ss[i];

			myAC.Insert(s);
		}

		myAC.Build();
		myAC.getMet(map1);
		
		powM(map1,M);
		printf("\n");
	}
	
	return 0;
}
