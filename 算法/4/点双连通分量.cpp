// 求点双连通分量，复杂度 O(N+M)。
// 输入： 边集E，N。
// 输出： 动态的Belong，Bcou。
// 注意： 边双连通可能以为着有割点，如同8字形；需要去重；一个点可能属于多个双连通分量，最好实时处理。
// 原理： 见之前的6。

const int MaxM=1000006;
const int MaxN=1010;

struct Edge
{
	int to,next;
};

Edge E[MaxM];
int head[MaxN],Ecou;

int LOW[MaxN],DFN[MaxN];
int Index;

int Stack[MaxN],top;
bool InStack[MaxN];
int Belong[MaxN],Bcou;

void Tarjan(int u,int pre)
{
	int v,tv;

	LOW[u]=DFN[u]=++Index;
	Stack[top++]=u;
	InStack[u]=1;
	
	for(int i=head[u];i!=-1;i=E[i].next)
	{
		v=E[i].to;

		if(v==pre)
			continue;

		if(!DFN[v])
		{
			Tarjan(v,u);

			if(LOW[v]<LOW[u])
				LOW[u]=LOW[v];

			if(DFN[u]<=LOW[v])
			{
				Bcou++;

				do
				{
					tv=Stack[--top];
					Belong[tv]=Bcou;
					InStack[tv]=0;

				}while(tv!=v);

				// 这个时候Belong里面还有u都是双连通分量里面的，注意！可能不只是一个里面的！所以在这里处理。
			}
		}
		else if(DFN[v]<LOW[u])
			LOW[u]=DFN[v];
	}
}

void getCUTP(int n)
{
	for(int i=1;i<=n;++i)
		if(!DFN[i])
			Tarjan(i,i);
}

void init(int n)
{
	Index=0;
	Ecou=0;
	Bcou=0;
	top=0;
	
	for(int i=1;i<=n;++i)
	{
		head[i]=-1;
		Belong[i]=0;
		InStack[i]=0;
		DFN[i]=0;
	}
}

void addEdge(int u,int v)
{
	E[Ecou].to=v;
	E[Ecou].next=head[u];
	head[u]=Ecou++;
}
