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

int N, M;
ll dist[100009];
ll dist1[100009];
ll distN[100009];

vector<pair<int, ll> > G[100009];

void dijkstra(int stt) {
    priority_queue<pair<ll, int>, vector<pair<ll, int> >, greater<pair<ll, int> > > PQ;
    for (int i = 0; i < N; i++) dist[i] = LINF;
    dist[stt] = 0;
    PQ.push(make_pair(0, stt));

    while(!PQ.empty()) {
        int pos = PQ.top().second; PQ.pop();
        for (int i = 0; i < G[pos].size(); i++) {
            int to = G[pos][i].first;
            ll cost = G[pos][i].second;
            if (dist[to] > dist[pos] + cost) {
                dist[to] = dist[pos] + cost;
                PQ.push(make_pair(dist[to], to));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b; ll c;
        cin >> a >> b >> c;
        a--, b--;
        G[a].push_back(make_pair(b, c));
        G[b].push_back(make_pair(a, c));
    }

    dijkstra(0);
    for (int i = 0; i < N; i++) dist1[i] = dist[i];

    dijkstra(N-1);
    for (int i = 0; i < N; i++) distN[i] = dist[i];

    for (int i = 0; i < N; i++) {
        ll ans = dist1[i] + distN[i];
        cout << ans << endl;
    }

    return 0;
}