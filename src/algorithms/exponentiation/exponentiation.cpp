#include <bits/stdc++.h>
#define REP(i, m, n) for(int (i) = (m); (i) < (n); ++i)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
using namespace std;
using Graph = vector< vector<int> >;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;
typedef pair<ll, ll> P;
const int INF = 1e9+7;
const ll LINF = 1LL<<60;

const int mod = 1e9+7;

int PowModRepeatSquaring(int a, int b) {
    if (b == 1) return a;
    if (b % 2 == 0) {
        int c = PowModRepeatSquaring(a, b / 2);
        return c * c % mod;
    }
    else {
        return a * PowModRepeatSquaring(a, b - 1) % mod;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int m, n;
    cin >> m >> n;

    cout << PowModRepeatSquaring(m, n) << endl;

    return 0;
}