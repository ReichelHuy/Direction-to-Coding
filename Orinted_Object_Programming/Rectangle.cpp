#include <bits/stdc++.h>
using namespace std;
class Rectangle
{
   private:
   int width, height; //Declear Elements including width and height


   public:
   Rectangle(); // First constructor;
   Rectangle(int, int); // Second constructor
   Rectangle(int);      // Third constructor
   ~Rectangle(); // Destructor
   int GetWidth(); // Get the width of the rectangle
   int GetHeight(); // Get the height of the rectangle .
   void SetWidth(int); // Set the width of the rectangle
   void SetHeight(int); // Set the height of the rectangle
   void SetWidthHeight(int,int); // Set the width and height of the rectangle
   int CalculateArea(Rectangle); // Calculate the area of the rectangle
   void Push(Rectangle); // Push the rectangle
   void input(); // Input THE rectangle
};

Rectangle::Rectangle(int w)// Third constructor
{
   width = w;
   height = 0;
}

Rectangle::Rectangle(int w, int h) {// First constructor
   width = w;
   height = h;
}

Rectangle::Rectangle() {// Second constructor
   width = 0;
   height = 0;
}

void Rectangle::input()
{
    cout<<" NHAP WIDTH: "<<endl;
    cin>>width;
    cout<<" NHAP HEIGHT: "<<endl;
    cin>>height;
}


// --------------------------------------------------------------------
int Rectangle::GetWidth() //Builds the width of the rectangle       
{
    return width;
}

int Rectangle::GetHeight() //Builds the height of the rectangle
{
    return height;
}

void Rectangle::SetWidth(int width) //Set the width of the rectangle
{
    this->width = width;
}

void Rectangle::SetHeight(int height) //Set the height of the rectangle
{
    this->height = height;
}
// --------------------------------------------------------------------
int CalculateArea(Rectangle r) //Builds the area of the rectangle
{
    return (r.GetWidth() * r.GetHeight());
}

void Rectangle::SetWidthHeight(int width , int height) //Builds the area of the rectangle)
{
    this->width = width;
    this->height = height;
}

void Push(Rectangle r)
{
    cout<< "Width: "<< r.GetWidth()<< "| Height: "<< r.GetHeight()<<" | Area: "<<  CalculateArea(r)<<endl;
}
Rectangle::~Rectangle(){};    //Destroys the rectangle


int main()
{
    Rectangle rect;
    rect.input();
    Push(rect);
    return 0;

}