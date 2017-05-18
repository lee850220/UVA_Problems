#include <iostream>
#define MAX 13
using namespace std;

int fact[MAX];
int factorial(int);

int main() {
    int power, k, x;
    int res, temp;
    for (int i = 0; i < MAX; i++) {
        fact[i] = 0;
    }
    fact[0] = fact[1] = 1;

    while (cin >> power) {
        res = 0;
        temp = 1;
        cin >> k;
        for (int i = 0; i < k; i++) {
            cin >> x;
            if (x < 2) continue;
            temp *= factorial(x); 
        }
        res = factorial(power) / temp;
        cout << res << endl;
    }
    return 0;
}

int factorial(int x) {
    if (fact[x] == 0) {
        fact[x] = factorial(x - 1) * x;
    }
    return fact[x];
}