#include <iostream>
#include <climits>
#define SIZE 101
#define MAX(a, b) ((a) > (b) ? (a) : (b))
using namespace std;

int dp[SIZE][SIZE];
int A[SIZE];

int dfs(int l, int r) {
    if (l > r) return 0;
    if (dp[l][r] != -INT_MAX) return dp[l][r];
    int sum = 0;

    for (int i = l; i <= r; i++) {
        sum += A[i];
        dp[l][r] = MAX(dp[l][r], sum - dfs(i+1, r));
    }
    sum = 0;
    for (int i = r; i >= l; i--) {
        sum += A[i];
        dp[l][r] = MAX(dp[l][r], sum - dfs(l, i-1));
    }
    return dp[l][r];
}

int main() {
    int size;

    while (1) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++)
                dp[i][j] = -INT_MAX;
        }
        cin >> size;
        if (!size) break;
        for (int i = 0; i < size; i++)
            cin >> A[i];
        cout << dfs(0, size-1) << endl;
    }
    return 0;
}