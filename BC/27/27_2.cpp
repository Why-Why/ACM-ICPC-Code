#include<iostream>
#include<cstring>

using namespace std;

const int MaxN=10e5+100;

long long C[MaxN];
int n,m;

inline int lowbit(int x)
{
    return x&(-x);
}

void add(int x,int d)  //the place of x adds d
{
    while(x<=n)
    {
        C[x]+=d;
        x+=lowbit(x);
    }
}

long long sum(int x)
{
    long long ans=0;

    while(x>0)
    {
        ans+=C[x];
        x-=lowbit(x);
    }

    return ans;
}

long long getsum(int x,int y)
{
	long long ans=sum(y-1)-sum(x-1);

	return ans;
}

int main()
{
	ios::sync_with_stdio(false);

	int T,a;
	int b;
	long long ans;
	bool fang;
	cin>>T;

	while(T--)
	{
		cin>>n>>m;
		ans=0;

		memset(C,0,sizeof(C));

		for(int i=1;i<=n-1;++i)
		{
			cin>>a;
			add(i,a);
		}

		for(int i=1;i<=m;++i)
		{
			cin>>a>>b;
			ans=0;

			if((i-1)%n+1<=a)
			{
				ans+=getsum((i-1)%n+1,a);
				fang=1;
			}
			else
			{
				ans+=getsum((i-1)%n+1,n)+getsum(a,n);
				fang=0;
			}

			if(b>a && fang==1)
				ans+=getsum(a,b);
			else if(b<a && fang==0)
				ans+=getsum(b,a);
			else if(b>a && fang==0)
				ans+=getsum(1,a)+getsum(1,b);
			else
				ans+=getsum(b,n)+getsum(a,n);

			cout<<ans<<endl;
		}
	}

	return 0;
}
