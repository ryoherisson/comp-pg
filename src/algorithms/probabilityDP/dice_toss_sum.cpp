// https://compro.tsutaj.com//archive/180220_probability_dp.pdf
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

const int MAXN = 200;
double dp[MAXN][6*MAXN];

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < K; j++) {
            for (int k=1; k < 6; k++) {
                dp[i+1][min(K, j+k)] += dp[i][j] / 6.0;
            }
        }
    }

    cout << dp[N][K] << endl;

    return 0;
}