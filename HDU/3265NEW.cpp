#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

#define lc po*2
#define rc po*2+1
#define lson L,M,lc
#define rson M+1,R,rc
#define ji1 i*4-3
#define ji2 i*4-2
#define ji3 i*4-1
#define ji4 i*4

using namespace std;

struct BIAN
{
	int x,y1,y2;
	short state;
};

const int maxn=50015;

BIAN bian[maxn*4];
long long BIT[maxn*4];
int COL[maxn*4];

void callUP(int L,int R,int po)
{
	if(COL[po]>=1)
		BIT[po]=R+1-L;
	else if(L==R)
		BIT[po]=0;
	else
		BIT[po]=BIT[lc]+BIT[rc];
}

void pushUP(int L,int R,int po)
{
	if(L!=R)						//如果不判断会越界。
	{
		int temp=min(COL[lc],COL[rc]);

		COL[po]+=temp;
		COL[lc]-=temp;
		COL[rc]-=temp;

		callUP(L,(L+R)/2,lc);
		callUP((L+R)/2+1,R,rc);
	}

	callUP(L,R,po);
}

void pushDown(int L,int R,int po)
{
	if(COL[po])
	{
		COL[lc]+=COL[po];
		COL[rc]+=COL[po];

		callUP(L,(L+R)/2,lc);
		callUP((L+R)/2+1,R,rc);

		COL[po]=0;
		callUP(L,R,po);
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

	pushDown(L,R,po);

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
	int cas=1;
	long long ans;
	int x1,x2,y1,y2,x3,x4,y3,y4;

	ios::sync_with_stdio(false);
	cout.setf(ios::fixed);
	cout.precision(2);

	for(cin>>N;N;cin>>N)
	{
		memset(BIT,0,sizeof(BIT));
		memset(COL,0,sizeof(COL));

		for(int i=1;i<=N;++i)
		{
			cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;

			bian[ji1].state=1;
			bian[ji2].state=-1;
			bian[ji3].state=-1;
			bian[ji4].state=1;

			bian[ji1].x=x1;
			bian[ji2].x=x2;
			bian[ji3].x=x3;
			bian[ji4].x=x4;

			bian[ji1].y1=bian[ji2].y1=y1;
			bian[ji1].y2=bian[ji2].y2=y2;
			bian[ji3].y1=bian[ji4].y1=y3;
			bian[ji3].y2=bian[ji4].y2=y4;
		}

		sort(bian+1,bian+4*N+1,cmp);

		ans=0;

		for(int i=1;i<=4*N;++i)
		{
			ans+=(long long)BIT[1]*(bian[i].x-bian[i-1].x);			//要加强制转换。

			update(bian[i].y1,bian[i].y2-1,bian[i].state,0,49999,1);
		}
		
		cout<<ans<<endl;
	}

	return 0;
}
