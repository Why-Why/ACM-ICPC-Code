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
// Created Time  : 2017年02月27日 星期一 22时53分52秒
// File Name     : L.cpp

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

const int MaxN=100005;

struct Edge {
	int to,next,len;
	int id;
};

Edge E[MaxN<<1];
int head[MaxN],Ecou;
int N;
int remEu[MaxN],remEv[MaxN],remEl[MaxN];

void init() {
	Ecou=0;
	for(int i=1;i<=N;++i) head[i]=-1;
}

inline void addEdge(int u,int v,int len,int id) {
	E[Ecou].to=v;
	E[Ecou].len=len;
	E[Ecou].id=id;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

/////////////////////////////////

int belong[MaxN];		// node belong to which diameter.
int maxLen,maxNum;		// diameter and the number of nodes in diameter.
int pos[MaxN];			// each node's position in diameter.
int fupos[MaxN];
int posVal[MaxN];		// the lenth from position 1 to position i.

int subMax1,subMax2;	// the first and second max diameter in all subtree.

//////////////////

int subFa[MaxN],subSon[MaxN];
int subEidAns[MaxN];

struct SubTree {
	private:
		int tmaxDep,trem;

		int dfs1(int u,int pre,int dep) {
			int ret=dep;

			if(dep>tmaxDep) {
				tmaxDep=dep;
				trem=u;
			}

			for(int i=head[u];i!=-1;i=E[i].next)
				if(belong[E[i].id]==-1 && E[i].to!=pre) {
					subFa[E[i].to]=i^1;
					ret=max(ret,dfs1(E[i].to,u,dep+E[i].len));
				}

			return ret;
		}

	public:
		int root;
		int tid;
		int maxDiameter;

		void getDiameter() {
			tmaxDep=-1;
			dfs1(root,-1,0);

			int a=trem,b;
			tmaxDep=-1;
			dfs1(a,-1,0);
			b=trem;

			maxDiameter=0;
			for(int u=b;u!=a;u=E[subFa[u]].to) {
				maxDiameter+=E[subFa[u]].len;
				belong[E[subFa[u]].id]=tid;
				subSon[E[subFa[u]].to]=subFa[u]^1;
			}

			int tmp=0,maxn=0;
			for(int u=b;u!=a;u=E[subFa[u]].to) {
				maxn=max(maxn,dfs1(u,-1,tmp));
				subEidAns[E[subFa[u]].id]=maxn;
				tmp+=E[subFa[u]].len;
			}

			tmp=0;
			maxn=0;
			for(int u=a;u!=b;u=E[subSon[u]].to) {
				maxn=max(maxn,dfs1(u,-1,tmp));
				subEidAns[E[subSon[u]].id]=max(subEidAns[E[subSon[u]].id],maxn);
				tmp+=E[subSon[u]].len;
			}
		}

		int divid(int eid) {
			if(belong[eid]==-1) return maxDiameter;
			return subEidAns[eid];
		}
}subtree[MaxN];

//////////////////

int sub2Leaf[MaxN],sub2Lcou;
int sub2LL[MaxN],sub2RR[MaxN];
int sub2Dep[MaxN];
int sub2AnsL[MaxN],sub2AnsR[MaxN];

struct SubTree2 {
	int root;
	int tid;
	int maxDep;

	int sub2L,sub2R;

	void dfs(int u,int pre,int dep) {
		int ok=1;

		pos[u]=tid;

		sub2Dep[u]=dep;
		sub2LL[u]=sub2Lcou+1;

		for(int i=head[u];i!=-1;i=E[i].next)
			if(belong[E[i].id] && E[i].to!=pre) {
				dfs(E[i].to,u,dep+E[i].len);
				ok=0;
			}

		if(ok) sub2Leaf[++sub2Lcou]=u;
		sub2RR[u]=sub2Lcou;
	}

	void solve() {
		sub2L=sub2Lcou+1;
		dfs(root,-1,0);
		sub2R=sub2Lcou;

		sub2AnsL[sub2L]=sub2Dep[sub2Leaf[sub2L]];
		for(int i=sub2L+1;i<=sub2R;++i)
			sub2AnsL[i]=max(sub2AnsL[i-1],sub2Dep[sub2Leaf[i]]);

		sub2AnsR[sub2R]=sub2Dep[sub2Leaf[sub2R]];
		for(int i=sub2R-1;i>=sub2L;--i)
			sub2AnsR[i]=max(sub2AnsR[i+1],sub2Dep[sub2Leaf[i]]);

		maxDep=sub2AnsL[sub2R];
	}

	int erase(int u) {
		int L=sub2LL[u],R=sub2RR[u];
		int ret=0;

		if(L>sub2L) ret=max(ret,sub2AnsL[L-1]);
		if(R<sub2R) ret=max(ret,sub2AnsR[R+1]);
		return ret;
	}

	int divid(int eid) {
		int a=remEu[eid],b=remEv[eid];
		if(sub2Dep[a]>sub2Dep[b]) swap(a,b);

		return max(sub2Dep[a],erase(b));
	}
}subtree2[MaxN];

//////////////////

#define lc (po<<1)
#define rc ((po<<1)|1)
#define lson L,M,lc
#define rson M+1,R,rc

struct BIT {
	int vAm,vDm,num;

	BIT operator + (const BIT & b) const {
		BIT ret;

		ret.num=max(num,b.num);
		ret.num=max(ret.num,vDm+b.vAm);

		ret.vAm=max(vAm,b.vAm);
		ret.vDm=max(vDm,b.vDm);

		return ret;
	}

}bit[MaxN<<2];

inline void pushUP(int po) {
	bit[po]=bit[lc]+bit[rc];
}

void build(int L,int R,int po) {
	if(L==R) {
		bit[po].vAm=posVal[fupos[L]]+subtree2[L].maxDep;
		bit[po].vDm=-posVal[fupos[L]]+subtree2[L].maxDep;
		bit[po].num=0;
		return;
	}

	int M=(L+R)>>1;
	build(lson);
	build(rson);
	pushUP(po);
}

BIT query(int ql,int qr,int L,int R,int po) {			// segment tree.
	if(ql<=L && qr>=R) return bit[po];

	int M=(L+R)>>1;
	if(qr<=M) return query(ql,qr,lson);
	if(ql>M) return query(ql,qr,rson);
	return query(ql,qr,lson)+query(ql,qr,rson);
}

void update(int up,int ut,int L,int R,int po) {			// segment tree.
	if(L==R) {
		bit[po].vAm=posVal[fupos[L]]+ut;
		bit[po].vDm=-posVal[fupos[L]]+ut;
		bit[po].num=0;
		return;
	}

	int M=(L+R)>>1;
	if(up<=M) update(up,ut,lson);
	else update(up,ut,rson);

	pushUP(po);
}

//////////////////

int fa[MaxN];
int tmaxn,trem;

void dfs(int u,int pre,int dep) {
	if(tmaxn<dep) {
		tmaxn=dep;
		trem=u;
	}

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre) {
			fa[E[i].to]=i^1;
			dfs(E[i].to,u,dep+E[i].len);
		}
}

