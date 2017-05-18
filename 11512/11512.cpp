#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#define MAX_STR 1001
using namespace std;

string SEQ;
int SA[MAX_STR], LCPA[MAX_STR] = {0};

int compareSA(const void* i, const void* j) {
    return strcmp(SEQ.c_str() + *(int*)i, SEQ.c_str() + *(int*)j);
}

int LCP_length(char* a, char* b){
    int n = 0;
    while (a[n] && b[n] && a[n] == b[n]) n++;
    return n;
}

int main () {
    int n;
    scanf("%d\n", &n);
    while (n--) {
        getline(cin, SEQ, '\n');
        int length = SEQ.length();
//        cout << SEQ << endl;
        for (int i = 0; i < length; i++) {
            SA[i] = i;
        }
        qsort(SA, length, sizeof(int), compareSA);

        for (int i = 1; i < length; i++)
            LCPA[i] = LCP_length(&SEQ[SA[i]], &SEQ[SA[i-1]]);
        
        int max = 0;
        for (int i = 1; i < length; i++) {
            if (LCPA[i] > LCPA[max])
                max = i;
        }
/*    
        for (int i = 0; i < length; i++) {
            cout << SA[i] << " " << LCPA[i] << " " << i << " ";
            for (int j = SA[i]; j < length; j++)
                cout << SEQ[j];
            cout << endl;
        }
*/
        string lcs = string(SEQ, SA[max-1], LCPA[max]);
        int lcs_length = lcs.length();
        int count = 0;
        if(lcs_length != 0) {
            for (int i = 0, fin = length - lcs_length; i <= fin; i++) {
                if (SEQ[i] != lcs[0]) continue;
                if (SEQ.compare(i, lcs_length, lcs) == 0)
                    count++;
            }
        }
        if (count == 1 || lcs_length == 0) 
            cout << "No repetitions found!\n";
        else
            cout << lcs << " " << count << endl;
/*     
        for (int i = SA[max-1]; i < length; i++) {
            cout << SEQ[i];
        }
        cout << " " << endl;
*/   
    }
    return 0;
}