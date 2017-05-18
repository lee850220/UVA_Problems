#include <iostream>
#include <string>
#define MAX_N 16
using namespace std;

typedef unsigned long long int ulli;
ulli DP[MAX_N][MAX_N];
int transpos(char);

int transpos(char A) {
    if (A >= '1' && A <= '9')
        return A - '0';
    else
        return A - 'A' + 10;
}

int main () {
    int length = 0;
    ulli sum;
    string temp;
    while (getline(cin, temp, '\n')) {
        length = temp.length();
        if(length == 0) continue;
        for (int n = 1; n <= length; n++) {
            DP[n][1] = 0;
        }
        if (temp[0] != '?') {
            DP[transpos(temp[0])][1] = 1;
        } else {
            for (int n = 1; n <= length; n++) {
               DP[n][1] = 1;
            }
        }

        for (int j = 2; j <= length; j++) {
            if (temp[j-1] == '?') {
                for (int i = 1; i <= length; i++) {
                    sum = 0;
                    for (int x = 1; x <= length; x++) {
                        int range = x - i;
                        if (range >= -1 && range <= 1) continue;
                        sum += DP[x][j - 1];
                    }
                    DP[i][j] = sum;
                }
            } else {
                for (int i = 1; i <= length; i++) {
                    if (i == transpos(temp[j-1])) {
                        sum = 0;
                        for (int x = 1; x <= length; x++) {
                            int range = x - i;
                            if (range >= -1 && range <= 1) continue;
                            sum += DP[x][j - 1];
                        }
                        DP[i][j] = sum;
                    } else {
                        DP[i][j] = 0;
                    }
                }
            }     
        }
        sum = 0;
        for (int n = 1; n <= length; n++) {
            sum += DP[n][length];
        }
        cout << sum << endl;
        
    }
    return 0;
}