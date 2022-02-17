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

    int N;
    cin >> N;

    for (int bit = 0; bit < (1 << N); bit++) {
        int sum = 0;
        string s = "";
        for (int i = N - 1; i >= 0; i--) {
            if ((bit & (1 << i)) == 0) {
                sum++;
                s += "(";
            } else {
                sum--;
                s += ")";
            }
            if (sum < 0) {
                break;
            }
        }

        if (sum == 0) {
            cout << s << endl;
        }
    }

    return 0;
}