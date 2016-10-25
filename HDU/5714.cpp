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
// Created Time  : 2016年05月30日 星期一 19时30分03秒
// File Name     : 5714.cpp

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

const int MaxN=10005<<1;

struct Treap
{
	int tot,root;
	int ch[MaxN][2];				// 儿子。
	int key[MaxN],pri[MaxN];		// 键值，优先值。
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

	void _insert(int &x,int k)
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
	void insert(int k)
	{
		_insert(root,k);
	}
	int count(int k) {
		int u=root,ret=0;

		while(u) {
			if(key[u]>=k) {
				ret+=cou[u]+size[ch[u][1]];
				u=ch[u][0];
			}
			else u=ch[u][1];
		}
		return ret;
	}
}tree,tree1;

typedef pair<int,int> pii;

pii rem1[MaxN],rem2[MaxN];
int cou1,cou2;
int N;
int rem[MaxN<<1],cou;

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	int x,y,z,d,a,b;
	scanf("%d",&T);

	while(T--) {
		scanf("%d",&N);
		cou1=cou2=cou=0;
		for(int i=1;i<=N;++i) {
			scanf("%d %d %d %d",&x,&y,&z,&d);
			a=y-z;
			b=x+z;
			if(a>b) continue;
			if(d==1) rem1[++cou1]=pii(a,b);
			else rem2[++cou2]=pii(a,b),rem[++cou]=a,rem[++cou]=b;
		}
		sort(rem1+1,rem1+cou1+1);
		sort(rem2+1,rem2+cou2+1);
		sort(rem+1,rem+cou+1);
		rem[++cou]=1000000000;

		tree.init();
		tree1.init();
		int p1=1,p2=1,max1=0,max2=0,ans=0;
		for(int i=1;i<=cou;++i) {
			while(p2<=cou2 && rem2[p2].first<=rem[i]) {
				tree.insert(rem2[p2].second);
				++p2;
			}
			max1=tree.count(rem[i]);
			while(p1<=cou1 && rem1[p1].first<=rem[i]) {
				tree1.insert(rem1[p1].second);
				max2=max(max2,tree1.count(rem1[p1].first));
				++p1;
			}
			ans=max(ans,max1+max2);
		}
		printf("Case #%d:\n%d\n",cas++,ans);
	}
	
	return 0;
}
