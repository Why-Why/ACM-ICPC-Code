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

const int step[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

class BoardEscape {
    public:
	int N,M;
	int K;
	vector <string> *ss;

	bool can(int x,int y) {
		return x>=0 && x<N && y>=0 && y<M;
	}

	bool rem(int x,int y) {
		int nx,ny;
		for(int i=0;i<4;++i) {
			nx=x+step[i][0];
			ny=y+step[i][1];
			if(can(nx,ny) && (*ss)[nx][ny]=='E') return 1;
		}
		return 0;
	}

	bool judge(int x,int y) {
		int nx,ny;
		int cou=0;
		for(int i=0;i<4;++i) {
			nx=x+step[i][0];
			ny=y+step[i][1];
			if(can(nx,ny)==0) continue;
			if((*ss)[nx][ny]=='E') return 1;
			if((*ss)[nx][ny]=='#' || rem(nx,ny)) ++cou;
		}
		if(cou==4) return 0;
		return (K&1);
	}

    string findWinner(vector<string> s, int k) {
		int cou=0;

		ss=&s;
		K=k;
		N=s.size();
		M=s[0].size();

		for(int i=0;i<N;++i)
			for(int j=0;j<M;++j)
				if(s[i][j]=='T' && judge(i,j))
					++cou;

        return (cou&1) ? "Alice" : "Bob";
    }
};

// CUT begin
ifstream data("BoardEscape.sample");

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

bool do_test(vector<string> s, int k, string __expected) {
    time_t startClock = clock();
    BoardEscape *instance = new BoardEscape();
    string __result = instance->findWinner(s, k);
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
        vector<string> s;
        from_stream(s);
        int k;
        from_stream(k);
        next_line();
        string __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(s, k, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1450455442;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 450 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "BoardEscape (450 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
