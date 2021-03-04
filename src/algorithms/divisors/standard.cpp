// 素因数分解
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

void makeDivisors(int a, vector<int> &A) {
    int n = pow(a, 0.5);
    for (int i = 1; i <= n; i++) {
        if (a % i == 0) {
            A.push_back(i);
            if (i != a / i) {
                A.push_back(a / i);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int a;
    cin >> a;

    vector<int> A;
    makeDivisors(a, A);

    for (int i = 0; i < A.size(); i++) {
        cout << A.at(i) << " ";
    }
    cout << endl;

    return 0;
}