#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
	
using namespace std;

double dp[2010][2010];
int n,t;
double p;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	double sum=0;

	cin>>n>>p>>t;

	dp[0][0]=1;

	if(n>=t)
	{
		cout<<t*p<<endl;
		return 0;
	}

	for(int i=1;i<=t;++i)
	{
		if(i<=n)
			for(int j=0;j<=i;++j)
				dp[i][j]=dp[i-1][j-1]*p+dp[i-1][j]*(1-p);
		else
		{
			sum=0;

			for(int j=0;j<n;++j)
			{
				dp[i][j]=dp[i-1][j-1]*p+dp[i-1][j]*(1-p);
				sum+=dp[i][j];
			}

			dp[i][n]=1-sum;
		}
	}

	for(int i=1;i<n;++i)
		cout<<dp[t][i]<<endl;

	double ans=0;

	for(int i=1;i<=n;++i)
		ans+=dp[t][i]*i;

	cout.setf(ios::fixed);
	cout.precision(10);

	cout<<ans<<endl;
	
	return 0;
}
