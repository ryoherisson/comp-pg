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

int Q;
long double T, L, X, Y, E;
long double PI = 3.14159265358979;

long double query(long double I) {
    long double cx = 0;
    long double cy = -(L / 2.0) * sin(I / T * 2.0 * PI);
    long double cz = (L / 2.0) - (L / 2.0) * cos(I / T * 2.0 * PI);
    long double d1 = sqrt((cx - X) * (cx - X) + (cy - Y) * (cy - Y));
    long double d2 = cz;
    long double kaku = atan2(d2, d1);
    return kaku * 180.0L / PI;
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> T >> L >> X >> Y;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        cin >> E;
        printf("%.12Lf\n", query(E));
    }

    return 0;
}