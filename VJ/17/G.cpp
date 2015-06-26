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

	const static int MaxL=1000;
	const static int Mod=10000;				// 数组每个元素保存 0-(Mod-1) 的值。
	const static int Dlen=4;

	int num[MaxL/Dlen+1],len;				// num的0处是最低位。

	void changeStoNum(const char *);

	public:

	BigNum() { len=1; memset(num,0,sizeof(num)); }
	BigNum(int);
	BigNum(const char *x) { changeStoNum(x); }
	
	BigNum operator + (const BigNum &) const;
	BigNum operator - (const BigNum &) const;
	BigNum operator * (const BigNum &) const;
	BigNum operator / (const int) const;
	BigNum operator - () const;
	bool operator > (const BigNum &a) const;
	int operator % (const int m) const;
	BigNum & operator = (const BigNum &);

	void scan();
	void print();
	void getNum(char *);
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

void BigNum::changeStoNum(const char *x)		// x的0处是最高位。
{
	int L=strlen(x),p=0;
	int temp,tp;
	int flag=1;

	if(x[0]=='-')
	{
		flag=-1;
		++x;
		L--;
	}

	memset(num,0,sizeof(num));
	len=L/Dlen;
	if(L%Dlen)	++len;

	for(int i=L-1;i>=0;i-=Dlen)
	{
		temp=0;
		tp=i-Dlen+1;
		if(tp<0) tp=0;

		for(int j=tp;j<=i;++j)
			temp=temp*10+x[j]-'0';
		num[p++]=flag*temp;
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
		printf("%04d",abs(num[i]));
}

void BigNum::getNum(char *s)
{
	int l=0;
	
	sprintf(s,"%d",num[len-1]);
	l=strlen(s);
	
	for(int i=len-2;i>=0;--i)
	{
		sprintf(s+l,"%04d",num[i]);
		l+=4;
	}
	s[l]=0;
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

BigNum BigNum::operator * (const BigNum &a) const
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

BigNum BigNum::operator - (const BigNum &a) const
{
	return *this+(-a);
}

BigNum BigNum::operator - () const
{
	BigNum ret;

	ret.len=len;

	for(int i=0;i<len;++i)
		ret.num[i]=-num[i];

	return ret;
}

BigNum BigNum::operator / (const int a) const
{
	BigNum ret;
	int down=0;

	ret.len=len;

	for(int i=len-1;i>=0;--i)
	{
		ret.num[i]=(num[i]+down*Mod)/a;
		down=num[i]+down*Mod-ret.num[i]*a;
	}
	while(ret.num[ret.len-1]==0 && ret.len>1)	--ret.len;

	return ret;
}

int BigNum::operator % (const int a) const
{
	int ret=0;

	for(int i=len-1;i>=0;--i)
		ret=((ret*Mod)%a+num[i])%a;

	return ret;
}

bool BigNum::operator > (const BigNum &a) const
{
	if(len!=a.len)
		return len>a.len;

	for(int i=len-1;i>=0;--i)
		if(num[i]!=a.num[i])
			return num[i]>a.num[i];

	return 0;
}

const int MaxSize=110;

template <typename T>
struct Metrix
{
	T num[MaxSize][MaxSize];
	int size;

	void operator = (int x)
	{
		memset(num,0,sizeof(num));

		if(x==1)
			for(int i=1;i<=size;++i)
				num[i][i]=1;
	}
/*
	Metrix <T> operator + (const Metrix <T> &b)
	{
		Metrix <T> ret;

		for(int i=1;i<=size;++i)
			for(int j=1;j<=size;++j)
				ret.num[i][j]=num[i][j]+b.num[i][j];

		return ret;
	}

	Metrix <T> operator * (Metrix <T> &b)
	{
		Metrix <T> ret;
		ret=0;

		for(int i=1;i<=size;++i)
			for(int j=1;j<=b.size;++j)
				for(int k=1;k<=size;++k)
					ret.num[i][j]=ret.num[i][j]+num[i][k]*b.num[k][j];

		return ret;
	}*/

	void dis()
	{
		for(int i=1;i<=size;++i,cout<<endl)
			for(int j=1;j<=size;++j)
				num[i][j].print();
		cout<<endl;
	}
};

const int MaxL=200;

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

	void Insert(char s[])
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

	template <typename T>
	void getMet(Metrix <T>  &a)
	{
		int temp,temp1;
		bool ok;

		a=0;
		a.size=Tp;

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
						a.num[i+1][temp1+1]=a.num[i+1][temp1+1]+1;
				}
	}
};

AC_auto myAC;
Metrix <BigNum> map1;
int N,M,P;
char s[70];

template <typename T>
T pow1(T a,int n)
{
	T ret=1;
	T base=a;

	while(n)
	{
		if(n&1)
			ret=ret*base;

		base=base*base;
		n>>=1;
	}

	return ret;
}

template <typename T>
void cheng(Metrix <T> &a,Metrix <T> &b)
{
	Metrix <T> temp;
	temp=0;

	for(int i=1;i<=a.size;++i)
		for(int j=1;j<=a.size;++j)
			for(int k=1;k<=a.size;++k)
				temp.num[i][j]=temp.num[i][j]+a.num[i][k]*b.num[k][j];

	for(int i=1;i<=a.size;++i)
		for(int j=1;j<=a.size;++j)
			a.num[i][j]=temp.num[i][j];
}

template <typename T>
void powM(Metrix <T> &a,int n)
{
	Metrix <T> base=a;
	a=1;

	while(n)
	{
		if(n&1)
			cheng(a,base);

		cheng(base,base);
		n>>=1;
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d %d %d",&N,&M,&P))
	{
		getchar();
		gets(s);

		int len=strlen(s);

		for(int i=0;i<len;++i)
			zhuan[s[i]]=i;

		myAC.Init(N);

		while(P--)
		{
//			getchar();
			gets(s);
			myAC.Insert(s);
		}

		myAC.Build();
		myAC.getMet(map1);
		
		powM(map1,M);

		map1.num[1][1].print();
		
		BigNum a,b;

		for(int i=1;i<=map1.size;++i)
			a=a+map1.num[1][i];
		b=pow1(BigNum(N),M);

		b=b-a;

		b.print();
		printf("\n");
	}
	
	return 0;
}
