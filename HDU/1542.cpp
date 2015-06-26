#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>

#define lson L,M,lc
#define rson M+1,R,rc
#define lc po*2
#define rc po*2+1

using namespace std;

struct BIAN
{
	double x,y1,y2;
	int state;
};

BIAN bian[210];
double hash[210];
double BIT[210*4];
int COL[210*4];
int COU;

bool cmp(BIAN a,BIAN b)
{
	return a.x<b.x;
}

int find(double x)
{
	int L=1,R=COU;
	int M;

	while(R>L)
	{
		M=(L+R)/2;

		if(fabs(hash[M]-x)<0.000001)
			return M;

		if(hash[M]<x)
			L=M+1;
		else
			R=M-1;
	}

	return L;
}

void pushUP(int L,int R,int po)
{
	if(COL[po])
		BIT[po]=hash[R+1]-hash[L];
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

		if(COL[po]>0)
			BIT[po]=hash[R+1]-hash[L];
		else if(L==R)
			BIT[po]=0;
		else
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

int main()
{
	int cas=0;
	int N;
	double x1,x2,y1,y2;
	double ans;

	for(cin>>N;N;cin>>N)
	{
		ans=0;
		COU=1;
		memset(hash,0,sizeof(hash));
		memset(COL,0,sizeof(COL));
		memset(BIT,0,sizeof(BIT));

		for(int i=1;i<=N;++i)
		{
			scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);

			bian[i*2-1].x=x1;
			bian[i*2-1].y1=y1;
			bian[i*2-1].y2=y2;
			bian[i*2-1].state=1;

			bian[i*2].x=x2;
			bian[i*2].y1=y1;
			bian[i*2].y2=y2;
			bian[i*2].state=-1;

			hash[COU++]=y1;
			hash[COU++]=y2;
		}

		sort(hash+1,hash+COU);
		sort(bian+1,bian+2*N+1,cmp);

		int k=2;
		for(int i=2;i<COU;++i)
			if(hash[i]!=hash[i-1])
				hash[k++]=hash[i];
		COU=k-1;

		for(int i=1;i<=2*N;++i)
		{
			ans+=BIT[1]*(bian[i].x-bian[i-1].x);

			update(find(bian[i].y1),find(bian[i].y2)-1,bian[i].state,1,COU-1,1);
		}

		ans+=BIT[1];
		printf("Test case #%d\nTotal explored area: %.2f\n\n",++cas,ans);
	}

	return 0;
}
