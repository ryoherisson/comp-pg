// https://qiita.com/e869120/items/eb50fdaece12be418faa

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

int n;
int S[100100];

int binarySearch(int key) {
    int left = 0;
    int right = n;
    int mid;

    while(left < right) {
        mid = (left + right) / 2;
        if (key == S[mid]) return 1;
        if (key > S[mid]) left = mid + 1;
        else right = mid;
    }
    return 0;
}

int main()
{
    cin >> n;
    rep(i, n) {
        cin >> S[i];
    }

    int res = 0;
    int q;
    cin >> q;
    rep(i, q) {
        int t;
        cin >> t;
        if (binarySearch(t)) res++;
        // libarary
        // if (binary_search(S, S+n, t)) res++;
    }

    cout << res << endl;

    return 0;
}