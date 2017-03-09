                                            
  //File Name: I.cpp
  //Created Time: 2017年02月13日 星期一 18时15分26秒
                                   
#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstdio>

using namespace std;

const int N=1e6+7;

int fa[N];
int n;
int du[N],flag[N],num[N];

queue <int> que,que1;

inline void init(){
        for (int i=1;i<=n;i++) flag[i]=1,du[i]=0,num[i]=0;
		while(!que.empty()) que.pop();
        num[1]=n;
}

bool pri[N];

int main(){
	for(int i=2;i<N;++i)
		if(!pri[i])
			for(int j=i*2;j<N;j+=i)
				pri[j]=1;

        while (scanf("%d",&n)!=EOF){
                init();
                for (int i=2;i<=n;i++) {
                        scanf("%d",&fa[i]);
                        du[fa[i]]++;
                }
                
                for (int i=1;i<=n;i++)
                        if (du[i]==0) que.push(i);

                int res=n;
                int ans=0;

                while (!que.empty()){
					if(pri[res]==0) {
						if (res>1) ++ans;
						break;
					}

					while(!que1.empty()) que1.pop();

                        int Flag=0;
                        while (!que.empty()) {
                                int u=que.front(); que.pop();
                                num[flag[u]]--;
                                num[flag[fa[u]]]--;
                                flag[fa[u]]+=flag[u];
                                num[flag[fa[u]]]++;
                                
                                du[fa[u]]--;
                                if (du[fa[u]]==0)
                                        que1.push(fa[u]);

                                res--;

                                Flag=flag[fa[u]];
                        }        

                        if (res==num[Flag]) ans++;

                        while (!que1.empty()) {
                                que.push(que1.front());
                                que1.pop();
                        }
                }

                printf("%d\n",ans);
        }        
}
