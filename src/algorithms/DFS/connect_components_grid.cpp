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

int H, W;
vector< vector<int> > field;

void dfs(int h, int w) {
    field[h][w] = 0;

    for (int dh = -1; dh <= 1; ++dh) {
        for (int dw = -1; dw <= 1; ++dw) {
            int nh = h + dh, nw = w + dw;

            if (nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
            if (field[nh][nw] == 0) continue;

            dfs(nh, nw);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    while (cin >> H >> W) {
        if (H == 0 || W == 0) break;
        field.assign(H, vector<int>(W, 0));
        for (int h = 0; h < H; ++h) for (int w = 0; w < W; ++w) cin >> field[h][w];

        int count = 0;
        for (int h = 0; h < H; ++h) {
            for (int w = 0; w < W; ++w) {
                if (field[h][w] == 0) continue;
                dfs(h, w);
                ++count;
            }
        }
        cout << count << endl;
    }

    return 0;
}