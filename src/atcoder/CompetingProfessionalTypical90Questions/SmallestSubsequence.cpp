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

    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    vector<vector< int> > nex(100009, vector<int>(26, 0));

    for (int i = 0; i < 26; i++) nex[S.size()][i] = S.size();
    for (int i = (int)S.size() - 1; i >= 0; i--) {
        for (int j = 0; j < 26; j++) {
            if ((int)(S[i] - 'a') == j) {
                nex[i][j] = i;
            }
            else {
                nex[i][j] = nex[i + 1][j];
            }
        }
    }

    string answer = "";
    int current_pos = 0;
    for (int i = 1; i <= K; i++) {
        for (int j = 0; j < 26; j++) {
            int nex_pos = nex[current_pos][j];
            int max_possible_length = (int)(S.size() - nex_pos - 1) + i;
            if (max_possible_length >= K) {
                answer += (char)('a' + j);
                current_pos = nex_pos + 1;
                break;
            }
        }
    }

    cout << answer << endl;

    return 0;
}