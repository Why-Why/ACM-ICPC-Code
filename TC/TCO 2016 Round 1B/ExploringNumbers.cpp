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

class ExploringNumbers {
	private:
	bool vis[1000];

	void init() {
		memset(vis,0,sizeof(vis));
		for(int i=2;i<1000;++i)
			if(!vis[i])
				for(int j=i*2;j<1000;j+=i) vis[j]=1;
	}

	bool isPrime(int n) {
		for(long long i=2;i*i<=n;++i)
			if(n%i==0) return 0;
		return 1;
	}

	int getnext(int x) {
		int ret=0,t;
		while(x) {
			t=x%10;
			ret+=t*t;
			x/=10;
		}
		return ret;
	}

    public:
    int numberOfSteps(int n) {
		if(n!=1 && isPrime(n)) return 1;
		init();
		vis[1]=1;

		set<int> sta;
		sta.clear();
		int ret=1;
		int t=n;

		for(int i=2;i<=n;++i) {
			t=getnext(t);
			++ret;
			if(vis[t]==0) return ret;
			if(sta.count(t)) return -1;
			sta.insert(t);
		}

        return -1;
    }
};

// CUT begin
ifstream data("ExploringNumbers.sample");

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

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(int n, int __expected) {
    time_t startClock = clock();
    ExploringNumbers *instance = new ExploringNumbers();
    int __result = instance->numberOfSteps(n);
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
        int n;
        from_stream(n);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(n, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1460473211;
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
        cout << "ExploringNumbers (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
