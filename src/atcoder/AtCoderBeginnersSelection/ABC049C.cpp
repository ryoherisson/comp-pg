#include <bits/stdc++.h>
#define REP(i, m, n) for(int (i) = (m); (i) < (n); ++i)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
using namespace std;
using Graph = vector< vector<int> >;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;
typedef pair<ll, ll> P;
const int INF = 1e9+7;
const ll LINF = 1LL<<60;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    string s;
    cin >> s;

    string divide[4] = {"dream", "dreamer", "erase", "eraser"};

    reverse(s.begin(), s.end());

    rep(i, 4) reverse(divide[i].begin(), divide[i].end());

    for (int i = 0; i < s.length();) {
        bool isok = false;
        for (int j = 0; j < 4; j++) {
            string d = divide[j];
            if (s.substr(i, d.size()) == d) {
                isok = true;
                i += d.size();
            }
        }
        if (!isok) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}