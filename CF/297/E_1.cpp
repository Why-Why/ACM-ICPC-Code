// ━━━━━━神兽出没━━━━━━
// 　　 ┏┓       ┏┓
// 　　┏┛┻━━━━━━━┛┻┓
// 　　┃           ┃
// 　　┃     ━     ┃
//     ████━████   ┃
// 　　┃           ┃
// 　　┃    ┻      ┃
// 　　┃           ┃
// 　　┗━┓       ┏━┛
// 　　  ┃       ┃
// 　　  ┃       ┃
// 　　　┃       ┗━━━┓
// 　　　┃           ┣┓
// 　　　┃           ┏┛
// 　　　┗┓┓┏━━━━━┳┓┏┛
// 　　　 ┃┫┫     ┃┫┫
// 　　　 ┗┻┛     ┗┻┛
//
// ━━━━━━感觉萌萌哒━━━━━━

// Author        : WhyWhy
// Created Time  : 2015年05月31日 星期日 19时28分30秒
// File Name     : E_1.cpp

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
#include <climits>

using namespace std;

const int MaxN=100010;
const int INF=0x3f3f3f3f;

struct Treap
{
	int tot,root;
	int ch[MaxN][2];				// 儿子。
	long long key[MaxN];
	int pri[MaxN];		// 键值，优先值。
	int cou[MaxN],size[MaxN];		// 节点值的个数，他及其子树节点的总数。

	void init()
	{
		tot=1;
		root=0;
		pri[0]=INT_MAX;				// 不能是INF。
		size[0]=0;
	}

	void update(int x)				// 维护size。
	{
		size[x]=size[ch[x][0]]+cou[x]+size[ch[x][1]];
	}

	void rotate(int &x,int t)		// 节点x按照t方向旋转，0为左。
	{
		int y=ch[x][t];

		ch[x][t]=ch[y][1-t];
		ch[y][1-t]=x;

		update(x);
		update(y);

		x=y;
	}

	void _insert(int &x,long long k)
	{
		if(x)
		{
			if(key[x]==k)
				++cou[x];
			else
			{
				int t=key[x]<k;

				_insert(ch[x][t],k);

				if(pri[ch[x][t]]<pri[x])
					rotate(x,t);
			}
		}
		else
		{
			x=tot++;
			key[x]=k;
			cou[x]=1;
			pri[x]=rand();			// !!!
			ch[x][0]=ch[x][1]=0;
		}

		update(x);
	}

	int find(long long k)
	{
		int u=root;

		while(u)
		{
			if(key[u]==k)
				return cou[u];

			u=ch[u][key[u]<k];
		}

		return 0;
	}

	void insert(long long k)
	{
		_insert(root,k);
	}
};

int n,k;
long long S;
Treap rem[26];
long long num[30];
long long jie[30];

void init()
{
	jie[0]=1;

	for(int i=1;i<=19;++i)
		jie[i]=jie[i-1]*i;

	for(int i=0;i<26;++i)
		rem[i].init();
}

long long getnum(long long num[],int sta,int d,int &temp)
{
	long long sum=0;
	int t1,ttt;

	temp=0;

	for(int j=0;j<d;++j)
	{
		t1=sta/3;
		ttt=sta-t1*3;
		sta=t1;

		if(ttt==1)
			sum+=num[j+1];
		else if(ttt==2)
		{
			if(num[j+1]>19)
				return -1;

			sum+=jie[num[j+1]];
			++temp;
		}

		if(sum>S || temp>k)
			return -1;
	}
	
	return sum;
}

void chuli(int d)
{
	long long temp;
	long long zong=1;
	int knum;

	for(int i=0;i<d;++i)
		zong*=3;

	for(int i=0;i<zong;++i)
	{
		temp=getnum(num,i,d,knum);

		if(temp!=-1)
			rem[knum].insert(temp);
	}
}

long long getans(long long num[],int d)
{
	long long temp;
	long long zong=1;
	long long ans=0;
	int knum;

	for(int i=0;i<d;++i)
		zong*=3;

	for(int i=0;i<zong;++i)
	{
		temp=getnum(num,i,d,knum);

		if(temp!=-1)
		{
			for(int i=0;i<=k-knum;++i)
				ans+=rem[i].find(S-temp);
		}
	}

	return ans;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	ios::sync_with_stdio(false);

	init();
	cin>>n>>k>>S;

	for(int i=1;i<=n;++i)
		cin>>num[i];

	sort(num+1,num+n+1);
	chuli((n+1)/2);
	cout<<getans(num+(n+1)/2,n-(n+1)/2)<<endl;
	
	return 0;
}
