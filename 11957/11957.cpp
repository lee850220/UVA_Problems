#include <iostream>
using namespace std;

//以右下為正向[Y][X]
struct Point{
    Point(void) : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
    int x;
    int y;
};

namespace UVA_11957 {   
    const int DIRX[4] = {-1, -1, 1, 1}; //左上、右上、左下、右下
    const int DIRY[4] = {-1, 1, -1, 1};
}

Point create_table(int**, int);
int get_num(int**, int, Point, int);
void calculate(int**, int, const Point);
bool check_side(const Point, int);
void print_table(int**, int);

int main() {
    int cases = 0, length = 0, res = 0;
    int **table = NULL;
    Point start;
    cin >> cases;
    for(int i = 0; i < cases; i++) {
        cin >> length;
        table = new int* [length];
        for(int z = 0; z < length; z++) {
            table[z] = new int [length];
        }

        for(int m = 0; m < length; m++) {
            for(int n = 0; n < length; n++) {
                table[m][n] = 0;
            }
        }

        start = create_table(table, length);
        calculate(table, length, start);
        for(int z = 0; z < length; z++) {
            if(table[0][z] == -1) continue;
            res += table[0][z];
            res %= 1000007;
        }
        cout << "Case " << i + 1 << ": " << res << endl;

        res = 0;
        delete [] table;
    }
    
    return 0;
}

Point create_table(int **table, int length){
    char temp;
    Point start;
    for(int i = 0; i < length; i++) {
        for(int j = 0; j < length; j++) {
            cin >> temp;
            switch(temp) {
                case '.':
                    break;
                case 'B':
                    table[i][j] = -1;
                    break;
                case 'W':
                    table[i][j] = 1;
                    start = Point (i, j);
                    break;
            }
        }
        cin.ignore();
    }
    return start;
}

void calculate(int **table, int length, const Point p) {
    Point new_p;
    for(int i = p.x - 1; i >= 0; i--) {
        for(int j = 0; j < length; j++) {
            if(table[i][j] == -1) continue;
            table[i][j] = get_num(table, length, Point(i + UVA_11957::DIRX[2],j + UVA_11957::DIRY[2]), 2) + 
                          get_num(table, length, Point(i + UVA_11957::DIRX[3],j + UVA_11957::DIRY[3]), 3);
            table[i][j] %= 1000007;
        }
    }
}

int get_num(int **table, int length, Point p, int dir) {
    if(check_side(p, length)) {
        if(table[p.x][p.y] == -1) {
            if(dir != -1)
                return get_num(table, length, Point(p.x + UVA_11957::DIRX[dir], p.y + UVA_11957::DIRY[dir]), -1);
            else
                return 0;
        }
        else return table[p.x][p.y];
    }else{
        return 0;
    }
}

bool check_side(const Point p, int length) {
    if(p.x < 0 || p.x > length - 1) return false;
    else if (p.y < 0 || p.y > length - 1) return false;
    else return true;
}

void print_table(int **table, int length) {
    for(int i = 0; i < length; i++) {
        for(int j = 0; j < length; j++) {
            cout << table[i][j];
        }
        cout << endl;
    }
}