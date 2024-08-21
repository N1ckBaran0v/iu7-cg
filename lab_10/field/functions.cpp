#include <cstring>
#include <cmath>

#include "functions.h"

double flat(const double x, const double z);
double sin(const double x, const double z);
double x2z2(const double x, const double z);

Func3D getFunc(const char *name) {
    if (strcmp(name, "flat") == 0) {
        return flat;
    }
    if (strcmp(name, "sin") == 0) {
        return sin;
    }
    if (strcmp(name, "x2z2") == 0) {
        return x2z2;
    }
    return nullptr;
}

double flat(const double x, const double z) {
    return 0;
}

double sin(const double x, const double z) {
    return sin(x);
}

double x2z2(const double x, const double z) {
    return x * x + z * z;
}
