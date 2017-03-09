#include<bits/stdc++.h>
#define LL long long
#define pii pair<int,int>
#define fir first
#define sec second
using namespace std;
const int MAXN = 5010;
const int P = (int)1e9 + 7;
vector<int> edge[MAXN];
vector<int> rem[MAXN];
int pa[MAXN];
int dep[MAXN];
int siz[MAXN];
int V,K;
int pre[MAXN],tot;
int vis[MAXN];
LL jie[MAXN];
LL inv[MAXN];
LL f[MAXN][MAXN];
LL qp(LL x,LL y){
	LL res = 1;
	for(;y>0;y>>=1){
		if(y & 1) res = res * x % P;
		x = x * x % P;
	}
	return res;
}
void init(){
	jie[0] = 1;
	inv[0] = 1;
	for(int i=1;i<MAXN;++i){
		jie[i] = jie[i - 1] * i % P;
		inv[i] = qp(jie[i],P - 2);
	}
}
void dfs(int u){
	siz[u] = 1;
	dep[u] = dep[pa[u]] + 1;
	for(int i=0;i<edge[u].size();++i){
		int v = edge[u][i];
		if(v == pa[u])
			continue;
		dfs(v);
		rem[u].push_back(v);
		siz[u] += siz[v];
	}
}
LL C(LL x,LL y){
	if(x<y || y<0) return 0;
	if(y == 0 || y == x) return 1;
	return jie[x] * qp(jie[y] * jie[x-y] % P,P - 2) % P;
}
LL solve(int n){
	dfs(1);
	tot = 0;
	pre[0] = V;
	vis[V] = 1;
	for(int i=pa[V];i;i=pa[i]){
		vis[i]=1;
		pre[++tot] = i;
	}
	f[0][K] = C(n - K,siz[V] - 1);
	if(tot){
		for(int j=K-1;j;--j){
			f[1][j] = C(n - j - siz[V],siz[pre[1]] - siz[V] - 1) * f[0][K]% P + f[1][j + 1];
			f[1][j] %= P;
		}
		for(int i=2;i<=tot;++i){
			for(int j=K-2;j>0;--j){
				f[i][j] = C(n - j - siz[pre[i-1]],siz[pre[i]] - siz[pre[i-1]]-1) * f[i-1][j+1] % P;
				f[i][j] = (f[i][j] + f[i][j+1]) % P;
			}
		}
	}
	LL res = f[tot][1];
	for(int i=1;i<=n;++i){
		LL tmp = 1;
		LL u = siz[i];
		for(int j=0;j<rem[i].size();++j){
			int v = rem[i][j];
			if(vis[v]){
				u -= siz[v];
			}
			else{
				tmp = tmp * inv[siz[v]] % P;
			}
		}
		tmp = tmp * jie[u - 1] % P;
		res = res * tmp % P;
	}
	return res;
}

int main(){
	init();
	int n;
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;++i){
			edge[i].clear();
			rem[i].clear();
		}
		memset(vis,0,sizeof(vis));
		memset(f,0,sizeof(f));
		pa[1] = 0;
		for(int i=2;i<=n;++i){
			scanf("%d",pa + i);
			edge[pa[i]].push_back(i);
		}
		scanf("%d %d",&V,&K);
		printf("%lld\n",solve(n));
	}
	return 0;
}

