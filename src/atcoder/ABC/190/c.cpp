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

    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> cond(M);
    for(auto& [A, B]: cond) cin >> A >> B;
    int K;
    cin >> K;
    vector<pair<int, int>> choice(K);
    for(auto& [C, D] : choice) cin >> C >> D;

    int ans = 0;
    for (int bit = 0; bit < 1 << K; bit++) {
        vector<bool> ball(N);
        for (int i = 0; i < K; i++) {
            const auto [C, D] = choice[i];
            ball[bit & 1 << i ? C : D] = 1;
        }
        int cnt = 0;
        for (auto [A, B] : cond) if(ball[A] && ball[B]) cnt++;
        if (ans < cnt) ans = cnt;
    }
    cout << ans << endl;

    return 0;
}