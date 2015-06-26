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

#pragma comment(linker, "/STACK:102400000,102400000")

using namespace std;

// AC自动机进行多模式串匹配，复杂度 O(n+km)。
// 输入：k个模式串，要搜索的串。
// 输出：有几个模式串出现在基串中(可以改成出现几次。)。
// 注意：先使用Init初始化，然后使用Insert插入，然后Build，然后Query。
// 原理：模式串构建一个Trie，然后构建失败指针fail。

const int MaxL=500;
const int MaxC=26;

int que[510];
int first,last;

const int MaxN=40;

int size;

struct Metrix
{
	unsigned long long num[MaxN][MaxN];

	void zero()
	{
		memset(num,0,sizeof(num));
	}

	Metrix operator + (const Metrix &b) const
	{
		Metrix ret;

		for(int i=1;i<=size;++i)
			for(int j=1;j<=size;++j)
				ret.num[i][j]=b.num[i][j]+num[i][j];

		return ret;
	}

	Metrix operator * (const Metrix &b) const
	{
		Metrix ret;

		ret.zero();

		for(int i=1;i<=size;++i)
			for(int j=1;j<=size;++j)
				for(int k=1;k<=size;++k)
					ret.num[i][j]+=num[i][k]*b.num[k][j];

		return ret;
	}

	void dis()
	{
		for(int i=1;i<=size;++i,cout<<endl)
			for(int j=1;j<=size;++j)
				cout<<num[i][j]<<' ';
		cout<<endl;
	}
};

struct Metrix1
{
	Metrix num[3][3];

	Metrix1 operator + (const Metrix1 &b) const
	{
		Metrix1 ret;

		for(int i=1;i<=2;++i)
			for(int j=1;j<=2;++j)
				ret.num[i][j]=num[i][j]+b.num[i][j];

		return ret;
	}

	Metrix1 operator * (const Metrix1 &b) const
	{
		Metrix1 ret;

		ret.num[1][1].zero();
		ret.num[1][2].zero();
		ret.num[2][1].zero();
		ret.num[2][2].zero();

		for(int i=1;i<=2;++i)
			for(int j=1;j<=2;++j)
				for(int k=1;k<=2;++k)
					ret.num[i][j]=ret.num[i][j]+num[i][k]*b.num[k][j];

		return ret;
	}

	void dis()
	{
		for(int i=1;i<=2;++i)
			for(int j=1;j<=2;++j)
				num[i][j].dis();
	}
};

struct AC_auto
{
	int next[MaxL][MaxC],fail[MaxL];		// 这个节点结尾的单词的个数。
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

	void Insert(char s[])
	{
		int p=root;
		for(int i=0;s[i];++i)
		{
			if(next[p][s[i]-'a']==-1)	next[p][s[i]-'a']=Newnode();
			p=next[p][s[i]-'a'];
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
					if(p==root)	fail[next[p][i]]=root;
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
						
						if(temp==-1)	fail[next[p][i]]=root;
					}
					que[last++]=next[p][i];
				}
		}
	}

	void getMet(Metrix &met)
	{
		int temp,temp1;

		size=Tp;
		met.zero();

		for(int i=0;i<size;++i)
			if(word[i]==0)
				for(int j=0;j<MaxC;++j)
				{
					temp=i;

					while(temp!=root && next[temp][j]==-1)
						temp=fail[temp];

					if(next[temp][j]==-1)
						temp=root;
					else
						temp=next[temp][j];

					bool ok=0;
					temp1=temp;

					while(temp1!=-1)
					{
						if(word[temp1])
						{
							ok=1;
							break;
						}

						temp1=fail[temp1];
					}

					if(!ok)
						++met.num[i+1][temp+1];
				}
	}

}myAC;

void multi(Metrix &a,Metrix b,int size1)
{
	Metrix ans;

	ans.zero();

	for(int i=1;i<=size1;++i)
		for(int j=1;j<=size1;++j)
			for(int k=1;k<=size1;++k)
				ans.num[i][j]+=a.num[i][k]*b.num[k][j];

	for(int i=1;i<=size1;++i)
		for(int j=1;j<=size1;++j)
			a.num[i][j]=ans.num[i][j];
}

void multi1(Metrix1 &a,Metrix1 b,int size1)
{
	Metrix1 ans;

	for(int i=1;i<=2;++i)
		for(int j=1;j<=2;++j)
			ans.num[i][j].zero();

	for(int i=1;i<=2;++i)
		for(int j=1;j<=2;++j)
			for(int k=1;k<=2;++k)
				ans.num[i][j]=ans.num[i][j]+a.num[i][k]*b.num[k][j];

	for(int i=1;i<=size1;++i)
		for(int j=1;j<=size1;++j)
			a.num[i][j]=ans.num[i][j];
}

Metrix powM(Metrix a,long long n)
{
	Metrix ans;
	ans.zero();

	for(int i=1;i<=2;++i)
		ans.num[i][i]=1;

	while(n)
	{
		if(n&1)
			multi(ans,a,2);

		multi(a,a,2);
		n>>=1;
	}

	return ans;
}

Metrix1 powM1(Metrix1 a,long long n,int size1)
{
	Metrix1 ans;
	ans.num[1][1].zero();
	ans.num[1][2].zero();
	ans.num[2][1].zero();
	ans.num[2][2].zero();

	for(int i=1;i<=size1;++i)
		for(int j=1;j<=size;++j)
			ans.num[i][i].num[j][j]=1;

	while(n)
	{
		if(n&1)
			multi1(ans,a,2);

		multi1(a,a,2);
		n>>=1;
	}

	return ans;
}

Metrix met;
char s[10];
int N,L;

unsigned long long getans1(long long n)
{
	Metrix temp;
	temp.num[1][1]=26;
	temp.num[1][2]=1;
	temp.num[2][1]=0;
	temp.num[2][2]=1;

	Metrix ans=powM(temp,n+1);

	return ans.num[1][2];
}

unsigned long long getans2(const Metrix &a,long long n)
{
	Metrix1 temp;
	Metrix t;
	t.zero();

	temp.num[1][1]=a;
	temp.num[2][1]=t;

	for(int i=1;i<=size;++i)
		t.num[i][i]=1;

	temp.num[1][2]=temp.num[2][2]=t;

	temp=powM1(temp,n+1,2);

	unsigned long long ret=0;

	for(int i=1;i<=size;++i)
		ret+=temp.num[1][2].num[1][i];

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	unsigned long long a,b;

	while(~scanf("%d %d",&N,&L))
	{
		myAC.Init();

		for(int i=1;i<=N;++i)
		{
			scanf("%s",s);
			myAC.Insert(s);
		}

		myAC.Build();
		myAC.getMet(met);

		a=getans1(L);
		b=getans2(met,L);

		a-=b;

		//cout<<a<<' '<<b<<endl;
		cout<<a<<endl;
	}
	
	return 0;
}
