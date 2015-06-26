#include<iostream>
#include<cstring>

using namespace std;

const int INF=10e8;
const int MaxN=600;
const int MaxM=33*33;
const int MaxNode=900*500+10;

struct DLX
{
	int n,m,size;
	int U[MaxNode],D[MaxNode],L[MaxNode],R[MaxNode],col[MaxNode];
	int S[MaxM],H[MaxN];
	int ans;

	void init(int _n,int _m)
	{
		n=_n;
		m=_m;

		ans=INF;

		for(int i=0;i<=m;++i)
		{
			S[i]=0;
			U[i]=D[i]=i;
			L[i]=i-1;
			R[i]=i+1;
		}
		L[0]=m;
		R[m]=0;

		size=m;

		for(int i=0;i<=n;++i)
			H[i]=-1;
	}

	void Link(int r,int c)	//r is row , c is col.
	{
		col[++size]=c;
		++S[c];

		U[size]=U[c];
		D[U[c]]=size;
		D[size]=c;
		U[c]=size;

		if(H[r]<0)
			H[r]=L[size]=R[size]=size;
		else
		{
			R[size]=H[r];
			L[size]=L[H[r]];
			R[L[H[r]]]=size;
			L[H[r]]=size;
		}
	}

	void remove(int c)
	{
		R[L[c]]=R[c];
		L[R[c]]=L[c];

		for(int i=D[c];i!=c;i=D[i])
			for(int j=R[i];j!=i;j=R[j])
			{
				D[U[j]]=D[j];
				U[D[j]]=U[j];
				--S[col[j]];
			}
	}

	void resume(int c)
	{
		for(int i=U[c];i!=c;i=U[i])
			for(int j=L[i];j!=i;j=L[j])
			{
				++S[col[j]];
				D[U[j]]=U[D[j]]=j;
			}

		R[L[c]]=L[R[c]]=c;
	}

	void Dance(int d)
	{
		if(R[0]==0)
		{
			if(d<ans)
				ans=d;

			return;
		}

		if(d>ans)
			return;

		int c=R[0];
		
		for(int i=R[0];i!=0;i=R[i])
			if(S[i]<S[c])
				c=i;

		remove(c);

		for(int i=D[c];i!=c;i=D[i])
		{
			for(int j=R[i];j!=i;j=R[j])
				remove(col[j]);

			Dance(d+1);

			for(int j=L[i];j!=i;j=L[j])
				resume(col[j]);
		}

		resume(c);
	}
};

DLX dlx;

int main()
{
	ios::sync_with_stdio(false);

	int T;
	int n,m,p;
	int x1,x2,y1,y2;
	cin>>T;

	while(T--)
	{
		cin>>n>>m>>p;

		dlx.init(p,(n)*(m));

		for(int i=1;i<=p;++i)
		{
			cin>>x1>>y1>>x2>>y2;

			for(int x=x1;x<x2;++x)
				for(int y=y1;y<y2;++y)
					dlx.Link(i,y*(n)+x+1);
		}

		dlx.Dance(0);

		if(dlx.ans==INF)
			cout<<-1<<endl;
		else
			cout<<dlx.ans<<endl;
	}

	return 0;
}
