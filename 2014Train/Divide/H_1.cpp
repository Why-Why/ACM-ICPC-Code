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
// Created Time  : 2015年12月29日 星期二 22时02分01秒
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

const int MaxN=100005;

int N;
double dp[MaxN],S,A[MaxN],B[MaxN],R[MaxN];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	scanf("%d",&N);
	scanf("%lf",&S);

	double ans;
	int rem=0;

	for(int i=1;i<=N;++i) scanf("%lf %lf %lf",A+i,B+i,R+i);
	ans=S;
	dp[1]=S*R[1]/(B[1]+R[1]*A[1]);
	cout<<dp[1]<<endl;

	for(int i=2;i<=N;++i) {
		double temp=0;
		int tr=0;
		for(int j=1;j<i;++j) {
			if(temp<dp[j]*A[i]+dp[j]/R[j]*B[i]) {
				tr=j;
				temp=dp[j]*A[i]+dp[j]/R[j]*B[i];
			}
		}
		if(ans<temp) {
			ans=temp;
			rem=tr;
		}
		dp[i]=ans*R[i]/(A[i]*R[i]+B[i]);
		cout<<dp[i]<<' '<<rem<<endl;
	}
	printf("%.3f\n",ans);
	
	return 0;
}
