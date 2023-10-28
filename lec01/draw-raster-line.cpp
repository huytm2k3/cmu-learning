#include <iostream>
#include <cmath>

int main()
{
    float u1, v1, u2, v2;
    std::cout << "Input coordinates of first endpoint (u1, v1): ";
    std::cin >> u1 >> v1;
    std::cout << "Input coordinates of second endpoint (u2, v2): ";
    std::cin >> u2 >> v2;

    float s = (u2 - u1) / (v2 - v1);
    float v = v1;
    std::cout << "Slope: " << (((u1 < u2) && (v1 < v2)) ? "Upper-right" : "Upper-left") << std::endl;

    for (float u = u1; u <= u2; u++)
    {
        v += s;
        std::cout << "(" << u << "," << round(v) << ")";
    }
    return 0;
}