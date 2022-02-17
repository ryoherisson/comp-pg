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

ll N, L, K;
ll A[1 << 18];

bool solve(ll M) {
    ll count = 0, pre = 0;
    for (int i = 1; i <= N; i++) {
        if (A[i] - pre >= M && L - A[i] >= M) {
            count++;
            pre = A[i];
        }
    }
    if (count >= K) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N >> L >> K;

    for (int i = 1; i <= N; i++) cin >> A[i];

    ll left = -1;
    ll right = L + 1;
    while (right - left > 1) {
        ll mid = left + (right - left) / 2;
        if (solve(mid) == false) right = mid;
        else left = mid;
    }

    cout << left << endl;

    return 0;
}