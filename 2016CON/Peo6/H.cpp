#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#define ll long long
using namespace std;

const int mod=1000000007;

//int a[107];
int fa[107];

int get_fa(int x){
	if (x==fa[x]) return x;
	return fa[x]=get_fa(fa[x]);
}

int main(){
	int t;
	scanf("%d",&t);
	while (t--){
		int n,m,k;
		scanf("%d%d%d",&n,&m,&k);
		for (int i=1;i<=n;i++) fa[i]=i;
		for (int i=0;i<m;i++){
			int l,r,d;
			scanf("%d%d%d",&l,&r,&d);
			for (int i=0;i<d;i++){
				int u=get_fa(l+i);
				int v=get_fa(r+i);
				fa[u]=v;
			}
			//cerr<<'#'<<endl;
		}
		ll ans=1;
		for (int i=1;i<=n;i++){
			if (i==get_fa(i))
				ans=(ans*26)%mod;
		}
		for (int i=1;i<=n;i++) cout<<get_fa(i)<<endl;
		printf("%lld\n",ans);
	}
	return 0;
}
