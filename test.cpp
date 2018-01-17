#include <iostream>
#include <string>
#include <cstring>
#include "stdarg.h"
#include <vector>
#include <iterator>
#include <algorithm>
#include "stdlib.h"
using namespace std;

// Classes
class CPoint {
    int x , y;
    string name;
    public:
    static int nPoints;
        CPoint() {
            this->x = 0;
            this->y = 0;
            this->name = "none";
            nPoints++;
        };
        CPoint( int x , int y , string name ) {
            this->x  = x;
            this->y  = y;
            this->name = name;
            nPoints++;
        };
        CPoint( int x , int y  ) {
            this->x = x;
            this->y = y;
            nPoints++;
        };
        ~CPoint() {
            cout << this->name << " Point is Destructed" << endl;
        }
        void copy(CPoint p) {
            this->x = p.x;
            this->y = p.y;
        };
        void setX(int x);
        void setY(int y);
        void setName(string name);
        void getPoint();
        int coordinatesAddition();
        CPoint operator=(CPoint & p);
        CPoint operator+(CPoint & p);
        CPoint operator+(double x);
        CPoint operator-(CPoint & p);
        CPoint operator-();
};

CPoint CPoint::operator=(CPoint & p) {
    copy(p);
    return *this;
}

CPoint CPoint::operator+(CPoint & p) {
    CPoint x;
    x.setX(this->x + p.x);
    x.setY(this->y + p.y);
    return x;
}

CPoint CPoint::operator+(double number) {
    CPoint x;
    x.setX(this->x + number);
    x.setY(this->y + number);
    return x;
}

CPoint CPoint::operator-(CPoint & p) {
    CPoint x;
    x.setX(this->x - p.x);
    x.setY(this->y - p.y);
    return x;
}

CPoint CPoint::operator-() {
    CPoint temp;
    temp.x = -this->x;
    temp.y = -this->y;
    return temp;
}


// Declaration of the Functions
void CPoint::setX(int x) {
    this->x = x;
}
void CPoint::setY(int y) {
    this->y = y;
}
void CPoint::getPoint() {
    cout << "Point " << this->name <<  "(" << this->x << "," << this->y <<  ") " << endl;  
}

int CPoint::coordinatesAddition() {
    return this->x + this->y;
}

void CPoint::setName(string name) {
    this->name = name;
}


// Inheritance & Polymorphism
class Shape {

    public:
        int width , height;
        void setValues(int width,int height) {
            this->width = width;
            this->height = height;
        }
        virtual float area() {
            return 0;
        }; 
        ~Shape() {
            cout << "Shape is Destructed" << endl;
        }
        // virtual float area() = 0 // Means No Implementation ==> This is an Abstract Class

};

class Rect:public Shape {

public:
    float area() {

        return this->width * this->height;
    }
    ~Rect() {
        cout << "Rect is Destructed" << endl;
    }


};

class Tri:public Shape {
public:

    float area() {
        return this->width * this->height * 0.5;
    }
    ~Tri() {
        cout << "Tri is Destructed" << endl;
    }

};





// Template Class
template<class T, class R>
R division(T x , T y) {
    return x / y;
}













    int CPoint::nPoints = 0;

int main() {

    CPoint x;
    x.getPoint();
    x.setX(5);
    x.setY(6);
    x.setName("X");
    x.getPoint();

    CPoint y(10 , 14 , "Y");
    y.getPoint();
    
    int result = x.coordinatesAddition();
    cout << "Co-ordinates Additions :: " << result << endl;

    CPoint z = x + y;
    z.setName("Z");
    z.getPoint();

    CPoint d = -x;
    d.getPoint();

    CPoint f = x + 4 + y;
    f.setName("F");
    f.getPoint();
    cout << "Number of Points Created " << CPoint::nPoints << endl;

    // Rect , Tri , Shape -> Test of Inheritance
    Rect a;
    a.setValues(5,3);
    cout << "Area : " << a.area() << endl;

    Tri b;
    b.setValues(2 , 5);
    cout << "Area : " << b.area() << endl;

    // Polymorphism & Abstract Class & Virtual Functions

    Shape *s =&a;
    Shape *s2 = &b;
    s->setValues(12,14);
    s2->setValues(5,10);
    
    cout << "Area From Shape ( Rect ): " << s->area()  << endl;
    cout << "Area From Shape ( Tri ): " << s2->area() << endl;


    // Templates
    cout << division<float , int>(5,3) << endl;
    cout << division<float , float>(5,3)<<endl;



    return 0;
}