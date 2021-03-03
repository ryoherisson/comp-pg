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

int f(int x) {
    string s = to_string(x);
    sort(all(s));

    int g2 = stoi(s);

    sort(all(s), greater<char>());

    int g1 = stoi(s);

    return g1 - g2;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    int a = n;
    rep(i, k) a = f(a);
    cout << a << endl;

    return 0;
}