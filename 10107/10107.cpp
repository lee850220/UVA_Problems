#include <iostream>
#include <algorithm>
#include <cstdlib>
#define N 10000
using namespace std;

int main() {
    int temp, i = 1;
    int list[N];

    fill(list, list+N, 0);
    while(cin >> temp) {
        list[i-1] = temp;
        sort(list, list+i);

        if(i & 1)
            cout << list[i/2] << endl;
        else
            cout << (list[i/2] + list[i/2 - 1]) / 2 << endl;
        
        i++;
    }
    return 0;
}