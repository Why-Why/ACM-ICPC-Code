#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string.h>
#include <vector>
using namespace std;

#define LL              long long
#define REP(i,a,b)      for(int i=a;i<b;++i)
#define MOD             1000000007
#define maxn            1000011
#define mset(a,b)       memset(a,b,sizeof a)

int m[20],a[20];

void gcd(LL a,LL b,LL& d,LL& x,LL& y){
    if(!b){d=a;x=1;y=0;}
    else {gcd(b,a%b,d,y,x);y-=x*(a/b);}
}

LL inv(LL a,LL n)
{
    LL d,x,y;
    gcd(a,n,d,x,y);
    return d==1?(x+n)%n:-1;
}

LL mul(LL a,LL b,LL m)
{
	LL ret=0;
	while(b)
	{
		if(b&1) (ret+=a)%=m;
		b>>=1;
		(a<<=1)%=m;
	}

	return ret;
}

LL china(int n,int *a,int *m)
{
    LL M=1,d,x=0,y;
    REP(i,0,n)  M*=m[i];
    REP(i,0,n)
    {
        LL w=M/m[i];
        gcd(m[i],w,d,d,y);
        x=(x+y*w*a[i])%M;
		x=(x+mul(mul(y,w,M),a[i],M));
    }
    return (x%M+M)%M;
}

int np(LL n,int p,int *a)
{
    int k=0;
    while(n)
    {
        a[k++]=n%p;
        n/=p;
    }
    return k;
}

int nmp(LL n,LL m,int p)
{
    int xn[77],kn=0,km=0,xm[77];
    kn=np(n,p,xn);
    km=np(m,p,xm);
    REP(i,0,km)
    {
        if(xm[i]>xn[i]) return 1;
    }
    return 0;
}

int jiep(LL n,int p)
{
    int k=n/p;
    int md=n%p;
    int ret=(k%2)?-1:1;
    if(md==0)   return ret;
    if(md==p-1) return -1*ret;
    int mo=1;
    REP(i,2,md+1)
    {
        mo*=i;
        mo%=p;
    }
    return mo*ret;
}

int cp(LL n,LL m,int p)
{
    if(!nmp(n,m,p))
    {
        LL ret=jiep(n,p);
        ret*=inv(jiep(m,p),p);
        ret%=p;
        ret*=inv(jiep(n-m,p),p);
        ret%=p;
        return ret;
    }
    else return 0;
}

int main()
{
    LL mm,n;
    int k,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%I64d%I64d%d",&n,&mm,&k);
        REP(i,0,k)
            scanf("%d",&m[i]);
        REP(i,0,k)
        {
            if(n==mm)   a[i]=1;
            else a[i]=cp(n,mm,m[i]);
        }
        LL ans=china(k,a,m);
        printf("%lld\n",ans);
    }


    return 0;
}
