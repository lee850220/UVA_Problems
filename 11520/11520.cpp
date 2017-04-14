#include <iostream>
#include <algorithm>
using namespace std;

char check_table(char** table, int i, int j, int lines) {
    char res = 'A';
    char list[4];
    fill(list, list+4, 126);
    //up
    if(j-1 >= 0) {
        if(table[i][j-1] != '.') list[0] = table[i][j-1];
    }
    //down
    if(j+1 < lines) {
        if(table[i][j+1] != '.') list[1] = table[i][j+1];
    }
    //left
    if(i-1 >= 0) {
        if(table[i-1][j] != '.') list[2] = table[i-1][j];
    }
    //right
    if(i+1 < lines) {
        if(table[i+1][j] != '.') list[3] = table[i+1][j];
    }

    sort(list, list+4);
    for(int i=0; i<4; i++) {
        if(res == list[i]) res++;
        else break;
    }
    return res;
}

int main() {
    int cases, lines, count = 1;
    char** table, ch;
    cin >> cases;
    while(cases--) {
        cin >> lines;
        cin.ignore();
        table = new char*[lines];
        for(int i = 0; i < lines; i++) {
            table[i] = new char[lines];
        }

        for(int i = 0; i < lines; i++) {
            for(int j = 0; j < lines; j++) {
                cin.get(table[i][j]);
            }
            cin.ignore(); 
        }


        for(int i = 0; i < lines; i++) {
            for(int j = 0; j < lines; j++) {
                if(table[i][j] != '.') continue;
                else {
                    table[i][j] = check_table(table, i, j, lines);
                }
            }
        }

        cout << "Case " << count++ << ":\n";
        for(int i = 0; i < lines; i++){
            for(int j = 0; j < lines; j++) {
                cout << table[i][j];
            }
            cout << endl;
        }
        delete [] table;
    }
    return 0;
}