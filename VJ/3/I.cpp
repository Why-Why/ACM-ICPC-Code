#include<iostream>
#include<cstring>

using namespace std;

const int MaxN=1010;
const int MaxM=1010;
const int MaxNode=MaxN*MaxM;

struct DLX
{
	int L[MaxNode],R[MaxNode],U[MaxNode],D[MaxNode],col[MaxNode];
	int H[MaxN],S[MaxM];
	int ansnum;
	int n,m,size;

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
		}
		L[0]=m;
		R[m]=0;

		size=m;

		ansnum=0;

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

	int getH()
	{
		int ret=0;

		for(int i=R[0];i!=0;i=R[i])
			++ret;

		return ret;
	}

	void Dance(int d)
	{
		if(R[0]==0)
		{
			if(d>ansnum)
				ansnum=d;

			return;
		}

		if(getH()+d<=ansnum)
			return;

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

DLX dlx;
unsigned long long num[1010];
int N;

void slove()
{
	dlx.init(N,N);

	for(int i=1;i<=N;++i)
		for(int j=1;j<=N;++j)
			if(num[i]%num[j]==0 || num[j]%num[i]==0)
				dlx.Link(i,j);

	dlx.Dance(0);

	cout<<dlx.ansnum<<endl;
}

int main()
{
	ios::sync_with_stdio(false);

	int T;
	cin>>T;

	while(T--)
	{
		cin>>N;

		for(int i=1;i<=N;++i)
			cin>>num[i];

		slove();
	}

	return 0;
}
