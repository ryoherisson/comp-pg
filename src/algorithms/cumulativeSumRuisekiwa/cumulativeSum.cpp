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

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n;
    cin >> n;
    ll a[n+1] = {};

    rep(i, n) {
        int x;
        cin >> x;
        if (i == 0) a[i + 1] = x;
        else a[i + 1] = a[i] + x;
    }

    ll res = 0;
    REP(k, 1, n + 1) {
        REP(i, k, n + 1) {
            chmax(res, a[i] - a[i - k]);
        }
        cout << res << endl;
    }

    return 0;
}