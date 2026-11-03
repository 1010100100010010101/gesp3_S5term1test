#include <iostream>
#include <string>
using namespace std;
int main() {
    string plain, cipher, text;
    cin >> plain >> cipher >> text;
    int k = (cipher[0] - plain[0] + 26) % 26;
    for (int i = 0; i < (int)text.size(); i++) {
        int x = text[i] - 'A';            // 轉成 0..25
        x = (x - k + 26) % 26;            // 逆向位移
        cout << char('A' + x);
    }
    cout << '\n';
    return 0;
}
