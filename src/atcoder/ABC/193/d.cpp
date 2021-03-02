#include <bits/stdc++.h>
#define REP(i, m, n) for(int (i) = (m); (i) < (n); ++i)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
using namespace std;
using Graph = vector<vector<int> >;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;
typedef pair<ll, ll> P;
const int INF = 1e9+7;
const ll LINF = 1LL<<60;

ll score(const string &S) {
    vector<ll> val(10);
    REP(v, 1, 10) val[v] = v;
    for (auto c: S) val[c - '0'] *= 10;
    ll sum = 0;
    REP(v, 1, 10) sum += val[v];
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    ll K;
    string S, T;
    cin >> K >> S >> T;

    vector<ll> rem(10, K);
    rep(i, 4) rem[S[i]-'0']--, rem[T[i]-'0']--;

    double res = 0.0;

    REP(i, 1, 10) {
        REP(j, 1, 10) {
            S[4] = (char)('0' + i), T[4] = (char)('0' + j);

            if (score(S) > score(T)) {
                if (i != j) res += rem[i] * rem[j];
                else res += rem[i] * (rem[i] - 1);
            }
        }
    }

    res /= (K*9-8) * (K*9-9);
    cout << fixed << setprecision(10) << res << endl;

    return 0;
}