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
// Created Time  : 2016年07月22日 星期五 10时15分18秒
// File Name     : 1008.cpp

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

const int MaxN=4000000+500000+10;

struct Point {
    int x,y,v;

    Point() {}
    Point(int a,int b,int c):x(a),y(b),v(c) {}

    bool operator < (const Point & b) const {
        if(x!=b.x) return x<b.x;
        if(y!=b.y) return y<b.y;
        return v<b.v;
    }
};

int N,M;

Point P[MaxN];
int pcou;

int hnum[MaxN],hcou;

int qu[1005];
int sum1[1005],sum0[1005];

char ans[500005];

inline int hash1(int x) {
    return (lower_bound(hnum,hnum+hcou,x)-hnum)+1;
}

int C[MaxN];

inline int lowbit(int x) {
    return x&(-x);
}

inline void add(int p,int x) {
    for(;p<=hcou;p+=lowbit(p)) C[p]+=x;
}

inline int sum(int p) {
    int ret=0;
    for(;p;p-=lowbit(p)) ret+=C[p];
    return ret;
}

void getans() {
    for(int i=0;i<=hcou;++i) C[i]=0;

    for(int i=0;i<pcou;++i)
        if(P[i].v>1) {
            if(sum(hash1(P[i].y))>0) ans[P[i].v>>1]='1';
        }
        else add(hash1(P[i].y),P[i].v);
}

inline int read() {
	int ret=0;
	char c=0;

	while(c<'0' || c>'9') c=getchar();
	ret=c-'0';
	while(c=getchar(),c>='0' && c<='9') ret=ret*10+c-'0';
	return ret;
}

int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int T;
	T=read();

    int x,y,xL,xR,yL,yR;

    while(T--) {
		N=read();
		M=read();
        pcou=0;
        hcou=0;
        sum1[0]=sum0[0]=0;

        for(int i=1;i<=N;++i) {
			qu[i]=read();
            sum1[i]=sum1[i-1];
            sum0[i]=sum0[i-1];

            if(i&1) {
                P[pcou++]=Point(0,0,1);
                P[pcou++]=Point(1,0,-1);
                P[pcou++]=Point(0,qu[i]+1,-1);
                P[pcou++]=Point(1,qu[i]+1,1);

                hnum[hcou++]=0;
                hnum[hcou++]=qu[i]+1;

                sum0[i]+=qu[i];
            }
            else {
                P[pcou++]=Point(0,0,1);
                P[pcou++]=Point(qu[i]+1,0,-1);
                P[pcou++]=Point(0,1,-1);
                P[pcou++]=Point(qu[i]+1,1,1);

                hnum[hcou++]=0;
                hnum[hcou++]=1;

                sum1[i]+=qu[i];
            }
        }

        for(int i=1;i<N;++i)
            for(int j=i+1;j<=N;++j) {

                xL=sum1[j-1]-sum1[i];
                yL=sum0[j-1]-sum0[i];

                if(!(i&1)) ++xL; else ++yL;
                if(!(j&1)) ++xL; else ++yL;

                xR=sum1[j]-sum1[i-1];
                yR=sum0[j]-sum0[i-1];

                P[pcou++]=Point(xL,yL,1);
                P[pcou++]=Point(xL,yR+1,-1);
                P[pcou++]=Point(xR+1,yL,-1);
                P[pcou++]=Point(xR+1,yR+1,1);

                hnum[hcou++]=yL;
                hnum[hcou++]=yR+1;
            }

        for(int i=1;i<=M;++i) {
			y=read();
			x=read();

            P[pcou++]=Point(x,y,i<<1);
            hnum[hcou++]=y;

            ans[i]='0';
        }
        ans[M+1]=0;

        sort(hnum,hnum+hcou);
        hcou=unique(hnum,hnum+hcou)-hnum;

        sort(P,P+pcou);

        getans();
        puts(ans+1);
    }

    return 0;
}
