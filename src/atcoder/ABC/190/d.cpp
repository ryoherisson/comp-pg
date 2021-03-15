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

    ll n;
    cin >> n;
    ll n2 = n*2;
    int ans = 0;
    auto check = [&](ll l) {
        ll tmp = n2 / l - l + 1;
        if (abs(tmp) % 2 == 0) ++ans;
    };

    for (ll x = 1; x*x <= n2; x++) {
        if (n2 % x) continue;
        ll y = n2 / x;
        check(x);
        if (x != y) check(y);
    }

    cout << ans << endl;
    return 0;
}