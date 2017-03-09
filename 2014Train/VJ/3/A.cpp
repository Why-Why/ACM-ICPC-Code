#include<iostream>
#include<cstring>

using namespace std;

struct state
{
    int col,row;
    state *left,*right,*up,*down;
};

int N,M;
state sta[100005];
state C[1005];
int ans[1005];
int cou,anscou;
state head;

void display(state *s)
{
	state *t;

	t=s->right;

	while(t!=s)
	{
		cout<<t->col<<' ';
		t=t->right;
	}

	cout<<endl;
}

void init()
{
    for(int i=1;i<=M;++i)
    {
		C[i].col=i;

        C[i].right=&C[i+1];
        C[i].left=&C[i-1];
        C[i].up=C[i].down=&C[i];
    }

    head.right=&C[1];
    head.left=&C[M];
	C[1].left=&head;
	C[M].right=&head;

    int numC,temp;
    state *hang1;
    cou=0;
    for(int i=1;i<=N;++i)
    {
        cin>>numC;
        hang1=NULL;

        for(int j=1;j<=numC;++j)
        {
            cin>>temp;
            ++cou;

            sta[cou].col=temp;
            sta[cou].row=i;

            sta[cou].up=C[temp].up;
            sta[cou].down=&C[temp];

            (C[temp].up)->down=&sta[cou];
            C[temp].up=&sta[cou];

            if(hang1==NULL)
            {
                sta[cou].left=sta[cou].right=&sta[cou];
                hang1=&sta[cou];
            }
            else
            {
                sta[cou].left=&sta[cou-1];
                sta[cou].right=hang1;

                hang1->left=&sta[cou];
                sta[cou-1].right=&sta[cou];
            }
        }
    }
}

void biaoji(int t)
{
	(C[t].left)->right=C[t].right;
	(C[t].right)->left=C[t].left;

	state *temp=C[t].down;

	while(temp!=&C[t])
	{
		(temp->left)->right=temp->right;
		(temp->right)->left=temp->left;

		temp=temp->down;
	}
}

void huibiao(int b[],int n)
{
	state *temp;

	for(int i=n-1;i>=0;--i)
	{
		(C[b[i]].left)->right=&C[b[i]];
		(C[b[i]].right)->left=&C[b[i]];

		temp=C[b[i]].down;

		while(temp!=&C[b[i]])
		{
			(temp->left)->right=temp;
			(temp->right)->left=temp;

			temp=temp->down;
		}
	}
}

bool dfs()
{
    if(head.right==&head)
        return 1;

    state *t1,*t2,*t3;
	int ht[1005];
	int htcou;

    t1=head.right;

	biaoji(t1->col);

    t2=t1->down;

    while(t2!=t1)
    {
		htcou=0;
		ans[anscou++]=t2->row;

        t3=t2->right;
		
        while(t3!=t2)
        {
			ht[htcou++]=t3->col;
            biaoji(t3->col);
            t3=t3->right;
        }
		

		if(dfs())
			return 1;

		--anscou;
		huibiao(ht,htcou);

        t2=t2->down;
    }

	htcou=1;
	ht[0]=t1->col;

	huibiao(ht,htcou);

	return 0;
}

void solve()
{
    anscou=0;

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
