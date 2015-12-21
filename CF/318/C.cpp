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
// Created Time  : 2015年09月06日 星期日 21时42分26秒
// File Name     : A.cpp

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

int chuli(int x)
{
	while(!(x%2))
		x/=2;
	while(!(x%3))
		x/=3;

	return x;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N;
	int a,pre;

	scanf("%d",&N);

	N--;
	scanf("%d",&a);
	pre=chuli(a);
	bool ok=1;

	while(N--)
	{
		scanf("%d",&a);
		a=chuli(a);
		if(a!=pre)
			ok=0;
	}

	printf("%s\n",ok ? "Yes" : "No");
	
	return 0;
}
