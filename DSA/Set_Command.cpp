/*
Thư viện set và multiset trong C++ cung cấp các hàm và phương thức hữu ích như:
insert(x): chèn phần tử x vào set/multiset. Nếu phần tử x đã có trong tập hợp thì không thêm vào nữa.
count(x): đếm số lần xuất hiện của phần tử x trong set/multiset.
erase(x): xóa phần tử x khỏi set/multiset.
size(): trả về số phần tử hiện có trong set/multiset.
empty(): trả về true nếu set/multiset rỗng, false nếu không.
begin(): trả về iterator tới phần tử đầu tiên của set/multiset.
end(): trả về iterator tới phần tử cuối cùng của set/multiset.
rbegin(): trả về iterator tới phần tử cuối cùng của set/multiset.
rend(): trả về iterator tới phần tử đầu tiên của set/multiset.
find(x): tìm phần tử x trong set/multiset. Nếu không tìm thấy thì trả về end().
lower_bound(x): trả về iterator tới phần tử đầu tiên trong set/multiset có giá trị không nhỏ hơn x.
upper_bound(x): trả về iterator tới phần tử đầu tiên trong set/multiset có giá trị lớn hơn x.
equal_range(x): trả về một cặp iterator, cặp đầu tiên trỏ đến phần tử đầu tiên trong set/multiset có giá trị không nhỏ hơn x, cặp thứ hai trỏ đến phần tử đầu tiên trong set/multiset có giá trị lớn hơn x.
set<int> s = {1, 2, 3};
for(int x : s) {
    cout << x << ' ';
}
set<int> s = {1, 2, 3};
for(set<int>::iterator it = s.begin(); it != s.end(); it++) {
    cout << *it << ' ';
}
*/