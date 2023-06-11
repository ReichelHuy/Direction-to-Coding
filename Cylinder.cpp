#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Lớp cơ sở Cylinder
class Cylinder {
protected:
    int Height; // Chiều cao của hình trụ
    int Radius ; // Bán kính đáy của hình trụ
    const float PI = 3.14; // Hằng số PI
public:
    // Constructor, Destructor
    Cylinder() { Height = 0; Radius = 0; }
    virtual ~Cylinder() {}

    // GetFunction, SetFunction
    int GetHeight() const { return Height; }
    void SetHeight(int Height) { this->Height = Height; }
    void SetRadius(int Radius) { this->Radius = Radius; }
    int GetRadius() const { return Radius; }

    // Command
    float Volume(); // Tính thể tích của hình trụ
    float Area();   // Tính diện tích xung quanh của hình trụ
    float Result(); // Tính giá trị 10% thể tích của hình trụ
};

// Lớp con Box, kế thừa từ lớp Cylinder
class Box : public Cylinder {
protected:
    int Width; // Chiều rộng của hình hộp chữ nhật
    int Length; // Chiều dai của hình hộp chữ nhật
public:
    // Constructor, Destructor
    Box() { Width = 0; Length = 0; }
    ~Box() {}

    // GetFunction, SetFunction
    int GetWidth() const { return Width; }
    void SetWidth(int Width) { this->Width = Width; }
    int GetLength() const { return Length; }
    void SetLength(int Length) { this->Length = Length; }

    // Command
    float Volume(); // Tính thể tích của hình hộp chữ nhật
    float Area();   // Tính diện tích toàn phần của hình hộp chữ nhật
    float Result(); // Tính giá trị 10% thể tích của hình hộp chữ nhật
};

// Lớp con Cube, kế thừa từ lớp Cylinder
class Cube : public Cylinder {
public:
    // Constructor, Destructor
    Cube() {}
    ~Cube() {}

    // Command
    float Volume(); // Tính thể tích của hình lập phương
    float Area();   // Tính diện tích toàn phần của hình lập phương
    float Result(); // Tính giá trị 10% thể tích của hình lập phương
};

// Phương thức tính thể tích của hình trụ
float Cylinder::Volume() {
    return PI * Radius * Radius * Height;
}

// Phương thức tính diện tích xung quanh của hình trụ
float Cylinder::Area() {
    return 2 * PI * Radius * Height;
}

// Phương thức tính giá trị 10% thể tích của hình trụ
float Cylinder::Result() {
    return 0.1 * Volume();
}

// Phương thức tính thể tích của hình hộp chữ nhật
float Box::Volume() {
    return Length * Width * Height;
}

// Phương thức tính diện tích toàn phần của hình hộp chữ nhật
float Box::Area() {
    return 2 * (Length * Width + Width * Height + Height * Length);
}

// Phương thức tính giá trị 10% thể tích của hình hộp chữ nhật
float Box::Result() {
    return 0.1 * Volume();
}

// Phương thức tính thể tích của hình lập phương
float Cube::Volume() {
    return Height * Height * Height;
}

// Phương thức tính diện tích toàn phần của hình lập phương
float Cube::Area() {
    return 6 * Height * Height;
}

// Phương thức tính giá trị 10% thể tích của hình lập phương
float Cube::Result() {
    return 0.1 * Volume();
}

int main() {
    int n;
    float sum1 = 0 , sum2 =0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int type;
        cin >> type;

        switch (type) {
            case 1:
            {
                int Height, Radius;
                cin >> Height;
                cin >> Radius;

            Cylinder* cyl = new Cylinder();
            cyl->SetHeight(Height);
            cyl->SetRadius(Radius);
            sum1+=cyl->Area();
            sum2+=cyl->Result();
                break;
            }
            case 2:
            {
                int Height, Length, Width;
                cin >> Height;
                cin >> Length;
                cin >> Width;

                Box* box = new Box();
                box->SetLength(Length);
                box->SetWidth(Width);
                box->SetHeight(Height);
            sum1+=box->Area();
            sum2+=box->Result();
                break;
            }
            case 3:
            {
                int Height;
                cin >> Height;

                Cube* cube = new Cube();
                cube->SetHeight(Height);
            sum1+=cube->Area();
            sum2+=cube->Result();
                break;
            }
        }
    }
    cout<<"Dien tich chai vo: "<<sum1<<endl;
    cout<<"Luong nuoc tren mat dat: "<<sum2<<endl;
    return 0;
}