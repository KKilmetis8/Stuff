#include <iostream> 
using namespace std;

class Triangle {
        int vash, ypsos;
    public:
        Triangle (int,int);
        int area() {return vash*ypsos/2 ;};
};

Triangle::Triangle (int a, int b)
{
    vash=a;
    ypsos=b;
}

int main() {
    Triangle trigonos(2,3);
    cout << "area: " << trigonos.area() << endl ;

    Triangle trigonidis(2,42);
    cout << "area: " << trigonidis.area();
    return 0;
}