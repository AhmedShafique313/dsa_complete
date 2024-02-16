#include <iostream>
using namespace std;

class rect
{
    private:
        double lenght;
        double width;
    public:
        double setlength(double);
        double setwidth(double);
        double getlength() const;
        double getwidth() const;
        double getarea() const;
};

double rect::setlength(double len)
{
    lenght = len;
}
double rect::setwidth(double w)
{
    width = w;
}

double rect::getlength() const
{
    return lenght;
}

double rect:: getwidth() const
{
    return width;
}

double rect::getarea() const
{
    return lenght * width;
}
