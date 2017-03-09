#include<iostream>
#include<cstring>

using namespace std;

int que[1000006],las,fir;
int A,B,C;
long long vis[101][101][101];

bool judge(int x,int y,int z)
{
	if(vis[x][y][z]==-1)
		return 1;
	return 0;
}

long long slove()
{
	int temp,t1,t2,t3;
	int base;

	las=fir=0;
	memset(vis,-1,sizeof(vis));

	que[las++]=A*110*110+0*110+0;
	vis[A][0][0]=0;

	while(las-fir)
	{
		temp=que[fir++];

		t1=temp/(110*110);
		t2=(temp/110)%110;
		t3=temp%110;
		base=vis[t1][t2][t3];
		if((t1==A/2&&(t2==A/2||t3==A/2))||(t2==A/2&&t3==A/2))
			return base;

		temp=min(t1,B-t2);
		t1-=temp;
		t2+=temp;
		if(judge(t1,t2,t3))
		{
			vis[t1][t2][t3]=base+1;
			que[las++]=t1*(110*110)+t2*110+t3;
		}
		t1+=temp;
		t2-=temp;

		temp=min(t1,C-t3);
		t1-=temp;
		t3+=temp;
		if(judge(t1,t2,t3))
		{
			vis[t1][t2][t3]=base+1;
			que[las++]=t1*(110*110)+t2*110+t3;
		}
		t1+=temp;
		t3-=temp;

		temp=min(t2,A-t1);
		t2-=temp;
		t1+=temp;
		if(judge(t1,t2,t3))
		{
			vis[t1][t2][t3]=base+1;
			que[las++]=t1*(110*110)+t2*110+t3;
		}
		t2+=temp;
		t1-=temp;

		temp=min(t2,C-t3);
		t2-=temp;
		t3+=temp;
		if(judge(t1,t2,t3))
		{
			vis[t1][t2][t3]=base+1;
			que[las++]=t1*(110*110)+t2*110+t3;
		}
		t2+=temp;
		t3-=temp;

		temp=min(t3,A-t1);
		t3-=temp;
		t1+=temp;
		if(judge(t1,t2,t3))
		{
			vis[t1][t2][t3]=base+1;
			que[las++]=t1*(110*110)+t2*110+t3;
		}
		t3+=temp;
		t1-=temp;

		temp=min(t3,B-t2);
		t3-=temp;
		t2+=temp;
		if(judge(t1,t2,t3))
		{
			vis[t1][t2][t3]=base+1;
			que[las++]=t1*(110*110)+t2*110+t3;
		}
		t3+=temp;
		t2-=temp;
	}

	return -1;
}

int main()
{
	ios::sync_with_stdio(false);

	long long ans;

	for(cin>>A>>B>>C;A+B+C;cin>>A>>B>>C)
	{
		if(A%2)
			ans=-1;
		else
			ans=slove();

		if(ans!=-1)
			cout<<ans<<endl;
		else
			cout<<"NO\n";
	}

	return 0;
}
