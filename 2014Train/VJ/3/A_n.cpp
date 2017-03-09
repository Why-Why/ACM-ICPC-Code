#include<iostream>
#include<cstring>

using namespace std;

int N,M;
int cou;
int ans[1005];
int anscou;
int lieCou[1005];		// how mang '1' in every col.

struct DLX
{
	DLX *up,*down,*left,*right;
	int col,row;
};

DLX C[1005];
DLX head;
DLX dlx[100005];

void init()
{
	head.col=0;
	cou=0;
	anscou=0;

	for(int i=1;i<=M;++i)
	{
		lieCou[i]=0;

		C[i].col=i;
		C[i].right=&C[i+1];
		C[i].left=&C[i-1];
		C[i].up=C[i].down=&C[i];
	}

	C[1].left=&head;
	C[M].right=&head;

	head.left=&C[M];
	head.right=&C[1];

	int numt,temp;
	DLX *hang;

	for(int i=1;i<=N;++i)
	{
		hang=NULL;
		cin>>numt;

		for(int j=1;j<=numt;++j)
		{
			cin>>temp;
			
			++lieCou[temp];
			
			dlx[cou].col=temp;
			dlx[cou].row=i;
	
			dlx[cou].up=C[temp].up;
			dlx[cou].down=&C[temp];

			(C[temp].up)->down=&dlx[cou];
			C[temp].up=&dlx[cou];

			if(hang==NULL)
			{
				dlx[cou].left=dlx[cou].right=&dlx[cou];

				hang=&dlx[cou];
			}
			else
			{
				dlx[cou].right=hang;
				dlx[cou].left=&dlx[cou-1];

				(hang->left)->right=&dlx[cou];
				hang->left=&dlx[cou];
			}

			++cou;
		}
	}
}

void biaoji(int ct)
{
	(C[ct].left)->right=C[ct].right;
	(C[ct].right)->left=C[ct].left;

	DLX *temp=C[ct].down;
	DLX *temp1;

	while(temp!=&C[ct])
	{
		temp1=temp->right;

		while(temp1!=temp)
		{
			(temp1->up)->down=temp1->down;
			(temp1->down)->up=temp1->up;

			temp1=temp1->right;
		}

		temp=temp->down;
	}
}

void huibiao(int ct)
{
	(C[ct].left)->right=&C[ct];
	(C[ct].right)->left=&C[ct];

	DLX *temp=C[ct].down;
	DLX *temp1;

	while(temp!=&C[ct])
	{
		temp1=temp->right;

		while(temp1!=temp)
		{
			(temp1->up)->down=temp1;
			(temp1->down)->up=temp1;

			temp1=temp1->right;
		}

		temp=temp->down;
	}
}

bool dfs()
{
	if(head.right==&head)
		return 1;

	int ct;
	DLX *t1,*t2;

	ct=(head.right)->col;
	
	for(int i=(C[ct].right)->col;i;i=(C[i].right)->col)
		if(lieCou[C[i].col]<lieCou[C[ct].col])
			ct=i;

	biaoji(ct);

	t1=C[ct].down;

	while(t1!=&C[ct])
	{
		t2=t1->right;
		ans[anscou++]=t1->row;

		while(t2!=t1)
		{
			biaoji(t2->col);

			t2=t2->right;
		}

		if(dfs())
			return 1;

		t2=t1->left;
		--anscou;

		while(t2!=t1)
		{
			huibiao(t2->col);

			t2=t2->left;
		}

		t1=t1->down;
	}

	huibiao(ct);

	return 0;
}

void solve()
{
	if(dfs())
	{
		cout<<anscou;

		for(int i=0;i<anscou;++i)
			cout<<' '<<ans[i];
	}
	else
		cout<<"NO";

	cout<<endl;
}

int main()
{
	ios::sync_with_stdio(false);

	while(cin>>N>>M)
	{
		init();

		solve();
	}

	return 0;
}
