#include<iostream>
#include<cstring>
#include<queue>
#include<utility>

using namespace std;

typedef struct pair<int,int> pii;

int vis[6][6];
int fa[6][6];

bool judge(int x,int y)
{
	if(x<0||y<0||x>4||y>4)
		return 0;

	if(vis[x][y])
		return 0;

	return 1;
}

void slove()
{
	queue < pii > que;
	pii temp,temp1;
	int t1,t2;

	que.push(make_pair(0,0));
	vis[0][0]=1;

	while(!que.empty())
	{
		temp=que.front();
		que.pop();

		t1=temp.first/5;
		t2=temp.first%5;
		fa[t1][t2]=temp.second;

		if(t1==4&&t2==4)
			return;

		--t1;
		if(judge(t1,t2))
		{
			vis[t1][t2]=1;
			temp1=make_pair(t1*5+t2,temp.first);
			que.push(temp1);
		}
		t1+=2;
		if(judge(t1,t2))
		{
			vis[t1][t2]=1;
			que.push(make_pair(t1*5+t2,temp.first));
		}
		--t1;
		--t2;	
		if(judge(t1,t2))
		{
			vis[t1][t2]=1;
			que.push(make_pair(t1*5+t2,temp.first));
		}	
		t2+=2;
		if(judge(t1,t2))
		{
			vis[t1][t2]=1;
			que.push(make_pair(t1*5+t2,temp.first));
		}
	}
}

void showans()
{
	int cou=0;
	int ans[30];
	int temp=24;

	while(temp)
	{
		ans[cou++]=temp;
		temp=fa[temp/5][temp%5];
	}

	cout<<"(0, 0)"<<endl;
	for(int i=cou-1;i>=0;--i)
		cout<<'('<<ans[i]/5<<", "<<ans[i]%5<<')'<<endl;
}

int main()
{
	ios::sync_with_stdio(false);

	while(cin>>vis[0][0])
	{
		for(int j=1;j<5;++j)
			cin>>vis[0][j];

		for(int i=1;i<5;++i)
			for(int j=0;j<5;++j)
				cin>>vis[i][j];

		slove();
		showans();
	}	

	return 0;
}
