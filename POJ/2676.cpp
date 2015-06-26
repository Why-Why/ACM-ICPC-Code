// ━━━━━━神兽出没━━━━━━
// 　　 ┏┓       ┏┓
// 　　┏┛┻━━━━━━━┛┻┓
// 　　┃           ┃
// 　　┃     ━     ┃
//     ████━████   ┃
// 　　┃           ┃
// 　　┃    ┻      ┃
// 　　┃           ┃
// 　　┗━┓       ┏━┛
// 　　  ┃       ┃
// 　　  ┃       ┃
// 　　　┃       ┗━━━┓
// 　　　┃           ┣┓
// 　　　┃           ┏┛
// 　　　┗┓┓┏━━━━━┳┓┏┛
// 　　　 ┃┫┫     ┃┫┫
// 　　　 ┗┻┛     ┗┻┛
//
// ━━━━━━感觉萌萌哒━━━━━━

// Author        : WhyWhy
// Created Time  : 2015年05月10日 星期日 16时52分04秒
// File Name     : 2676.cpp

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

const int INF=10e8;
const int MaxN=800;
const int MaxM=400;
const int MaxNode=MaxN*MaxM;            // 这个的大小可以适当减少。 。 。

char map1[20][20];

struct DLX
{
    int U[MaxNode],D[MaxNode],L[MaxNode],R[MaxNode],col[MaxNode],row[MaxNode];      //row 可以不要。
    int H[MaxN],S[MaxM];
    int size,n,m;
    int ansnum,ans[MaxN];

    void init(int _n,int _m)
    {
        n=_n; m=_m; size=m; ansnum=INF;

        for(int i=0;i<=m;++i)
        {
            L[i]=i-1; R[i]=i+1; U[i]=D[i]=i;
            S[i]=0;
        }
        R[m]=0; L[0]=m;

        for(int i=1;i<=n;++i) H[i]=-1;
    }
    void link(int r,int c)
    {
        col[++size]=c; ++S[c]; row[size]=r;
        U[size]=U[c]; D[size]=c; D[U[c]]=size; U[c]=size;

        if(H[r]==-1) H[r]=L[size]=R[size]=size;
        else { L[size]=L[H[r]]; R[size]=H[r]; R[L[H[r]]]=size; L[H[r]]=size; }
    }
    void remove(int c)
    {
        L[R[c]]=L[c]; R[L[c]]=R[c];

        for(int i=D[c];i!=c;i=D[i])
            for(int j=R[i];j!=i;j=R[j])
            {
                U[D[j]]=U[j]; D[U[j]]=D[j];
                --S[col[j]];
            }
    }
    void resume(int c)
    {
        for(int i=U[c];i!=c;i=U[i])
            for(int j=L[i];j!=i;j=L[j])
            {
                U[D[j]]=D[U[j]]=j;
                ++S[col[j]];
            }
        L[R[c]]=R[L[c]]=c;
    }
    void showans(int d)
    {
        for(int i=1;i<=9;++i)
			puts(map1[i]+1);
    }
    bool Dance(int d)
    {
        if(R[0]==0)
        {
            showans(d);
            return 1;
        }
        int c=R[0];
		int t;

        for(int i=R[0];i;i=R[i]) if(S[i]<S[c]) c=i;
        remove(c);

        for(int i=D[c];i!=c;i=D[i])
        {
            t=(row[i]-1)/9+1;

			map1[(t-1)/9+1][(t-1)%9+1]=(row[i]-1)%9+1+'0';

            for(int j=R[i];j!=i;j=R[j]) remove(col[j]);
            if(Dance(d+1)) return 1;
            for(int j=L[i];j!=i;j=L[j]) resume(col[j]);
        }
        resume(c);
        return 0;
    }
};

DLX dlx;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int T;
	char s[20];

	scanf("%d",&T);

	while(T--)
	{
		dlx.init(81*9,81*4);

		for(int i=1;i<=81;++i)
			for(int j=1;j<=9;++j)
				dlx.link(j+(i-1)*9,i);

		for(int i=1;i<=9;++i)
			for(int j=1;j<=9;++j)
				for(int k=1;k<=9;++k)
					dlx.link(81*(i-1)+9*(j-1)+k,81+9*(i-1)+k);

		for(int i=1;i<=9;++i)
			for(int j=1;j<=81;++j)
				dlx.link(81*(i-1)+j,81*2+j);

		for(int i=1;i<=3;++i)
			for(int j=1;j<=3;++j)
				for(int k=1;k<=3;++k)
					for(int l=1;l<=3;++l)
						for(int m=1;m<=9;++m)
							dlx.link(243*(i-1)+81*(j-1)+27*(k-1)+9*(l-1)+m,27*(i-1)+9*(k-1)+m+81*3);

		for(int i=1;i<=9;++i)
			scanf("%s",map1[i]+1);

		int t;

		for(int i=1;i<=9;++i)
			for(int j=1;j<=9;++j)
				if(map1[i][j]!='0')
				{
					t=9*(i-1)+j;
					dlx.remove(t);

					for(int k=dlx.D[t];k!=t;k=dlx.D[k])
						if((dlx.row[k]-1)%9+1==map1[i][j]-'0')
						{
							for(int l=dlx.R[k];l!=k;l=dlx.R[l])
								dlx.remove(dlx.col[l]);
							break;
						}
				}

		dlx.Dance(0);
	}
	
	return 0;
}
