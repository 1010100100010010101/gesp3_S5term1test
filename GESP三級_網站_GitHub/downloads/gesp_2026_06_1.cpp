#include <iostream>
using namespace std;
int a[20005], key[10];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int d = 0; d < 10; d++) cin >> key[d];
    for (int i = 0; i < n; i++) {
        if (i > 0) cout << ' ';
        cout << key[a[i]];                // 以原數字查表
    }
    cout << '\n';
    return 0;
}
