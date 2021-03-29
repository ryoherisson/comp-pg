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

    ll N;
    cin >> N;

    int comma = 0;
    ll ans = 0;
    ll L = 1, R = 10;
    REP(i, 0, 16)
    {
        if (R <= N)
            ans += (R - L) * comma;
        else if (L <= N && N < R)
            ans += (N - L + 1) * comma;

        L *= 10;
        R *= 10;
        if (i % 3 == 2)
            comma++;
    }

    cout << ans << endl;

    return 0;
}