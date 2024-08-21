#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

typedef double (*Func3D)(const double, const double);

Func3D getFunc(const char *name);

#endif // __FUNCTIONS_H__
