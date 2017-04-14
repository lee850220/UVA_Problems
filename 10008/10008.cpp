#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct Word_count{
    int count;
    char word;
    Word_count(): count(0), word('\0'){}
};

enum Word_type {NWord, LCase, UCase};

void input_string(string*, int n);
void count_num(string*, Word_count*, int);
Word_type check_word(char);
void print_table(Word_count*);

bool greater_sec(const Word_count& A, const Word_count B){
    if(A.count == B.count) {
        return A.word < B.word;
    }else{
        return A.count > B.count;
    }
}

int main(){
    int n;
    string *str = NULL;
    Word_count cnt[26];
    for(int i = 0; i < 26; i++){
        cnt[i].word = 65 + i;
    }

    cin >> n;
    str = new string[n];
    input_string(str, n);
    count_num(str, cnt, n);
    sort(cnt, cnt+26, greater_sec);
    print_table(cnt);
    return 0;
}

void input_string(string* str, int n){ 
    cin.ignore();   
    for(int i = 0; i < n; i++)
        getline(cin, str[i],'\n');  
}

void count_num(string* str, Word_count* cnt, int n){
    char temp;
    for (int i = 0; i < n; i++){
        for(int j = 0; j < str[i].length(); j++){
            temp = str[i][j];
            switch(check_word(temp)){
                case NWord:
                    break;
                case LCase:
                    cnt[temp - 32 - 65].count++;
                    break;
                case UCase:
                    cnt[temp - 65].count++;
                    break;
            }
        }
    }
}

Word_type check_word(char a){
    if(a >= 97 && a <= 122) return LCase;
    else if(a >= 65 && a <= 90) return UCase;
    else return NWord;
}

void print_table(Word_count* cnt){
    for(int i = 0; i < 26; i++){
        if(cnt[i].count == 0) break;
        cout << cnt[i].word << ' ' << cnt[i].count << endl;
    }
}