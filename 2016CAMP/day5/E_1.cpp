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
// Created Time  : 2017年02月17日 星期五 11时20分35秒
// File Name     : E.cpp

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

const long long MaxN=100005<<1;

struct Edge {
        long long to,next;
};

Edge E[MaxN<<1];
long long head[MaxN],Ecou;
long long N;

typedef pair<long long,long long> pii;
pii rem[MaxN];

void init() {
        Ecou=0;
        for(long long i=1;i<=N;++i) head[i]=-1;
}

inline void addEdge(long long u,long long v) {
        E[Ecou].to=v;
        E[Ecou].next=head[u];
        head[u]=Ecou++;
}

long long num[MaxN],Index,pos[MaxN];
long long LL[MaxN],RR[MaxN];

int dep[MaxN];

void dfs(long long u,long long pre) {
		num[++Index]=u;
        LL[u]=Index;

        for(long long i=head[u];i!=-1;i=E[i].next)
                if(E[i].to!=pre) {
						dep[E[i].to]=dep[u]+1;
                        dfs(E[i].to,u);
				}

        num[++Index]=u;
        RR[u]=Index;
		pos[u]=Index;
}

/////////////////

#define lc (po<<1)
#define rc ((po<<1)|1)
#define lson L,M,lc
#define rson M+1,R,rc

long long col[MaxN<<2];

inline void pushDown(long long po) {
        if(col[po]) {
				if(dep[col[lc]]<dep[col[po]]) col[lc]=col[po];
				if(dep[col[rc]]<dep[col[po]]) col[rc]=col[po];
                col[po]=0;
        }
}

void build(long long L,long long R,long long po) {
        col[po]=0;
        if(L==R) return;

        long long M=(L+R)>>1;
        build(lson);
        build(rson);
}

void update(long long ul,long long ur,long long ut,long long L,long long R,long long po) {
        if(ul<=L && ur>=R) {
				if(dep[col[po]]<dep[ut]) col[po]=ut;
                return;
        }

        pushDown(po);

        long long M=(L+R)>>1;
        if(ul<=M) update(ul,ur,ut,lson);
        if(ur>M) update(ul,ur,ut,rson);
}

long long query(long long qp,long long L,long long R,long long po) {
        if(L==R) return col[po];

        pushDown(po);
        long long M=(L+R)>>1;

        if(qp<=M) return query(qp,lson);
        if(qp>M) return query(qp,rson);
}

/////////////////

//long long start[MaxN];
//long long ans[MaxN];

int next1[MaxN],pre1[MaxN];

inline void solve(long long u) {
        long long fa=query(pos[u],1,N+N,1);
        if(fa==u) return;

		int a=LL[u],b=RR[u];
		int x=LL[fa],y=RR[fa];
		int c=pre1[a],d=next1[b];

		int ta=a,tpre1x=pre1[x],tx=x,tb=b,td=d,tc=c;

		next1[pre1[x]]=ta;
		pre1[a]=pre1[x];

		next1[b]=tx;
		pre1[x]=tb;

		next1[c]=td;
		pre1[d]=tc;

        update(LL[u],RR[u],u,1,N+N,1);
}

int main() {
        //freopen("in.txt","r",stdin);
        //freopen("out.txt","w",stdout);

        long long p;

        while(~scanf("%lld",&N)) {
                init();
                Index=0;
                for(long long i=2;i<=N;++i) {
                        scanf("%lld",&p);
                        addEdge(p,i);
                        addEdge(i,p);
                }

                for(long long i=1;i<=N;++i) {
                        scanf("%lld",&p);
                        rem[i]=pii(p,i);
                }
                sort(rem+1,rem+N+1);

				dep[0]=0;
				dep[1]=1;
                dfs(1,-1);
				for(int i=0;i<=N+N+1;++i) next1[i]=i+1,pre1[i]=i-1;

                build(1,N+N,1);
                col[1]=1;
                for(long long i=1;i<=N;++i) solve(rem[i].second);

				for(int i=next1[0];i!=N+N+1;i=next1[i])
					if(pos[num[i]]==i) printf("%lld ",num[i]);
                puts("");
        }

        return 0;
}
