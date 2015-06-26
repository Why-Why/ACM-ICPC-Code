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

int n,t;
double p;

double getpow(double x,int y)
{
	double ret=1;

	for(int i=1;i<=y;++i)
		ret*=x;

	return ret;
}

int sgn(double x)
{
	if(fabs(x)<1e-8)
		return 0;

	return 1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	cin>>n>>p>>t;

	if(n>=t)
	{
		cout<<t*p<<endl;
		return 0;
	}

	double c=1,base=1,ans1=0,ans2=0;
	int x=0,y=n-1;
	double po=getpow(p,n);
	
	for(int i=0;i<=t-n;++i)
	{
		ans1+=c*base;
		c=c*((y+1.0)/(x+1.0));
		++y;
		++x;
		base*=(1.0-p);
	}

	ans1*=po*n;

//cout<<n<<' '<<p<<' '<<t<<endl;
	x=1;
	y=t;
	c=t;
	base=getpow(1-p,t-1);
	po=p;

	for(int i=1;i<n;++i)
	{
		ans2+=i*c*po*base;
//cout<<ans2<<endl;
//		cout<<ans2/i<<endl;

		po*=p;
		c=c*(double(y-x)/(x+1.0));
		++x;

		if(sgn(1-p))
			base/=(1-p);
	}

	cout.setf(ios::fixed);
	cout.precision(10);

	cout<<ans1+ans2<<endl;

	return 0;
}
