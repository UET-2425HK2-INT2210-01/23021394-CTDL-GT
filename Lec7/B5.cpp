#include <bits/stdc++.h>       
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Hàm đệ quy sinh hoán vị
void generate(int a[], int l, int r) {
    if (l == r) {                    // Nếu đã cố định hết vị trí
        for (int i = 0; i <= r; i++) // In ra dãy hiện tại
            cout << a[i];
        cout << endl;
    } else {
        for (int i = l; i <= r; i++) {
            swap(a[l], a[i]);              // Đổi chỗ phần tử hiện tại với phần tử ở vị trí l
            generate(a, l + 1, r);         // Gọi đệ quy với phần còn lại
            swap(a[l], a[i]);              // Đổi lại để quay lui
        }
    }
}

int main() {
    int n;
    cin >> n;             
    int a[10];            

    for (int i = 0; i < n; i++) {
        a[i] = i + 1;  
    }
    generate(a, 0, n - 1); // Gọi hàm sinh hoán vị

    return 0;
}