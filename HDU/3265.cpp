#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

#define lc po*2
#define rc po*2+1
#define lson L,M,lc
#define rson M+1,R,rc

using namespace std;

struct BIAN
{
	int x,y1,y2;
	short state;
};

const int maxn=50005;

BIAN bian[50005*8];
int BIT[maxn*4];
int COL[maxn*4];

void pushUP(int L,int R,int po)
{
	if(COL[po])
		BIT[po]=R+1-L;
	else if(L==R)
		BIT[po]=0;
	else
		BIT[po]=BIT[lc]+BIT[rc];
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
	long long ans;
	int x1,x2,x3,x4,y1,y2,y3,y4;

	while(~scanf("%d",&N))
	{
		if(!N)
			break;

		memset(COL,0,sizeof(COL));
		memset(BIT,0,sizeof(BIT));
		ans=0;

		for(int i=1;i<=N;++i)
		{
			scanf("%d %d %d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);

			bian[i*8-5].x=x1;
			bian[i*8-5].y1=y1;
			bian[i*8-5].y2=y2;
			bian[i*8-5].state=1;
			
			bian[i*8-4].x=x3;
			bian[i*8-4].y1=y1;
			bian[i*8-4].y2=y2;
			bian[i*8-4].state=-1;

			bian[i*8-3].x=x4;
			bian[i*8-3].y1=y1;
			bian[i*8-3].y2=y2;
			bian[i*8-3].state=1;

			bian[i*8-2].x=x2;
			bian[i*8-2].y1=y1;
			bian[i*8-2].y2=y2;
			bian[i*8-2].state=-1;

			bian[i*8-1].x=x3;
			bian[i*8-1].y1=y4;
			bian[i*8-1].y2=y2;
			bian[i*8-1].state=1;

			bian[i*8].x=x4;
			bian[i*8].y1=y4;
			bian[i*8].y2=y2;
			bian[i*8].state=-1;

			bian[i*8-7].x=x3;
			bian[i*8-7].y1=y1;
			bian[i*8-7].y2=y3;
			bian[i*8-7].state=1;

			bian[i*8-6].x=x4;
			bian[i*8-6].y1=y1;
			bian[i*8-6].y2=y3;
			bian[i*8-6].state=-1;
		}

		sort(bian+1,bian+8*N+1,cmp);

		for(int i=1;i<=8*N;++i)
		{
			ans+=(long long)BIT[1]*(bian[i].x-bian[i-1].x);
			
			if(bian[i].y2>bian[i].y1)
				update(bian[i].y1,bian[i].y2-1,bian[i].state,0,50000,1);
		}

		cout<<ans<<endl;
	}

	return 0;
}
