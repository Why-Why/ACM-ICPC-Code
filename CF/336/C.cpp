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
// Created Time  : 2015年12月24日 星期四 02时01分55秒
// File Name     : C.cpp

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

const int MaxN=1000005;

const char dic[256];

char S1[MaxN],S2[MaxN],*s1,*s2;
int N;
int p1,p2;
int tiao1,tiao2;
char qian1,qian2;
int Rem1[4],Rem2[4],*rem1,*rem2;

bool getans() {
	while(p1<N && p2<N) {
		rem[0]=rem[1]=rem[2]=rem[3]=-1;
		for(;p2<N;++p2)
			if(dui(s2[p2],s1[p1])) {
				--p2;
				break;
			}
			else rem[dic[s2[p2]]]=p2;

		if(dui(s2[p2],s1[p1+1])) {
			p2=find(s2[p2]);
			
		}
	}

	return 1;
}

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	dic['N']=0;
	dic['E']=1;
	dic['S']=2;
	dic['W']=3;

	scanf("%d %s %s",&N,s1,s2);
	p1=p2=0;
	tiao1=tiao2=0;
	s1=S1;
	s2=S2;
	rem1=Rem1;
	rem2=Rem2;

	if(getans()) puts("YES");
	else puts("NO");
	
	return 0;
}
