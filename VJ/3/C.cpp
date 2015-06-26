#include<iostream>
#include<cstring>

using namespace std;

const int MaxN=55;
const int MaxM=55;
const int MaxNode=MaxN*MaxM;

int K;
int N,M;

struct DLX
{
	int D[MaxNode],U[MaxNode],L[MaxNode],R[MaxNode],col[MaxNode];
	int H[MaxN],S[MaxM];
	int n,m,size;

	void init(int _n,int _m)
	{
		n=_n;
		m=_m;

		for(int i=0;i<=m;++i)
		{
			D[i]=U[i]=i;
			L[i]=i-1;
			R[i]=i+1;
			
			S[i]=0;
		}
		L[0]=m;
		R[m]=0;
		
		size=m;

		for(int i=0;i<=n;++i)
			H[i]=-1;
	}

	void Link(int r,int c)
	{
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
			R[L[i]]=R[i];
			L[R[i]]=L[i];
		}
	}

	void resume(int c)
	{
		for(int i=U[c];i!=c;i=U[i])
			R[L[i]]=L[R[i]]=i;
	}

	bool vis[MaxM];

	int getH()
	{
		int ret=0;

		for(int c=R[0];c!=0;c=R[c])
			vis[c]=1;

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

	bool Dance(int d)
	{
		if(d+getH()>K)
			return 0;

		if(R[0]==0)
		{
			if(d<=K)
				return 1;
			return 0;
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

			if(Dance(d+1))
				return 1;

			for(int j=L[i];j!=i;j=L[j])
				resume(j);

			resume(i);
		}

		return 0;
	}
};

DLX dlx;
int Rx[60],Ry[60],Cx[60],Cy[60];

void solve()
{
	double L=0,R=1001.0,Mid;

	while(R-L>0.0000001)
	{
		Mid=(L+R)/2;

		dlx.init(M,N);

		for(int i=1;i<=M;++i)
			for(int j=1;j<=N;++j)
				if(Mid*Mid>=(Rx[i]-Cx[j])*(Rx[i]-Cx[j])+(Ry[i]-Cy[j])*(Ry[i]-Cy[j]))
					dlx.Link(i,j);

		if(dlx.Dance(0))
			R=Mid;
		else
			L=Mid;
	}

	cout<<L<<endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cout.setf(ios::fixed);
	cout.precision(6);

	int T;
	cin>>T;

	while(T--)
	{
		cin>>N>>M>>K;

		for(int i=1;i<=N;++i)
			cin>>Cx[i]>>Cy[i];

		for(int i=1;i<=M;++i)
			cin>>Rx[i]>>Ry[i];

		solve();
	}

	return 0;
}
