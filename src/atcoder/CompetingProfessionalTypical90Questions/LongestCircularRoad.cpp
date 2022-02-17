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

void getdist(int start, Graph G, vector<int>& dist) {

    for (int i = 1; i <= dist.size() - 1; i++) dist[i] = -1;

    queue<int> que;
    que.push(start);
    dist[start] = 0;

    while(!que.empty()) {
        int v = que.front();
        que.pop();

        for (int nv : G[v]) {
            if (dist[nv] != -1) continue;
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N;
    cin >> N;

    Graph G(N+1);

    int a, b;

    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> dist(N+1);

    getdist(1, G, dist);
    int maxn1 = -1, maxid1 = -1;
    for (int i = 1; i <= N; i++) {
        if (maxn1 < dist[i]) {
            maxn1 = dist[i];
            maxid1 = i;
        }
    }

    getdist(maxid1, G, dist);
    int maxn2 = -1;
    for (int i = 1; i <= N; i++) {
        maxn2 = max(maxn2, dist[i]);
    }

    cout << maxn2 + 1 << endl;

    return 0;
}