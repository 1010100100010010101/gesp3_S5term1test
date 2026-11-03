#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    int n = (int)s.size(), start = 0;
    for (int k = 1; ; k++) {
        int run = 0, cut = -1;
        for (int i = start; i < n; i++) {
            if (s[i] == ' ') run++;
            else run = 0;
            if (run == k) {
                cut = i - k + 1;          // 分隔空格的起點
                break;
            }
        }
        if (cut == -1) {
            cout << s.substr(start) << '\n';
            break;
        }
        cout << s.substr(start, cut - start) << '\n';
        start = cut + k;                  // 只消耗 k 個空格
    }
    return 0;
}
