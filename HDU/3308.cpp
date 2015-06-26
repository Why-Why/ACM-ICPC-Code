#include<iostream>
#include<cstdio>
#include<cstring>

#define lson L,M,po*2
#define rson M+1,R,po*2+1
#define lc po*2
#define rc po*2+1

using namespace std;

const int maxn=10e5+10;

int mBIT[maxn*4],lBIT[maxn*4],rBIT[maxn*4];
int num[maxn];

void pushUP(int po,int len,int M)
{
	mBIT[po]=max(mBIT[lc],mBIT[rc]);
	lBIT[po]=lBIT[lc];
	rBIT[po]=rBIT[rc];

	if(num[M]<num[M+1])
	{
		mBIT[po]=max(mBIT[po],rBIT[lc]+lBIT[rc]);
		
		if(lBIT[lc]==len-(len/2))
			lBIT[po]+=lBIT[rc];

		if(rBIT[rc]==(len/2))
			rBIT[po]+=rBIT[lc];
	}
}

void build_tree(int L,int R,int po)
{
	if(L==R)
	{
		scanf("%d",&num[L]);
		mBIT[po]=lBIT[po]=rBIT[po]=1;

		return;
	}

	int M=(L+R)/2;

	build_tree(lson);
	build_tree(rson);

	pushUP(po,R-L+1,M);
}

void update(int up,int L,int R,int po)
{
	if(L==R&&L==up)
		return;

	int M=(L+R)/2;

	if(up<=M)
		update(up,lson);
	else
		update(up,rson);

	pushUP(po,R-L+1,M);
}

int query(int ql,int qr,int L,int R,int po)
{
	if(ql<=L&&qr>=R)
		return mBIT[po];

	int M=(L+R)/2;

	if(qr<=M)
		return query(ql,qr,lson);
	if(ql>M)
		return query(ql,qr,rson);

	int ans=max(query(max(ql,L),M,lson),query(M+1,min(qr,R),rson));
	int temp=min(rBIT[lc],M-ql+1)+min(lBIT[rc],qr-M);

	if(num[M]<num[M+1])							//这里要判断！
		return max(ans,temp);
	else
		return ans;
}

int main()
{
	int N,M;
	int a,b;
	char c[5];
	int T;
	cin>>T;

	while(T--)
	{
		scanf("%d %d",&N,&M);

		build_tree(0,N-1,1);

		while(M--)
		{
			scanf("%s %d %d",c,&a,&b);

			if(c[0]=='Q')
				printf("%d\n",query(a,b,0,N-1,1));
			else
			{
				num[a]=b;
				update(a,0,N-1,1);
			}
		}
	}

	return 0;
}
