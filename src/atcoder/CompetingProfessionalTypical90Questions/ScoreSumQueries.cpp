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
    vector<int> first(N+1, 0);
    vector<int> second(N+1, 0);

    for (int i = 0; i < N; i++) {
        int c, p;
        cin >> c >> p;
        if (c == 1) {
            first[i+1] += first[i] + p;
            second[i+1] += second[i];
        } else {
            first[i+1] += first[i];
            second[i+1] += second[i] + p;
        }
    }

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        int ans1 = first[r] - first[l-1];
        int ans2 = second[r] - second[l-1];
        cout << ans1 << " " << ans2 << endl;
    }

    return 0;
}