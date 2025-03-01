#include <iostream>
using namespace std;

int ucln(int m, int n) {
    while (n != 0) {
        int tmp = m % n;
        m = n;
        n = tmp;
    }
    return m;
}

int main() {
    int m, n;
    cin >> m >> n;
    cout << ucln(m, n);
    return 0;