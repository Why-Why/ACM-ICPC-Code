#include<iostream>
#include<cstring>
#include<cmath>
#include<queue>

using namespace std;

int A,B,C;
int rem[105][105];
int shorem[10005];

struct state
{
	int a,b;
	int type;
	int faa,fab;
	int num;

	state() {}
};

state sta[105][105];

void showans(state *e)
{
	int cou=0;

	while(e->a||e->b)
	{
		shorem[cou++]=e->type;

		e=&sta[e->faa][e->fab];
	}

	cout<<cou<<endl;
	for(int i=cou-1;i>=0;--i)
		switch(shorem[i])
		{
			case 1:
				cout<<"FILL(1)\n";
				break;
			case 2:
				cout<<"FILL(2)\n";
				break;
			case 3:
				cout<<"DROP(1)\n";
				break;
			case 4:
				cout<<"DROP(2)\n";
				break;
			case 5:
				cout<<"POUR(1,2)\n";
				break;
			case 6:
				cout<<"POUR(2,1)\n";
				break;
		}

}

void slove()
{
	queue <state *> que;
	state *temp;
	int t1,t2,t3;

	sta[0][0].faa=sta[0][0].fab=-1;
	sta[0][0].type=0;
	sta[0][0].num=0;
	que.push(&sta[0][0]);

	while(!que.empty())
	{
		temp=que.front();
		que.pop();

		if(temp->a==C||temp->b==C)
		{
			showans(temp);
			return;
		}

		t1=temp->a;
		t2=temp->b;
		
		if(sta[A][t2].num==-1)
		{
			sta[A][t2].num=temp->num+1;
			sta[A][t2].faa=t1;
			sta[A][t2].fab=t2;
			sta[A][t2].type=1;

			que.push(&sta[A][t2]);
		}
		if(sta[t1][B].num==-1)
		{
			sta[t1][B].num=temp->num+1;
			sta[t1][B].faa=t1;
			sta[t1][B].fab=t2;
			sta[t1][B].type=2;

			que.push(&sta[t1][B]);
		}
		if(sta[0][t2].num==-1)
		{
			sta[0][t2].num=temp->num+1;
			sta[0][t2].faa=t1;
			sta[0][t2].fab=t2;
			sta[0][t2].type=3;

			que.push(&sta[0][t2]);
		}
		if(sta[t1][0].num==-1)
		{
			sta[t1][0].num=temp->num+1;
			sta[t1][0].faa=t1;
			sta[t1][0].fab=t2;
			sta[t1][0].type=4;

			que.push(&sta[t1][0]);
		}
		t3=min(t1,B-t2);
		if(sta[t1-t3][t2+t3].num==-1)
		{
			sta[t1-t3][t2+t3].num=temp->num+1;
			sta[t1-t3][t2+t3].faa=t1;
			sta[t1-t3][t2+t3].fab=t2;
			sta[t1-t3][t2+t3].type=5;

			que.push(&sta[t1-t3][t2+t3]);
		}
		t3=min(t2,A-t1);
		if(sta[t1+t3][t2-t3].num==-1)
		{
			sta[t1+t3][t2-t3].num=temp->num+1;
			sta[t1+t3][t2-t3].faa=t1;
			sta[t1+t3][t2-t3].fab=t2;
			sta[t1+t3][t2-t3].type=6;

			que.push(&sta[t1+t3][t2-t3]);
		}
	}

	cout<<"impossible\n";
}

int main()
{
	ios::sync_with_stdio(false);

	for(int i=0;i<=100;++i)
		for(int j=0;j<=100;++j)
		{
			sta[i][j].a=i;
			sta[i][j].b=j;
		}

	while(cin>>A>>B>>C)
	{
		for(int i=0;i<=100;++i)
			for(int j=0;j<=100;++j)
				sta[i][j].num=-1;

		slove();
	}

	return 0;
}
