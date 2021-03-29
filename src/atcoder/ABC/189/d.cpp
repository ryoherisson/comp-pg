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
    vector<ll> dp(2, 1);
    rep(i, n)
    {
        string s;
        cin >> s;
        vector<ll> p(2);
        swap(dp, p);
        rep(j, 2) rep(x, 2)
        {
            int nj = j;
            if (s == "AND")
                nj &= x;
            else
                nj |= x;
            dp[nj] += p[j];
        }
    }

    cout << dp[1] << endl;

    return 0;
}