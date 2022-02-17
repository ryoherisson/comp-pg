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
    int t_prev = 0, x_prev = 0, y_prev = 0;

    rep(i, N) {
        int t, x, y;
        cin >> t >> x >> y;

        int a = t - t_prev - (abs(x - x_prev) + abs(y - y_prev));
        if (!(a >= 0 && a % 2 == 0)) {
            cout << "No" << endl;
            return 0;
        }

        t_prev = t, x_prev = x, y_prev = y;
    }

    cout << "Yes" << endl;

    return 0;
}