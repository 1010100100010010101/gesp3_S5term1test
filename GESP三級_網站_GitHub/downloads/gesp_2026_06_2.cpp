#include <iostream>
#include <string>
using namespace std;
int main() {
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if ('A' <= c && c <= 'Z')
            cout << char(c - 'A' + 'a');
        else if ('a' <= c && c <= 'z')
            cout << char(c - 'a' + 'A');
        else
            cout << '*';                  // 題目保證是數字
    }
    cout << '\n';
    return 0;
}
