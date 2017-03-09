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
// Created Time  : 2017年03月06日 星期一 13时23分52秒
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
#include <bitset>

using namespace std;

const int MaxN=805;
const int MaxM=805;

bitset <MaxM+1> data[MaxN];

// 高斯消元求XOR方程组。
// 数组从1开始。
// 输入N个方程，M-1个变量，data为系数矩阵（(data[i][1]*x[i][1])^(data[i][2]*x[i][2])...）。
// 返回自由变量个数，和自由变量数组，-1为无解。
int GaussXOR(int N,int M,int freenum[]) {
	int ret=0;
	int r,c,rem;

	for(r=1,c=1;r<=N && c<M;++r,++c) {
		for(rem=r;rem<=N;++rem)
			if(data[rem][c])
				break;

		if(rem>N) {
			--r;
			freenum[++ret]=c;
			continue;
		}

		if(rem!=r) swap(data[rem],data[r]);
		for(int i=r+1;i<=N;++i)
			if(data[i][c]) data[i]^=data[r];
	}

	for(int i=r;i<=N;++i)
		if(data[i][M])
			return -1;
	return ret;

	/*
	// 得到解集。
	for(int i=M-1;i>=1;--i) {
		ans[i]=data[i][M];
		for(int j=i+1;j<M;++j) ans[i]^=(data[i][j] & ans[j]);
	}
	*/
}

////////////////////////////

class BigNum {
	public:
		const static int MaxL=260;
		const static int Mod=10000;
		const static int Dlen=4;

		int num[MaxL/Dlen+1],len;

		void changeStoNum(const char *);

	public:
		BigNum() { len=1; memset(num,0,sizeof(num)); }
		BigNum(int);
		BigNum(const char *s) { changeStoNum(s); }

		BigNum operator - (const BigNum &) const;
		BigNum operator / (const long long) const;
		int operator % (const int m) const;
		bool is0() const;
};

BigNum::BigNum(int x)
{
	memset(num,0,sizeof(num));
	len=0;

	do
	{
		num[len++]=x-(x/Mod)*Mod;
		x/=Mod;

	}while(x);
}

void BigNum::changeStoNum(const char *x)
{
	int L=strlen(x);
	int temp,tp;
	int p=0;

	memset(num,0,sizeof(num));
	len=(L-1)/Dlen+1;

	for(int i=L-1;i>=0;i-=Dlen)
	{
		temp=0;
		tp=i-Dlen+1;

		if(tp<0)
			tp=0;

		for(int j=tp;j<=i;++j)
			temp=(temp<<3)+(temp<<1)+x[j]-'0';

		num[p++]=temp;
	}

	while(num[len-1]==0 && len>1)
		--len;
}

BigNum BigNum::operator - (const BigNum &b) const		// 不支持负数，一定要是a>b。
{
	int L=this->len;
	int p;
	BigNum ret(*this);

	for(int i=0;i<L;++i)
	{
		if(ret.num[i]<b.num[i])
		{
			p=i+1;

			while(!ret.num[p])
				++p;

			--ret.num[p--];

			while(p>i)
				ret.num[p--]=Mod-1;

			ret.num[i]+=Mod-b.num[i];
		}
		else
			ret.num[i]-=b.num[i];
	}

	while(!ret.num[ret.len-1] && ret.len>1)
		--ret.len;

	return ret;
}

BigNum BigNum::operator / (const long long b) const
{
	BigNum ret;
	long long down=0;

	for(int i=len-1;i>=0;--i)
	{
		ret.num[i]=(num[i]+down*Mod)/b;
		down=num[i]+down*Mod-ret.num[i]*b;			// 注意，这里可能会溢出，所以把b和down改成了long long。
	}

	ret.len=len;

	while(ret.num[ret.len-1]==0 && ret.len>1)
		--ret.len;

	return ret;
}

int BigNum::operator % (const int b) const
{
	int ret=0;

	for(int i=len-1;i>=0;--i)
		ret=((ret*Mod)%b+num[i])%b;

	return ret;
}

bool BigNum::is0() const {
	if(len>1) return 0;
	if(num[0]) return 0;
	return 1;
}

////////////////////////////

int N,M,Q;
BigNum k;

char s[MaxN];
char ans[MaxN];

//int rem[805][1605],rcou[805];
//int tmp[10000];

