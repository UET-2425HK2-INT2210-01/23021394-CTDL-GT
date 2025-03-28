#include <bits/stdc++.h>

using namespace std;


const int MAXN = 100005;

// Danh sách kề để lưu cây
vector<int> adj[MAXN];
 // Mảng lưu chiều cao của từng nút
int height[MAXN];
// Biến kiểm tra cây nhị phân
 bool isBinary = true;

// Tính chiều cao của cây
 int calcHeight(int node) {
    if (adj[node].empty()) { // Nếu là lá, chiều cao là 0
        height[node] = 0;
        return 0;
    }
     int maxChildHeight = 0;
    for (int child : adj[node]) {
        maxChildHeight = max(maxChildHeight, calcHeight(child));
    }
    height[node] = 1 + maxChildHeight; // Chiều cao của nút = 1 +chiều cao lớn nhất của con
    return height[node];
}

// Duyệt preorder: Gốc => Trái => Phải
void preorder(int node) {
    cout << node << " "; // In nút hiện tại
    for (int child : adj[node]) {
        preorder(child); // Duyệt các con
    }
}

// Duyệt postorder: Trái => Phải => Gốc
void postorder(int node) {
    for (int child : adj[node]) {
        postorder(child); // Duyệt các con
    }
    cout << node << " "; // In nút hiện tại
}

// Duyệt inorder: Trái =>Gốc => Phải (chỉ cho cây nhị phân)
 void inorder(int node) {
    if (adj[node].empty()) { // Nếu là lá, chỉ in nút
        cout << node << " ";
        return;
    }
    if (adj[node].size() >= 1) inorder(adj[node][0]); // Duyệt con trái
    cout << node << " "; // In nút hiện tại
    if (adj[node].size() >= 2) inorder(adj[node][1]); // Duyệt con phải
        }

int main() {
    int N, M;
    cin >> N >> M;

    // Đọc các cạnh và xây dựng cây
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    // Kiểm tra xem cây có phải là cây nhị phân không
    for (int i = 1; i <= N; i++) {
        if (adj[i].size() > 2) { // Nếu một nút có hơn 2 con
            isBinary = false;
            break;
        }
    }

    // Tính chiều cao của cây, bắt đầu từ gốc (nút 1)
    cout << calcHeight(1) << endl;

    // In preorder
    preorder(1);
    cout << endl;

    // In postorder
    postorder(1);
    cout << endl;

    // Kiểm tra cây nhị phân và in inorder nếu đúng
    if (isBinary) {
        inorder(1);
        cout << endl;
    }
    else {
        cout << "NOT BINARY TREE" << endl;
    }

    return 0;
}