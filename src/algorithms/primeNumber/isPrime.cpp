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


#define MAXN 100005

int d[MAXN];

bool isPrime(int x) {
    if (x == 0 || x == 1) return false;
    if (x == 2) return true;

    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int q;
    cin >> q;

    for (int i = 3; i < MAXN; i++) {
        d[i] += d[i - 1];
        if (i % 2 != 0 && isPrime(i) && isPrime((i + 1) / 2)) {
            d[i]++;
        }
    }

    rep(i, q) {
        int l, r;
        cin >> l >> r;
        cout << d[r] - d[l-1] << endl;
    }

    return 0;
}