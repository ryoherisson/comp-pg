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

    int n, q;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    cin >> q;
    rep(i, q)
    {
        int m;
        cin >> m;
        bool ok = false;
        for (int bit = 0; bit < (1 << n); bit++)
        {
            int sum = 0;
            rep(i, n)
            {
                if ((bit >> i) & 1)
                {
                    sum += a[i];
                }
            }
            if (m == sum)
            {
                ok = true;
                break;
            }
        }
        if (ok)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    return 0;
}