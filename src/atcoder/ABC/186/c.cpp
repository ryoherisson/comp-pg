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

string to_oct(int n)
{
    string s;
    while (n)
    {
        s = to_string(n % 8) + s;
        n /= 8;
    }
    return s;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int sum = 0;

    REP(i, 1, n + 1)
    {
        string s = to_string(i);
        bool ok = true;
        rep(j, s.length())
        {
            if (s[j] == '7')
                ok = false;
        }

        s = to_oct(i);
        rep(j, s.length())
        {
            if (s[j] == '7')
                ok = false;
        }
        if (ok)
            sum++;
    }

    cout << sum << endl;

    return 0;
}