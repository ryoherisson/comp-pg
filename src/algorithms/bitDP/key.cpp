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
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    vector< pair<int, int> > key;
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        int s = 0;
        rep(j, b) {
            int c;
            cin >> c;
            --c;
            s |= 1 << c; // 1 << 3 -> 1000
        }
        key.push_back(make_pair(s, a));
    }

    // dp[s]:= sを全て開けられる鍵の買い方の最小コスト
    vector<int> dp(1 << n, INF);
    dp[0] = 0;
    rep(s, 1 << n) {
        rep(i, m) {
            int t = s | key[i].first;
            int cost = dp[s] + key[i].second;
            dp[t] = min(dp[i], cost);
        }
    }

    int ans = dp.back();
    if (ans == INF) ans = -1;
    cout << ans << endl;

    return 0;
}