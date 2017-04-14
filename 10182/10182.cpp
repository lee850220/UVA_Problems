#include <iostream>
#define N 100000
#define DIR_NUM 6
using namespace std;

struct Location {
    Location(void) : x(0), y(0) {};
    Location(int a, int b) : x(a), y(b) {};
    int x;
    int y;
};

namespace UVA_10182 {
    const Location init(0, 0);
    int DirX[6] = {0, -1, -1, 0, 1, 1};
    int DirY[6] = {1, 1, 0, -1, -1, 0};
}

void create_table(Location*);
void print_table(Location*);

int main() {
    int temp;
    Location table[N];
    create_table(table);
    
    while(cin >> temp) {
        cout << table[temp - 1].x << " " << table[temp - 1].y << endl;
    }

    
    return 0;
}

void create_table(Location* table) {
    int count = 1, init_stat[6] = {1, 0, 1, 1, 1, 1};
    table[0] = UVA_10182::init;
    while(1) {
        for(int i = 0; i < DIR_NUM; i++) {
            for(int j = 0; j < init_stat[i]; j++) {
                table[count].x = table[count - 1].x + UVA_10182::DirX[i];
                table[count].y = table[count - 1].y + UVA_10182::DirY[i];
                count++;
                if(count > N) break;
            }
            if(count > N) break;
            init_stat[i]++;
        }
        if(count > N) break;
    }
}