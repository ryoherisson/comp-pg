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

    int N, Q;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());

    cin >> Q;
    vector<int> B(Q);
    for (int i = 0; i < Q; i++) {
        int b;
        cin >> b;
        int ind = lower_bound(A.begin(), A.end(), b) - A.begin();
        if (ind == N) cout << abs(b - A[N-1]) << endl;
        else if (ind == 0) cout << abs(b - A[0]) << endl;
        else {
            cout << min(abs(b - A[ind]), abs(b - A[ind-1])) << endl;
        }
    };


    return 0;
}