#include <iostream>
using namespace std;

int main () {
    int cases, walls, list[50];
    int high, low;

    cin >> cases;
    for (int i = 0; i < cases; i++) {
        high = 0;
        low = 0;
        cin >> walls;
        for (int j = 0; j < walls; j++)
                cin >> list[j];
        if (walls > 1) {  
            for (int j = 1; j < walls; j++) {
                if (list[j] < list[j-1]) low++;
                else if (list[j] > list[j-1]) high++;
            }
        }

        cout << "Case " << i+1 << ": " << high << " " << low << endl;
    }
    return 0;
}