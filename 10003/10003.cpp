#include <iostream>
#include <climits>
#include <cstdlib>
#define N 51
#define MIN(a, b) ((a)<(b)?(a):(b))
using namespace std;

int dp[N][N], point[N];
int cutting(int, int, int, int);

int main() {
    int length, cut;

    while((cin >> length) && length) {
        cin >> cut;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                dp[i][j] = INT_MAX;
        
        fill(point, point+cut, 0);
        for(int i = 0; i < cut; i++) {
            cin >> point[i];
        }
        cout << "The minimum cutting is " << cutting(0, length, 0, cut - 1) << ".\n";
    }

    return 0;
}

int cutting(int left, int right, int l_index, int r_index) {
    int length = right - left;
    if (l_index == r_index) {
        return length;
    }
    else if (l_index > r_index) {
        return 0;
    }
    else if (dp[l_index][r_index] != INT_MAX) {
        return dp[l_index][r_index];
    }

    for(int i = l_index; i <= r_index; i++) {
        dp[l_index][r_index] = MIN(dp[l_index][r_index], cutting(left, point[i], l_index, i - 1) + cutting(point[i], right, i + 1, r_index) + length);
    }

    return dp[l_index][r_index];
}