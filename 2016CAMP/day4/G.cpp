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
// Created Time  : 2017年02月16日 星期四 16时22分26秒
// File Name     : G.cpp

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

const int MaxN=100005;
const double PI=atan2(1.0,1.0)*4.0;

int N,M,t;
int num[100005<<3];

long long rem1[MaxN<<3];
long long ans[100005<<3];

/////////////////////

struct Complex {
	double x,y;

	Complex(double a=0.0,double b=0.0):x(a),y(b) {}

	Complex operator + (const Complex & b) const {
		return Complex(x+b.x,y+b.y);
	}
	Complex operator - (const Complex & b) const {
		return Complex(x-b.x,y-b.y);
	}
	Complex operator * (const Complex & b) const {
		return Complex(x*b.x-y*b.y,x*b.y+y*b.x);
	}
};

void change(Complex y[],int len) {
	int k;
	for(int i=1,j=len>>1;i<len-1;++i) {
		if(i<j) swap(y[i],y[j]);
		k=len>>1;
		while(j>=k) {
			j-=k;
			k>>=1;
		}
		if(j<k) j+=k;
	}
}

// len是2的幂，on=1 is DFT，on=-1 is IDFT。
void fft(Complex y[],int len,int on) {
	change(y,len);

	for(int h=2;h<=len;h<<=1) {
		Complex wn(cos(-on*2*PI/h),sin(-on*2*PI/h));
		for(int j=0;j<len;j+=h) {
			Complex w(1,0);
			for(int k=j;k<j+h/2;++k) {
				Complex u=y[k];
				Complex t=w*y[k+h/2];
				y[k]=u+t;
				y[k+h/2]=u-t;
				w=w*wn;
			}
		}
	}

	if(on==-1)
		for(int i=0;i<len;++i)
			y[i].x/=len;
}

//////////////////////////

Complex x1[MaxN<<3],x2[MaxN<<3];
int len;

inline void change1(long long a[],long long b[],long long c[]) {
	for(int i=0;i<N;++i) x1[N+i]=x1[i]=Complex(b[i],0),x2[i]=Complex(c[i],0);
	for(int i=N+N;i<len;++i) x1[i]=Complex(0,0);
	for(int i=N;i<len;++i) x2[i]=Complex(0,0);

	fft(x1,len,1);
	fft(x2,len,1);
	for(int i=0;i<len;++i) x1[i]=x1[i]*x2[i];
	fft(x1,len,-1);

	for(int i=0;i<N;++i) a[i]=(int(x1[i+N].x+0.5))%M;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	scanf("%d",&T);

	while(T--) {
		scanf("%d %d %d",&N,&M,&t);
		for(int i=0;i<N;++i) scanf("%d",num+i),--num[i];

		len=1;
		while(len<N*2) len<<=1;
		len<<=1;

		for(int i=0;i<N;++i) rem1[i]=0,ans[i]=0;
		ans[0]=1;
		rem1[0]=M-1;
		rem1[1]=2;

		for(;t;t>>=1) {
			if(t&1) {
				//for(int i=0;i<N;++i) (ans[i]+=rem1[i])%=M;
				change1(ans,ans,rem1);
			}
			change1(rem1,rem1,rem1);
		}

		for(int i=0;i<N;++i) x1[N+i]=x1[i]=Complex(ans[i],0);
		for(int i=N+N;i<len;++i) x1[i]=Complex(0,0);
		for(int i=0;i<N;++i) x2[i]=Complex(num[N-1-i],0);
		for(int i=N;i<len;++i) x2[i]=Complex(0,0);

		fft(x1,len,1);
		fft(x2,len,1);
		for(int i=0;i<len;++i) x1[i]=x1[i]*x2[i];
		fft(x1,len,-1);

		for(int i=0;i<N;++i) printf("%d ",int(x1[2*N-1-i].x+0.5)%M+1);
		puts("");
	}

	return 0;
}
