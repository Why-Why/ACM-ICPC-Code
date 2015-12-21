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

int que[111],cou,N;
long long ans;
long long x,A,B;
int zzz;

const long long mod=1000000007;

int getcou(long long M) {
	int cou=0;
	for(long long tx=x,i=0;i<N;++i) {
		if(tx<M) ++cou;
		tx=(tx*A+B)%mod;
	}
	return cou;
}

long long solve(long long L,long long R) {
	long long M=(L+R)>>1;

	while(R>L) {
		M=(L+R+1)>>1;
		if(getcou(M)>zzz) R=M-1;
		else L=M;	
	}
	return L;
}

class LimitedMemorySeries1 {
    public:
    long long getSum(int n, int x0, int a, int b, vector<int> query) {
		sort(query.begin(),query.end());
		cou=query.size();
		for(int i=0;i<cou;++i) que[i]=query[i];

		x=x0;
		N=n;
		ans=0;
		A=a;
		B=b;
		long long temp=0;
		for(int i=0;i<cou;++i) {
			zzz=que[i];
			temp=solve(temp,1000000006);
			ans+=temp;
		}
		return ans;
    }
};

// CUT begin
ifstream data("LimitedMemorySeries1.sample");

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
    t.clear();
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

bool do_test(int n, int x0, int a, int b, vector<int> query, long long __expected) {
    time_t startClock = clock();
    LimitedMemorySeries1 *instance = new LimitedMemorySeries1();
    long long __result = instance->getSum(n, x0, a, b, query);
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
        int x0;
        from_stream(x0);
        int a;
        from_stream(a);
        int b;
        from_stream(b);
        vector<int> query;
        from_stream(query);
        next_line();
        long long __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(n, x0, a, b, query, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1449751175;
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
        cout << "LimitedMemorySeries1 (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
