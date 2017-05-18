#include <iostream>
#define MAX_N 1001
using namespace std;

typedef unsigned long long int ulli;

ulli DP[MAX_N][MAX_N] = {};
int list[MAX_N];

int main() {
    int N, M;
    ulli max;
    for (int i = 0; i <= MAX_N; i++)
            DP[i][0] = 1;

    while (1) {
        N = 0, M = 0;
        cin >> N >> M;
        if (N == 0 && M == 0) break;
        for (int i = 1; i <= N; i++) {
            cin >> list[i];
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= i; j++) {
                DP[i][j] = DP[i-1][j-1]*list[i] + DP[i-1][j];
                if (DP[i][j] >= M)
                    DP[i][j] %= M;
            }
        }

        max = 0;
        for (int i = 1; i <= N; i++) {
            if(max < DP[N][i]) 
                max = DP[N][i];
        }
        cout << max << endl;
    }
    return 0;
}