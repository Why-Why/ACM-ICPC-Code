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
// Created Time  : 2016年10月26日 星期三 21时13分40秒
// File Name     : I.cpp

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

const int MaxN=4000;
const int INF=0x3f3f3f3f;

struct Treap {
	int tot,root;
	int ch[MaxN][2];				// 儿子。
	int key[MaxN],pri[MaxN];		// 键值，优先值。
	int cou[MaxN],size[MaxN];		// 节点值的个数，他及其子树节点的总数。

	int sum[MaxN],all[MaxN];

	int num;

	void init() {
		tot=1;
		root=0;
		pri[0]=INT_MAX;				// 不能是INF。
		size[0]=0;

		sum[0]=0;
		all[0]=0;

		num=0;
	}

	void update(int x) {
		size[x]=size[ch[x][0]]+cou[x]+size[ch[x][1]];
		all[x]=all[ch[x][0]]+sum[x]+all[ch[x][1]];
	}

	void rotate(int &x,int t) {
		int y=ch[x][t];

		ch[x][t]=ch[y][1-t];
		ch[y][1-t]=x;

		update(x);
		update(y);

		x=y;
	}

	void _insert(int &x,int k,int v) {
		if(x) {
			if(key[x]==k) ++cou[x],sum[x]+=v;
			else {
				int t=key[x]<k;

				_insert(ch[x][t],k,v);

				if(pri[ch[x][t]]<pri[x]) rotate(x,t);
			}
		}
		else {
			x=tot++;
			key[x]=k;
			cou[x]=1;
			pri[x]=rand();			// !!!
			ch[x][0]=ch[x][1]=0;

			sum[x]=v;
		}

		update(x);
	}

	void _erase(int &x,int k) {
		if(!x) return;

		if(key[x]==k)
			if(cou[x]>1) --cou[x],sum[x]-=k;
			else {
				if(ch[x][0]==0 && ch[x][1]==0) {
					x=0;				// 那一块内存不能用了，所以容量要开大。
					return;
				}

				int t=pri[ch[x][0]]>pri[ch[x][1]];

				rotate(x,t);
				_erase(x,k);
			}
		else _erase(ch[x][key[x]<k],k);

		update(x);
	}

	void insert(int k,int v) {
		_insert(root,k,v);
		++num;
	}

	void erase(int k) {
		_erase(root,k);
		--num;
	}

	int getSum(int k) {
		int x=root;
		int ret=0;

		while(k && x) {
			if(size[ch[x][0]]>=k) x=ch[x][0];
			else {
				k-=size[ch[x][0]];
				ret+=all[ch[x][0]];

				if(k<=cou[x]) {
					ret+=sum[x]/cou[x]*k;
					k=0;
				}
				else {
					ret+=sum[x];
					k-=cou[x];
					x=ch[x][1];
				}
			}
		}

		return ret;
	}
}tree1,tree2;

///////////////////////////////////////////

struct pii {
	int first,second,id;
};

int N,P,S;
pii num[3003],ttt[3003];
int base=0;

bool cmp(const pii & a,const pii & b) {
	if(a.first!=b.first) return a.first<b.first;
	return a.second>b.second;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d %d",&N,&P,&S);
	for(int i=1;i<=N;++i) scanf("%d",&num[i].first),num[i].id=i;
	for(int i=1;i<=N;++i) scanf("%d",&num[i].second);
	sort(num+1,num+N+1,cmp);

	tree1.init();
	tree2.init();

	int temp=0;

	for(int i=1;i<=N;++i) tree1.insert(-num[i].second,-num[i].second);
	for(int i=N,j=0;j<P;--i,++j) {
		tree1.erase(-num[i].second);
		tree2.insert(num[i].second-num[i].first,num[i].second-num[i].first);
		base+=num[i].second;

		temp+=num[i].first;
	}

	int ans=temp-tree1.getSum(S),tans,t;
	int rem=N-P+1;

	for(int i=N-P,j=P+1;i>=1;--i,++j) {
		tree1.erase(-num[i].second);
		tree2.insert(num[i].second-num[i].first,num[i].second-num[i].first);
		base+=num[i].second;

		t=S-j+P;
		if(t<0 || t>tree1.num) continue;

		tans=base-tree2.getSum(P)-tree1.getSum(t);
		if(ans<tans) ans=tans,rem=i;
	}

	printf("%d\n",ans);

	int cou=0;
	for(int i=rem;i<=N;++i) {
		ttt[++cou].first=num[i].second-num[i].first;
		ttt[cou].id=num[i].id;
	}

	sort(ttt+1,ttt+cou+1,cmp);
	for(int i=1;i<=P;++i) printf("%d ",ttt[i].id);
	puts("");

	for(int i=P+1;i<=cou;++i) printf("%d ",ttt[i].id);
	t=S-cou+P;

	cou=0;
	for(int i=1;i<rem;++i) {
		ttt[++cou].first=-num[i].second;
		ttt[cou].id=num[i].id;
	}

	sort(ttt+1,ttt+cou+1,cmp);
	for(int i=1;i<=t;++i) printf("%d ",ttt[i].id);
	puts("");

	return 0;
}
