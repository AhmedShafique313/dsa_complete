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

int main()
{
    rect box;
    double rect_l, rect_W;
    cout<<"Enter the length of rectangle: ";cin>>rect_l;cout<<endl;
    cout<<"ENter the width of rectangle: ";cin>>rect_W;cout<<endl;
    box.setlength(rect_l);
    box.setwidth(rect_W);
    cout<<"/n The dimension of rectabgle like length "<<rect_l<<" meter and "<<"widht "<<rect_W<<" meter gives us area which is "<<box.getarea()<<" meter-square"<<endl;
    return 0;
}