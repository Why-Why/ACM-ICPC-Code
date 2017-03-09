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
// Created Time  : 2017年02月18日 星期六 11时54分46秒
// File Name     : B.cpp

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

const int maxN=1e5+7;

long long a[maxN];

inline void slove(long long b[],long long &ans){
	for (int i=1;i<=5;i++)
	for (int j=i+1;j<=5;j++) if (b[0]<b[i]+b[j]){
		long long tmp=0;
		bool flag=0;
		for (int k=1;k<=5;k++) if (k!=i && k!=j){
			if (!flag) {
				tmp+=b[k];
				flag=1;
			}
			else tmp-=b[k];
		}

		if (tmp<0) {
			ans=0;
			for (int k=0;k<=5;k++)
				ans+=b[k];
			return;
		}
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1,greater<long long>());

	long long ans1,ans2,ans3;
	ans1=ans2=ans3=-1;

	for (int i=1;i+5<=n;i++){
		slove(a+i,ans1);
		if (ans1!=-1) break;
	}

	for (int i=1;i+2<=n;){
		if (ans2==-1) {
			if (a[i]<a[i+1]+a[i+2])
				ans2=a[i]+a[i+1]+a[i+2],i+=3;
			else 
				i++;
		}
		else {
			if (a[i]<a[i+1]+a[i+2])
				ans3=a[i]+a[i+1]+a[i+2],i+=3;
			else i++;
		}
		if (ans3!=-1) break;
	}

	if (ans1==-1 && ans3==-1) puts("0");
	else {
		if (ans1==-1) printf("%lld\n",ans2+ans3);
		else if (ans3==-1) printf("%lld\n",ans1);
		else printf("%lld\n",max(ans1,ans2+ans3));
	}

	return 0;
}
