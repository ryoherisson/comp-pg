// https://qiita.com/e869120/items/eb50fdaece12be418faa
// https://atcoder.jp/contests/joi2009yo/tasks/joi2009yo_d
#include <bits/stdc++.h>
#define REP(i, m, n) for(int (i) = (m); (i) < (n); ++i)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;
typedef pair<ll, ll> P;
const int INF = 1e9+7;
const ll LINF = 1LL<<60;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int m, n;
vector<vector<int>> g;
int res = 0;

void dfs(int sy, int sx, int cnt=1){
    g[sy][sx] = 0;

    rep(i, 4) {
        int ny = dy[i] + sy;
        int nx = dx[i] + sx;
        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        if (g[ny][nx]==1) {
            res = max(res, cnt+1);
            dfs(ny, nx, cnt + 1);
        }
    }
    g[sy][sx] = 1;
}

int main()
{
    cin >> m >> n;
    g = vector<vector<int>>(n, vector<int>(m));
    rep(i, n) {
        rep(j, m) {
            cin >> g[i][j];
        }
    }


    rep(i, n) {
        rep(j, m) {
            int counter = 0;
            if (!g[i][j]) continue;
            dfs(i, j);
        }
    }

    cout << res << endl;

    return 0;
}