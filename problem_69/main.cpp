#include <iostream>
#include <math.h>
using namespace std;

int mySqrt(int x)
{
    return floor(pow(x, 0.5));
}

int main()
{
    cout << mySqrt(4) << endl;
    cout << mySqrt(8) << endl;
    return 0;
}