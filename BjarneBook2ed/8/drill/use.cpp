#include "my.h"

int foo;

int main()
{
    // foo = 7;
    // print_foo();
    // print(99);

    int x = 7;
    int y = 9;
    swap_r (x, y);
    swap_v (7, 9);
    //const int cx = 7;
    //const int cy = 9;
    //swap_v (cx, cy);
    swap_v (7.7, 9.9);
    double dx = 7.7;
    double dy = 9.9;
    swap_v (dx, dy);
    swap_v (7.7, 9.9);
}
