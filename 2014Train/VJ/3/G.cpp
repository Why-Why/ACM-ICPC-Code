#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

const int MaxN=16*16*16+10;
const int MaxM=4*16*16+10;
const int MaxNode=MaxN*MaxM/16;

int cas=1;

struct DLX
{
	int U[MaxNode],D[MaxNode],L[MaxNode],R[MaxNode],col[MaxNode],row[MaxNode];
	int size,n,m;
	int H[MaxN],S[MaxM];
	int ans[16*16+10],ans1[16*16+10];

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
		if(cas!=1)
			cout<<endl;

		for(int i=0;i<d;++i)
			ans1[(ans[i]-1)/16+1]=(ans[i]-1)%16+1;

		for(int i=1;i<=256;++i)
		{
			cout<<char(ans1[i]-1+'A');

			if(i%16==0)
				cout<<endl;
		}

		++cas;
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
				cout<<'('<<j<<','<<(row[j]-1)%16+1<<')'<<' ';

			cout<<endl;
		}
	}
};

DLX dlx;
char s[300];

void getchange(int &r,int &c1,int &c2,int &c3,int &c4,int i,int j,int k)
{
	r=(i*16+j)*16+k;
	c1=i*16+j+1;
	c2=256+i*16+k;
	c3=512+j*16+k;
	c4=768+((i/4)*4+(j/4))*16+k;
}

void slove()
{
	int r,c1,c2,c3,c4;

	dlx.init(16*16*16,4*16*16);

	for(int i=0;i<16;++i)
		for(int j=0;j<16;++j)
			for(int k=1;k<=16;++k)
				if(s[i*16+j]=='-' || s[i*16+j]-'A'+1==k)
				{
					getchange(r,c1,c2,c3,c4,i,j,k);

					dlx.Link(r,c1);
					dlx.Link(r,c2);
					dlx.Link(r,c3);
					dlx.Link(r,c4);
				}

/*	for(int i=1;i<=256;++i)
		for(int j=1;j<=16;++j)
			if(s[i-1]=='-' || (j+(i-1)*16-1)%16+1==s[i-1]-'A'+1)
				dlx.Link(j+(i-1)*16,i);

	for(int i=1;i<=256;++i)
		for(int j=1;j<=16;++j)
			if(s[i-1]=='-' || (16*(j-1)+(i-1)%16+1+256*((i-1)/16)-1)%16+1==s[i-1]-'A'+1)
				dlx.Link(16*(j-1)+(i-1)%16+1+256*((i-1)/16),i+256);

	for(int i=1;i<=256;++i)
		for(int j=1;j<=16;++j)
			if(s[i-1]=='-' || ((j-1)*256+i-1)%16+1==s[i-1]-'A'+1)
				dlx.Link((j-1)*256+i,i+512);

	for(int i=1;i<=4;++i)
		for(int j=1;j<=4;++j)
			for(int k=1;k<=16;++k)
				for(int l=1;l<=4;++l)
					for(int m=1;m<=4;++m)
						if(s[(i-1)*64+(j-1)*16+k-1]=='-' || ((i-1)*1024+(j-1)*64+k+(l-1)*256+(m-1)*16-1)%16+1==s[(i-1)*64+(j-1)*16+k-1]-'A'+1)
							dlx.Link((i-1)*1024+(j-1)*64+k+(l-1)*256+(m-1)*16,(i-1)*64+(j-1)*16+k+768);

	for(int i=0;i<256;++i)
		if(s[i]!='-')
		{
			dlx.ans1[i+1]=s[i]-'A'+1;

			dlx.remove(i+1);

			for(int j=dlx.D[i+1];j!=i+1;j=dlx.D[j])
			{
				if((dlx.row[j]-1)%16+1==s[i]-'A'+1)
				{
					for(int k=dlx.R[j];k!=j;k=dlx.R[k])
						dlx.remove(dlx.col[k]);
					
					break;
				}
			}
		}
*/
	dlx.Dance(0);
}

int main()
{
	ios::sync_with_stdio(false);

	char st[100];

	while(cin>>s)
	{
		for(int i=0;i<15;++i)
		{
			cin>>st;
			strcat(s,st);
		}

		slove();
	}

	return 0;
}
