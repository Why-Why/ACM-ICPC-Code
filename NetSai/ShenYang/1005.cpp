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
// Created Time  : 2015年09月20日 星期日 23时23分52秒
// File Name     : 1005.cpp

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

const int MaxN=400005;
const int MaxQ=50004;

#define lc (po<<1)
#define rc ((po<<1)|1)
#define lson L,M,lc
#define rson M+1,R,rc

struct BIT
{
	long long ZHI[MaxN<<2];
	long long ANG[MaxN<<2];
	long long RANG[MaxN<<2];
	long long COL[MaxN<<2];

	void pushUP(int len,int po)
	{
		ZHI[po]=ZHI[lc]+ZHI[rc];
		ANG[po]=ANG[lc]+ANG[rc]+ZHI[rc]*((len+1)/2);
		RANG[po]=RANG[lc]+RANG[rc]+ZHI[lc]*(len/2);
	}

	void pushDown(int len,int po)
	{
		if(COL[po])
		{
			long long llen=(len+1)/2,rlen=len/2;
			ZHI[lc]+=COL[po]*llen;
			ZHI[rc]+=COL[po]*rlen;
			ANG[lc]+=(llen+1)*llen*COL[po]/2;
			ANG[rc]+=(rlen+1)*rlen*COL[po]/2;
			RANG[lc]+=(llen+1)*llen*COL[po]/2;
			RANG[rc]+=(rlen+1)*rlen*COL[po]/2;

			COL[lc]+=COL[po];
			COL[rc]+=COL[po];
			COL[po]=0;
		}
	}

	void update(int ul,int ur,int L,int R,int po)
	{
		if(ul<=L && ur>=R)
		{
			++COL[po];
			ZHI[po]+=R-L+1LL;
			ANG[po]+=(R-L+1LL)*(R-L+2LL)/2;
			RANG[po]+=(R-L+1LL)*(R-L+2LL)/2;
			return;
		}

		pushDown(R-L+1,po);
		int M=(L+R)>>1;

		if(ul<=M) update(ul,ur,lson);
		if(ur>M) update(ul,ur,rson);

		pushUP(R-L+1,po);
	}

	long long query_ZHI(int ql,int qr,int L,int R,int po)
	{
		if(ql<=L && qr>=R)
			return ZHI[po];

		pushDown(R-L+1,po);
		int M=(L+R)>>1;
		long long ret=0;

		if(qr>M) ret+=query_ZHI(ql,qr,rson);
		if(ql<=M) ret+=query_ZHI(ql,qr,lson);

		return ret;
	}

	long long query_ANG(long long & zhi,int ql,int qr,int L,int R,int po)
	{
		if(ql<=L && qr>=R)
		{
			zhi=ZHI[po];
			return ANG[po];
		}

		pushDown(R-L+1,po);
		int M=(L+R)>>1;
		long long t1,t2,t3,t4;

		if(ql>M) return query_ANG(zhi,ql,qr,rson);
		if(qr<=M) return query_ANG(zhi,ql,qr,lson);

		t1=query_ANG(t3,ql,M,lson);
		t2=query_ANG(t4,M+1,qr,rson);
		zhi=t3+t4;

		return t1+t2+t4*(M-ql+1);
	}

	long long query_RANG(long long & zhi,int ql,int qr,int L,int R,int po)
	{
		if(ql<=L && qr>=R)
		{
			zhi=ZHI[po];
			return RANG[po];
		}

		pushDown(R-L+1,po);
		int M=(L+R)>>1;
		long long t1,t2,t3,t4;

		if(ql>M) return query_RANG(zhi,ql,qr,rson);
		if(qr<=M) return query_RANG(zhi,ql,qr,lson);

		t1=query_RANG(t3,ql,M,lson);
		t2=query_RANG(t4,M+1,qr,rson);
		zhi=t3+t4;

		return t1+t2+t3*(qr-M);
	}

	void init()
	{
		memset(ZHI,0,sizeof(ZHI));
		memset(COL,0,sizeof(COL));
		memset(ANG,0,sizeof(ANG));
		memset(RANG,0,sizeof(RANG));
	}
};

BIT bit1,bit2;
int N,Q;

long long getans(int x1,int x2,int y1,int y2)
{
	long long ret=0,temp;
	int len,qlen;
	int j1,j2;

	if(x2-x1>=y2-y1) len=x2-x1-y2+y1,qlen=y2-y1;
	else len=y2-y1-x2+x1,qlen=x2-x1;

	j1=x1+y1-1;
	j2=x2+y2-1;
	ret+=bit1.query_ANG(temp,j1,j1+qlen,1,2*N-1,1) \
		 +(qlen+1LL)*bit1.query_ZHI(j1+qlen+1,j1+qlen+len,1,2*N-1,1) \
		 +bit1.query_RANG(temp,j1+qlen+len+1,j2,1,2*N-1,1);

	j1=x1-y2+N;
	j2=x2-y1+N;

	ret+=bit2.query_ANG(temp,j1,j1+qlen,1,2*N-1,1) \
		 +(qlen+1LL)*bit2.query_ZHI(j1+qlen+1,j1+qlen+len,1,2*N-1,1) \
		 +bit2.query_RANG(temp,j1+qlen+len+1,j2,1,2*N-1,1);

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T,cas=1;
	int op,a,b,c,d;
	scanf("%d",&T);

	while(T--)
	{
		scanf("%d %d",&N,&Q);
		bit1.init();
		bit2.init();

		printf("Case #%d:\n",cas++);

		while(Q--)
		{
			scanf("%d",&op);
			if(op==1)
			{
				scanf("%d %d",&a,&b);
				bit1.update(a-1,b-1,1,2*N-1,1);
			}
			else if(op==2)
			{
				scanf("%d %d",&a,&b);
				bit2.update(a+N,b+N,1,2*N-1,1);
			}
			else
			{
				scanf("%d %d %d %d",&a,&b,&c,&d);
				printf("%I64d\n",getans(a,b,c,d));
			}
		}
	}
	
	return 0;
}
