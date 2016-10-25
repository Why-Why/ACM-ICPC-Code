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
// Created Time  : 2016年07月23日 星期六 16时18分59秒
// File Name     : 1402.cpp

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

const double PI=atan2(1.0,1.0)*4.0;

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

/////////////////////////////////////

const int MaxN=200005;

Complex x1[MaxN],x2[MaxN];
char str1[MaxN],str2[MaxN];
int sum[MaxN];
int main()
{
while(scanf("%s%s",str1,str2)==2)
{
int len1 = strlen(str1);
int len2 = strlen(str2);
int len = 1;
while(len < len1*2 || len < len2*2)len<<=1;
for(int i = 0;i < len1;i++)
x1[i] = Complex(str1[len1-1-i]-'0',0);
for(int i = len1;i < len;i++)
x1[i] = Complex(0,0);
for(int i = 0;i < len2;i++)
x2[i] = Complex(str2[len2-1-i]-'0',0);
for(int i = len2;i < len;i++)
x2[i] = Complex(0,0);
//求DFT
fft(x1,len,1);
fft(x2,len,1);
for(int i = 0;i < len;i++)
x1[i] = x1[i]*x2[i];
fft(x1,len,-1);
for(int i = 0;i < len;i++)
sum[i] = (int)(x1[i].x+0.5);
for(int i = 0;i < len;i++)
{
sum[i+1]+=sum[i]/10;
sum[i]%=10;
}
len = len1+len2-1;
while(sum[len] <= 0 && len > 0)len--;
for(int i = len;i >= 0;i--)
printf("%c",sum[i]+'0');
printf("\n");
}
return 0;
}
