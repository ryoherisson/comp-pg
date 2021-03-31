#include <bits/stdc++.h>
#define REP(i, m, n) for (int(i) = (m); (i) < (n); ++i)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
using namespace std;
using Graph = vector<vector<int>>;
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
typedef long long ll;
typedef pair<ll, ll> P;
const int INF = 1e9 + 7;
const ll LINF = 1LL << 60;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n, 0);
    rep(i, n) cin >> a[i];

    int ans = INF * 2;
    for (int i = 0; i < 1 << (n - 1); i++)
    {
        int xored = 0;
        int ored = 0;
        for (int j = 0; j <= n; j++)
        {
            if (j < n)
                ored |= a[j];
            if (j == n || (i >> j & 1))
                xored ^= ored, ored = 0;
        }
        ans = min(ans, xored);
    }

    cout << ans << endl;

    return 0;
}