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

    ll n;
    cin >> n;

    ll X = 0;
    vector<ll> x(n);
    rep(i, n)
    {
        ll a, b;
        cin >> a >> b;
        X -= a;
        x[i] = a + a + b;
    }
    sort(x.begin(), x.end());
    ll ans = 0;
    while (X <= 0)
    {
        X += x.back();
        x.pop_back();
        ans++;
    }

    cout << ans << endl;

    return 0;
}