void solve() {
	tmaxn=-1;
	dfs(1,-1,0);

	int a=trem;
	tmaxn=-1;
	dfs(a,-1,0);
	int b=trem;

	maxNum=maxLen=0;

	for(int u=b;u!=a;u=E[fa[u]].to) {
		belong[E[fa[u]].id]=0;
		pos[u]=++maxNum;
		fupos[maxNum]=u;
		posVal[u]=maxLen;
		maxLen+=E[fa[u]].len;
	}

	pos[a]=++maxNum;
	fupos[maxNum]=a;
	posVal[a]=maxLen;

	subMax1=subMax2=-1;

	for(int u=b;;u=E[fa[u]].to) {
		subtree[pos[u]].root=u;
		subtree[pos[u]].tid=pos[u];
		subtree[pos[u]].getDiameter();

		int t=subtree[pos[u]].maxDiameter;

		if(t>subMax1) {
			subMax2=subMax1;
			subMax1=t;
		}
		else subMax2=max(subMax2,t);

		subtree2[pos[u]].root=u;
		subtree2[pos[u]].tid=pos[u];
		subtree2[pos[u]].solve();

		if(u==a) break;
	}

	build(1,maxNum,1);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	int Q;
	int a,b,c,t[4];
	int ans,tmp;
	scanf("%d",&T);

	while(T--) {
		scanf("%d %d",&N,&Q);
		init();

		sub2Lcou=0;

		for(int i=1;i<N;++i) {
			scanf("%d %d %d",&a,&b,&c);
			addEdge(a,b,c,i);
			addEdge(b,a,c,i);

			belong[i]=-1;
			remEu[i]=a;
			remEv[i]=b;
			remEl[i]=c;
		}

		solve();

		while(Q--) {
			scanf("%d %d",&a,&b);

			if(belong[a] && belong[b])
				printf("%d\n",maxLen);
			else if(belong[a]==0 && belong[b]==0) {
				t[0]=pos[remEu[a]];
				t[1]=pos[remEv[a]];
				t[2]=pos[remEu[b]];
				t[3]=pos[remEv[b]];
				sort(t,t+4);

				ans=max(query(1,t[0],1,maxNum,1).num,query(t[1],t[2],1,maxNum,1).num);
				ans=max(ans,query(t[3],maxNum,1,maxNum,1).num);
				ans=max(ans,subMax1);

				printf("%d\n",ans);
			}
			else {
				if(belong[a]) swap(a,b);
				t[0]=pos[remEu[a]];
				t[1]=pos[remEv[a]];
				if(t[0]>t[1]) swap(t[0],t[1]);

				int tid=pos[remEu[b]];
				if(subtree[tid].maxDiameter<subMax1) ans=subMax1;
				else ans=max(subMax2,subtree[tid].divid(b));

				tmp=subtree2[tid].divid(b);
				update(pos[remEu[b]],tmp,1,maxNum,1);

				ans=max(ans,max(query(1,t[0],1,maxNum,1).num,query(t[1],maxNum,1,maxNum,1).num));
				update(pos[remEu[b]],subtree2[pos[remEu[b]]].maxDep,1,maxNum,1);

				printf("%d\n",ans);
			}
		}
	}

	return 0;
}
