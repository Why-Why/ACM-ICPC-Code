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
// Created Time  : 2015年07月04日 星期六 13时12分38秒
// File Name     : D.cpp

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

#define lc (po<<1)
#define rc ((po<<1)|1)
#define lson L,M,lc
#define rson M+1,R,rc

struct state
{
	long long bit,wul,wur,wua;

	state() {}
	state(long long a,long long b,long long c,long long d):bit(a),wul(b),wur(c),wua(d) {}
};

long long BIT[MaxN<<2];
long long wuL[MaxN<<2],wuR[MaxN<<2],wuA[MaxN<<2];

void pushUP(int po)
{
	BIT[po]=max(wuL[rc]+BIT[lc],wuR[lc]+BIT[rc]);
	BIT[po]=max(BIT[po],max(BIT[lc],BIT[rc]));

	wuL[po]=max(wuL[lc]+wuL[rc],wuA[lc]+BIT[rc]);
	wuL[po]=max(wuL[po],max(wuL[lc],BIT[rc]));

	wuR[po]=max(wuR[rc]+wuR[lc],wuA[rc]+BIT[lc]);
	wuR[po]=max(wuR[po],max(wuR[rc],BIT[lc]));

	wuA[po]=max(wuL[lc]+wuA[rc],wuR[rc]+wuA[lc]);
	wuA[po]=max(wuA[po],max(wuL[lc],wuR[rc]));
}

void update(int up,long long ut,int L,int R,int po)
{
	if(L==R)
	{
		BIT[po]=ut;
		wuL[po]=wuR[po]=wuA[po]=0;

		return;
	}

	int M=(L+R)>>1;

	if(up<=M)
		update(up,ut,lson);
	if(up>M)
		update(up,ut,rson);

	pushUP(po);
}

void build(int L,int R,int po)
{
	if(L==R)
	{
		scanf("%lld",&BIT[po]);
		wuL[po]=wuR[po]=wuA[po]=0;

		return;
	}

	int M=(L+R)>>1;

	build(lson);
	build(rson);

	pushUP(po);
}

state query(int ql,int qr,int L,int R,int po)
{
	if(ql<=L && qr>=R)
		return state(BIT[po],wuL[po],wuR[po],wuA[po]);

	int M=(L+R)>>1;

	if(ql>M)
		return query(ql,qr,rson);
	if(qr<=M)
		return query(ql,qr,lson);

	state lsta,rsta;

	lsta=query(ql,qr,lson);
	rsta=query(ql,qr,rson);

	state ret;

	ret.bit=max(max(lsta.bit,rsta.bit),max(rsta.wul+lsta.bit,lsta.wur+rsta.bit));
	ret.wul=max(max(lsta.wul,rsta.bit),max(lsta.wul+rsta.wul,lsta.wua+rsta.bit));
	ret.wur=max(max(rsta.wur,lsta.bit),max(rsta.wur+lsta.wur,rsta.wua+lsta.bit));
	ret.wua=max(max(rsta.wur,lsta.wul),max(lsta.wul+rsta.wua,rsta.wur+lsta.wua));

	return ret;
}

int N,Q;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d",&N,&Q);

	build(1,N,1);

	int a,b,c;

	while(Q--)
	{
		scanf("%d %d %d",&a,&b,&c);

		if(a==1)
			update(b+1,c,1,N,1);
		else
			printf("%lld\n",query(b+1,c+1,1,N,1).bit);
	}
	
	return 0;
}
