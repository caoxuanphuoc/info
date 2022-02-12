#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define pb push_back
#define all(v) v.begin(), v.end()
#define in_array(a) for(auto &c:a)cin>>c
using namespace std;
vector<int> ST={0, 10, 4 ,10, 4, 2, 3, 10};
void update(int id, int l, int r, int i, int v) {
    if (i < l || r < i) {
        // i nằm ngoài đoạn [l, r], ta bỏ qua nút i
        return ;
    }
    if (l == r) {
        // Đoạn chỉ gồm 1 phần tử, không có nút con
        ST[id] = v;
        return ;
    }

    // Gọi đệ quy để xử lý các nút con của nút id
    int mid = (l + r) / 2;
    update(id*2, l, mid, i, v);
    update(id*2 + 1, mid+1, r, i, v);

    // Cập nhật lại giá trị max của đoạn [l, r] theo 2 nút con:
    ST[id] = max(ST[id*2], ST[id*2 + 1]);
}
int get(int id, int l, int r, int u, int v) {
    if (v < l || r < u) {
        // Đoạn [u, v] không giao với đoạn [l, r], ta bỏ qua đoạn này
        return -INFINITY;
    }
    if (u <= l && r <= v) {
        // Đoạn [l, r] nằm hoàn toàn trong đoạn [u, v] mà ta đang truy vấn, ta trả lại
        // thông tin lưu ở nút id
        return ST[id];
    }
    int mid = (l + r) / 2;
    // Gọi đệ quy với các con của nút id
    return max(get(id*2, l, mid, u, v), get(id*2 + 1, mid+1, r, u, v));
}
int main(){
 ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  update(1,2,7,7,15);
// for(auto c: ST)
// 	cout<<c<<" ";
//ST={0, 10, 4 ,10, 4, 2, 3, 10};
cout<<get(1,2,7,5,6);
}













