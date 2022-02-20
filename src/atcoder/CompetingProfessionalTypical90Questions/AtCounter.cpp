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
    string S;
    cin >> N >> S;

    long long mod = 1000000007;

    vector<vector <ll> > dp(100009, vector<ll>(8, 0));
    dp[0][0] = 1;

    for (int i = 0; i < (int)S.size(); i++) {
        for (int j = 0; j <= 7; j++) {
            dp[i + 1][j] += dp[i][j];
            if (S[i] == 'a' && j == 0) dp[i + 1][j + 1] += dp[i][j];
            if (S[i] == 't' && j == 1) dp[i + 1][j + 1] += dp[i][j];
            if (S[i] == 'c' && j == 2) dp[i + 1][j + 1] += dp[i][j];
            if (S[i] == 'o' && j == 3) dp[i + 1][j + 1] += dp[i][j];
            if (S[i] == 'd' && j == 4) dp[i + 1][j + 1] += dp[i][j];
            if (S[i] == 'e' && j == 5) dp[i + 1][j + 1] += dp[i][j];
            if (S[i] == 'r' && j == 6) dp[i + 1][j + 1] += dp[i][j];
        }
        for (int j = 0; j <= 7; j++) dp[i + 1][j] %= mod;
    }

    cout << dp[S.size()][7] << endl;
    return 0;
}