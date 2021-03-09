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

#define MAXN 1000

int n;
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

vector<pair<int, ll>> adj[MAXN];

void dijkstra(int a, int b) {
    priority_queue<pair<ll, int>> PQ;
    int color[MAXN];
    ll d[MAXN];
    rep(i, MAXN) {
        color[i] = WHITE;
        d[i] = LINF;
    }

    d[a] = 0;
    PQ.push(make_pair(d[a], a));
    color[a] = GRAY;

    while(!PQ.empty()) {
        pair<ll, int> f = PQ.top();
        PQ.pop();

        int u = f.second;
        color[u] = BLACK;

        if (d[u] < f.first * (-1)) continue;

        rep(i, (int)adj[u].size()) {
            int v = adj[u][i].first;
            if (color[v] == BLACK) continue;
            if (d[v] > d[u] + adj[u][i].second) {
                d[v] = d[u] + adj[u][i].second;
                PQ.push(make_pair(d[v] * (-1), v));
                color[v] = GRAY;
            }
        }
    }
    if (d[b] == LINF) cout << -1 << endl;
    else cout << d[b] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int k;
    cin >> n >> k;

    rep(i, k) {
        int a;
        cin >> a;
        if (a) {
            int c, d;
            ll e;
            cin >> c >> d >> e;
            --c, --d;
            adj[c].push_back(make_pair(d, e));
            adj[d].push_back(make_pair(c, e));
        }
        else {
            int a, b;
            cin >> a >> b;
            --a, --b;
            dijkstra(a, b);
        }
    }

    return 0;
}