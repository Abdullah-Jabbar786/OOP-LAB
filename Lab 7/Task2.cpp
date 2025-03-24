#include <iostream>
#include <cmath>
using namespace std;


class Shape 
{
protected:
    double positionX, positionY;
    string color;
    double borderThickness;

public:

    Shape(double x, double y, string c, double bt = 0) : positionX(x), positionY(y), color(c), borderThickness(bt){}

    virtual ~Shape(){}


    virtual void draw() const 
    {
        cout << "Drawing a shape at (" << positionX << ", " << positionY << ") with color " << color << " and border thickness " << borderThickness << endl;
    }

    virtual double calculateArea() const = 0;
    virtual double calculatePerimeter() const = 0;

};


class Circle : public Shape 
{
private:
    double radius;

public:

    Circle(double x, double y, string c, double r, double bt = 0) : Shape(x, y, c, bt), radius(r){}


    void draw() const override
    {
        cout << "Drawing a circle at (" << positionX << ", " << positionY << ") with radius " << radius << ", color " << color << ", and border thickness " << borderThickness << endl;
    }


    double calculateArea() const override 
    {
        return M_PI * radius * radius;
    }


    double calculatePerimeter() const override 
    {
        return 2 * M_PI * radius;
    }
};


class Rectangle : public Shape 
{

private:
    double width, height;

public:
    Rectangle(double x, double y, string c, double w, double h, double bt = 0) : Shape(x, y, c, bt), width(w), height(h) {}
    
    void draw() const override 
    {
        cout << "Drawing a rectangle at (" << positionX << ", " << positionY << ") with width " << width << ", height " << height << ", color " << color << ", and border thickness " << borderThickness << endl;
    }

    double calculateArea() const override 
    {
        return width * height;
    }

    double calculatePerimeter() const override 
    {
        return 2 * (width + height);
    }

};

class Triangle : public Shape 
{
private:
    double side1, side2, side3;

public:

    Triangle(double x, double y, string c, double s1, double s2, double s3, double bt = 0) : Shape(x, y, c, bt), side1(s1), side2(s2), side3(s3){}

    void draw() const override 
    {
        cout << "Drawing a triangle at (" << positionX << ", " << positionY << ") with sides " << side1 << ", " << side2 << ", " << side3 << ", color " << color << ", and border thickness " << borderThickness << endl;
    }

    double calculateArea() const override 
    {
        double s = (side1 + side2 + side3) / 2.0;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    double calculatePerimeter() const override 
    {
        return side1 + side2 + side3;
    }
};


class Polygon : public Shape 
{
private:

    int numSides;

    double sideLength;


public:

    Polygon(double x, double y, string c, int ns, double sl, double bt = 0) : Shape(x, y, c, bt), numSides(ns), sideLength(sl) {}

    void draw() const override 
    {
        cout << "Drawing a polygon at (" << positionX << ", " << positionY << ") with " << numSides << " sides of length " << sideLength << ", color " << color << ", and border thickness " << borderThickness << endl;
    }

    double calculateArea() const override 
    {
        return (numSides * sideLength * sideLength)/(4 * tan(M_PI / numSides));
    }

    double calculatePerimeter() const override 
    {
        return numSides * sideLength;
    }
};


int main() 
{

    Circle circle(10, 10, "red", 5, 2);
    Rectangle rectangle(20, 20, "blue", 10, 5, 1);
    Triangle triangle(30, 30, "green", 3, 4, 5, 0.5);
    Polygon polygon(40, 40, "yellow", 6, 8, 3);

    circle.draw();
    cout << "Area: " << circle.calculateArea() << ", Perimeter: " << circle.calculatePerimeter() << endl;

    rectangle.draw();
    cout << "Area: " << rectangle.calculateArea() << ", Perimeter: " << rectangle.calculatePerimeter() << endl;


    triangle.draw();
    cout << "Area: " << triangle.calculateArea() << ", Perimeter: " << triangle.calculatePerimeter() << endl;

    polygon.draw();
    cout << "Area: " << polygon.calculateArea() << ", Perimeter: " << polygon.calculatePerimeter() << endl;

    return 0;
}
