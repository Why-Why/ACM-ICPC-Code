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
#include <climits>
	
using namespace std;

const int MaxN=200006;
const int INF=0x3f3f3f3f;

struct Treap
{
	int tot,root;
	int ch[MaxN][2];
	int key[MaxN],pri[MaxN];
	int cou[MaxN],size[MaxN];

	void init()
	{
		tot=1;
		root=0;
		pri[0]=INT_MAX;
		size[0]=0;
	}

	void update(int x)
	{
		size[x]=size[ch[x][0]]+cou[x]+size[ch[x][1]];
	}

	void rotate(int &x,int t)
	{
		int y=ch[x][t];

		ch[x][t]=ch[y][1-t];
		ch[y][1-t]=x;

		update(x);
		update(y);

		x=y;
	}

	void _insert(int &x,int k)
	{
		if(x)
		{
			if(key[x]==k)
				return;
			else
			{
				int t=key[x]<k;

				_insert(ch[x][t],k);

				if(pri[ch[x][t]]<pri[x])
					rotate(x,t);
			}
		}
		else
		{
			x=tot++;
			key[x]=k;
			cou[x]=1;
			pri[x]=rand();
			ch[x][0]=ch[x][1]=0;
		}

		update(x);
	}

	void _erase(int &x,int k)
	{
		if(!x)
			return;

		if(key[x]==k)
			if(cou[x]>1)
				--cou[x];
			else
			{
				if(ch[x][0]==0 && ch[x][1]==0)
				{
					x=0;
					return;
				}

				int t=pri[ch[x][0]]>pri[ch[x][1]];

				rotate(x,t);
				_erase(x,k);
			}
		else
			_erase(ch[x][key[x]<k],k);

		update(x);
	}

	int _getKth(int &x,int k)
	{
		if(k<=size[ch[x][0]])
			return _getKth(ch[x][0],k);

		k-=size[ch[x][0]]+cou[x];

		if(k<=0)
			return key[x];

		return _getKth(ch[x][1],k);

	}

	int _find(int x,int k)
	{
		int ret=0;

		if(key[x]>=k)
			if(ch[x][0]==0)
				return 0;
			else
				return _find(ch[x][0],k);
		else
		{
			if(ch[x][1])
				ret+=_find(ch[x][1],k);

			if(ch[x][0])
				ret+=size[ch[x][0]];

			return ret+cou[x];
		}
	}

	int find(int k)
	{
		return _find(root,k);
	}

	void insert(int k)
	{
		_insert(root,k);
	}

	void erase(int k)
	{
		_erase(root,k);
	}

	int getKth(int k)
	{
		return _getKth(root,k);
	}
};

Treap tree;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int Q,a;
	char s[10];

	scanf("%d",&Q);

	tree.init();

	while(Q--)
	{
		scanf("%s %d",s,&a);

		if(s[0]=='I')
			tree.insert(a);
		else if(s[0]=='D')
			tree.erase(a);
		else if(s[0]=='K')
		{
			if(a>tree.size[tree.root])
				printf("invalid\n");
			else
				printf("%d\n",tree.getKth(a));
		}
		else
			printf("%d\n",tree.find(a));
	}
	
	return 0;
}
