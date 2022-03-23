
#include <iostream>
#include <cmath>
#define MAX_SIZE 256

struct Point {
    int x, y;
    double distance;
};
int main()
{
    int n;
    Point v[MAX_SIZE];
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> v[i].x >> v[i].y;
        v[i].distance = sqrt(v[i].x * v[i].x + v[i].y * v[i].y);
    }

    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (v[i].distance < v[j].distance)
                std::swap(v[i], v[j]);
    printf("(%d,%d)\n(%d,%d)\n(%d,%d)", v[1].x, v[1].y, v[2].x, v[2].y, v[3].x, v[3].y);
}
