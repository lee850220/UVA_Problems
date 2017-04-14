#include <iostream>
#include <cmath>
#define MAXINT 4294967295
using namespace std;

unsigned int reverse (unsigned int);
void calculate(unsigned int);

int main() {
    int cases = 0;
    unsigned int num = 0;

    cin >> cases;
    while(cases--) {
        cin >> num;
        cin.ignore();
        calculate(num);
    }

    return 0;
}

void calculate(unsigned int num) {
    int adds = 0, rev;

    while(adds <= 1000) {
        if(num > MAXINT) break;
        rev = reverse(num);
        if(num == rev) break;
        
        num += rev;
        adds++;
    }

    cout << adds << " " << num << endl;
}

unsigned int reverse(unsigned int num) {
    int res = 0, i = 0;
    while(num != 0) {
        res *= 10;
        res += num % 10;
        num /= 10;
    }
    return res;
}