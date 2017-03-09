// 树的点分治，时间复杂度O(NlogNlogN)。
// 输入：树。
// 输出：结果。
// 注意：一共进行了N次calc，有logN层；先输入N，然后初始化，加边，ans=0，getans(1)。
// 原理：找到重心进行点分治。

const int MaxN=200005;
const int INF=0x7fffffff;			// !!!!!!

struct Edge {
	int to,next;
	int w;
}E[MaxN<<1];

int head[MaxN],Ecou;

int N,K,M;
int ans;
bool vis[MaxN];
bool cow[MaxN];

inline void init() {
	Ecou=0;
	for(int i=1;i<=N;++i) {
		head[i]=-1;
		vis[i]=0;				// 修改。
	}
}

inline void addEdge(int u,int v,int w) {
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	E[Ecou].w=w;
	head[u]=Ecou++;
}

//////////////////////////////

int sumnode;
int cen,minnC;
int maxson[MaxN],couson[MaxN];

void dfsC1(int u,int pre) {
	couson[u]=1;
	maxson[u]=0;

	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to] && E[i].to!=pre) {
			dfsC1(E[i].to,u);
			couson[u]+=couson[E[i].to];
			maxson[u]=max(maxson[u],couson[E[i].to]);
		}
}

void dfsC2(int u,int pre) {
	int maxn=max(maxson[u],sumnode-couson[u]);
	if(maxn<minnC) { minnC=maxn; cen=u; }

	for(int i=head[u];i!=-1;i=E[i].next)
		if(!vis[E[i].to] && E[i].to!=pre)
			dfsC2(E[i].to,u);
}

int getCenter(int u) {
	dfsC1(u,-1);
	sumnode=couson[u];
	minnC=INF;
	cen=u;			/////
	dfsC2(u,-1);
	return cen;
}

//////////////////////////////

void dfsc(int u,int pre,int cou,int dis) {
}

void calc(int u) {
}

//////////////////////////////

void getans(int u) {
	int c=getCenter(u);
	vis[c]=1;
	calc(c);

	for(int i=head[c];i!=-1;i=E[i].next)
		if(!vis[E[i].to])
			getans(E[i].to);
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a,b,c;

	scanf("%d %d %d",&N,&K,&M);
	init();

	while(M--) {
		scanf("%d",&a);
		cow[a]=1;
	}

	for(int i=1;i<N;++i) {
		scanf("%d %d %d",&a,&b,&c);
		addEdge(a,b,c);
		addEdge(b,a,c);
	}

	ans=0;
	getans(1);
	printf("%d\n",ans);

	return 0;
}
