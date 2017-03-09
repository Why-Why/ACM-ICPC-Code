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
// Created Time  : 2017年03月05日 星期日 21时50分25秒
// File Name     : H_1.cpp

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

const int MaxN=205;
const double eps=1e-9;
const double PI=atan2(1.0,1.0)*4.0;

inline int sgn(double x) {
	return x<-eps ? -1 : x>eps;
}

inline double sqr(double x) {
	return x*x;
}

struct Point {
	double x,y;

	Point() {}
	Point(double a,double b):x(a),y(b) {}

	Point operator + (const Point &b) const {
		return Point(x+b.x,y+b.y);
	}

	Point operator - (const Point &b) const {
		return Point(x-b.x,y-b.y);
	}

	Point operator * (double d) const {
		return Point(x*d,y*d);
	}

	Point operator / (double d) const {
		return Point(x/d,y/d);
	}

	double operator ^ (const Point &b) const {
		return x*b.y-y*b.x;
	}

	Point trangXY(double cost,double sint) {
		return Point(x*cost-y*sint,x*sint+y*cost);
	}
};

struct CIRCLE {
	Point o;
	double r;
	int cover;			// the number be covered

	bool operator < (const CIRCLE & b) const {
		return sgn(r-b.r)<0;
	}
};

struct EVENT {
	int cover;
	double angle;
	Point p;

	EVENT() {}
	EVENT(int a,double b,const Point &c):cover(a),angle(b),p(c) {}

	bool operator < (const EVENT &b) const {
		if(sgn(angle-b.angle)) return angle<b.angle;
		return cover>b.cover;
	}
};

inline double dist(const Point &a,const Point b) {
	double dx=a.x-b.x,dy=a.y-b.y;
	return sqrt(fabs(dx*dx+dy*dy));
}

// 求两个圆的交点，返回交点个数（重合为0），p1和p2按照圆a的顺时针排列。
inline int CircleCross(const CIRCLE &a,const CIRCLE &b,Point &p1,Point &p2) {
	double d=dist(a.o,b.o);
	if(sgn(d)==0 || sgn(fabs(a.r-b.r)-d)>0 || sgn(a.r+b.r-d)<0) return 0;

	double cost=(sqr(a.r)+sqr(d)-sqr(b.r))/(2.0*a.r*d);
	double sint=sqrt(fabs(1.0-sqr(cost)));

	Point p=(b.o-a.o)*a.r/d;
	p1=a.o+p.trangXY(cost,-sint);
	p2=a.o+p.trangXY(cost,sint);

	return sgn(sint) ? 2 : 1;
}

///////////////////////////////////

EVENT event[MaxN];

inline double cal(const CIRCLE &c,const EVENT &e1,const EVENT &e2) {
	double ans=(e2.angle-e1.angle)*sqr(c.r);
	ans-=(e1.p-c.o)^(e2.p-c.o);
	ans+=e1.p^e2.p;
	return ans/2.0;
}

// 输入N个cir圆，输出覆盖次数不小于i次的面积的area数组。
void getUnion(int N,CIRCLE cir[],double area[]) {
	sort(cir+1,cir+N+1);
	for(int i=1;i<=N;++i) {
		area[i]=0;
		cir[i].cover=1;
		for(int j=i+1;j<=N;++j)
			if(sgn(cir[j].r-cir[i].r-dist(cir[i].o,cir[j].o))>=0)
				++cir[i].cover;
	}

	Point tp1,tp2;
	int tcou,Ecou;

	for(int i=1;i<=N;++i) {
		Ecou=tcou=0;
		for(int j=1;j<=N;++j)
			if(i!=j && CircleCross(cir[i],cir[j],tp1,tp2)==2) {
				event[++Ecou]=EVENT(1,atan2(tp1.y-cir[i].o.y,tp1.x-cir[i].o.x),tp1);
				event[++Ecou]=EVENT(-1,atan2(tp2.y-cir[i].o.y,tp2.x-cir[i].o.x),tp2);
				if(sgn(event[Ecou-1].angle-event[Ecou].angle)>0) ++tcou;
			}
		event[++Ecou]=EVENT(tcou,-PI,Point(cir[i].o.x-cir[i].r,cir[i].o.y));
		event[++Ecou]=EVENT(-tcou,PI,Point(cir[i].o.x-cir[i].r,cir[i].o.y));
		sort(event+1,event+Ecou+1);

		tcou=cir[i].cover+event[1].cover;
		for(int j=2;j<=Ecou;++j) {
			area[tcou]+=cal(cir[i],event[j-1],event[j]);
			tcou+=event[j].cover;
		}
	}
}

/////////////////////////////////////

int N,K;
double W,S,Z[MaxN];
double area[MaxN];
CIRCLE cir[MaxN],tcir[MaxN];

inline bool judge(double H) {
	double L;

	for(int i=1;i<=N;++i) {
		tcir[i]=cir[i];
		L=sqrt(sqr(H)+sqr(cir[i].o.x)+sqr(cir[i].o.y));
		tcir[i].r=W/(Z[i]*L);
	}

	getUnion(N,tcir,area);
	return sgn(area[K]-S)>0;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	scanf("%d",&T);

	while(T--) {
		scanf("%d %lf %d %lf",&N,&W,&K,&S);
		for(int i=1;i<=N;++i) scanf("%lf %lf %lf",&cir[i].o.x,&cir[i].o.y,Z+i);

		double L=0.0,R=500.0,M;

		while(R-L>eps) {
			M=(L+R)/2.0;
			if(judge(M)) L=M;
			else R=M;
		}

		if(sgn(L-500.0)>=0) puts("Oops!");
		else if(sgn(L)<=0) puts("No solution!");
		else printf("%.4f\n",L);
	}

	return 0;
}
