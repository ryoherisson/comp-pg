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

    int h, w, x, y;
    cin >> h >> w >> x >> y;
    --x, --y;

    string s[h];
    rep(i, h) cin >> s[i];

    int sum = 0;

    if (s[x][y] == '#')
    {
        sum = 0;
    }
    else
    {
        sum++;
        for (int i = x - 1; i >= 0; i--)
        {
            if (s[i][y] == '#')
                break;
            else
                sum++;
        }
        for (int i = x + 1; i < h; i++)
        {
            if (s[i][y] == '#')
                break;
            else
                sum++;
        }
        for (int i = y - 1; i >= 0; i--)
        {
            if (s[x][i] == '#')
                break;
            else
                sum++;
        }
        for (int i = y + 1; i < w; i++)
        {
            if (s[x][i] == '#')
                break;
            else
                sum++;
        }
    }

    cout << sum << endl;

    return 0;
}