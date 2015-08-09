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
// Created Time  : 2015年07月23日 星期四 16时15分02秒
// File Name     : 1009.cpp

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

int N;

void show0(int N,int base1,int base2)
{
	for(int i=1;i<=N;i+=2)
		printf("%d - %d\n",base1+i,base1+i+1);

	if(N==2)
		return;

	printf("%d + %d\n",base2+1,base2+2);

	for(int i=2;i<=(N/2-1);++i)
		printf("%d + %d\n",base2+i+1,base2+(N>>1)+i-1);
}

void show(int N,int base)
{
	if(N<=3)
	{
		printf("-1\n");
		return;
	}

	switch(N)
	{
		case 4:
			printf("1 * 2\n");
			printf("3 + 4\n");
			printf("%d + %d\n",base+1,base+2);
			break;
		case 5:
			printf("1 / 2\n");
			printf("%d / 3\n",base+1);
			printf("4 - %d\n",base+2);
			printf("5 * %d\n",base+3);
			break;
		case 6:
			printf("1 + 2\n");
			printf("%d + 3\n",base+1);
			printf("%d + 4\n",base+2);
			printf("5 / 6\n");
			printf("%d * %d\n",base+3,base+4);
			break;
		case 7:
			printf("1 + 2\n");
			printf("%d + 3\n",base+1);
			printf("4 + 5\n");
			printf("%d + 6\n",base+3);
			printf("%d / 7\n",base+2);
			printf("%d + %d\n",base+4,base+5);
			break;
		case 8:
			printf("1 + 2\n");
			printf("%d / 3\n",base+1);
			printf("4 + 5\n");
			printf("6 / 7\n");
			printf("%d * %d\n",base+3,base+4);
			printf("%d * %d\n",base+2,base+5);
			printf("%d - 8\n",base+6);
			break;
		case 9:
			printf("1 + 2\n");
			printf("3 / 4\n");
			printf("5 / 6\n");
			printf("7 / 8\n");
			printf("%d + %d\n",base+2,base+3);
			printf("%d + %d\n",base+4,base+5);
			printf("9 - %d\n",base+6);
			printf("%d + %d\n",base+1,base+7);
			break;
		case 10:
			printf("1 / 2\n");
			printf("3 / 4\n");
			printf("5 / 6\n");
			printf("7 / 8\n");
			printf("%d + %d\n",base+1,base+2);
			printf("%d + %d\n",base+3,base+5);
			printf("%d + %d\n",base+4,base+6);
			printf("9 + 10\n");
			printf("%d + %d\n",base+7,base+8);
			break;
		case 11:
			printf("1 - 2\n");
			printf("3 - 4\n");
			printf("5 - 6\n");
			printf("7 + 8\n");
			printf("9 + 10\n");
			printf("%d + %d\n",base+1,base+2);
			printf("%d + %d\n",base+3,base+6);
			printf("%d / 11\n",base+5);
			printf("%d + %d\n",base+4,base+8);
			printf("%d + %d\n",base+7,base+9);
			break;
		case 12:
			printf("1 + 2\n");
			printf("3 + 4\n");
			printf("%d + %d\n",base+1,base+2);
			printf("%d / 5\n",base+3);
			printf("6 + 7\n");
			printf("8 + %d\n",base+5);
			printf("%d / 9\n",base+6);
			printf("10 + 11\n");
			printf("%d / 12\n",base+8);
			printf("%d * %d\n",base+4,base+7);
			printf("%d * %d\n",base+9,base+10);
			break;
		case 13:
			printf("1 + 2\n");
			printf("%d + 3\n",base+1);
			printf("%d / 4\n",base+2);
			printf("5 + 6\n");
			printf("%d / 7\n",base+4);
			printf("8 + 9\n");
			printf("%d / 10\n",base+6);
			printf("11 + 12\n");
			printf("%d / 13\n",base+8);
			printf("%d + %d\n",base+5,base+7);
			printf("%d * %d\n",base+3,base+10);
			printf("%d * %d\n",base+9,base+11);
			break;
	}
}

int main()
{
	while(~scanf("%d",&N))
	{
		if(N>=14)
		{
			if(N&1)
			{
				show0(N-13,13,N);
				show(13,N+N-14);
				printf("%d + %d\n",N+N-2,N+N-14);
			}
			else
			{
				show0(N-12,12,N);
				show(12,N+N-13);
				printf("%d + %d\n",N+N-2,N+N-13);
			}
		}
		else
			show(N,N);
	}
	
	return 0;
}
