#include<iostream>
using namespace std;
#define MAX 100000

int partition(int A[], int p, int r) {
    int x, i, j, t;
    x = A[r];
    i = p - 1;
    for (j = p; j < r; j++) {
        if (A[j] <= x) {
            i++;
            t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
    }
    t = A[i + 1];
    A[i + 1] = A[r];
    A[r] = t;
    return i + 1;
}

void quickSort(int A[], int p, int r) {
    int q;
    if (p < r) {
        q = partition(A, p, r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}

int main() {
    int A[MAX], n;

    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];

    quickSort(A, 0, n - 1);

    for (int i = 0; i < n; i++) {
        if (i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    return 0;
}