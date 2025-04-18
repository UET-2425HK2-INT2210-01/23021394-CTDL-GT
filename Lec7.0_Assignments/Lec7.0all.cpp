#include <bits/stdc++.h>
using namespace std;

// Tính t?ng các s? t? 1 ð?n n
int tinhTong(int n) {
    if (n == 1) return 1;
    return n + tinhTong(n - 1);
}

// Tính giai th?a c?a n (n!)
unsigned long long tinhGiaiThua(int n) {
    if (n == 0 || n == 1) return 1;
    return n * tinhGiaiThua(n - 1);
}

// Tính s? Fibonacci th? n
int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Tính l?y th?a x^n
unsigned long long tinhLuyThua(int coSo, int soMu) {
    if (soMu == 0) return 1;
    return coSo * tinhLuyThua(coSo, soMu - 1);
}

// Ð?m s? ch? s? c?a s? nguyên dýõng n
int demSoChuSo(int n) {
    if (n < 10) return 1;
    return 1 + demSoChuSo(n / 10);
}

// Tính t?ng các ch? s? c?a s? nguyên dýõng n
int tongCacChuSo(int n) {
    if (n < 10) return n;
    return (n % 10) + tongCacChuSo(n / 10);
}

// Ð?o ngý?c s? nguyên dýõng n
int daoNguocSo(int n, int soDao = 0) {
    if (n == 0)
        return soDao;
    return daoNguocSo(n / 10, soDao * 10 + n % 10);
}
// int main() {
// int n;
// cin >> n;               
// cout << "yeu cau de bai";
// return 0;
// }     

