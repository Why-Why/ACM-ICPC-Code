
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<queue>
#include<algorithm>
#include<vector>
#include<stack>
#include<list>
#include<iostream>
#include<map>
using namespace std;
#define inf 0x3f3f3f3f
#define M 2000010
int max(int a,int b)
{
	return a>b?a:b;
}
int min(int a,int b)
{
	return a<b?a:b;
}
int next[M],extend[M];
bool flag[2][M];
long long ans;
int cnt;
struct node
{
    int num,cnt;
    int next[26];
    void init()
    {
        num=cnt=0;
        memset(next,0,sizeof(next));
    }
}tri[M];
void getnext(char *T,int lp,int rp)
{
    int i,j,k,l,len;
    j=0;
    while(lp+j+1<=rp&&T[lp+j]==T[lp+j+1]) j++;
    next[lp+1]=j;k=lp+1;
    for(i=lp+2;i<=rp;i++)
    {
        len=k+next[k]-1;l=next[lp+i-k];
        if(l<len-i+1)
            next[i]=l;
        else
        {
            j=max(0,len-i+1);
            while(i+j<=rp&&T[lp+j]==T[i+j]) j++;
            next[i]=j;k=i;
        }
    }
}
void exkmp(char *S,char *T,int lp,int rp,int tp)//我这种写法下标都要加lp;
{
    int i,j,k,l,len;
    j=0;
    while(j+lp<=rp&&S[j+lp]==T[j+lp]) j++;
    extend[lp]=j;k=lp;
    for(i=lp+1;i<=rp;i++)
    {
        len=k+extend[k]-1,l=next[lp+i-k];
        if(l<len-i+1)
            extend[i]=l;
        else
        {
            j=max(0,len-i+1);
            while(i+j<=rp&&S[i+j]==T[lp+j]) j++;
            extend[i]=j;k=i;
        }
    }
    for(i=lp;i<=rp;i++)
    {
        if(extend[i]==rp-i+1)
            flag[tp][i]=1;
    }
}

void insert(char *s,int lp,int rp)
{
    int i,p,x;
    p=0;
    for(i=lp;i<=rp;i++)
    {
        x=s[i]-'a';
        tri[p].num+=flag[0][i];
        if(!tri[p].next[x])
        {
            tri[++cnt].init();
            tri[p].next[x]=cnt;
        }
        p=tri[p].next[x];
    }
    tri[p].cnt++;
}
void search(char *s,int lp,int rp)
{
    int i,p,x;
    p=0;
    for(i=lp;i<=rp;i++)
    {
        x=s[i]-'a';
        p=tri[p].next[x];
        if(!p)
             break;

        if((i<rp&&flag[1][i+1])||(i==rp))//如果匹配串比原串长或相同
        ans+=tri[p].cnt;
    }
    if(p)//如果没匹配完则p=0;
    ans+=tri[p].num;//如果匹配串比原串短
}
char s[M],str[M];
int begin[M],end[M];
int main()
{
	//freopen("in.txt","r",stdin);

    int i,j,n,len,totlen;
    while(scanf("%d",&n)!=EOF)
    {
        totlen=0;
        ans=0;
        tri[0].init();
        memset(flag,0,sizeof(flag));
        cnt=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&len);
            scanf("%s",s+totlen);
            begin[i]=totlen;
            for(j=0;j<len;j++)
               str[totlen+j]=s[totlen+len-1-j];
            getnext(str,totlen,totlen+len-1);
            exkmp(s,str,totlen,totlen+len-1,0);
            getnext(s,totlen,totlen+len-1);
            exkmp(str,s,totlen,totlen+len-1,1);
            insert(s,totlen,totlen+len-1);
            end[i]=totlen+len-1;
            totlen+=len;
        }
        for(i=0;i<n;i++)
            search(str,begin[i],end[i]);
        printf("%lld\n",ans);
    }
}
