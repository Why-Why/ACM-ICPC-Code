#include<iostream>
#include<cstring>

using namespace std;

const int MaxN=800;
const int MaxM=350;
const int MaxNode=MaxN*MaxM;

struct DLX
{
	int U[MaxNode],D[MaxNode],L[MaxNode],R[MaxNode],col[MaxNode],row[MaxNode];
	int size,n,m;
	int H[MaxN],S[MaxM];
	int ans[100],ans1[100];

	void init(int _n,int _m)
	{
		n=_n;
		m=_m;

		for(int i=0;i<=m;++i)
		{
			U[i]=D[i]=i;
			L[i]=i-1;
			R[i]=i+1;
			row[i]=0;

			S[i]=0;
		}
		L[0]=m;
		R[m]=0;

		size=m;

		for(int i=1;i<=n;++i)
			H[i]=-1;
	}

	void Link(int r,int c)
	{
		col[++size]=c;
		row[size]=r;
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
		L[R[c]]=L[c];
		R[L[c]]=R[c];

		for(int i=D[c];i!=c;i=D[i])
			for(int j=R[i];j!=i;j=R[j])
			{
				U[D[j]]=U[j];
				D[U[j]]=D[j];
				--S[col[j]];
			}
	}

	void resume(int c)
	{
		for(int i=U[c];i!=c;i=U[i])
			for(int j=L[i];j!=i;j=L[j])
			{
				U[D[j]]=j;
				D[U[j]]=j;
				++S[col[j]];
			}

		L[R[c]]=R[L[c]]=c;
	}

	void showans(int d)
	{
		for(int i=0;i<d;++i)
			ans1[(ans[i]-1)/9+1]=(ans[i]-1)%9+1;

		for(int i=1;i<=81;++i)
			cout<<ans1[i];

		cout<<endl;
	}

	bool Dance(int d)
	{
		if(R[0]==0)
		{
			showans(d);
			return 1;
		}

		int c=R[0];

		for(int i=R[0];i!=0;i=R[i])
			if(S[i]<S[c])
				c=i;

		remove(c);

		for(int i=D[c];i!=c;i=D[i])
		{
			ans[d]=row[i];

			for(int j=R[i];j!=i;j=R[j])
				remove(col[j]);

			if(Dance(d+1))
				return 1;

			for(int j=L[i];j!=i;j=L[j])
				resume(col[j]);
		}

		resume(c);

		return 0;
	}

	void display()
	{
		for(int i=R[0];i!=0;i=R[i])
		{
			cout<<i<<' ';
			for(int j=D[i];j!=i;j=D[j])
				cout<<'('<<j<<','<<(row[j]-1)%9+1<<')'<<' ';

			cout<<endl;
		}
	}
};

DLX dlx;
char s[100];

void slove()
{
	dlx.init(729,324);

	for(int i=1;i<=81;++i)
		for(int j=1;j<=9;++j)
			dlx.Link(j+(i-1)*9,i);

	for(int i=1;i<=81;++i)
		for(int j=1;j<=9;++j)
			dlx.Link(9*(j-1)+(i-1)%9+1+81*((i-1)/9),i+81);

	for(int i=1;i<=81;++i)
		for(int j=1;j<=9;++j)
			dlx.Link((j-1)*81+i,i+162);

	for(int i=1;i<=3;++i)
		for(int j=1;j<=3;++j)
			for(int k=1;k<=9;++k)
				for(int l=1;l<=3;++l)
					for(int m=1;m<=3;++m)
						dlx.Link((i-1)*243+(j-1)*27+k+(l-1)*81+(m-1)*9,(i-1)*27+(j-1)*9+k+243);

	for(int i=0;i<81;++i)
		if(s[i]!='.')
		{
			dlx.ans1[i+1]=s[i]-'0';

			dlx.remove(i+1);

			for(int j=dlx.D[i+1];j!=i+1;j=dlx.D[j])
			{
				if((dlx.row[j]-1)%9+1==s[i]-'0')
				{
					for(int k=dlx.R[j];k!=j;k=dlx.R[k])
						dlx.remove(dlx.col[k]);
					
					break;
				}
			}
		}

	dlx.Dance(0);
}

int main()
{
	ios::sync_with_stdio(false);

	for(cin>>s;s[0]!='e';cin>>s)
		slove();

	return 0;
}
