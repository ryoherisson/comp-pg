// 連結成分が何個あるか
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
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        G.at(a).push_back(b);
        G.at(b).push_back(a);
    }

    vector<int> dist(N, -1);
    queue<int> que;

    int count = 0;
    for (int v = 0; v < N; v++) {
        if (dist[v] != -1) continue;
        dist.at(v) = 0;
        que.push(v);
        while(!que.empty()) {
            int k = que.front();
            que.pop();
            for(int nv : G.at(k)) {
                if (dist.at(nv) != -1) continue;
                dist.at(nv) = 0;
                que.push(nv);
            }
        }
        count++;
    }

    cout << count << endl;

    return 0;
}