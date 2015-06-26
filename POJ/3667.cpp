#include<iostream>
#include<cstdio>
#include<cstring>

#define lson L,M,po*2
#define rson M+1,R,po*2+1
#define lc po*2
#define rc po*2+1

using namespace std;

const int maxn=50005;

int msum[maxn*4],lsum[maxn*4],rsum[maxn*4];
int COL[maxn*4];

void pushDown(int po,int len)
{
	if(COL[po]==1)
	{
		COL[lc]=COL[rc]=1;
		msum[lc]=rsum[lc]=lsum[lc]=0;
		msum[rc]=rsum[rc]=lsum[rc]=0;

		COL[po]=-1;
	}
	else if(COL[po]==0)
	{
		COL[lc]=COL[rc]=0;
		msum[lc]=rsum[lc]=lsum[lc]=len-(len/2);
		msum[rc]=rsum[rc]=lsum[rc]=len/2;

		COL[po]=-1;
	}
}

void pushUP(int po,int len)
{
	msum[po]=max(msum[lc],msum[rc]);
	msum[po]=max(msum[po],rsum[lc]+lsum[rc]);

	lsum[po]=lsum[lc];
	if(lsum[lc]==(len-(len/2)))
		lsum[po]+=lsum[rc];

	rsum[po]=rsum[rc];
	if(rsum[rc]==len/2)
		rsum[po]+=rsum[lc];
}

void build_tree(int L,int R,int po)
{
	COL[po]=-1;
	msum[po]=rsum[po]=lsum[po]=R-L+1;

	if(L==R)
		return;

	int M=(L+R)/2;

	build_tree(lson);
	build_tree(rson);
}

void update(int ul,int ur,int ut,int L,int R,int po)
{
	if(ul<=L&&ur>=R)
	{
		COL[po]=ut;
		msum[po]=lsum[po]=rsum[po]=(ut ? 0 : R-L+1);

		return;
	}

	pushDown(po,R-L+1);

	int M=(L+R)/2;

	if(ul<=M)
		update(ul,ur,ut,lson);
	if(ur>M)
		update(ul,ur,ut,rson);

	pushUP(po,R-L+1);
}

int query(int len,int L,int R,int po)
{
	if(L==R)
		return L;

	pushDown(po,R-L+1);

	int M=(L+R)/2;

	if(msum[lc]>=len)
		return query(len,lson);
	else if(rsum[lc]+lsum[rc]>=len)
		return M-rsum[lc]+1;
	else
		return query(len,rson);
}

int main()
{
	int M,N;
	int a,b,c;

	while(~scanf("%d %d",&N,&M))
	{
		build_tree(1,N,1);

		for(int i=0;i<M;++i)
		{
			scanf("%d %d",&a,&b);

			if(a==1)
			{
				if(msum[1]<b)
					printf("%d\n",0);
				else
				{
					c=query(b,1,N,1);
					update(c,c+b-1,1,1,N,1);
					printf("%d\n",c);
				}
			}
			else
			{
				scanf("%d",&c);
				update(b,b+c-1,0,1,N,1);
			}
		}
	}

	return 0;
}
