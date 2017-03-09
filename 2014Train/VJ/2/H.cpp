#include<iostream>
#include<cstring>
#include<cmath>
#include<queue>
#include<cstdio>

using namespace std;

struct state
{
	unsigned long long num[4];
	int D;

	state() {}
	state(int *n,int b)
	{
		D=b;

		for(int i=0;i<4;++i)
			num[i]=n[i];
	}
};

const unsigned long long Enum[4]={241340514,518435178,795529842,1072624506};

state Star;
int xk[4],yk[4];

void display(const unsigned long long *t)
{
	cout<<endl;
	unsigned int temp;

	for(int i=0;i<4;++i,cout<<endl)
		for(int j=0;j<7;++j)
		{
			temp=(t[i]>>(j*5))&31;

			cout<<(temp>>3)<<(temp&7)<<' ';
		}
}

bool judgeEnd(state &t)
{
	for(int i=0;i<4;++i)
		if(Enum[i]!=t.num[i])
			return 0;

	return 1;
}

inline unsigned int qian(int x,int y,state &t)
{
	if(x==0)
		return (y<<3)+1;

	return (t.num[y]>>((x-1)*5))&31;
}

int findZai(state &t)
{
	unsigned long long temp;
	int ans=0;

	for(int i=0;i<4;++i)
	{
		temp=Enum[i]^t.num[i];
cout<<temp<<endl;
		for(int j=0;j<7;++j)
		{
			if(temp&31==0)
				++ans;
cout<<temp-(temp/32)*32<<' ';
			temp>>=5;
		}
	}

	return ans;
}

void find(int &x1,int &y1,unsigned int dirt,state &t)
{
	unsigned long long temp;

	for(int i=0;i<4;++i)
	{
		temp=t.num[i];

		for(int j=0;j<7;++j)
		{
			if(temp&31==dirt)
			{
				x1=j;
				y1=i;

				return;
			}
		}
	}
}

void change(int x1,int y1,int x2,int y2,state &t)
{
	unsigned long long temp1,temp2;

	temp1=(t.num[y1]>>(x1*5))&31;
	temp2=(t.num[y2]>>(x2*5))&31;

	t.num[y1]=t.num[y1]&(31LL<<(5*x1));
	t.num[y2]=t.num[y2]&(31LL<<(5*x2));

	t.num[y1]+=temp2<<(5*x1);
	t.num[y2]+=temp1<<(5*x2);
}

bool judge(int n,state &t)
{
	int x=xk[n],y=yk[n];
	unsigned int t1=qian(x,y,t);
	int zai=findZai(t);
cout<<t1<<' '<<zai<<endl;
getchar();
	if(t1&7==x-1&&t1>>3==y)
		return 0;

	if(t1&7==0)
		return 0;

	if(t1&7==7)
		return 0;

	int x1,y1;

	find(x1,y1,t1&(-8)+t1&7+1,t);

	change(x1,y1,x,y,t);

	xk[n]=x1;
	yk[n]=y1;

	if(findZai(t)<zai)
		return 0;
	else
		return 1;
}

int bfs()
{
	int temp;
	int D;
	int tx,ty;
	state tsta,tempsta;
	queue <state> que;

	que.push(Star);
	
	while(!que.empty())
	{
		tsta=que.front();
		que.pop();

		D=tsta.D;
		tempsta=tsta;

		if(judgeEnd(tsta))
			return D;

		for(int i=0;i<4;++i)
		{
			tx=xk[i];
			ty=yk[i];

			if(judge(i,tsta))
			{
				que.push(tsta);
			}

			tsta=tempsta;
			xk[i]=tx;
			yk[i]=ty;
		}
	}

	return -1;
}

void solve()
{
	cout<<bfs()<<endl;
}

int main()
{
	ios::sync_with_stdio(false);

	int T;
	int a,cou;
	cin>>T;

	while(T--)
	{
		cou=0;
		memset(Star.num,0,sizeof(Star.num));

		for(int i=0;i<4;++i)
			for(int j=0;j<7;++j)
			{
				cin>>a;
				if(a%10==1)
				{
					xk[cou]=j;
					yk[cou]=i;
					++cou;
					a=10;
				}

				Star.num[i]+=((a/10-1)*8+a%10)*(1LL<<(j*5));
			}

		solve();
	}

	return 0;
}
