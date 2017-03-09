#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

const int MaxN=50004;

int fa[MaxN];
int fnum[MaxN];
int N,K;

int find(int &num,int x)
{
	if(fa[x]==-1)
		return x;

	fa[x]=find(num,fa[x]);
	num+=fnum[x];
	fnum[x]=num;

	return fa[x];
}

void hebing(int t1,int t2,int n1,int n2,int d)
{
	fa[t2]=t1;

	if(d==1)
		fnum[t2]=n1-n2;
	else
		fnum[t2]=n1-n2+1;
}

inline int mo(int x)
{
	int t=x%3;

	if(t<0)
		t+=3;

	return t;
}

bool judge(int n1,int n2,int d)
{
	if(d==1 && mo(n1) != mo(n2))
		return 0;

	if(d==2 && mo(n1+1) != mo(n2))
		return 0;

	return 1;
}

void slove()
{
	int d,a,b;
	int t1,t2,n1,n2;
	int ans=0;

	for(int i=0;i<K;++i)
	{
		scanf("%d %d %d",&d,&a,&b);

		if(a>N || b>N || (a==b && d==2))
		{
			++ans;
			continue;
		}

		n1=n2=0;
		t1=find(n1,a);
		t2=find(n2,b);

		if(t1==t2 && !judge(n1,n2,d))
			++ans;
		else if(t1 != t2)
			hebing(t1,t2,n1,n2,d);
//		cout<<ans<<endl;
	}

	printf("%d\n",ans);
}

int main()
{
	//freopen("out.tst","w",stdout);
	scanf("%d %d",&N,&K);

	for(int i=1;i<=N;++i)
	{
		fa[i]=-1;
		fnum[i]=0;
	}

	slove();

	return 0;
}
