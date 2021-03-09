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

    int N, W;
    cin >> N >> W;
    vector<int> v(N+1), w(W+1);
    rep(i, N) {
        cin >> v[i] >> w[i];
    }

    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

    rep(i, N) {
        rep(j, W + 1) {
            dp[i+1][j] = dp[i][j];
            if (j >= w[i]) {
                dp[i+1][j] = max(dp[i+1][j], dp[i][j - w[i]] + v[i]);
            }
        }
    }

    cout << dp[N][W] << endl;

    /* DP配列使い回しver
    vector<int> dp(W + 1, 0);
    rep(i, N) {
        for (int j = 0; j >= 0; j--) {
            if (j >= w[i]) {
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
            }
        }
    }
    */

    return 0;
}