#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

const int MaxN=100;
const int MaxM=100;
const int MaxNode=MaxN*MaxM;
const int INF=10e8;

struct DLX
{
	int U[MaxNode],D[MaxNode],L[MaxNode],R[MaxNode],col[MaxNode];
	int H[MaxN],S[MaxM];
	int ans;
	int n,m,size;

	void init(int _n,int _m)
	{
		n=_n;
		m=_m;
		size=m;
		ans=INF;

		for(int i=0;i<=m;++i)
		{
			L[i]=i-1;
			R[i]=i+1;
			U[i]=D[i]=i;

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

	bool vis1[MaxM];

	int getH()
	{
		int ret=0;

		for(int i=R[0];i!=0;i=R[i])
			vis1[i]=1;

		for(int i=R[0];i!=0;i=R[i])
			if(vis1[i])
			{
				++ret;
				vis1[i]=0;

				for(int j=D[i];j!=i;j=D[j])
					for(int k=R[j];k!=j;k=R[k])
						vis1[col[k]]=0;								//!!!!!!!!!!!!!!
			}

		return ret;
	}

	void Dance(int d)
	{
		if(getH()+d>=ans)
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

DLX dlx;
int N,M,R;
int C[10][10];
int lans[10][10][10];

void getC()
{
	for(int i=0;i<=8;++i)
		C[i][0]=1;

	for(int i=1;i<=8;++i)
		for(int j=1;j<=i;++j)
			C[i][j]=C[i-1][j-1]+C[i-1][j];
}

void numTOp(int *s,int x,int n,int m,int d)
{
	if(m<=0)
		return;

	if(x>=C[n-1][m-1])
		numTOp(s,x-C[n-1][m-1],n-1,m,d+1);
	else
	{
		s[0]=d;
		numTOp(s+1,x,n-1,m-1,d+1);
	}
}

int pTOnum(int *s1,int *s2)
{
	int vis[10],ans1=0;

	memset(vis,0,sizeof(vis));

	for(int i=0;i<R;++i)
		vis[s1[s2[i]-1]]=1;

	int tR=R-1;

	for(int i=1;i<=N && tR>=0;++i)
	{
		if(vis[i]==0)
			ans1+=C[N-i][tR];
		else
			--tR;
	}

	return ans1;
}

void slove()
{
	int s[10];
	int ts[10],temp;

	dlx.init(C[N][M],C[N][R]);

	for(int i=0;i<C[N][M];++i)
	{
		numTOp(s,i,N,M,1);

		for(int j=0;j<C[M][R];++j)
		{
			numTOp(ts,j,M,R,1);

			temp=pTOnum(s,ts);

			dlx.Link(i+1,temp+1);
		}
	}

	dlx.Dance(0);
}

int main()
{
	ios::sync_with_stdio(false);
	
	freopen("out.txt","w",stdout);

	int T;

	cin>>T;

	getC();

	for(N=1;N<=8;++N)
	{
		cout<<'{';
		
		for(M=1;M<=N;++M)
		{
			cout<<'{';

			for(R=1;R<=M;++R)
			{
				if(N==8 && M==5 && R==4)
					cout<<20;
				else
				{
					slove();
					cout<<dlx.ans;
				}

				if(R!=M)
					cout<<',';
			}

			cout<<'}';

			if(M!=N)
				cout<<',';
		}

		cout<<'}';

		if(N!=8)
			cout<<',';
	}

/*	for(int cas=1;cas<=T;++cas)
	{
		cin>>N>>M>>R;

		cout<<"Case #"<<cas<<": "<<lans[N][M][R]<<endl;
	}*/

	return 0;
}
