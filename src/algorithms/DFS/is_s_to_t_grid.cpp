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

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int H, W;
vector<string> field;

bool seen[510][510];

void dfs(int h, int w) {
    seen[h][w] = true;

    for (int dir = 0; dir < 4; ++dir) {
        int nh = h + dy[dir];
        int nw = w + dx[dir];

        if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
        if (field[nh][nw] == '#') continue;

        if (seen[nh][nw]) continue;

        dfs(nh, nw);
    }
}


int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


    cin >> H >> W;
    field.resize(H);

    for (int h = 0; h < H; h++) cin >> field[h];

    int sh, sw, gh, gw;

    for (int h = 0; h < H; ++h) {
        for (int w = 0; w < W; ++w) {
            if (field[h][w] == 's') sh = h, sw = w;
            if (field[h][w] == 't') gh = h, gw = w;
        }
    }

    memset(seen, 0, sizeof(seen));
    dfs(sh, sw);

    if (seen[gh][gw]) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}