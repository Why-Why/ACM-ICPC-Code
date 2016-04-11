#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int MaxL=400005;
const int MaxC=27;

int que[MaxL],first,last;

vector<int>rem[MaxL];
int zhuan[200005];

struct AC_auto {
	int next1[MaxL][MaxC],fail[MaxL];
	int root,Tp;
	bool word[MaxL];
	int success[MaxL];

	void init() {
		Tp=1;
		success[Tp]=-1;
		root=Tp++;
		first=last=0;
	}

	void insert(int id,char s[]) {
		int p=root;
		for(int i=0;s[i];++i) {
			if(next1[p][s[i]-'a']==0) {
				success[Tp]=-1;
				next1[p][s[i]-'a']=Tp++;
			}
			p=next1[p][s[i]-'a'];
		}
		word[p]=1;
		zhuan[id]=p;
	}

	void build() {
		int p,temp;
		fail[root]=-1;
		que[last++]=root;
		while(last-first) {
			p=que[first++];
			for(int i=0;i<MaxC;++i)
				if(next1[p][i]!=0) {
					if(p==root) fail[next1[p][i]]=root;
					else {
						temp=fail[p];
						while(temp!=-1) {
							if(next1[temp][i]!=0) {
								fail[next1[p][i]]=next1[temp][i];
								break;
							}
							temp=fail[temp];
						}
						if(temp==-1) fail[next1[p][i]]=root;
					}
					que[last++]=next1[p][i];
				}
		}
	}

	void dfs(int p) {
		if(success[p]!=-1) return;
		if(fail[p]==root) { success[p]=root; return; }
		if(word[fail[p]]) { success[p]=fail[p]; return; }
		dfs(fail[p]);
		success[p]=success[fail[p]];
	}

	void getSuccess() {
		success[root]=-1;
		for(int i=root+1;i<Tp;++i)
			if(success[i]==-1)
				dfs(i);
	}

	void query(char s[]) {
		int p=root,temp;
		int cou=1;
		int len;

		for(int i=0;s[i];++i) {
			if(s[i]=='z'+1) ++cou;
			while(p!=root && next1[p][s[i]-'a']==0) p=fail[p];
			if(next1[p][s[i]-'a']!=0) p=next1[p][s[i]-'a'];
			else p=root;
			temp=p;
			while(temp!=root) {
				//cout<<i<<' '<<temp<<endl;
				if(word[temp]) rem[temp].push_back(cou);
				//temp=fail[temp];
				temp=success[temp];
			}
		}
	}
}AC;

char s[MaxL];

int N,Q;

bool vis[MaxL];

int main() {
	AC.init();

	int a,b,c;
	int cou=0;

	scanf("%d %d",&N,&Q);
	for(int i=1;i<=N;++i) {
		scanf("%s",s+cou);
		AC.insert(i,s+cou);
		cou+=strlen(s+cou);
		s[cou++]='z'+1;
		s[cou]=0;
	}
	AC.build();
	AC.getSuccess();
	AC.query(s);


	for(int i=1;i<=N;++i)
		if(vis[zhuan[i]]==0) {
			sort(rem[zhuan[i]].begin(),rem[zhuan[i]].end());
			vis[zhuan[i]]=1;
		}

	while(Q--) {
		scanf("%d %d %d",&a,&b,&c);
		printf("%d\n",(int)(upper_bound(rem[zhuan[c]].begin(),rem[zhuan[c]].end(),b)-lower_bound(rem[zhuan[c]].begin(),rem[zhuan[c]].end(),a)));
	}

	return 0;
}
