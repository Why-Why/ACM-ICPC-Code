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
// Created Time  : 2016年03月21日 星期一 22时01分24秒
// File Name     : I.cpp

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

typedef pair<string,int> pii;
queue <pii> que;
set <string> sta;

void bfs(int N) {
	sta.clear();
	while(!que.empty()) que.pop();
	char temp[100]={};
	pii tt;
	string ts;
	string end;

	for(int i=0;i<N-1;++i) temp[i]=i+2+'0';
	ts=string(temp);
	que.push(pii(ts,0));
	sta.insert(ts);

	for(int i=0;i<N-1;++i) temp[i]=N-i+'0';
	end=string(temp);

	while(!que.empty()) {
		tt=que.front();
		que.pop();

		//cerr<<tt.first<<endl;
		if(tt.first==end) {
			cout<<"Ans: "<<tt.second<<endl;
			return;
		}


		for(int i=0;i<N-2;++i) {
			swap(tt.first[i],tt.first[i+1]);
			if(sta.count(tt.first)==0) {
				sta.insert(tt.first);
				que.push(pii(tt.first,tt.second+1));
			}
			swap(tt.first[i],tt.first[i+1]);
		}
		ts=tt.first;
		ts.insert(0,1,ts[ts.length()-1]);
		ts=ts.erase(ts.length()-1,1);
		if(sta.count(ts)==0) {
			sta.insert(ts);
			que.push(pii(ts,tt.second+1));
		}

		char tc=tt.first[0];
		ts=tt.first.erase(0,1);
		ts.append(1,tc);

		if(sta.count(ts)==0) {
			sta.insert(ts);
			que.push(pii(ts,tt.second+1));
		}
	}
}

int main() {
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	int N;

	while(cin>>N)
		bfs(N);
	
	return 0;
}
