#include <iostream>
#include <cmath>

using namespace std;

// Define M_PI if it's not already defined
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class PointType {
private:
    double x;
    double y;

public:
    // Constructors
    PointType() : x(0.0), y(0.0) {}
    PointType(double xVal, double yVal) : x(xVal), y(yVal) {}

    // Getters and Setters
    double getX() const { return x; }
    double getY() const { return y; }

    void setX(double xVal) { x = xVal; }
    void setY(double yVal) { y = yVal; }

    // Print point
    void print() const {
        cout << "(" << x << ", " << y << ")";
    }
};

class CircleType {
protected:
    PointType center;
    PointType circumferencePoint;

public:
    // Constructors
    CircleType() : center(PointType()), circumferencePoint(PointType()) {}
    CircleType(const PointType& c, const PointType& cp) : center(c), circumferencePoint(cp) {}

    // Getters and Setters
    PointType getCenter() const { return center; }
    PointType getCircumferencePoint() const { return circumferencePoint; }

    void setCenter(const PointType& c) { center = c; }
    void setCircumferencePoint(const PointType& cp) { circumferencePoint = cp; }

    // Calculate the radius
    double calculateRadius() const {
        double xDiff = circumferencePoint.getX() - center.getX();
        double yDiff = circumferencePoint.getY() - center.getY();
        return sqrt(xDiff * xDiff + yDiff * yDiff);
    }

    // Calculate the circumference
    double calculateCircumference() const {
        double radius = calculateRadius();
        return 2 * M_PI * radius;
    }

    // Calculate the area
    double calculateArea() const {
        double radius = calculateRadius();
        return M_PI * radius * radius;
    }

    // Print Circle Information
    void printCircleInfo() const {
        double radius = calculateRadius();
        double circumference = calculateCircumference();
        double area = calculateArea();

        cout << "Base Circle Info:" << endl;
        cout << "Radius: " << radius << endl;
        cout << "Circumference: " << circumference << endl;
        cout << "Area: " << area << endl;
    }
};

class CylinderType : public CircleType {
private:
    double height;

public:
    // Constructors
    CylinderType() : CircleType(), height(0.0) {}
    CylinderType(const PointType& c, const PointType& cp, double h)
        : CircleType(c, cp), height(h) {}

    // Set the height
    void setHeight(double h) {
        height = h;
    }

    // Calculate the volume of the cylinder
    double calculateVolume() const {
        double baseArea = calculateArea();
        return baseArea * height;
    }

    // Calculate the surface area of the cylinder
    double calculateSurfaceArea() const {
        double radius = calculateRadius();
        double baseArea = calculateArea();
        double lateralSurfaceArea = 2 * M_PI * radius * height;
        return (2 * baseArea) + lateralSurfaceArea;
    }

    // Print Cylinder Information
    void printCylinderInfo() const {
        // Print base circle information
        printCircleInfo();
        // Print cylinder-specific information
        cout << "Cylinder Info:" << endl;
        cout << "Height: " << height << endl;
        cout << "Surface Area: " << calculateSurfaceArea() << endl;
        cout << "Volume: " << calculateVolume() << endl;
    }
};

int main() {
    // Create a cylinder with base center at (0, 0), a point on the circumference at (1, 0), and height 5
    PointType center(0, 0);
    PointType circumferencePoint(1, 0);
    CylinderType cylinder(center, circumferencePoint, 5);

    // Print the cylinder's properties
    cylinder.printCylinderInfo();

    return 0;
}
