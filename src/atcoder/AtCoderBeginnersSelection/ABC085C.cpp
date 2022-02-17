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

    int N, Y;
    cin >> N >> Y;

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N - i; j++) {
            int sum  = 1000 * i + 5000 * j + 10000 * (N - i - j);
            if (Y == sum) {
                cout << (N - i - j) << " " << j << " " << i << endl;
                return 0;
            }
        }
    }

    cout << -1 << " " << -1 << " " << -1 << endl;

    return 0;
}