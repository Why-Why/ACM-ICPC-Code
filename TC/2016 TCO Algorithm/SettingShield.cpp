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

const int MaxN=100005;

struct State {
	int LEF,RIG;

	bool operator < (const State &b) const {
		return LEF==b.LEF ? RIG>b.RIG : LEF<b.LEF;
	}

}sta[MaxN];

int pro[MaxN];
int N,T;

int rrr[MaxN];

long long temp[MaxN];
long long C[MaxN];

inline int lowbit(int x) {
	return x&(-x);
}

void add(int p,long long t) {
	for(;p<=N;p+=lowbit(p)) C[p]+=t;
}

long long query(int x) {
	++x;
	long long ret=0;
	for(;x;x-=lowbit(x)) ret+=C[x];
	return ret;
}

void update(int R,long long p) {
	++R;
	add(1,p);
	add(R+1,-p);
}

#define lc (po<<1)
#define rc ((po<<1)|1)
#define lson L,M,lc
#define rson M+1,R,rc

int BIT[MaxN<<2];
int COL[MaxN<<2];

inline void pushUP(int po) {
	BIT[po]=max(BIT[lc],BIT[rc]);
}

inline void pushDown(int po) {
	if(COL[po]!=-1) {
		COL[lc]=max(COL[lc],COL[po]);
		COL[rc]=max(COL[rc],COL[po]);
		BIT[lc]=max(BIT[lc],COL[lc]);
		BIT[rc]=max(BIT[rc],COL[rc]);
		COL[po]=-1;
	}
}

void update(int ul,int ur,int ut,int L,int R,int po) {
	if(ul<=L && ur>=R) {
		BIT[po]=max(BIT[po],ut);
		COL[po]=max(COL[po],ut);
		return;
	}
	pushDown(po);
	int M=(L+R)>>1;
	if(ul<=M) update(ul,ur,ut,lson);
	if(ur>M) update(ul,ur,ut,rson);
	pushUP(po);
}

int query(int p,int L,int R,int po) {
	if(L==R) return BIT[po];		// !!!
	pushDown(po);
	int M=(L+R)>>1;
	if(p<=M) return query(p,lson);
	else return query(p,rson);
}

class SettingShield {
	private:
	long long judge(long long x) {
		long long ret=x*T;

		int p=0;
		long long maxn=0;

		for(int i=0;i<N;++i) {
			temp[i]=pro[i]-x,C[i+1]=0;
			maxn=max(maxn,temp[i]);
		}
		for(int i=0;i<N;++i) {
			temp[i]-=query(i);
			if(temp[i]>0) {
				if(rrr[i]==-1) return -1;
				ret+=temp[i];
				update(rrr[i],temp[i]);
			}
		}

		return ret;
	}

    public:
    long long getOptimalCost(int n, int h, int t, vector<int> val0, vector<int> a, vector<int> b, vector<int> m) {
		N=n;
		T=t;
		pro[0]=val0[0];
		for(int i=1;i<n;++i) pro[i]=((long long)a[0]*(long long)pro[i-1]+b[0])%m[0];

		sta[0].LEF=val0[1];
		sta[0].RIG=val0[2];
		long long dis;
		for(int i=1;i<h;++i) {
			sta[i].LEF=min(n-1LL,((long long)a[1]*(long long)sta[i-1].LEF+b[1])%m[1]);
			dis=sta[i-1].RIG-sta[i-1].LEF;
			sta[i].RIG=min(n-1LL,sta[i].LEF+((long long)a[2]*dis+b[2])%m[2]);
		}
		memset(BIT,-1,sizeof(BIT));
		memset(COL,-1,sizeof(COL));
		for(int i=0;i<h;++i) update(sta[i].LEF+1,sta[i].RIG+1,sta[i].RIG,1,n,1);
		for(int i=0;i<n;++i) rrr[i]=query(i+1,1,n,1);

		int L=0,R=10000000,M1,M2;
		long long x,y;

		while(R>L) {
			M1=(L+L+R)/3;
			M2=(L+R+R)/3;
			x=judge(M1);
			y=judge(M2);

			if(x==-1 || x>y) L=M1+1;
			else if(x<y) R=M2-1;
			else R=M2;
		}

        return judge(L);
    }
};

// CUT begin
ifstream data("SettingShield.sample");

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

bool do_test(int n, int h, int t, vector<int> val0, vector<int> a, vector<int> b, vector<int> m, long long __expected) {
    time_t startClock = clock();
    SettingShield *instance = new SettingShield();
    long long __result = instance->getOptimalCost(n, h, t, val0, a, b, m);
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
        int h;
        from_stream(h);
        int t;
        from_stream(t);
        vector<int> val0;
        from_stream(val0);
        vector<int> a;
        from_stream(a);
        vector<int> b;
        from_stream(b);
        vector<int> m;
        from_stream(m);
        next_line();
        long long __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(n, h, t, val0, a, b, m, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1460475149;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "SettingShield (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
