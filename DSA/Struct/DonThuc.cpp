#include <bits/stdc++.h>
using namespace std;


struct DONTHUC{
	int somu;
	double heso;

	DONTHUC(double _heso = 0,int _somu=0){
		heso = _heso;
		somu  = _somu;
	}

	DONTHUC& operator = (const DONTHUC &rhs){
		if (this == &rhs) return *this;
		this->heso = rhs.heso;
		this->somu = rhs.somu;
		return *this;
	}
};


struct Node{
	DONTHUC* data;
	Node* next;

	Node(DONTHUC* _data = nullptr){
		this->data = _data;
		this->next = nullptr;
	}

};

struct DATHUC{
	Node* head;
	Node* tail;
	DATHUC(){
		this->head = nullptr;
		this->tail = nullptr;
	}
};


void Nhap(DATHUC &P, double heso, int somu){
	// tạo một đơn thức mới với hệ số và số mũ đã cho
	DONTHUC* newDT = new DONTHUC(heso, somu);

	// nếu danh sách rỗng, thêm đơn thức mới vào đầu danh sách và đặt tail bằng head
	if (P.head == nullptr){
		P.head = new Node(newDT);
		P.tail = P.head;
	}
	// nếu danh sách không rỗng, thêm đơn thức mới vào cuối danh sách
	else {
		P.tail->next = new Node(newDT);
		P.tail = P.tail->next;
	}
}

double TinhDaThuc(const DATHUC &P, double x){
	double result = 0.0;

	// duyệt qua từng đơn thức trong danh sách
	for (Node* current = P.head; current != nullptr; current = current->next){
		// tính giá trị của đơn thức và cộng vào kết quả
		result += current->data->heso * pow(x, current->data->somu);
	}

	return result;
}
void Xuat(const DATHUC &P){
    if (P.head == nullptr) {
        cout << "0";
        return;
    }
    Node* current = P.head;
    while (current != nullptr && current->data->heso == 0) {
        current = current->next;
    }
    if (current == nullptr) {
        cout << "0";
        return;
    }
    if (current->data->heso < 0) cout << "-";
    if (abs(current->data->heso) != 1 || current->data->somu == 0)
        cout << abs(current->data->heso);
    if (current->data->somu == 1) cout << "x";
    else if (current->data->somu > 1) cout << "x^" << current->data->somu;
    current = current->next;
    while (current != nullptr) {
        if (current->data->heso == 0) {
            current = current->next;
            continue;
        }
        if (current->data->heso > 0) cout << "+";
        else cout << "-";
        if (abs(current->data->heso) != 1 || current->data->somu == 0)
            cout << abs(current->data->heso);
        if (current->data->somu == 1) cout << "x";
        else if (current->data->somu > 1) cout << "x^" << current->data->somu;
        current = current->next;
    }
}
int main() {
    DATHUC B;
    int N;

    cin >> N;
    for (int test = 0; test < N; test++){
		double heso; int somu;
		cin >> heso >> somu;
		Nhap(B,heso,somu);
    }


    cout << "Da thuc vua nhap la: "; Xuat(B);
    double x; cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << TinhDaThuc(B, x);
    return 0;
}