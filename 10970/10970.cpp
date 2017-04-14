#include <iostream>

using namespace std;

int main(){
    int m, n;
    int split;

    while(cin >> m){
        cin >> n;
        split = m * n - 1;
        cout << split << endl;
    }
    return 0;
}