/*
inline void init() {
	rcou[0]=0;
	rcou[1]=1;
	rem[1][0]=0;

	for(int i=2;i<=801;++i) {
		int tcou=0;
		for(int j=0;j<rcou[i-2];++j) tmp[tcou++]=rem[i-2][j];
		for(int j=0;j<rcou[i-1];++j) {
			tmp[tcou++]=rem[i-1][j];
			tmp[tcou++]=rem[i-1][j]-1;
			tmp[tcou++]=rem[i-1][j]+1;
		}
		sort(tmp,tmp+tcou);

		int tt=1;
		for(int j=1;j<=tcou;++j)
			if(tmp[j]!=tmp[j-1] || j==tcou) {
				if(tt&1) rem[i][rcou[i]++]=tmp[j-1];
				tt=1;
			}
			else ++tt;
	}
}
*/

int fnum[MaxN],fcou;
bitset <MaxN> fans,cnum[MaxN],BASE;

inline void run(int step,int M,const bitset <MaxN> &t) {
	cnum[0].reset();
	cnum[1]=t;

	for(int i=2;i<=step;++i) {
		cnum[i]=cnum[i-2]^cnum[i-1]^(cnum[i-1]<<1)^(cnum[i-1]>>1);
		cnum[i]&=BASE;
	}
}

inline void solve() {
	BASE.reset();
	for(int i=1;i<=M;++i) BASE.set(i),data[i].reset();

	for(int i=1;i<=M;++i) {
		fans.reset();
		fans.set(i);
		run(N+1,M,fans);

		for(int j=1;j<=M;++j)
			if(cnum[N+1][j])
				data[j].set(i);
	}

	fcou=GaussXOR(M,M+1,fnum);

	/*
	for(int i=1;i<=M;++i,cout<<endl)
		for(int j=1;j<=M+1;++j)
			cout<<data[i][j]<<' ';
	cout<<endl;

	cout<<fcou<<endl;
	for(int i=1;i<=fcou;++i) cout<<fnum[i]<<' ';
	cout<<endl;
	*/
}

inline bool change() {
	if(fcou==-1) return 0;

	fans.reset();
	for(int i=1;i<=fcou;++i) {
		fans[fnum[i]]=k%2;
		k=k/2;
	}
	if(!k.is0()) return 0;

	for(int i=M,j=M-fcou,p=fcou;i>=1;--i,--j) {
		while(p>=1 && fnum[p]==i) {
			--p;
			--i;
		}
		if(i<1) break;

		fans[i]=data[j][M+1];
		for(int t=i+1;t<=M;++t) fans[i]=fans[i]^(fans[t] & data[j][t]);
	}

	for(int i=1,j=M;i<j;++i,--j)
		if(fans[i]!=fans[j]) {
			fans[i]=!fans[i];
			fans[j]=!fans[j];
		}

	return 1;
}

inline char getans(int x,int y) {
	run(x,M,fans);
	return '0'+cnum[x][y];
}

/*
inline bool judge() {
	if(fcou<=0) return 1;
	if(fnum[1]!=M-fcou+1) return 0;
	if(fnum[fcou]!=M) return 0;
	return 1;
}
*/

int map1[105][105];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	//init();

	/*
	int T=30;

	for(int i=1;i<=T;++i) {
		for(int j=1;j<=T;++j) {
			N=i;
			M=j;
			solve();

			if(fcou>0) {
				//cout<<i<<' '<<j<<' '<<fcou<<endl;
				map1[i][j]=fcou;
			}
			else map1[i][j]=0;

			//if(judge()==0) cout<<i<<' '<<j<<endl;
		}
		//cout<<"##\n";
	}

	for(int i=1;i<=T;++i,cout<<endl)
		for(int j=1;j<=T;++j)
			if(map1[i][j])
			printf("%4d",map1[i][j]);
			else printf("%4c",' ');
			*/

	/////////////////

	int x,y;

	while(~scanf("%d %d %d",&N,&M,&Q)) {
		solve();
		for(int i=0;i<Q;++i) {
			scanf("%s %d %d",s,&x,&y);
			k=BigNum(s)-1;
			if(!change()) ans[i]='?';
			else ans[i]=getans(x,y);
		}
		ans[Q]=0;
		puts(ans);
	}

	return 0;
}
