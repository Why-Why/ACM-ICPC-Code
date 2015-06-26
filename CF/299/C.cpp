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

int A1,B1,n1,l1,r1,t1,m1;
long long A,B,n,l,t,m;
long long x,y;

long long getnum()
{
	long long dA=B,dB=2*A-2*B+B*(2*l-1),dC=-2*t*m;
	long double dd=sqrt((double(dB))*dB-4.0*dA*dC);
	long long ret=(dd-dB)/(2.0*dA)+l-1.0;

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d %d %d",&A1,&B1,&n1);

	A=A1;
	B=B1;
	n=n1;

	while(n--)
	{
		scanf("%d %d %d",&l1,&t1,&m1);
		l=l1;
		t=t1;
		m=m1;

		x=1+(t-A)/B;
		y=getnum();

		x=min(x,y);

		if(x<l)
			printf("-1\n");
		else
			cout<<x<<endl;
	}
	
	return 0;
}
