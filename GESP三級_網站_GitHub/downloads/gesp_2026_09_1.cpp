#include <iostream>
using namespace std;
int main() {
    int n;
    unsigned int common, x;
    cin >> n >> common;                   // 第一個數作初值
    for (int i = 1; i < n; i++) {
        cin >> x;
        common &= x;
    }
    int ans = 0;
    while (common > 0) {
        ans += common & 1u;
        common >>= 1;
    }
    cout << ans << '\n';
    return 0;
}
