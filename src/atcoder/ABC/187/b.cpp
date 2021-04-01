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
    double x[n];
    double y[n];

    rep(i, n)
    {
        cin >> x[i] >> y[i];
    }

    int ans = 0;

    rep(i, n - 1)
    {
        REP(j, i + 1, n)
        {
            if (x[j] - x[i] == 0)
                continue;
            double r = (y[j] - y[i]) / (x[j] - x[i]);
            if (r >= -1 && r <= 1)
                ans++;
        }
    }

    cout << ans << endl;

    return 0;
}