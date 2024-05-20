#include <iostream>
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

// Абстрактний базовий клас
class Shape {
public:
    virtual ~Shape() {}

    // Віртуальні функції для обчислення площі та периметру
    virtual double area() const = 0;
    virtual double perimeter() const = 0;

    // Метод для виводу інформації про фігуру
    virtual void print() const = 0;
};

class Circle : public Shape {
public:
    Circle(double radius) : radius(radius) {}

    double area() const override {
        return M_PI * radius * radius;
    }

    double perimeter() const override {
        return 2 * M_PI * radius;
    }

    void print() const override {
        std::cout << "Круг, в якому радіус: " << radius << "см" << std::endl;
        std::cout << "площа: " << area() << "см" << std::endl;
        std::cout << "Периметр: " << perimeter() << "см" << std::endl;
    }

private:
    double radius;
};


class Square : public Shape {
public:
    Square(double side) : side(side) {}

    double area() const override {
        return side * side;
    }

    double perimeter() const override {
        return 4 * side;
    }

    void print() const override {
        std::cout << "Квадрат, в якого 1 сторона: " << side << "см" << std::endl;
        std::cout << "Площа: " << area() << "см" << std::endl;
        std::cout << "Периметр: " << perimeter() << "см" << std::endl;
    }

    double getSide() const {
        return side;
    }

private:
    double side;
};

class InscribedCircle : public Circle {
public:
    InscribedCircle(const Square& square)
        : Circle(square.getSide() / 2), square(square) {}

    void print() const override {
        std::cout << "Вписане коло в квадраті, в якого 1 сторона: " << square.getSide()  << "см" << std::endl;
        std::cout << "Радіус: " << getRadius() << "см" << std::endl;
        std::cout << "Площа: " << area() << "см" << std::endl;
        std::cout << "Периметр: " << perimeter() << "см" << std::endl;
    }

    double getRadius() const {
        return square.getSide() / 2;
    }

private:
    Square square;
};

int main() {

    setlocale(LC_CTYPE, "uk_UA");

    Circle circle(5.0);
    Square square(4.0);
    InscribedCircle inscribedCircle(square);

    Shape* shapes[] = { &circle, &square, &inscribedCircle };

    for (Shape* shape : shapes) {
        shape->print();
        std::cout << std::endl;
    }

    return 0;
}