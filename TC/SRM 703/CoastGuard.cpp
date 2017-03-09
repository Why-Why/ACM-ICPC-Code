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

const int mod=1000000007;

vector <int> D,X,Y;
int N;
long long cant[55][55];

long long dfs(int p,long long sta) {
	cout<<p<<' '<<sta<<endl;

	if(p>=N) return 1;

	long long ret=0;

	for(int i=0;i<N;++i) {
		cout<<p<<' '<<i<<' '<<cant[p][i]<<' '<<sta<<endl;
		if(sta&(1LL<<i));
		else if((cant[p][i]|sta)==sta) {
			ret+=dfs(p+1,sta|(1LL<<i));
			if(ret>=mod) ret-=mod;
		}
	}

	return ret;
}

inline bool judge(int a,int b,int c) {
	int x1=X[b]-D[a],y1=Y[b];
	int x2=X[b]-D[N-1],y2=Y[b];
	int tx1=X[c]-D[a],ty1=Y[c];
	int tx2=X[c]-D[N-1],ty2=Y[c];

	if(x2*ty2==y2*tx2) {
		if(tx2*tx2+ty2*ty2>=x2*x2+y2*y2) return 1;
		else return 0;
	}

	if(x2*ty2>=y2*tx2 && x1*ty1>=y1*tx1) return 1;
	return 0;
}

class CoastGuard {
    public:
    int count(vector<int> d, vector<int> x, vector<int> y) {
		D=d; X=x; Y=y;
		sort(D.begin(),D.end());
		N=D.size();

		for(int i=0;i<N;++i)
			for(int j=0;j<N;++j) {
				cant[i][j]=0;
				for(int k=0;k<N;++k)
					if(j!=k && judge(i,j,k)) {
						cant[i][j]|=(1LL<<k);
					}
			}

		return dfs(0,0);
    }
};

// CUT begin
ifstream data("CoastGuard.sample");

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

bool do_test(vector<int> d, vector<int> x, vector<int> y, int __expected) {
    time_t startClock = clock();
    CoastGuard *instance = new CoastGuard();
    int __result = instance->count(d, x, y);
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
        vector<int> d;
        from_stream(d);
        vector<int> x;
        from_stream(x);
        vector<int> y;
        from_stream(y);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(d, x, y, __answer)) {
            passed++;
        }

		getchar();
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1483798600;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "CoastGuard (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
