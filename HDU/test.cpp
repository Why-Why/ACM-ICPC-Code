#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>

#define lc po*2
#define rc po*2+1
#define lson L,M,lc
#define rson M+1,R,rc
#define ji i*2-1
#define ou i*2

using namespace std;

struct BIAN
{
	double x,y1,y2;
	short state;
};

const int maxn=205;

BIAN bian[maxn];
double BIT[maxn*4];
double BIT1[maxn*4];
int COL[maxn*4];
double hash[maxn];
int COU;

int find(double x)
{
	int L=1,R=COU,M;

	while(R>L)
	{
		M=(L+R)/2;

		if(fabs(x-hash[M])<0.0000001)
			return M;

		if(hash[M]<x)
			L=M+1;
		else
			R=M-1;
	}
	
	return L;
}

void callUP(int L,int R,int po)
{
	if(COL[po]>=2)
		BIT[po]=hash[R+1]-hash[L];
	else if(L==R)
	{
		if(COL[po])
		{
			BIT[po]=0;
			BIT1[po]=hash[R+1]-hash[L];
		}
		else
			BIT[po]=BIT1[po]=0;
	}
	else
		if(COL[po])
		{
			BIT[po]=BIT[lc]+BIT[rc]+BIT1[lc]+BIT1[rc];
			BIT1[po]=BIT1[lc]+BIT1[rc];
		}
		else
		{
			BIT1[po]=BIT1[lc]+BIT1[rc];
			BIT[po]=BIT[lc]+BIT[rc];
		}
}

void pushUP(int L,int R,int po)
{
	int temp=min(COL[lc],COL[rc]);

	COL[po]+=temp;
	COL[lc]-=temp;
	COL[rc]-=temp;

	callUP(L,(L+R)/2,lc);
	callUP((L+R)/2+1,R,rc);

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

		callUP(L,R,po);

		COL[po]=0;
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
	double ans;
	double x1,x2,y1,y2;

	ios::sync_with_stdio(false);
	cout.setf(ios::fixed);
	cout.precision(2);

	for(cin>>N;N;cin>>N)
	{
		memset(BIT,0,sizeof(BIT));
		memset(BIT1,0,sizeof(BIT1));
		memset(COL,0,sizeof(COL));
		memset(hash,0,sizeof(hash));

		for(int i=1;i<=N;++i)
		{
			cin>>x1>>y1>>x2>>y2;

			hash[ji]=y1;
			hash[ou]=y2;

			bian[ji].state=1;
			bian[ou].state=-1;

			bian[ji].x=x1;
			bian[ou].x=x2;

			bian[ji].y1=bian[ou].y1=y1;
			bian[ji].y2=bian[ou].y2=y2;
		}

		sort(bian+1,bian+2*N+1,cmp);
		sort(hash+1,hash+2*N+1);

		COU=2;
		for(int i=2;i<=2*N;++i)
			if(hash[i]!=hash[i-1])
				hash[COU++]=hash[i];
		--COU;

		ans=0;

		for(int i=1;i<=2*N;++i)
		{
			ans+=BIT[1]*(bian[i].x-bian[i-1].x);

			update(find(bian[i].y1),find(bian[i].y2)-1,bian[i].state,1,COU,1);
		}

		cout<<"Test case #"<<cas++<<endl;
		cout<<"Total explored area: "<<ans<<endl<<endl;
	}

	return 0;
}
