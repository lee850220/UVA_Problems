#include <iostream>
#include <cstdio>
#include <string>
#define MAX_N 23
#define min(a, b) ((a) < (b) ? (a) : (b))
using namespace std;

typedef unsigned long long int ulli;

int DP[MAX_N][MAX_N];

int main () {
    int N, M, cases = 0;
    while (1) {
        string name[MAX_N];
        int target;
        int m = 500000;
        scanf("%d %d\n", &N, &M);
        if (N == 0) break;
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                DP[i][j] = 500000;
        
        for (int i = 1; i <= N; i++) {
            getline(cin, name[i], '\n');
            DP[i][i] = 0;
        }

        for (int i = 1, srt, end, dis; i <= M; i++) {
            scanf("%d %d %d\n", &srt, &end, &dis);
            DP[srt][end] = DP[end][srt] = dis;
        }

        for (int k = 1; k <= N; k++) {
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= N; j++) {
                    DP[i][j] = min(DP[i][j], DP[i][k] + DP[k][j]);
                }
            }
        }

        for (int i = 1; i <= N; i++) {
            ulli sum = 0;
            for (int j = 1; j <= N; j++) {
                if(i != j)
                    sum += DP[i][j];
            }
            if (m > sum) {
                m = sum;
                target = i;
            }
        }
        
        cout << "Case #" << ++cases << " : " << name[target] << endl;
    }
}