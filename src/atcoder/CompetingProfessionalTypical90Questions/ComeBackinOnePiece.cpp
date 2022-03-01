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

bool used[1 << 18];
Graph G;
Graph H;
vector<int> I;
ll counts = 0;

void dfs(int pos) {
    used[pos] = true;
    for (int i : G[pos]) {
        if (used[i] == false) dfs(i);
    }
    I.push_back(pos);
}

void dfs2(int pos) {
    used[pos] = true;
    counts++;
    for (int i : H[pos]) {
        if (used[i] == false) dfs2(i);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N >> M;
    G.resize(N);
    H.resize(N);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        H[b].push_back(a);
    }

    // first dfs
    for (int i = 0; i < N; i++) {
        if (used[i] == false) dfs(i);
    }

    // second dfs
    ll answer = 0;
    reverse(I.begin(), I.end());
    for (int i = 0; i < M; i++) used[i] = false;
    for (int i : I) {
        if (used[i] == true) continue;
        counts = 0;
        dfs2(i);
        answer += counts * (counts - 1LL) / 2LL;
    }

    cout << answer << endl;

    return 0;
}