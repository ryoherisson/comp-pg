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

    int h, w;
    cin >> h >> w;

    string S[h];
    rep(i, h) cin >> S[i];

    int res = 0;

    rep(i, h) {
        rep(j, w) {
            int t = 0;
            if (i == h - 1 || j == w - 1) continue;
            if (S[i][j] == '#') t++;
            if (S[i+1][j] == '#') t++;
            if (S[i][j+1] == '#') t++;
            if (S[i+1][j+1] == '#') t++;
            if (t == 1 || t == 3) res++;
        }
    }

    cout << res << endl;

    return 0;
}