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
// Created Time  : 2015年10月13日 星期二 17时27分11秒
// File Name     : F.cpp

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

const int MaxN=2000005;
const int INF=0x3f3f3f3f;

struct Num
{
    int a,b;

    Num() {}
    Num(int x,int y):a(x),b(y) {}

    bool operator < (const Num & y) const
    {
        return a==y.a ? b<y.b : a<y.a;
    }

    bool operator > (const Num & y) const
    {
        return a==y.a ? b>y.b : a>y.a;
    }

    bool operator == (const Num & y) const
    {
        return a==y.a && b==y.b;
    }

    Num operator + (const Num & y) const
    {
        return Num(a+y.a,b+y.b);
    }
};

struct State
{
	Num n;
	int base;
	long long route;

	bool operator < (const State &b) const
	{
		return n<b.n;
	}

	bool operator == (const State &b) const
	{
		return n==b.n;
	}
};

bool cmp(const State &a,const State &b)
{
	return a.n==b.n ? a.base>b.base : a.n<b.n;
}

State sta[MaxN];
int cou;

int N;
Num rem[30][3];
int rnum[30];

int bbb;
long long lll;

void dfs1(int d,Num tn,int b,long long l)
{
    if(d>((N+1)>>1))
    {
		sta[cou].n=tn;
		sta[cou].base=b;
		sta[cou++].route=l;
        return;
    }

    for(int i=0;i<3;++i)
        dfs1(d+1,tn+rem[d][i],b+(i ? rnum[d] : 0),(l<<2)|i);
}

void dfs2(int d,Num tn,int b,long long l)
{
    if(d>N)
    {
		State ts;
		ts.n.a=-tn.a;
		ts.n.b=-tn.b;

		int p=lower_bound(sta,sta+cou,ts)-sta;

		if(p<cou && sta[p]==ts && sta[p].base+b>bbb)
		{
			bbb=sta[p].base+b;
			lll=(sta[p].route<<(2*(N/2)))|l;
		}

        return;
    }

    for(int i=0;i<3;++i)
        dfs2(d+1,tn+rem[d][i],b+(i ? rnum[d] : 0),(l<<2)|i);
}

void show()
{
	int rrr[30];

    for(int i=0;i<N;++i)
    {
        rrr[i]=lll & 3;
        lll>>=2;
    }

    for(int i=N-1;i>=0;--i)
        if(rrr[i]==0) puts("MW");
        else if(rrr[i]==1) puts("LW");
        else puts("LM");
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int a,b,c;

    scanf("%d",&N);
    for(int i=1;i<=N;++i)
    {
        scanf("%d %d %d",&a,&b,&c);
        rnum[i]=a;
        rem[i][0]=Num(b,c);
        rem[i][1]=Num(-a,c-a);
        rem[i][2]=Num(b-a,-a);
    }

	cou=0;
    bbb=-INF;
    dfs1(1,Num(0,0),0,0);
	sort(sta,sta+cou,cmp);
	cou=unique(sta,sta+cou)-sta;
    dfs2((N+1)/2+1,Num(0,0),0,0);

    if(bbb==-INF) puts("Impossible");
    else show();
    
    return 0;
}
