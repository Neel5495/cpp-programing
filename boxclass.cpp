#include <iostream>
using namespace std;

class Box
{
private:
    double length, width, height;

public:
    Box()
    {
        length = 1;
        width = 1;
        height = 1;
        cout << "Default constructor called." << endl;
    }

    Box(double l, double w, double h)
    {
        length = l;
        width = w;
        height = h;
        cout << "Parameterized constructor called." << endl;
    }

    Box(const Box &b)
    {
        length = b.length;
        width = b.width;
        height = b.height;
        cout << "Copy constructor called." << endl;
    }

    double volume()
    {
        return length * width * height;
    }

    void display()
    {
        cout << "Length: " << length << endl;
        cout << "Width: " << width << endl;
        cout << "Height: " << height << endl;
        cout << "Volume: " << volume() << endl;
        cout << "-------------------" << endl;
    }

    ~Box()
    {
        cout << "Destructor called." << endl;
    }
};

int main()
{
    Box box1;
    box1.display();

    Box box2(10, 5, 4);
    box2.display();

    Box box3(box2);
    box3.display();

    return 0;
}
