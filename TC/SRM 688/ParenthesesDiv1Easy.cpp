#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <fstream>

using namespace std;

const int MaxN=1005;

int N;
int sum[MaxN];
int minn[MaxN][MaxN];

int dp[MaxN][MaxN];
int fa[MaxN][MaxN];

void init(string & s) {
	sum[0]=0;
	memset(dp,-1,sizeof(dp));

	for(int i=1;i<=N;++i) {
		sum[i]=sum[i-1]+(s[i-1]=='(' ? 1 : -1);

		int cou=0,tminn=MaxN;
		for(int j=i;j<=N;++j) {
			cou+=(s[j-1]=='(' ? 1 : -1);
			tminn=min(tminn,cou);
			minn[i][j]=tminn;
		}

		cou=0,tminn=MaxN;
		for(int j=i;j>=1;--j) {
			cou-=(s[j-1]=='(' ? 1 : -1);
			tminn=min(tminn,cou);
			minn[i][j]=tminn;
		}
	}
}

int getans(int u,int v) {
	if(u==0) return (v==0 ? 0 : 11);
	if(dp[u][v]!=-1) return dp[u][v];

	int & ret=dp[u][v],t;

	for(int i=0;i<u-1;++i) {
		if(v-(sum[u]-sum[i])>=-minn[i+1][u] && (t=getans(i,v-(sum[u]-sum[i])))<=10) {
			if(ret==-1 || ret>t) { ret=t; fa[u][v]=u-i; }
		}
		else if(v+(sum[u]-sum[i])>=-minn[u][i+1] && (t=getans(i,v+(sum[u]-sum[i])))<10) {
			if(ret==-1 || ret>t+1) { ret=t+1; fa[u][v]=i-u; }
		}
	}

	int i=u-1;
	if(v-(sum[u]-sum[i])>=minn[i+1][u] && (t=getans(i,v-(sum[u]-sum[i])))<=10) {
		if(ret==-1 || ret>t) { ret=t; fa[u][v]=u-i; }
	}
	else if(v+(sum[u]-sum[i])>=-minn[u][i+1] && (t=getans(i,v+(sum[u]-sum[i])))<10) {
		if(ret==-1 || ret>t+1) { ret=t+1; fa[u][v]=i-u; }
	}

	if(ret==-1) ret=11;

	return ret;
}

class ParenthesesDiv1Easy {
    public:
    vector<int> correct(string s) {
		N=s.length();
		vector <int> ret;
		ret.push_back(-1);

		if(N&1) return ret;

		init(s);
		if(getans(N,0)>10) return ret;

		ret.clear();
		int u=N,v=0,t;

		while(u) {
			t=fa[u][v];
			if(t>=0) v-=sum[u]-sum[u-t];
			else t=-t,v+=sum[u]-sum[u-t],ret.push_back(u-1),ret.push_back(u-t);
			u-=t;
		}

		reverse(ret.begin(),ret.end());
        return ret;
    }
};

// CUT begin
ifstream data("ParenthesesDiv1Easy.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

template <typename T> string to_string(vector<T> ts) {
    stringstream s;
    s << "[ ";
    for (int i = 0; i < ts.size(); ++i) {
        if (i > 0) s << ", ";
        s << to_string(ts[i]);
    }
    s << " ]";
    return s.str();
}

bool do_test(string s, vector<int> __expected) {
    time_t startClock = clock();
    ParenthesesDiv1Easy *instance = new ParenthesesDiv1Easy();
    vector<int> __result = instance->correct(s);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        string s;
        from_stream(s);
        next_line();
        vector<int> __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(s, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1461075161;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 250 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "ParenthesesDiv1Easy (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
