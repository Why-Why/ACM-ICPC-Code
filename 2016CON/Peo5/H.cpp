#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int MaxN=50004;

struct Edge {
	int to,next;
}E[MaxN<<1];

int head[MaxN],Ecou;
int N,K;

long long ans;
bool vis[MaxN];

void init() {
	Ecou=0;
	memset(head,-1,sizeof(head));
}

void addEdge(int u,int v) {
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}

int sumnode;

int dfscou(int u,int pre) {
	int ret=1;
	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to] && E[i].to!=pre)
			ret+=dfscou(E[i].to,u);
	return ret;
}

//////////////////

int cen;
int minrem;
int couson[MaxN],maxson[MaxN];
int minn;

void dfs1(int u,int pre) {
	couson[u]=1;
	maxson[u]=0;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre && !vis[E[i].to]) {
			dfs1(E[i].to,u);
			couson[u]+=couson[E[i].to];
			maxson[u]=max(maxson[u],couson[E[i].to]);
		}
}

void dfs2(int u,int pre) {
	int t=max(sumnode-couson[u],maxson[u]);
	if(minn>t) {
		minn=t;
		minrem=u;
	}
	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre && !vis[E[i].to])
			dfs2(E[i].to,u);
}

int getcen(int u) {
	dfs1(u,-1);
	sumnode=couson[u];
	minn=0x3f3f3f3f;
	minrem=u;
	dfs2(u,-1);
	return minrem;
}

/////////

int C[555];

inline int lowbit(int x) { return x&(-x); }
void add(int x,int p) {
	for(;x<=K;x+=lowbit(x))
		C[x]+=p;
}

int query(int x) {
	if(x<0) return 0;
	if(x==0) return 1;
	int ret=1;
	for(;x>0;x-=lowbit(x)) ret+=C[x];
	return ret;
}

int rem[MaxN],rcou;

void dfs(int u,int pre,int dis) {
	rem[rcou++]=dis;
	ans+=query(K-dis)-query(K-dis-1);

	for(int i=head[u];i!=-1;i=E[i].next)
		if(E[i].to!=pre && !vis[E[i].to])
			dfs(E[i].to,u,dis+1);
}

void calc(int u) {
	rcou=0;
	int last=0;
	for(int i=head[u];i!=-1;i=E[i].next) {
		if(vis[E[i].to]) continue;
		dfs(E[i].to,u,1);
		for(int i=last;i<rcou;++i) add(rem[i],1);
		last=rcou;
	}

	for(int i=0;i<rcou;++i) add(rem[i],-1);
}

void getans(int u) {
	int c=getcen(u);
	vis[c]=1;
	calc(c);

	for(int i=head[c];i!=-1;i=E[i].next)
		if(vis[E[i].to]==0)
			getans(E[i].to);
}

int main() {
	int a,b;
	scanf("%d %d",&N,&K);
	init();

	for(int i=1;i<N;++i) {
		scanf("%d %d",&a,&b);
		addEdge(a,b);
		addEdge(b,a);
	}

	ans=0;
	getans(1);
	printf("%I64d\n",ans);

	return 0;
}
