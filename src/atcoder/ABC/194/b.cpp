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

    int N;
    cin >> N;

    vector<int> a(N);
    vector<int> b(N);

    rep(i, N) {
        cin >> a[i] >> b[i];
    }

    int res = INF;
    rep (i, N) {
        rep(j, N) {
            res = min(res, i == j ? a[i] + b[i] : max(a[i], b[j]));
        }
    }

    cout << res << endl;

    return 0;
}