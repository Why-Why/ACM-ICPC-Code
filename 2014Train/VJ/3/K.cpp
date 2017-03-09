// abs and long long kengle me.......

#include<iostream>
#include<cstring>
#include<utility>
#include<algorithm>

using namespace std;

const int MaxN=70;
const int MaxM=70;
const int MaxNode=MaxN*MaxM;

int N,K;
long long X[70],Y[70];

long long abs1(long long x)
{
	if(x<0)
		x=-x;

	return x;
}

struct DLX
{
	int U[MaxNode],D[MaxNode],L[MaxNode],R[MaxNode],col[MaxNode];
	int S[MaxM],H[MaxN];
	int size,m,n;

	void init(int _n,int _m)
	{
		n=_n;
		m=_m;
		size=m;

		for(int i=0;i<=m;++i)
		{
			U[i]=D[i]=i;
			L[i]=i-1;
			R[i]=i+1;

			S[i]=0;
		}

		L[0]=m;
		R[m]=0;

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

		for(int i=R[0];i;i=R[i])
			vis[i]=1;

		for(int c=R[0];c;c=R[c])
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
			return d<=K;

		int c=R[0];

		for(int i=R[0];i;i=R[i])
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


pair <long long,int> rem[70][70];
long long remP[70];
DLX dlx;

void slove(long long maxNum)
{
	long long L=0,R=maxNum,M,ans;

	for(int i=1;i<=N;++i)
	{
		for(int j=1;j<=N;++j)
		{
			rem[i][j].first=(long long)abs1(X[i]-X[j])+(long long)abs1(Y[i]-Y[j]);
			rem[i][j].second=j;
		}

		sort(rem[i]+1,rem[i]+N+1);

		remP[i]=1;
	}

/*	dlx.init(N,N);

	for(M=L;M<=R;++M)
	{
		for(int i=1;i<=N;++i)
			while(rem[i][remP[i]].first<=M)
			{
				dlx.Link(i,rem[i][remP[i]].second);
				++remP[i];
			}

		if(dlx.Dance(0))
			break;
	}*/

	while(R>L)
	{
		M=(L+R)/2;

		dlx.init(N,N);

		for(int i=1;i<=N;++i)
			for(int j=1;j<=N;++j)
				if(rem[i][j].first<=M)
					dlx.Link(i,rem[i][j].second);
				else
					break;

		if(dlx.Dance(0))
			R=M;
		else
			L=M+1;
	}

	cout<<L<<endl;
}

int main()
{
	ios::sync_with_stdio(false);

	int T;
	long long maxX,maxY,minX,minY;
	cin>>T;

	for(int cas=1;cas<=T;++cas)
	{
		cin>>N>>K;

		cin>>X[1]>>Y[1];

		maxX=minX=X[1];
		maxY=minY=Y[1];

		for(int i=2;i<=N;++i)
		{
			cin>>X[i]>>Y[i];

			if(maxX<X[i])
				maxX=X[i];

			if(maxY<Y[i])
				maxY=Y[i];

			if(minX>X[i])
				minX=X[i];

			if(minY>Y[i])
				minY=Y[i];
		}

		cout<<"Case #"<<cas<<": ";
		slove(maxX+maxY-minX-minY);
	}

	return 0;
}
