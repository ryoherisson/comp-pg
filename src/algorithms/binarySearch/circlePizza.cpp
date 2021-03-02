// https://qiita.com/e869120/items/eb50fdaece12be418faa
// https://atcoder.jp/contests/joi2009ho/tasks/joi2009ho_b
#include <bits/stdc++.h>
#define REP(i, m, n) for(int (i) = (m); (i) < (n); ++i)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;
typedef pair<ll, ll> P;
const int INF = 1e9+7;
const ll LINF = 1LL<<60;

int main()
{
    int d, n, m;
    cin >> d >> n >> m;

    vector<int> D;
    D.push_back(0);
    rep(i, n-1) {
        int a;
        cin >> a;
        D.push_back(a);
    }
    D.push_back(d);

    sort(D.begin(), D.end());

    int res = 0;
    rep(i, m) {
        int k;
        cin >> k;
        int j = lower_bound(D.begin(), D.end(), k) - D.begin();
        res += min(abs(D[j] - k), abs(D[j-1] - k));
    }

    cout << res << endl;

    return 0;
}