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
// Created Time  : 2015年08月15日 星期六 10时46分49秒
// File Name     : 110.cpp

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

const int MaxN=55;
const double eps=1e-10;

inline int sgn(double x)
{
	return x<-eps ? -1 : (x>eps);
}

struct Point
{
	double x,y,z;

	Point() {}
	Point(double a,double b,double c)
	{
		x=a,y=b,z=c;
	}
};

struct Ball
{
	double x,y,z;
	double r;

	Ball() {}
	Ball(double a,double b,double c,double d)
	{
		x=a,y=b,z=c;
		r=d;
	}

	bool jiao(const Point &p0,const Point &p1,Point &pret)
	{
		double A,B,C,det;
		double x0=p0.x,y0=p0.y,z0=p0.z;
		double x1=p1.x,y1=p1.y,z1=p1.z;
		double x2=x,y2=y,z2=z;

		A=(x1-x0)*(x1-x0)+(y1-y0)*(y1-y0)+(z1-z0)*(z1-z0);
		B=2*(x1-x0)*(x0-x2)+2*(y1-y0)*(y0-y2)+2*(z1-z0)*(z0-z2);
		C=(x0-x2)*(x0-x2)+(y0-y2)*(y0-y2)+(z0-z2)*(z0-z2)-r*r;

		det=B*B-4*A*C;
		if(sgn(det)<0) return 0;
		det=sqrt(det);

		double t1=(-B-det)/(2.0*A),t2=(-B+det)/(2.0*A);
		double t;

		if(sgn(t1)<=0)
			if(sgn(t2)<=0) return 0;
			else t=t2;
		else t=t1;

		pret.x=x0+t*(x1-x0);
		pret.y=y0+t*(y1-y0);
		pret.z=z0+t*(z1-z0);

		return 1;
	}
};

struct Line
{
	double x0,y0,z0;
	double x1,y1,z1;

	Line() {}
	Line(double a,double b,double c,double d,double e,double f)
	{
		x0=a,y0=b,z0=c;
		x1=d,y1=e,z1=f;
	}
};

Ball ball[MaxN];
int N;

double getnum(double a[][4])
{
	double ret=0;

	ret+=a[1][1]*(a[2][2]*a[3][3]-a[2][3]*a[3][2]);
	ret-=a[1][2]*(a[2][1]*a[3][3]-a[2][3]*a[3][1]);
	ret+=a[1][3]*(a[2][1]*a[3][2]-a[2][2]*a[3][1]);

	return ret;
}

double dist(const Point &a,const Point &b)
{
	double ret=(a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z);
	return sqrt(ret);
}

void duichen(const Point &p0,const Point &p1,const Point &p2,Point &pret)
{
	double x0=p0.x,y0=p0.y,z0=p0.z;
	double x1=p1.x,y1=p1.y,z1=p1.z;
	double x2=p2.x,y2=p2.y,z2=p2.z;
	double a[5][5];
	double X1[4][4],X2[4][4],X3[4][4],Y[4][4];

	a[1][1]=x1-x2;		a[1][2]=y1-y2;		 a[1][3]=z1-z2;		 a[1][4]=(x1-x2)*x0+(y1-y2)*y0+(z1-z2)*z0;
	a[2][1]=(y1-y2)/2;	a[2][2]=-(x1-x2)/2;	 a[2][3]=0;			 a[2][4]=(x1-x2)*(y0-2*y1)/2-(y1-y2)*(x0-2*x1)/2;
	a[3][1]=0;			a[3][2]=(z1-z2)/2;	 a[3][3]=(y1-y2)/2;	 a[3][4]=(y1-y2)*(z0-2*z1)/2-(z1-z2)*(y0-2*y1)/2;

	for(int i=1;i<=3;++i)
		for(int j=1;j<=3;++j)
			Y[i][j]=X1[i][j]=X2[i][j]=X3[i][j]=a[i][j];
	for(int i=1;i<=3;++i)
		X1[i][1]=X2[i][2]=X3[i][3]=a[i][4];

	double D=getnum(Y);
	pret.x=getnum(X1)/D;
	pret.y=getnum(X2)/D;
	pret.z=getnum(X3)/D;

	if(sgn(x1-x2)==0) pret.x=2*x1-x0;
	if(sgn(y1-y2)==0) pret.y=2*y1-y0;
	if(sgn(z1-z2)==0) pret.z=2*z1-z0;

	if(sgn(D)==0)
		pret=p0;
}

int getans(Point &p0,Point &p1)
{
	Point rem;
	int ret;
	Point p,tp;
	double dis=-100;
	double temp;

	for(int i=1;i<=N;++i)
		if(ball[i].jiao(p0,p1,p))
		{
			temp=dist(p0,p);

			if(dis<0 || dis>dist(p0,p))
			{
				dis=temp;
				rem=p; ret=i;
			}
		}

	if(dis<0) return 0;
	duichen(p0,rem,Point(ball[ret].x,ball[ret].y,ball[ret].z),tp);
	p0=rem; p1=tp;

	return ret;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	double a,b,c,d,e,f;
	Point p0,p1;

	while(~scanf("%d",&N))
	{
		for(int i=1;i<=N;++i)
			scanf("%lf %lf %lf %lf",&ball[i].x,&ball[i].y,&ball[i].z,&ball[i].r);
		scanf("%lf %lf %lf %lf %lf %lf",&a,&b,&c,&d,&e,&f);
		p0=Point(a,b,c);
		p1=Point(d,e,f);

		int t;
		bool first=0;

		for(int i=1;i<=10;++i)
			if(t=getans(p0,p1))
			{
				if(first) printf(" ");
				else first=1;

				printf("%d",t);
			}
			else
				goto finish;
		if(getans(p0,p1))
			printf(" etc.");
		
finish:
		printf("\n");
	}
	
	return 0;
}
