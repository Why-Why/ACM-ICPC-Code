#include<iostream>
#include<cstring>

using namespace std;

const int INF=10e8;
const int MaxN=250;
const int MaxM=250;
const int MaxNode=MaxN*MaxM;

struct DLX
{
	int R[MaxNode],L[MaxNode],U[MaxNode],D[MaxNode],col[MaxNode];
	int ans,size,n,m;
	int H[MaxN],S[MaxM];
	bool VIS[MaxM];

	void init(int _n,int _m)
	{
		n=_n;
		m=_m;

		for(int i=0;i<=m;++i)
		{
			U[i]=D[i]=i;
			L[i]=i-1;
			R[i]=i+1;

			S[i]=0;
			VIS[i]=0;
		}

		L[0]=m;
		R[m]=0;

		size=m;
		ans=INF;

		for(int i=0;i<=n;++i)
			H[i]=-1;
	}

	void Link(int r,int c)
	{
		if(VIS[c])
			return;

		col[++size]=c;
		++S[c];

		U[size]=U[c];
		D[size]=c;
		D[U[c]]=size;
		U[c]=size;

		if(H[r]==-1)
			H[r]=L[size]=R[size]=size;
		else
		{
			L[size]=L[H[r]];
			R[size]=H[r];
			R[L[H[r]]]=size;
			L[H[r]]=size;
		}
	}

	void remove(int c)
	{
		for(int i=D[c];i!=c;i=D[i])
		{
			L[R[i]]=L[i];
			R[L[i]]=R[i];
		}
	}

	void resume(int c)
	{
		for(int i=U[c];i!=c;i=U[i])
			L[R[i]]=R[L[i]]=i;
	}

	bool vis[MaxM];

	int getH()
	{
		int ret=0;

		for(int i=R[0];i!=0;i=R[i])
			vis[i]=1;

		for(int c=R[0];c!=0;c=R[c])
			if(vis[c])
			{
				++ret;
				vis[c]=0;

				for(int i=D[c];i!=c;i=D[i])
					for(int j=R[i];j!=i;j=R[j])
						vis[col[j]]=0;
			}

		return ret;
	}

	void removeCOL(int c)
	{
		L[R[c]]=L[c];
		R[L[c]]=R[c];

		VIS[c]=1;
	}

	void Dance(int d)
	{
		if(d+getH()>=ans)
			return;

		if(R[0]==0)
		{
			if(d<ans)
				ans=d;

			return;
		}

		int c=R[0];

		for(int i=R[0];i!=0;i=R[i])
			if(S[i]<S[c])
				c=i;

		for(int i=D[c];i!=c;i=D[i])
		{
			remove(i);

			for(int j=R[i];j!=i;j=R[j])
				remove(j);

			Dance(d+1);

			for(int j=L[i];j!=i;j=L[j])
				resume(j);

			resume(i);
		}
	}
};

int N,M,N1,M1;
DLX dlx;

int main()
{
	ios::sync_with_stdio(false);

	int a;
	int cou;

	while(cin>>N>>M)
	{
		cou=0;
		dlx.init(N*M,N*M);

		for(int i=1;i<=N;++i)
			for(int j=1;j<=M;++j)
			{
				cin>>a;

				if(!a)
					dlx.removeCOL((i-1)*M+j);
			}

		cin>>N1>>M1;

		for(int i=1;i+N1<=N+1;++i)
			for(int j=1;j+M1<=M+1;++j)
			{
				++cou;
				for(int x=i;x<i+N1;++x)
					for(int y=j;y<j+M1;++y)
						dlx.Link(cou,(x-1)*M+y);
			}

		dlx.Dance(0);

		if(dlx.ans==INF)
			cout<<0<<endl;
		else
			cout<<dlx.ans<<endl;
	}

	return 0;
}
