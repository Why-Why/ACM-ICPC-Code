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

int N,M,P;

class BigNum
{
	private:

	const static int MaxL=100;
	const static int Mod=10000;				// 数组每个元素保存 0-(Mod-1) 的值。
	const static int Dlen=4;

	int num[MaxL/Dlen+1],len;				// num的0处是最低位。

	public:

	BigNum() { len=1; memset(num,0,sizeof(num)); }
	BigNum(int);
	
	BigNum operator + (const BigNum &) const;
	BigNum & operator = (const BigNum &);

	void add(const BigNum &b)
	{
		int flag=0;
		int p=0;

		len=max(len,b.len);

		while(p<len || flag)
		{
			num[p]+=b.num[p]+flag;
			flag=0;

			if(num[p]>=Mod)
			{
				num[p]-=Mod;
				flag=1;
			}

			++p;
		}

		if(num[len])
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

BigNum & BigNum::operator = (const BigNum &a)
{
	memset(num,0,sizeof(num));

	len=a.len;
	for(int i=0;i<len;++i)
		num[i]=a.num[i];

	return *this;
}

BigNum BigNum::operator + (const BigNum &a) const
{
	BigNum ret;
	
	ret.len=max(len,a.len);

	for(int i=0;i<ret.len;++i)
	{
		ret.num[i]+=((i<len ? num[i] : 0)+(i<a.len ? a.num[i] : 0));
		ret.num[i+1]+=ret.num[i]/Mod;
		ret.num[i]%=Mod;
	}
	if(ret.num[ret.len]>0)	++ret.len;

	return ret;
}

const int MaxL=200;

int MaxC;
int que[200],first,last;
int zhuan[256];

struct AC_auto
{
	int next[MaxL][52],fail[MaxL];
	bool word[MaxL];
	int root,Tp;

	int Newnode()
	{
		for(int i=0;i<MaxC;++i)
			next[Tp][i]=-1;
		word[Tp++]=0;
		return Tp-1;
	}

	void Init()
	{
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

	BigNum dp[60][110];
	BigNum ans;

	bool judge(int a,int fang,int &b)
	{
		while(a!=root && next[a][fang]==-1)
			a=fail[a];

		if(next[a][fang]==-1)
			b=root;
		else
			b=next[a][fang];

		int temp=b;

		while(temp!=-1)
		{
			if(word[temp])
				return 0;
			temp=fail[temp];
		}

		return 1;
	}

	void getans()
	{
		int temp;

		memset(dp,0,sizeof(dp));

		dp[0][0]=1;

		for(int i=0;i<M;++i)
			for(int j=0;j<Tp;++j)
				for(int k=0;k<MaxC;++k)
					if(judge(j,k,temp))
						dp[i+1][temp].add(dp[i][j]);

		ans=0;

		for(int i=0;i<Tp;++i)
			ans.add(dp[M][i]);

		ans.print();
		printf("\n");
	}
}myAC;

char ss[100];
int s[100];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int temp;

	while(~scanf("%d %d %d",&N,&M,&P))
	{
		getchar();
		gets(ss);

		MaxC=N;

		for(int i=0;i<=N;++i)
		{
			if(ss[i]<0)
				temp=ss[i]+256;
			else
				temp=ss[i];

			zhuan[temp]=i;
		}

		myAC.Init();

		while(P--)
		{
			gets(ss);
			int len=strlen(ss);

			for(int i=0;i<=len;++i)
				if(ss[i]<0)
					s[i]=ss[i]+256;
				else
					s[i]=ss[i];

			myAC.Insert(s);
		}

		myAC.Build();
		myAC.getans();
	}
	
	return 0;
}
