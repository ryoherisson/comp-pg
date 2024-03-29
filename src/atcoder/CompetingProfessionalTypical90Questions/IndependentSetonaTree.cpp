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

Graph G;
vector<int> binary;
int count_p = 1;
int count_m = 0;

void dfs(int s, int b) {
    for (int v : G[s]) {
        if (binary[v] != 0) continue;
        binary[v] = -1 * b;
        if (binary[v] < 0) count_m++;
        else count_p++;
        dfs(v, binary[v]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N;
    cin >> N;

    G.resize(N);
    binary.assign(N, 0);

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    binary[0] = 1;
    dfs(0, binary[0]);

    int check;
    if (count_p < count_m) check = -1;
    else check = 1;

    int count = 0;

    for (int i = 0; i < N; i++) {
        if (count >= N / 2) break;
        if (binary[i] == check) {
            cout << i + 1 << " ";
            count++;
        }
    }

    cout << endl;

    return 0;
}