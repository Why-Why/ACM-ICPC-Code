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
#include <queue>

using namespace std;

class MultiplicationTable2 {
	private:
		static const int MaxN=55;

		bool inque[MaxN];
		bool in[MaxN];
		int N;
		queue <int> que;
		vector <int> map1;

		int getans(int start) {
			int ret=0;
			int u;
			que.push(start);
			inque[start]=1;

			while(!que.empty()) {
				u=que.front();
				que.pop();

				++ret;
				in[u]=1;

				for(int i=0;i<N;++i)
					for(int j=0;j<N;++j)
						if(in[i] && in[j] && inque[map1[i*N+j]]==0) {
							que.push(map1[i*N+j]);
							inque[map1[i*N+j]]=1;
						}
			}

			return ret;
		}

    public:
    int minimalGoodSet(vector<int> table) {
		map1=table;
		N=sqrt((double)table.size());
		int ans=N;

		for(int i=0;i<N;++i) {
			while(!que.empty()) que.pop();
			memset(in,0,sizeof(in));
			memset(inque,0,sizeof(inque));
			ans=min(getans(i),ans);
		}

        return ans;
    }
};

// CUT begin
ifstream data("MultiplicationTable2.sample");

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

bool do_test(vector<int> table, int __expected) {
    time_t startClock = clock();
    MultiplicationTable2 *instance = new MultiplicationTable2();
    int __result = instance->minimalGoodSet(table);
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
        vector<int> table;
        from_stream(table);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(table, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1458572944;
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
        cout << "MultiplicationTable2 (250 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
