// 二部グラフ判定
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

    Graph G(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        G.at(a).push_back(b);
        G.at(b).push_back(a);
    }

    bool is_bipartite = true;
    vector<int> dist(N, -1);
    queue<int> que;

    for (int v = 0; v < N; v++) {
        if (dist.at(v) != -1) continue;
        dist.at(v) = 0;
        que.push(v);

        while (!que.empty()) {
            int k = que.front();
            que.pop();
            for (int nv: G.at(k)) {
                if (dist.at(nv) == -1) {
                    dist.at(nv) = dist.at(nv) + 1;
                    que.push(nv);
                } else {
                    if (dist.at(nv) == dist.at(k)) is_bipartite = false;
                }
            }
        }
    }

    if (is_bipartite) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}