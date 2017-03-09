#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

const int maxn=400005;
const int jie[9]={1,1,2,6,24,120,720,5040,40320};
const int Step[4][2]={{1,0},{0,-1},{0,1},{-1,0}};

int ans[maxn];
int Deep;
int Node[3][3];
int x01,y01;
int Esta[3][3];
int Ewei[9];

void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}

bool judge()
{
	for(int i=0;i<3;++i)
		for(int j=0;j<3;++j)
			if(Node[i][j]!=Esta[i][j])
				return 0;

	return 1;
}

bool JiOujian()
{
	int ni=0;

	for(int i=0;i<9;++i)
		for(int j=0;j<i;++j)
			if(Node[i/3][i%3]&&Node[j/3][j%3])
				if(Node[i/3][i%3]<Node[j/3][j%3])
					++ni;

	return ni%2;
}

int getH()
{
	int reH=0;

	for(int i=0;i<3;++i)
		for(int j=0;j<3;++j)
			reH+=abs(i-(Ewei[Node[i][j]])/3)+abs(j-(Ewei[Node[i][j]])%3);

	return reH;
}

void showans(int G)
{
	cout<<G<<endl;

	for(int i=0;i<G;++i)
		if(ans[i]==0)
			cout<<'d';
		else if(ans[i]==1)
			cout<<'l';
		else if(ans[i]==2)
			cout<<'r';
		else
			cout<<'u';

	cout<<endl;
}

bool judgeBian(int x,int y)
{
	if(x<0||y<0||x>2||y>2)
		return 0;

	return 1;
}

bool dfs(int G,int lasStep)
{
	int H=getH();

	if(G>Deep)
		return 0;

	if(judge())
	{
		showans(G);
		return 1;
	}

	for(int i=0;i<4;++i)
	{
		if(i+lasStep==3)
			continue;

		if(judgeBian(x01+Step[i][0],y01+Step[i][1])==0)
			continue;

		swap(Node[x01][y01],Node[x01+Step[i][0]][y01+Step[i][1]]);
		x01+=Step[i][0];
		y01+=Step[i][1];

		ans[G]=i;

		if(dfs(G+1,i))
			return 1;

		x01-=Step[i][0];
		y01-=Step[i][1];
		swap(Node[x01][y01],Node[x01+Step[i][0]][y01+Step[i][1]]);
	}

	return 0;
}

void getEwei()
{
	for(int i=0;i<3;++i)
		for(int j=0;j<3;++j)
			Ewei[Esta[i][j]]=i*3+j;
}

void solve()
{
//	if(JiOujian())
//	{
//		cout<<"unsolvable\n";
//		return;
//	}
	
	getEwei();

	Deep=1;

	while(1)
	{
		if(dfs(0,-1000))
			return;

		++Deep;
	}
}

int main()
{
	ios::sync_with_stdio(false);

	char c;
	int T;
	cin>>T;

	for(int cas=1;cas<=T;++cas)
	{
		for(int i=0;i<3;++i)
			for(int j=0;j<3;++j)
			{
				cin>>c;
				Node[i][j]=c=='X'?0:c-'0';
			}

		for(int i=0;i<3;++i)
			for(int j=0;j<3;++j)
			{
				cin>>c;
				Esta[i][j]=c=='X'?0:c-'0';
			}

		for(int i=0;i<3;++i)
			for(int j=0;j<3;++j)
				if(Node[i][j]==0)
					x01=i,y01=j;

		cout<<"Case "<<cas<<": ";

		solve();
	}

	return 0;
}
