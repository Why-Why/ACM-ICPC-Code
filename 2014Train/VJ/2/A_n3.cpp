#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

const int maxn=400005;
const int Enum=46233;
const int jie[9]={1,1,2,6,24,120,720,5040,40320};
const int Step[4][2]={{1,0},{0,-1},{-1,0},{0,1}};

int ans[maxn];
int Deep;
int Node[3][3];
int x01,y01;

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
			if(Node[i][j]&&Node[i][j]!=i*3+j+1)
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
			if(Node[i][j])
				reH+=abs(i-(Node[i][j]-1)/3)+abs(j-(Node[i][j]-1)%3);
			else
				reH+=abs(2-i)+abs(2-j);

	return reH;
}

void showans(int G)
{
	for(int i=0;i<G;++i)
		if(ans[i]==0)
			cout<<'d';
		else if(ans[i]==1)
			cout<<'l';
		else if(ans[i]==2)
			cout<<'u';
		else
			cout<<'r';

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

	if(H+G>Deep)
		return 0;

	if(judge())
	{
		showans(G);
		return 1;
	}

	for(int i=0;i<4;++i)
	{
		if(i%2==lasStep%2&&i!=lasStep)
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

void solve()
{
	if(JiOujian())
	{
		cout<<"unsolvable\n";
		return;
	}

	Deep=1;

	while(1)
	{
		if(dfs(0,-1))
			return;

		++Deep;
	}
}

int main()
{
	ios::sync_with_stdio(false);

	char c;

	while(cin>>c)
	{
		Node[0][0]=c=='x'?0:c-'0';
		cin>>c;
		Node[0][1]=c=='x'?0:c-'0';
		cin>>c;
		Node[0][2]=c=='x'?0:c-'0';

		for(int i=1;i<3;++i)
			for(int j=0;j<3;++j)
			{
				cin>>c;
				Node[i][j]=c=='x'?0:c-'0';
			}

		for(int i=0;i<3;++i)
			for(int j=0;j<3;++j)
				if(Node[i][j]==0)
					x01=i,y01=j;

		solve();
	}

	return 0;
}
