// ━━━━━━神兽出没━━━━━━
//      ┏┓       ┏┓
//     ┏┛┻━━━━━━━┛┻┓
//     ┃           ┃
//     ┃     ━     ┃
//     ████━████   ┃
//     ┃           ┃
//     ┃    ┻      ┃
//     ┃           ┃
//     ┗━┓       ┏━┛
//       ┃       ┃
//       ┃       ┃
//       ┃       ┗━━━┓
//       ┃           ┣┓
//       ┃           ┏┛
//       ┗┓┓┏━━━━━┳┓┏┛
//        ┃┫┫     ┃┫┫
//        ┗┻┛     ┗┻┛
//
// ━━━━━━感觉萌萌哒━━━━━━

// Author        : WhyWhy
// Created Time  : 2015年09月16日 星期三 19时14分00秒
// File Name     : D.cpp

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

#include <iomanip>

using namespace std;

double x[4],y[4],z[4];
double kx1,kx2,ky1,ky2,kz1,kz2;

const double eps=1e-12;

inline int sgn(double x)
{
	return x<(-eps) ? -1 : x>eps;
}

void getans()
{
	double A=kx1*kx1+ky1*ky1+kz1*kz1;
	double B=kx2*kx2+ky2*ky2+kz2*kz2;
	double C=2*kx1*kx2+2*ky1*ky2+2*kz1*kz2;
	C=-C;
	double D=2*kx1*(x[0]-x[2])+2*ky1*(y[0]-y[2])+2*kz1*(z[0]-z[2]);
	double E=2*kx2*(x[0]-x[2])+2*ky2*(y[0]-y[2])+2*kz2*(z[0]-z[2]);
	E=-E;
	double F=(x[0]-x[2])*(x[0]-x[2])+(y[0]-y[2])*(y[0]-y[2])+(z[0]-z[2])*(z[0]-z[2]);

	double b=(C*D-2*A*E)/(4*A*B-C*C);
	double a=(-C*b-D)/(2*A);

	double ans=A*a*a+B*b*b+C*a*b+D*a+E*b+F;
	ans=sqrt(ans);

	//printf("%.6f\n",ans);
	//printf("%.6f %.6f %.6f %.6f %.6f %.6f\n",x[0]+a*kx1,y[0]+a*ky1,z[0]+a*kz1,\
			x[2]+b*kx2,y[2]+b*ky2,z[2]+b*kz2);

	cout.setf(ios::fixed);
	cout<<setprecision(6);
	cout<<ans+eps<<endl;

	double zans[]={x[0]+a*kx1,y[0]+a*ky1,z[0]+a*kz1,x[2]+b*kx2,y[2]+b*ky2,z[2]+b*kz2};

	for(int i=0;i<5;++i)
		if(sgn(zans[i])<0) cout<<zans[i]-eps<<' ';
		else cout<<zans[i]+eps<<' ';
	if(sgn(zans[5])<0) cout<<zans[5]-eps<<endl;
	else cout<<zans[5]+eps<<endl;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out1.txt","w",stdout);

	ios::sync_with_stdio(false);

	int T;

	cin>>T;

	while(T--)
	{
		for(int i=0;i<4;++i)
			cin>>x[i]>>y[i]>>z[i];

		kx1=x[1]-x[0];
		ky1=y[1]-y[0];
		kz1=z[1]-z[0];
		
		kx2=x[3]-x[2];
		ky2=y[3]-y[2];
		kz2=z[3]-z[2];

		getans();
	}
	
	return 0;
}
