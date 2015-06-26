#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

const char step[4]={'A','C','G','T'};

int N;

struct state
{
	int D;
	unsigned int EN;

	state() {}

	state(int a,unsigned int b):D(a),EN(b) {}
};

unsigned int Esta;
char num[10][10];

bool judge(unsigned int &a,int x)
{
	bool ok=0;
	unsigned int t;

	for(int i=0;i<N;++i)
	{
		t=(a>>(i*4))&15;

		if(num[i][t]==step[x] && t<((Esta>>(i*4))&15))
		{
			ok=1;

			a+=(1<<(i*4));
		}
	}

	return ok;
}

void getEnum()
{
	Esta=0;

	unsigned int t;

	for(int i=0;i<N;++i)
	{
		t=strlen(num[i]);

		Esta+=t*(1<<(i*4));
	}
}

int bfs()
{
	queue <state> que;
	state tsta;
	unsigned int temp,t1;

	que.push(state(0,0));

	while(!que.empty())
	{
		tsta=que.front();
		que.pop();

		temp=tsta.D;
		t1=tsta.EN;

		if(t1==Esta)
			return temp;

		for(int i=0;i<4;++i)
			if(judge(t1,i))
			{
				que.push(state(temp+1,t1));

				t1=tsta.EN;
			}
	}
}

void solve()
{
	getEnum();
	cout<<bfs()<<endl;
}

int main()
{
	ios::sync_with_stdio(false);

	int T;
	cin>>T;

	while(T--)
	{
		cin>>N;

		for(int i=0;i<N;++i)
			cin>>num[i];

		solve();
	}

	return 0;
}
