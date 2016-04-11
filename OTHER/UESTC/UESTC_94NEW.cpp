#include<iostream>
#include<cstdio>
#include<cstring>

#define lson L,M,po*2
#define rson M+1,R,po*2+1
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)

using namespace std;

int BIT[100015*4];
int QS[100015*4];
int MS[100015*4];
int XOR[100015*4];
int COL[100015*4];
char ss[100015];

void pushUP(int po)
{
    BIT[po]=BIT[po*2]+BIT[po*2+1];
	QS[po]=max(QS[po*2],BIT[po*2]+QS[po*2+1]);			//这里要注意。
	MS[po]=min(MS[po*2],BIT[po*2]+MS[po*2+1]);
}

void pushDown(int po,int len)
{
    if(COL[po])
    {
        COL[po*2]=COL[po];
        COL[po*2+1]=COL[po];
		XOR[po*2]=XOR[po*2+1]=0;				//这里不能忘记。
        BIT[po*2]=(len-(len/2))*COL[po];
        BIT[po*2+1]=(len/2)*COL[po];
		
		QS[po*2]=max(-1,BIT[po*2]);
		QS[po*2+1]=max(-1,BIT[po*2+1]);
		MS[po*2]=min(1,BIT[po*2]);
		MS[po*2+1]=min(1,BIT[po*2+1]);

		COL[po]=0;
    }

    if(XOR[po])
    {
		int temp;

		XOR[po*2]=!XOR[po*2];
		XOR[po*2+1]=!XOR[po*2+1];

        BIT[po*2]=-BIT[po*2];
        BIT[po*2+1]=-BIT[po*2+1];

		temp=QS[po*2];
		QS[po*2]=-MS[po*2];
		MS[po*2]=-temp;

		temp=QS[po*2+1];
		QS[po*2+1]=-MS[po*2+1];
		MS[po*2+1]=-temp;

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
            BIT[po]=1;
			QS[po]=1;
			MS[po]=1;
		}
        else
		{
		 	BIT[po]=-1;
			QS[po]=-1;
			MS[po]=-1;
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
		
		QS[po]=max(-1,BIT[po]);
		MS[po]=min(1,BIT[po]);

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
		XOR[po]=!XOR[po];
        BIT[po]=-BIT[po];

		int temp=QS[po];
		QS[po]=-MS[po];
		MS[po]=-temp;

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

int query(int &qs,int ql,int qr,int L,int R,int po)			//不能忘记写 ＆ ！！！
{
    if(ql<=L&&qr>=R)
    {
		qs=MS[po];
		return BIT[po];
	}

    pushDown(po,R-L+1);

    int M=(L+R)/2;
    int ans=0;

    if(qr<=M)
        return query(qs,ql,qr,lson);
    if(ql>M)
        return query(qs,ql,qr,rson);

	int temp1,temp2,a1;

	a1=query(temp1,ql,qr,lson);
	ans=a1+query(temp2,ql,qr,rson);

	qs=min(temp1,temp2+a1);

    return ans;
}

bool getans(int ql,int qr,int N)
{
	int t1;
	int ans;

	if((qr-ql)%2==0)
		return 0;

	ans=query(t1,ql,qr,0,N,1);

	if(ans==0&&t1==0)
		return 1;
	else
		return 0;
}

int main()
{
    int T;
    int N,Q;
    char t1[20],t2[20];
    int a,b;
    cin>>T;

    for(int cas=1;cas<=T;++cas)
    {
        printf("Case %d:\n",cas);

        scanf("%d",&N);
        scanf("%s",ss);

        build_tree(0,N-1,1);					//这里应该是N-1。

        scanf("%d",&Q);

        for(int i=0;i<Q;++i)
        {
            scanf("%s %d %d",t1,&a,&b);

            if(t1[0]=='s')
            {
                scanf("%s",t2);
                update_col(a,b,t2[0]=='('?1:-1,0,N-1,1);
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
