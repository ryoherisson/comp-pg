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

double dp[2010][2010];

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N, K;
    cin >> N >> K;
    dp[1][1] = 1;

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < K; j++) {
            if (j + 1 < K) dp[i+1][j+1] += dp[i][j] / 2.0;
            dp[i+1][1] += dp[i][j] / 2.0;
        }
    }

    double sum = 0.0;
    for (int i = 0; i < K; i++) sum += dp[N][i];
    cout << 1 - sum << endl;

    return 0;
}