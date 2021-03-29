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

    vector<int> a(1 << n);
    rep(i, 1 << n) cin >> a[i];

    int half = 1 << (n - 1);
    int max = max_element(a.begin(), a.end()) - a.begin();
    auto start = max < half ? a.begin() + half : a.begin();
    cout << (int)(max_element(start, start + half) - a.begin() + 1) << endl;

    return 0;
}