#include<iostream>
#include<cstring>

using namespace std;

long long ans[1005][1005];

void getans()
{
	for(int i=0;i<1000;++i)
		ans[i][0]=ans[0][i]=1;

	for(int i=1;i<1000;++i)
		for(int j=1;j<1000;++j)
		{
			ans[i][j]=ans[i-1][j]+ans[i][j-1];
		}
}

long long solve(long long x,long long y)
{
	if(x==1||y==1)
		return max(x,y)+1;
	if(x==0||y==0)
		return 1;

	if(x<1000&&y<1000)
		return ans[x][y];
	return solve(x-1,y)+solve(x,y-1);
}

int main()
{
	ios::sync_with_stdio(false);

	long long A,B;
	
	getans();
	
	for(cin>>A>>B;A+B;cin>>A>>B)
	{
		if(A<1000&&B<1000)
			cout<<ans[A][B]<<endl;
		else if(A==1||B==1)
			cout<<max(A,B)+1<<endl;
		else
			cout<<solve(A,B)<<endl;
	}

	return 0;
}
