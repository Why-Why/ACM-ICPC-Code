// ━━━━━━神兽出没━━━━━━
//      ┏┓       ┏┓
//     ┏┛┻━━━━━━━┛┻┓
//     ┃           ┃
//     ┃     ━     ┃
//     ████━████   ┃
//     ┃           ┃
//     ┃    ┻      ┃
//     ┃           ┃
//     ┗━┓       ┏━┛
//       ┃       ┃
//       ┃       ┃
//       ┃       ┗━━━┓
//       ┃           ┣┓
//       ┃           ┏┛
//       ┗┓┓┏━━━━━┳┓┏┛
//        ┃┫┫     ┃┫┫
//        ┗┻┛     ┗┻┛
//
// ━━━━━━感觉萌萌哒━━━━━━

// Author        : WhyWhy
// Created Time  : 2016年03月17日 星期四 21时09分39秒
// File Name     : B.cpp

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

using namespace std;

struct State {
	long long t,d,id;
	State() {}
	State(long long a,long long b,long long c):t(a),d(b),id(c) {}
};

int N,B;

queue <State> que;
long long ans[200005];

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	long long a,b;
	long long last=0;
	State temp;

	ios::sync_with_stdio(false);

	cin>>N>>B;
	for(int i=1;i<=N;++i) {
		cin>>a>>b;
		if(a<last) {
			if(que.size()>=B) ans[i]=-1;
			else que.push(State(a,b,i));
		}
		else if(a>=last) {
			if(que.empty()) {
				ans[i]=a+b;
				last=a+b;
			}
			else {
				while(a>=last) {
					if(que.empty()) break;

					temp=que.front();
					que.pop();
    
					ans[temp.id]=last+temp.d;
					last+=temp.d;
				}

				if(a>=last) {
					ans[i]=a+b;
					last=a+b;
				}
				else {
					if(que.size()>=B) ans[i]=-1;
					else que.push(State(a,b,i));
				}
			}
		}
	}

	while(!que.empty()) {
		temp=que.front();
		que.pop();

		ans[temp.id]=last+temp.d;
		last+=temp.d;
	}

	for(int i=1;i<=N;++i) cout<<ans[i]<<' ';
	cout<<endl;
	
	return 0;
}
