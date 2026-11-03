#include <iostream>
using namespace std;
int main() {
    int n, ans = 0;
    cin >> n;
    for (int x = 1; x <= n; x++) {
        int a[32], len = 0;
        int t = x;                       // 用副本做轉換
        while (t > 0) {
            a[len++] = t % 2;             // 存最低位
            t /= 2;
        }
        bool ok = true;
        for (int l = 0, r = len - 1; l < r; l++, r--) {
            if (a[l] != a[r]) {
                ok = false;
                break;
            }
        }
        if (ok) ans++;
    }
    cout << ans << '\n';
    return 0;
}
