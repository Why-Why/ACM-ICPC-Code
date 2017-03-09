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

long long dp[55][100005];
long long base[100005];
int rem[100005],rcou;

inline long long Euler(int K) {
	long long ret=K;

	for(long long i=2;i*i<=K;++i)
		if(K%i==0) {
			ret-=ret/i;
			while(K%i==0) K/=i;
		}
	if(K>1) ret-=ret/K;

	return ret;
}

int gcd(int a,int b) {
	if(!a) return b;
	return gcd(b%a,a);
}

class ModEquation {
    public:
    vector<int> count(int n, int K, vector<int> query) {
		int t;

		rcou=0;
		rem[rcou++]=0;
		rem[rcou++]=1;
		for(long long i=2;i*i<=K;++i)
			if(K%i==0) {
				rem[rcou++]=i;
				if(i*i!=K) rem[rcou++]=K/i;
			}
		sort(rem,rem+rcou);

		base[0]=K;
		for(int i=1;i<rcou;++i) base[i]=Euler(K/rem[i])*rem[i];

		for(int i=0;i<rcou;++i) dp[1][i]=1;
		for(int p=2;p<=n;++p) {
			dp[p][0]=0;
			for(int j=0;j<rcou;++j)
				(dp[p][0]+=dp[p-1][j]*base[j]%mod)%=mod;

			for(int i=1;i<rcou;++i) {
				dp[p][i]=0;
				for(int j=1;j<rcou && rem[j]*(long long)rem[j]<=rem[i];++j)
					if(rem[i]%rem[j]==0) {
						(dp[p][i]+=dp[p-1][j]*base[j]%mod)%=mod;

						t=rem[i]/rem[j];
						t=lower_bound(rem,rem+rcou,t)-rem;
						if(rem[t]!=rem[j]) (dp[p][i]+=dp[p-1][t]*base[t]%mod)%=mod;		// !!!
					}
			}
		}

		/*
		for(int i=0;i<rcou;++i) cout<<rem[i]<<' ';
		cout<<endl;
		for(int i=0;i<rcou;++i) cout<<base[i]<<' ';
		cout<<endl;
		for(int i=0;i<rcou;++i) cout<<dp[n][i]<<' ';
		cout<<endl;
		*/

		vector <int> ans;

		int len=query.size();
		for(int i=0;i<len;++i) {
			if(query[i]) t=gcd(query[i],K);
			else t=0;

			cout<<t<<endl;

			t=lower_bound(rem,rem+rcou,t)-rem;
			cout<<t<<endl;


			ans.push_back(dp[n][t]);
		}

        return ans;
    }
}ttt;

// CUT begin
ifstream data("ModEquation.sample");

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

bool do_test(int n, int K, vector<int> query, vector<int> __expected) {
    time_t startClock = clock();
    ModEquation *instance = new ModEquation();
    vector<int> __result = instance->count(n, K, query);
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
        int K;
        from_stream(K);
        vector<int> query;
        from_stream(query);
        next_line();
        vector<int> __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(n, K, query, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1483603958;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
	vector<int> tt;
	tt.push_back(122327049);
	cout<<ttt.count(20,420708171,tt)[0]<<endl;
	return 0;

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
        cout << "ModEquation (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
