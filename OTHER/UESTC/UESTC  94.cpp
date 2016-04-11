#include<iostream>
#include<cstdio>

#define lson L,M,po*2
#define rson M+1,R,po*2+1

using namespace std;

int BIT[100005*4];
bool QB[100005*4];
bool HB[100005*4];
bool XOR[100005*4];
int COL[100005*4];
char ss[100005];

void pushUP(int po)
{
    BIT[po]=BIT[po*2]+BIT[po*2+1];

	if(QB[po*2]&&BIT[po]>=0)
		QB[po]=1;
	else
		QB[po]=0;

	if(HB[po*2+1]&&BIT[po]<=0)
		HB[po]=1;
	else
		HB[po]=0;
}

void pushDown(int po,int len)
{
    if(COL[po])
    {
        COL[po*2]=COL[po];
        COL[po*2+1]=COL[po];
        XOR[po*2]=0;
		XOR[po*2+1]=0;
		BIT[po*2]=(len-(len/2))*COL[po];
        BIT[po*2+1]=(len/2)*COL[po];
        
		if(COL[po]==1)
		{
			QB[po*2]=QB[po*2+1]=1;
			HB[po*2]=HB[po*2+1]=0;
		}
		else
		{
			QB[po*2]=QB[po*2+1]=0;
			HB[po*2]=HB[po*2+1]=1;
		}

        COL[po]=0;
    }

    if(XOR[po])
    {
		if(COL[po*2])
			COL[po*2]=-COL[po*2];
		else
			XOR[po*2]=!XOR[po*2];

		if(COL[po*2+1])
			COL[po*2+1]=-COL[po*2+1];
		else
			XOR[po*2+1]=!XOR[po*2+1];

		BIT[po*2]=-BIT[po*2];
        BIT[po*2+1]=-BIT[po*2+1];
        
		QB[po*2]=!QB[po*2];
		HB[po*2]=!HB[po*2];
		QB[po*2+1]=!QB[po*2+1];
		HB[po*2+1]=!HB[po*2+1];

		if(BIT[po*2]>0)
			HB[po*2]=0;
		if(BIT[po*2]<0)
			QB[po*2]=0;
		if(BIT[po*2+1]>0)
			HB[po*2+1]=0;
		if(BIT[po*2+1]<0)
			QB[po*2+1]=0;

        XOR[po]=0;
    }
}

void build_tree(int L,int R,int po)
{
    XOR[po]=0;
    COL[po]=0;

    if(L==R)
    {
        if(ss[L]=='(')
        {
            BIT[po]=QB[po]=1;
			HB[po]=0;
		}
        else
		{
		 	BIT[po]=-1;
			QB[po]=0;
			HB[po]=1;
		}

        return;
    }

    int M=(L+R)/2;

    build_tree(lson);
    build_tree(rson);

    pushUP(po);
}

void update_col(int ul,int ur,int ut,int L,int R,int po)
{
    if(ul<=L&&ur>=R)
    {
        XOR[po]=0;
        COL[po]=ut;
        BIT[po]=ut*(R-L+1);
		
		if(ut==1)
		{
			QB[po]=1;
			HB[po]=0;
		}
		else if(ut==-1)
		{
			QB[po]=0;
			HB[po]=1;
		}

        return;
    }

    pushDown(po,R-L+1);

    int M=(L+R)/2;

    if(ul<=M)
        update_col(ul,ur,ut,lson);
    if(ur>M)
        update_col(ul,ur,ut,rson);

    pushUP(po);
}

void update_xor(int ul,int ur,int L,int R,int po)
{
    if(ul<=L&&ur>=R)
    {
		if(COL[po])
			COL[po]=-COL[po];
		else
	        XOR[po]=!XOR[po];
    
		BIT[po]=-BIT[po];

		QB[po]=!QB[po];
		HB[po]=!HB[po];

		if(BIT[po]>0)
			HB[po]=0;
		if(BIT[po]<0)
			QB[po]=0;

        return;
    }

    pushDown(po,R-L+1);

    int M=(L+R)/2;

    if(ul<=M)
        update_xor(ul,ur,lson);
    if(ur>M)
        update_xor(ul,ur,rson);

    pushUP(po);
}

int query(bool &qs,bool &hs,int ql,int qr,int L,int R,int po)
{
    if(ql<=L&&qr>=R)
    {
		qs=QB[po];
		hs=HB[po];
		return BIT[po];
	}

    pushDown(po,R-L+1);

	bool temp1,temp2,temp3,temp4;
    int M=(L+R)/2;
    int ans=0;

    if(qr<=M)
        return query(qs,hs,ql,qr,lson);
    if(ql>M)
        return query(qs,hs,ql,qr,rson);

	ans=query(temp1,temp2,ql,qr,lson)+query(temp3,temp4,ql,qr,rson);

	if(temp1&&ans>=0)
		qs=1;
	else
		qs=0;

	if(temp4&&ans<=0)
		hs=1;
	else
		hs=0;

    return ans;
}

bool getans(int ql,int qr,int N)
{
	bool t1,t2;
	int ans;

	ans=query(t1,t2,ql,qr,0,N,1);

	if(ans==0&&t1&&t2)
		return 1;
	else
		return 0;
}

int main()
{
    int T;
    int N,Q;
    char t1[20];
    int a,b;
    cin>>T;

    for(int cas=1;cas<=T;++cas)
    {
        printf("Case %d:\n",cas);

        scanf("%d",&N);
        scanf("%s",ss);

        build_tree(0,N-1,1);

        scanf("%d",&Q);

        for(int i=0;i<Q;++i)
        {
            scanf("%s %d %d",t1,&a,&b);

            if(t1[0]=='s')
            {
                scanf("%s",t1);
                update_col(a,b,t1[0]=='('?1:-1,0,N-1,1);
            }
            else if(t1[0]=='r')
                update_xor(a,b,0,N-1,1);
            else
                if(getans(a,b,N-1))
                    printf("YES\n");
                else
                    printf("NO\n");
        }

        printf("\n");
    }

    return 0;
}
