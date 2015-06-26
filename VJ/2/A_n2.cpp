#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>

using namespace std;

const int maxn=400005;
const int Enum=46233;
const int jie[9]={1,1,2,6,24,120,720,5040,40320};
const int step[4][2]={{1,0},{0,-1},{-1,0},{0,1}};

struct state
{
	int F,G,num;

	state() {}
	state(int a,int b,int c):F(a),G(b),num(c) {}

	friend bool operator < (state x,state y)
	{
		return x.F>y.F;
	}
};

int Snum,Mnum;
int fa[maxn],son[maxn];
int rem[maxn],Mrem;
char ans[maxn];

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
	int cou=0;
	char c;
	int tnum=Mnum;

	while(tnum!=Snum)
	{
		if(rem[tnum]==1)
			c='d';
		else if(rem[tnum]==2)
			c='l';
		else if(rem[tnum]==3)
			c='u';
		else
			c='r';

		ans[cou++]=c;

		tnum=fa[tnum];
	}

	for(int i=cou-1;i>=0;--i)
		cout<<ans[i];

	rem[Mnum]=Mrem;
	tnum=Mnum;

	while(tnum!=Enum)
	{
		rem[tnum]=-rem[tnum];
		if(rem[tnum]==1)
			c='u';
		else if(rem[tnum]==2)
			c='r';
		else if(rem[tnum]==3)
			c='d';
		else
			c='l';

		cout<<c;

		tnum=son[tnum];
	}

	cout<<endl;
}

int getH(int (*m)[3])
{
	int H=0;

	for(int i=0;i<3;++i)
		for(int j=0;j<3;++j)
			if(m[i][j])
				H+=abs(i-(m[i][j]-1)/3)+abs(j-(m[i][j]-1)%3);
			else
				H+=abs(i-2)+abs(j-2);

	return H;
}

bool bfs()
{
	priority_queue <state> que1,que2;

	int temp,t1[3][3],t2[3][3];
	int tnum1,tnum2;
	int x01,y01,x02,y02;

	state tsta1,tsta2;
	int H,G1,G2;

	que1.push(state(0,0,Snum));
	que2.push(state(0,0,Enum));

	rem[Snum]=100;
	rem[Enum]=-100;

	son[Enum]=Enum;
	fa[Snum]=Snum;

	while(!que1.empty()&&!que2.empty())
	{
		tsta1=que1.top();
		tsta2=que2.top();
		que1.pop();
		que2.pop();

		tnum1=tsta1.num;
		tnum2=tsta2.num;
		G1=tsta1.G;
		G2=tsta2.G;

		zhankai(t1,tnum1);
		zhankai(t2,tnum2);

		for(int i=0;i<3;++i)
			for(int j=0;j<3;++j)
			{
				if(t1[i][j]==0)
					x01=i,y01=j;
				if(t2[i][j]==0)
					x02=i,y02=j;
			}

		for(int i=0;i<4;++i)
		{
			if(judge(x01+step[i][0],y01+step[i][1])==0)
				continue;
			
			swap(t1[x01][y01],t1[x01+step[i][0]][y01+step[i][1]]);
			temp=hebing(t1);

			if(rem[temp]==0)
			{
				rem[temp]=i+1;
				fa[temp]=tnum1;
				H=getH(t1);
				que1.push(state(H+G1+1,G1+1,temp));
			}
			else if(rem[temp]<0)
			{
				fa[temp]=tnum1;
				Mrem=rem[temp];
				rem[temp]=i+1;
				Mnum=temp;

				return 1;
			}

			swap(t1[x01][y01],t1[x01+step[i][0]][y01+step[i][1]]);
		}

		for(int i=0;i<4;++i)
		{
			if(judge(x02+step[i][0],y02+step[i][1])==0)
				continue;

			swap(t2[x02][y02],t2[x02+step[i][0]][y02+step[i][1]]);
			temp=hebing(t2);

			if(rem[temp]==0)
			{
				rem[temp]=-(i+1);
				son[temp]=tnum2;
				H=getH(t2);
				que2.push(state(H+G2+1,G2+1,temp));
			}
			else if(rem[temp]>0)
			{
				son[temp]=tnum2;
				Mrem=-(i+1);
				Mnum=temp;

				return 1;
			}

			swap(t2[x02][y02],t2[x02+step[i][0]][y02+step[i][1]]);
		}
	}

	return 0;
}

bool JiOujian(int (*m)[3])
{
	int ni=0;

	for(int i=0;i<9;++i)
		for(int j=0;j<i;++j)
			if(m[i/3][i%3]&&m[j/3][j%3])
				if(m[i/3][i%3]<m[j/3][j%3])
					++ni;

	return ni%2;
}

void solve(int (*m)[3])
{
	if(JiOujian(m))
	{
		cout<<"unsolvable\n";
		return;
	}

	memset(rem,0,sizeof(rem));

	Snum=hebing(m);

	if(Snum==Enum)
	{
		cout<<endl;
		return;
	}

	if(bfs())
		showans();
	else
		cout<<"unsolvable\n";
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
