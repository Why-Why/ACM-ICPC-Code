#include<iostream>
#include<cstring>

using namespace std;

const int INF=10e8;
const int MaxN=70;
const int MaxM=70;
const int MaxNode=MaxN*MaxM;

struct DLX
{
	int L[MaxNode],R[MaxNode],U[MaxNode],D[MaxNode],col[MaxNode],row[MaxNode];
	int S[MaxM],H[MaxN];
	int n,m,size;
	int ans;

	void init(int _n,int _m)
	{
		n=_n;
		m=_m;

		for(int i=0;i<=m;++i)
		{
			U[i]=D[i]=i;
			R[i]=i+1;
			L[i]=i-1;
			row[i]=0;				// !!!

			S[i]=0;
		}

		R[m]=0;
		L[0]=m;

		size=m;
		ans=INF;

		for(int i=0;i<=n;++i)		// !!!
			H[i]=-1;
	}

	void Link(int r,int c)
	{
		col[++size]=c;
		++S[c];
		row[size]=r;

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

	void remove1(int r)
	{
		if(H[r]==-1)
			return;

		for(int i=U[H[r]];i!=H[r];i=U[i])
		{
			if(H[row[i]]==i)			// !!!
			{
				if(R[i]==i)
					H[row[i]]=-1;
				else
					H[row[i]]=R[i];
			}

			L[R[i]]=L[i];
			R[L[i]]=R[i];
		}

		for(int i=R[H[r]];i!=H[r];i=R[i])
			for(int j=U[i];j!=i;j=U[j])
			{
				if(H[row[j]]==j)
				{
					if(R[j]==j)
						H[row[j]]=-1;
					else
						H[row[j]]=R[j];
				}

				L[R[j]]=L[j];
				R[L[j]]=R[j];
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

int N;
DLX dlx;
int ans1[6]={0,1,3,6,9,14};

void slove()
{
	dlx.init(2*N*(N+1),N*(N+1)*(2*N+1)/6);

	int t1,t2;
	int cou=0;
	int K,a;

	cin>>K;

	if(K==0)
	{
		cout<<ans1[N]<<endl;
		return;
	}

	for(int i=1;i<=N;++i)
		for(int j=1;j<=(N-i+1)*(N-i+1);++j)
		{
			++cou;

			t1=(j-1)%(N-i+1)+1+(2*N+1)*((j-1)/(N-i+1));

			for(int k=0;k<i;++k)
			{
				dlx.Link(k+t1,cou);
				dlx.Link((2*N+1)*k+t1+i-1+N+1,cou);
				dlx.Link((2*N+1)*k+t1+N,cou);
				dlx.Link(k+t1+i*(2*N+1),cou);
			}
		}

	for(int i=0;i<K;++i)
	{
		cin>>a;

		dlx.remove1(a);
	}

	dlx.Dance(0);

	if(dlx.ans==INF)
		cout<<0<<endl;
	else
		cout<<dlx.ans<<endl;
}

int main()
{
	ios::sync_with_stdio(false);

	int T;
	cin>>T;

	while(T--)
	{
		cin>>N;

		slove();
	}

	return 0;
}
