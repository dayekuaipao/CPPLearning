#include <iomanip>
#include <iostream>
int main(int argc, char **argv)
{
    for (int i = 1; i < argc; i++)
    {
        float x = atof(argv[i]);
        std::cout.setf(std::ios::fixed);
        std::cout << std::setprecision(2) << x << std::endl;
    }
}