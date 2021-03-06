#include<iostream>
#include<cstring>

using namespace std;

const int maxn=400005;
const int Enum=46233;
const int jie[9]={1,1,2,6,24,120,720,5040,40320};

int que[400005];
int fa[maxn];
int las,fir;
int rem[maxn];
char ans1[maxn];
int cou;

int hebing(int (*m)[3])
{
	bool vis[10]={0};
	int cou;
	int ans=0;

	for(int i=0;i<9;++i)
	{
		cou=0;
		for(int j=0;j<m[i/3][i%3];++j)
			if(vis[j])
				++cou;

		vis[m[i/3][i%3]]=1;

		ans+=(m[i/3][i%3]-cou)*jie[8-i];
	}

	return ans;
}

void zhankai(int (*m)[3],int x)
{
	bool vis[10]={0};
	int cou;
	int k;

	for(int i=0;i<3;++i)
		for(int j=0;j<3;++j)
		{
			cou=x/jie[8-3*i-j]+1;		//	!!!
			x%=jie[8-3*i-j];
			
			for(k=0;k<9&&cou;++k)
				if(vis[k]==0)
					--cou;

			vis[k-1]=1;					//  !!!
			m[i][j]=k-1;				//  !!!
		}
}

void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}

bool judge(int x,int y)
{
	if(x<0||y<0||x>2||y>2)
		return 0;

	return 1;
}

void showans()
{
	int temp=Enum;
	char c;
	cou=0;

	while(fa[temp]!=-1)
	{
		if(rem[temp]==1)
			c='d';
		else if(rem[temp]==2)
			c='l';
		else if(rem[temp]==3)
			c='u';
		else
			c='r';

		ans1[cou++]=c;

		temp=fa[temp];
	}

	for(int i=cou-1;i>=0;--i)
		cout<<ans1[i];

	cout<<endl;
}

void solve(int (*m)[3])
{
	int ni=0;

	for(int i=0;i<9;++i)
		for(int j=0;j<i;++j)
			if(m[i/3][i%3]&&m[j/3][j%3])
				if(m[i/3][i%3]<m[j/3][j%3])
					++ni;

	if(ni%2)
	{
		cout<<"unsolvable\n";
		return;
	}

	las=fir=0;
	memset(rem,0,sizeof(rem));

	bool ok=0;
	int temp,t1[3][3],temp1;
	int x0,y0;

	temp=hebing(m);

	rem[temp]=-1;
	que[las++]=temp;
	fa[temp]=-1;

	while(las-fir)
	{
		temp=que[fir++];

		if(temp==Enum)
		{
			ok=1;
			break;
		}

		zhankai(t1,temp);

		for(int i=0;i<3;++i)
			for(int j=0;j<3;++j)
				if(t1[i][j]==0)
					x0=i,y0=j;

		if(judge(x0-1,y0))
		{
			swap(t1[x0][y0],t1[x0-1][y0]);
			temp1=hebing(t1);

			if(rem[temp1]==0)
			{
				rem[temp1]=3;
				fa[temp1]=temp;
				que[las++]=temp1;
			}

			swap(t1[x0][y0],t1[x0-1][y0]);
		}
		if(judge(x0+1,y0))
		{
			swap(t1[x0+1][y0],t1[x0][y0]);
			temp1=hebing(t1);

			if(rem[temp1]==0)
			{
				rem[temp1]=1;
				fa[temp1]=temp;
				que[las++]=temp1;
			}

			swap(t1[x0][y0],t1[x0+1][y0]);
		}
		if(judge(x0,y0-1))
		{
			swap(t1[x0][y0-1],t1[x0][y0]);
			temp1=hebing(t1);

			if(rem[temp1]==0)
			{
				rem[temp1]=2;
				fa[temp1]=temp;
				que[las++]=temp1;
			}

			swap(t1[x0][y0],t1[x0][y0-1]);
		}
		if(judge(x0,y0+1))
		{
			swap(t1[x0][y0+1],t1[x0][y0]);
			temp1=hebing(t1);

			if(rem[temp1]==0)
			{
				rem[temp1]=4;
				fa[temp1]=temp;
				que[las++]=temp1;
			}

			swap(t1[x0][y0],t1[x0][y0+1]);
		}
	}

	if(ok)
		showans();
	else
		cout<<"unsolvable"<<endl;
}

int main()
{
	ios::sync_with_stdio(false);

	int m[3][3];
	char c;

	while(cin>>c)
	{
		m[0][0]=c=='x'?0:c-'0';
		cin>>c;
		m[0][1]=c=='x'?0:c-'0';
		cin>>c;
		m[0][2]=c=='x'?0:c-'0';

		for(int i=1;i<3;++i)
			for(int j=0;j<3;++j)
			{
				cin>>c;
				m[i][j]=c=='x'?0:c-'0';
			}

		solve(m);
	}

	return 0;
}
