#include <bits/stdc++.h> 
using namespace std;

const int MAX = 100; 

int main() {
    int m, n;       
    int a[MAX][MAX];    

    cin >> m >> n;

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];

    // Các biến lưu tọa độ và tổng lớn nhất
    int maxSum = a[0][0];         
    int final_r1 = 0, final_r2 = 0; // Tọa độ hàng trên và hàng dưới của hcn
    int final_c1 = 0, final_c2 = 0; // Tọa độ cột trái và phải của hcn

    // Duyệt tất cả các cặp hàng r1 và r2 (r1 ≤ r2)
    for (int r1 = 0; r1 < m; ++r1) {
        int temp[MAX] = {0}; // Mảng tạm để lưu tổng của các cột từ hàng r1 đến r2

        for (int r2 = r1; r2 < m; ++r2) {
            // Cộng hàng r2 vào mảng temp (tính tổng các phần tử theo từng cột)
            for (int col = 0; col < n; ++col)
                temp[col] += a[r2][col];

            // Áp dụng Kadane's algorithm trên mảng 1 chiều temp
            int sum = temp[0];         // Tổng lớn nhất tìm được đến thời điểm hiện tại
            int max_here = temp[0];    // Tổng hiện tại đang xét
            int c1 = 0, temp_c1 = 0;   // Tọa độ bắt đầu đoạn con lớn nhất
            int c2 = 0;                // Tọa độ kết thúc đoạn con lớn nhất

            // Duyệt mảng temp để tìm đoạn con có tổng lớn nhất
            for (int i = 1; i < n; ++i) {
                // Nếu tổng hiện tại < 0, khởi động lại đoạn con tại vị trí mới
                if (max_here < 0) {
                    max_here = temp[i];
                    temp_c1 = i;
                } else {
                    max_here += temp[i];  // Cộng thêm phần tử tiếp theo
                }

                // Cập nhật nếu tìm được tổng lớn hơn
                if (max_here > sum) {
                    sum = max_here;
                    c1 = temp_c1;
                    c2 = i;
                }
            }

            // Cập nhật kết quả tổng thể nếu tổng hiện tại lớn hơn tổng tốt nhất trước đó
            if (sum > maxSum) {
                maxSum = sum;
                final_r1 = r1;
                final_r2 = r2;
                final_c1 = c1;
                final_c2 = c2;
            }
        }
    }

    // In ra kết quả: r1 c1 r2 c2 s (chuyển về chỉ số bắt đầu từ 1 theo đề bài)
    cout << final_r1 + 1 << " "   // Hàng bắt đầu
         << final_c1 + 1 << " "   // Cột bắt đầu
         << final_r2 + 1 << " "   // Hàng kết thúc
         << final_c2 + 1 << " "   // Cột kết thúc
         << maxSum << endl;       // Tổng lớn nhất

    return 0; 
}