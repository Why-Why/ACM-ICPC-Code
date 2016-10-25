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
// Created Time  : 2016年09月10日 星期六 12时11分03秒
// File Name     : 1005.cpp

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

int h,L,k;

int getans(int a) {
	if(a>k) return 0;

	int rd=k/a,rr=k%a;
	int wd=L/a,wr=L%a;

	int ans=(wd+rd-1)/rd;
	if(wr==0) return ans;

	if(wr<=rr) return ans;
	if(wd%rd) return ans;

	return ans+1;
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int ans=0;

	scanf("%d %d %d",&h,&L,&k);
	for(int i=1;i<=h;++i) {
		ans=max(ans,getans(i));
		cout<<i<<' '<<getans(i)<<endl;
	}
	printf("%d\n",ans);

	return 0;
}
