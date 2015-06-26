#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

#define lc po*2
#define rc po*2+1
#define lson L,M,lc
#define rson M+1,R,rc

using namespace std;

const int maxn=20004;

struct BIAN
{
	int x,y1,y2;
	short state;
};

BIAN bian[10004];
bool vis[maxn];
int BIT[maxn*4];
int COL[maxn*4];

bool lBIT[maxn*4],rBIT[maxn*4];
int coubian[maxn*4];

void pushUP(int L,int R,int po)
{
	if(COL[po])
	{
		BIT[po]=R-L+1;
		lBIT[po]=rBIT[po]=1;
		coubian[po]=2;
	}
	else if(L==R)
	{
		BIT[po]=0;
		lBIT[po]=rBIT[po]=0;
		coubian[po]=0;
	}
	else
	{
		BIT[po]=BIT[lc]+BIT[rc];
		lBIT[po]=lBIT[lc];
		rBIT[po]=rBIT[rc];
		coubian[po]=coubian[lc]+coubian[rc];

		if(lBIT[rc]&&rBIT[lc])
			coubian[po]-=2;
	}
}

void update(int ul,int ur,int ut,int L,int R,int po)
{
	if(ul<=L&&ur>=R)
	{
		COL[po]+=ut;
		pushUP(L,R,po);

		return;
	}

	int M=(L+R)/2;

	if(ul<=M)
		update(ul,ur,ut,lson);
	if(ur>M)
		update(ul,ur,ut,rson);

	pushUP(L,R,po);
}

bool cmp(BIAN a,BIAN b)
{
	return a.x<b.x;
}

int main()
{
	int N;
	int x1,x2,y1,y2;
	int ans,last;

	while(~scanf("%d",&N))
	{
		ans=0;
		last=0;
		memset(COL,0,sizeof(COL));
		memset(BIT,0,sizeof(BIT));
		memset(vis,0,sizeof(vis));
		memset(lBIT,0,sizeof(lBIT));
		memset(rBIT,0,sizeof(rBIT));
		memset(coubian,0,sizeof(coubian));

		for(int i=1;i<=N;++i)
		{
			scanf("%d %d %d %d",&x1,&y1,&x2,&y2);

			bian[i*2-1].x=x1;
			bian[i*2-1].y1=y1+10001;
			bian[i*2-1].y2=y2+10001;
			bian[i*2-1].state=1;

			bian[i*2].x=x2;
			bian[i*2].y1=y1+10001;
			bian[i*2].y2=y2+10001;
			bian[i*2].state=-1;
		}

		sort(bian+1,bian+2*N+1,cmp);

		for(int i=1;i<=2*N;++i)
		{
			ans+=coubian[1]*(bian[i].x-bian[i-1].x);

			update(bian[i].y1,bian[i].y2-1,bian[i].state,1,20001,1);

			ans+=abs(BIT[1]-last);
			last=BIT[1];
		}

		printf("%d\n",ans);
	}

	return 0;
}
