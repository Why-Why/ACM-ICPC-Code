#include<iostream>
#include<cstdio>
#include<cstring>

#define lc po*2
#define rc po*2+1
#define lson L,M,lc
#define rson M+1,R,rc

using namespace std;

const int maxn=1e5+5;

int sum[maxn*4],lsum[2][maxn*4],rsum[2][maxn*4],msum[2][maxn*4];
int COL[maxn*4],XOR[maxn*4];

inline void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}

void pushUP(int po,int len)
{
	sum[po]=sum[lc]+sum[rc];
	
	for(int i=0;i<2;++i)
	{
		msum[i][po]=max(msum[i][lc],msum[i][rc]);
		msum[i][po]=max(msum[i][po],lsum[i][rc]+rsum[i][lc]);
	
		lsum[i][po]=lsum[i][lc];
		if(lsum[i][lc]==(len-(len/2)))
			lsum[i][po]+=lsum[i][rc];
	
		rsum[i][po]=rsum[i][rc];
		if(rsum[i][rc]==(len/2))
			rsum[i][po]+=rsum[i][lc];
	}
}

void pushDown(int po,int len)
{
	if(COL[po]!=-1)
	{
		COL[lc]=COL[rc]=COL[po];
		XOR[lc]=XOR[rc]=0;

		sum[lc]=COL[po]*(len-(len/2));
		sum[rc]=COL[po]*(len/2);

		for(int i=0;i<2;++i)
		{
			msum[i][lc]=lsum[i][lc]=rsum[i][lc]=(i ? sum[lc] : len-(len/2)-sum[lc]);
			msum[i][rc]=rsum[i][rc]=lsum[i][rc]=(i ? sum[rc] : (len/2)-sum[rc]);
		}

		COL[po]=-1;
	}

	if(XOR[po])
	{
		XOR[lc]=!XOR[lc];
		XOR[rc]=!XOR[rc];

		sum[lc]=len-(len/2)-sum[lc];
		sum[rc]=(len/2)-sum[rc];

		swap(msum[0][lc],msum[1][lc]);
		swap(msum[0][rc],msum[1][rc]);

		swap(lsum[0][lc],lsum[1][lc]);
		swap(rsum[0][lc],rsum[1][lc]);

		swap(lsum[0][rc],lsum[1][rc]);
		swap(rsum[0][rc],rsum[1][rc]);

		XOR[po]=0;
	}
}

void build_tree(int L,int R,int po)
{
	COL[po]=-1;
	XOR[po]=0;

	if(L==R)
	{
		int temp;
		scanf("%d",&temp);

		sum[po]=temp;
		lsum[0][po]=rsum[0][po]=msum[0][po]=1-temp;
		lsum[1][po]=rsum[1][po]=msum[1][po]=temp;

		return;
	}

	int M=(L+R)/2;

	build_tree(lson);
	build_tree(rson);

	pushUP(po,R-L+1);
}

void update_col(int ul,int ur,int ut,int L,int R,int po)
{
	if(ul<=L&&ur>=R)
	{
		COL[po]=ut;
		XOR[po]=0;

		sum[po]=ut*(R-L+1);
		lsum[1][po]=rsum[1][po]=msum[1][po]=sum[po];
		lsum[0][po]=rsum[0][po]=msum[0][po]=R-L+1-sum[po];

		return;
	}

	pushDown(po,R-L+1);

	int M=(L+R)/2;

	if(ul<=M)
		update_col(ul,ur,ut,lson);
	if(ur>M)
		update_col(ul,ur,ut,rson);

	pushUP(po,R-L+1);
}

void update_xor(int ul,int ur,int L,int R,int po)
{
	if(ul<=L&&ur>=R)
	{
		XOR[po]=!XOR[po];

		sum[po]=R-L+1-sum[po];
		swap(msum[0][po],msum[1][po]);
		swap(lsum[0][po],lsum[1][po]);
		swap(rsum[0][po],rsum[1][po]);

		return;
	}

	pushDown(po,R-L+1);

	int M=(L+R)/2;

	if(ul<=M)
		update_xor(ul,ur,lson);
	if(ur>M)
		update_xor(ul,ur,rson);

	pushUP(po,R-L+1);
}

int query_sum(int ql,int qr,int L,int R,int po)
{
	if(ql<=L&&qr>=R)
		return sum[po];

	pushDown(po,R-L+1);

	int M=(L+R)/2;

	if(qr<=M)
		return query_sum(ql,qr,lson);
	if(ql>M)
		return query_sum(ql,qr,rson);

	return query_sum(ql,qr,lson)+query_sum(ql,qr,rson);
}

int query_max(int ql,int qr,int L,int R,int po)
{
	if(ql<=L&&qr>=R)
		return msum[1][po];

	pushDown(po,R-L+1);

	int M=(L+R)/2;
	int ans=0;

	if(qr<=M)
		return query_max(ql,qr,lson);
	if(ql>M)
		return query_max(ql,qr,rson);

	ans=max(query_max(ql,qr,lson),query_max(ql,qr,rson));
	ans=max(ans,min(rsum[1][lc],M-ql+1)+min(lsum[1][rc],qr-M));			//!!!

	return ans;
}

int main()
{
	int T;
	int N,M;
	int a,b,c;
	cin>>T;

	while(T--)
	{
		scanf("%d %d",&N,&M);

		build_tree(0,N-1,1);

		while(M--)
		{
			scanf("%d %d %d",&a,&b,&c);

			switch(a)
			{
				case 0:
					update_col(b,c,0,0,N-1,1);
					break;
				case 1:
					update_col(b,c,1,0,N-1,1);
					break;
				case 2:
					update_xor(b,c,0,N-1,1);
					break;
				case 3:
					printf("%d\n",query_sum(b,c,0,N-1,1));
					break;
				case 4:
					printf("%d\n",query_max(b,c,0,N-1,1));
					break;
			}
		}
	}

	return 0;
}
