#include <iostream>

int main() {
    int *p = new int(5);
    int *p2 = new int(10);
    p = p2;
    p2 = nullptr;
    int *p3;
}
