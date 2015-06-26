#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	long long r,x1,y1,x2,y2;
	long long d;
	double d1;

	cin>>r>>x1>>y1>>x2>>y2;

	d=(x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
	d1=sqrt(double(d));

	if(fabs(((long long)(d1/(2.0*r)))*2*r-d1)<0.00000001)
		cout<<((long long)(d1/(2.0*r)))<<endl;
	else
		cout<<((long long)(d1/(2.0*r)))+1<<endl;

	return 0;
}
