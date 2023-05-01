#include <iostream>
#include <cmath>

using namespace std;
bool flag=false;
int my_hash(string str) {
    int total = 0;
    for (int i = 0; i < str.length(); i++) {
        int j = str.length() - i - 1;
        total += str[i] * (pow(10, j));
    }
    return total;
}

void rabin_karp(string pattern, string str) {
    int pattern_hash = my_hash(pattern);
    for (int i = 0; i < str.length(); i++) {
        int hash_val = my_hash(str.substr(i, pattern.length()));
        if (hash_val == pattern_hash) 
        {
            cout << "String matched at index = " << i << endl;
            flag=true;
            break;
        }
    }
    if(!flag)
        cout<<"Oops! Pattern not found"<<endl;
}

int main() {
    string pattern = "aba";
    string str = "baaaaabc";
    // string str, pattern;
    // cout << "Enter the text: ";
    // cin>>str;
    // cout << "Enter the pattern to search: ";
    // cin>>pattern;
    rabin_karp(pattern, str);
    return 0;
}
