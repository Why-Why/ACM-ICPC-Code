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

// AC自动机进行多模式串匹配，复杂度 O(n+km)。
// 输入：k个模式串，要搜索的串。
// 输出：有几个模式串出现在基串中(可以改成出现几次。)。
// 注意：先使用Init初始化，然后使用Insert插入，然后Build，然后Query。
// 原理：模式串构建一个Trie，然后构建失败指针fail。

const int MaxL=110;
const int MaxC=4;

int que[500010];
int first,last;

inline int change(char c)
{
	switch(c)
	{
		case 'A':
			return 0;
		case 'C':
			return 1;
		case 'G':
			return 2;
		case 'T':
			return 3;
		default:
			return -1;
	}
}

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
		int temp;
		for(int i=0;s[i];++i)
		{
			temp=change(s[i]);

			if(temp==-1)
				continue;

			if(next[p][temp]==-1)	next[p][temp]=Newnode();
			p=next[p][temp];
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

	void Chuli(long long map1[][110])
	{
		int temp,temp1;

		for(int i=1;i<=Tp;++i)
			for(int j=1;j<=Tp;++j)
				map1[i][j]=0;

		for(int i=0;i<Tp;++i)
			if(word[i]==0)
				for(int j=0;j<MaxC;++j)
				{
					temp=i;

					while(temp!=root && next[temp][j]==-1)
						temp=fail[temp];

					if(next[temp][j]!=-1)
						temp1=next[temp][j];
					else
						temp1=root;

					bool ok=0;
					temp=temp1;

					while(temp1!=-1)
					{
						if(word[temp1]==1)
						{
							ok=1;
							break;
						}

						temp1=fail[temp1];
					}

					if(!ok)
						++map1[i+1][temp+1];
				}

//		for(int i=1;i<=Tp;++i)

	}
};

AC_auto myAC;

const long long mod=100000;

long long map1[110][110];
int N,M;
char s[110];
int S;

void getmap()
{
	myAC.Init();

	while(M--)
	{
		scanf("%s",s);
		myAC.Insert(s);
	}

	myAC.Build();
	S=myAC.Tp;

	myAC.Chuli(map1);
}

void cheng(long long a[][110],long long b[][110])
{
	long long temp;
	long long ans[110][110];

	for(int i=1;i<=S;++i)
		for(int j=1;j<=S;++j)
		{
			temp=0;

			for(int k=1;k<=S;++k)
				temp=(temp+a[i][k]*b[k][j])%mod;

			ans[i][j]=temp;
		}

	for(int i=1;i<=S;++i)
		for(int j=1;j<=S;++j)
			a[i][j]=ans[i][j];
}

long long temp1[110][110]={0};

void getans()
{
	memset(temp1,0,sizeof(temp1));

	for(int i=1;i<=S;++i)
		temp1[i][i]=1;

	int temp=N;

	while(temp)
	{
		if(temp&1)
			cheng(temp1,map1);

		cheng(map1,map1);

		temp>>=1;
	}

	long long ans=0;

	for(int i=1;i<=S;++i)
		ans=(ans+(temp1[1][i]))%mod;

	printf("%d\n",(int)(ans%mod));
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	while(~scanf("%d %d",&M,&N))
	{
		getmap();

	//	for(int i=1;i<=S;++i,cout<<endl)
	//		for(int j=1;j<=S;++j)
	//			cout<<map1[i][j]<<' ';
	//	cout<<endl;

		getans();
	}
	
	return 0;
}
