// https://qiita.com/e869120/items/eb50fdaece12be418faa

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

const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};
int w, h;

void dfs(const vector<vector<int>> &c, vector<vector<bool>> &seen, int x, int y) {
    rep(k, 8) {
        if (x + dx[k] < 0 || x + dx[k] >= w || y + dy[k] < 0 || y + dy[k] >= h) continue;
        if (seen[y+dy[k]][x+dx[k]] == true) continue;
        if (c[y+dy[k]][x+dx[k]] == 1) {
            seen[y+dy[k]][x+dx[k]] = true;
            dfs(c, seen, x+dx[k], y+dy[k]);
        }
    }
}


int main()
{
    int n = 3;
    while(true) {
        cin >> w >> h;
        if (w == 0 && h == 0) break;
        vector<vector<int>> c(h, vector<int>(w));
        rep(i, h) {
            rep(j, w) {
                cin >> c[i][j];
            }
        }

        vector<vector<bool>> seen(h, vector<bool>(w, false));

        int sum = 0;
        rep(i, h) {
            rep(j, w) {
                if (c[i][j] == 0) continue;
                if (seen[i][j]) continue;
                dfs(c, seen, j, i);
                sum++;
            }
        }

        cout << sum << endl;
        n--;
    }


    return 0;
}