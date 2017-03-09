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
// Created Time  : 2017年03月03日 星期五 15时51分30秒
// File Name     : H.cpp

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

	Point operator * (double t) const {
		return Point(x*t,y*t);
	}

	Point operator / (double t) const {
		return Point(x/t,y/t);
	}
};

struct CIRCLE {
	Point o;
	double r;
	double Z;

	bool operator < (const CIRCLE &b) const {
		return r>b.r;
	}
};

inline double dist(const Point &a,const Point &b) {
	double dx=a.x-b.x,dy=a.y-b.y;
	return sqrt(dx*dx+dy*dy);
}

inline double dist2(const Point &a,const Point &b) {
	double dx=a.x-b.x,dy=a.y-b.y;
	return dx*dx+dy*dy;
}

inline double sqr(double x) {
	return x*x;
}

Point PointRotate(Point v,double cost,double sint) {
	return Point(v.x*cost-v.y*sint,v.x*sint+v.y*cost);
}

pair<Point,Point> CirCross(const CIRCLE &a,const CIRCLE &b) {
	double d=dist(a.o,b.o);
	double cost=(a.r*a.r+d*d-b.r*b.r)/(2.0*a.r*d);
	double sint=sqrt(1.0-cost*cost);
	Point v=(b.o-a.o)*a.r/d;
	return make_pair(a.o+PointRotate(v,cost,-sint),a.o+PointRotate(v,cost,sint));
}

////////////////////////////////

struct ARC {
	double Ly,Ry,My;
	int type;
	double area;

	bool operator < (const ARC &b) const {
		return My<b.My;
	}
};

const int MaxN=205;
const int MaxE=MaxN*MaxN+3*MaxN;
const double eps=1e-9;

double Erem[MaxE];
ARC Arem[MaxN<<1];
int Acou;

inline double calArea(const ARC &a,const CIRCLE &c,double L,double R) {
	double len=sqrt(sqr(a.Ly-a.Ry)+sqr(R-L));
	double d=sqrt(sqr(c.r)-sqr(len)/4.0);
	double angle=atan(len/2.0/d);
	return fabs(angle*sqr(c.r)-d*len/2.0);
}

inline double Set(const CIRCLE &c,double p,double &ans1,double &ans2) {
	double dx=fabs(c.o.x-p);
	double dy=sqrt(fabs(sqr(c.r)-sqr(dx)));
	ans1=c.o.y-dy;
	ans2=c.o.y+dy;
}

inline void getARC(const CIRCLE &c,double L,double R) {
	Set(c,L,Arem[Acou+1].Ly,Arem[Acou+2].Ly);
	Set(c,R,Arem[Acou+1].Ry,Arem[Acou+2].Ry);
	Set(c,(L+R)/2.0,Arem[Acou+1].My,Arem[Acou+2].My);
	Arem[Acou+1].type=1;
	Arem[Acou+2].type=-1;
	Arem[Acou+1].area=Arem[Acou+2].area=calArea(Arem[Acou+1],c,L,R);
	Acou+=2;
}

inline int uniqueC(int N,CIRCLE cir[]) {				// 去除覆盖的圆。
	sort(cir+1,cir+N+1);
	int p=0,ok;

	for(int i=1;i<=N;++i) {
		ok=1;
		for(int j=1;j<i;++j)
			if(sqr(cir[i].r-cir[j].r)+1e-12>=dist2(cir[i].o,cir[j].o)) {
				ok=0;
				break;
			}
		if(ok) cir[++p]=cir[i];
	}

	return p;
}

inline int uniqueINF(int N,CIRCLE cir[]) {				// 去除覆盖的圆。
	sort(cir+1,cir+N+1);
	int p=0;

	for(int i=1;i<=N;++i) {
		if(cir[i].r>1e50) continue;
		cir[++p]=cir[i];
	}

	return p;
}

double getans(int N,int K,CIRCLE cir[]) {
	//int tt=uniqueINF(N,cir);
	//K-=N-tt;
	//N=tt;

	int Ecou=0;
	Point tp1,tp2;
	pair<Point,Point> tcro;

	for(int i=1;i<=N;++i) {
		Erem[++Ecou]=cir[i].o.x;
		Erem[++Ecou]=cir[i].o.x-cir[i].r;
		Erem[++Ecou]=cir[i].o.x+cir[i].r;

		for(int j=1;j<i;++j)
			if(sqr(cir[i].r+cir[j].r)+eps>=dist2(cir[i].o,cir[j].o) && !(sqr(cir[i].r-cir[j].r)+1e-12>=dist2(cir[i].o,cir[j].o))) {

				tcro=CirCross(cir[i],cir[j]);

				Erem[++Ecou]=tcro.first.x;
				Erem[++Ecou]=tcro.second.x;
			}
	}

	sort(Erem+1,Erem+Ecou+1);
	Ecou=unique(Erem+1,Erem+Ecou+1)-Erem-1;

	////////

	double ret=0,L,R;
	int cou;

	for(int i=2;i<=Ecou;++i) {
		L=Erem[i-1],R=Erem[i];
		Acou=0;

		for(int j=1;j<=N;++j)
			if(cir[j].o.x-cir[j].r<R && cir[j].o.x+cir[j].r>L)
				getARC(cir[j],L,R);

		if(Acou) {
			sort(Arem+1,Arem+Acou+1);
			cou=0;

			for(int i=1;i<=Acou;++i) {
				if(cou>=K) {
					ret+=(fabs(Arem[i].Ly-Arem[i-1].Ly)+fabs(Arem[i].Ry-Arem[i-1].Ry))*(R-L)/2.0;
					ret+=Arem[i-1].area*Arem[i-1].type;
					ret-=Arem[i].area*Arem[i].type;
				}
				cou+=Arem[i].type;
			}
		}
	}

	return ret;
}

CIRCLE cir[MaxN],tcir[MaxN];
int N,K;
double W,S;

inline bool judge(double H) {
	double t;

	for(int i=1;i<=N;++i) {
		t=sqr(cir[i].o.x)+sqr(cir[i].o.y);
		t=sqrt(fabs(t+H*H));
		cir[i].r=W/(cir[i].Z*t);

		tcir[i]=cir[i];
	}

	for(int i=1;i<=N;++i)
		cout<<tcir[i].o.x<<' '<<tcir[i].o.y<<' '<<tcir[i].r<<endl;


	cout<<getans(N,K,tcir)<<endl;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;

	scanf("%d",&T);

	while(T--) {
		scanf("%d %lf %d %lf",&N,&W,&K,&S);
		for(int i=1;i<=N;++i) 
			scanf("%lf %lf %lf",&cir[i].o.x,&cir[i].o.y,&cir[i].Z);

		judge(500);
		return 0;

		if(K==0 || judge(500)) {
			puts("Oops!");
			continue;
		}

		if(!judge(0)) {
			puts("No solution!");
			continue;
		}

		double L=0,R=500,M;

		while(R-L>1e-5) {
			M=(L+R)/2.0;
			if(judge(M)) L=M;
			else R=M;
		}

		printf("%.4f\n",L);
	}

	return 0;
}
