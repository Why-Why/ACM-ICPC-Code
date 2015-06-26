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

const int MaxN=100005;
const long long INF=100000000000000000LL;

struct Treap
{
	int tot,root;
	int ch[MaxN][2];
	int pri[MaxN];
	long long key[MaxN];
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

	void _insert(int &x,long long k)
	{
		if(x)
		{
			if(key[x]==k)
				++cou[x];
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

	int find(long long k)
	{
		int u=root;

		while(u)
		{
			if(key[u]==k)
				return cou[u];

			u=ch[u][key[u]<k];
		}

		return 0;
	}

	void insert(long long k)
	{
		_insert(root,k);
	}
};

Treap sta;
int zhuan[30];
char s[100005];

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int a;
	long long sum=0;
	long long ans=0;
	long long temp;

	sta.init();

	for(int i=0;i<26;++i)
	{
		scanf("%d",&a);
		zhuan[i]=a;
	}

	scanf("%s",s);

	for(int i=0;s[i];++i)
	{
		temp=(s[i]-'a')*100000000000000LL+sum;
		ans+=sta.find(temp);
		sum+=zhuan[s[i]-'a'];
		temp+=zhuan[s[i]-'a'];
		sta.insert(temp);
	}

	cout<<ans<<endl;
	
	return 0;
}
