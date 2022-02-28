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

    int A, B, C, N;
    cin >> N >> A >> B >> C;

    ll ans = LINF;

    for (int i = 0; i <= 9999; i++) {
        for (int j = 0; j <= 9999 - i; j++) {
            ll v = N - 1LL * i * A - 1LL * j * B;
            ll r = 1LL * i + 1LL * j + v / C;
            if (v % C != 0LL || v < 0 || r > 9999LL) continue;
            ans = min(ans, r);
        }
    }

    cout << ans << endl;

    return 0;
}