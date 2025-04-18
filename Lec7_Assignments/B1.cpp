#include <bits/stdc++.h> 
using namespace std;

// Hàm sắp xếp mảng các số thực theo thứ tự tăng dần
void sort(float a[], int n) {
    for (int i = 0; i < n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            // Nếu phần tử đứng trước lớn hơn phần tử sau => hoán đổi vị trí
            if (a[i] > a[j]) {
                float temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
}

int main() {
    float a[1000];  // Mảng lưu các số thực 
    int n = 0;      // Biến đếm số lượng phần tử đọc được

    // Nhập dữ liệu từ bàn phím thay cho đọc file
    // Nhập kết thúc khi gặp ký hiệu kết thúc file
    while (cin >> a[n]) {
        n++; 
    }

    sort(a, n);

    for (int i = 0; i < n; ++i) {
        cout << a[i];             
        if (i < n - 1) cout << " "; // Thêm dấu cách giữa các số (trừ số cuối)
    }
    return 0; 
}