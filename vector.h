#ifndef __TYPES_H__
#define __TYPES_H__

typedef double vector3[3];
#define FILL_VECTOR(vector,a,b,c) {vector[0]=a;vector[1]=b;vector[2]=c;}
extern vector3 *hVel, *dVel;
extern vector3 *hPos, *dPos;
extern double *mass, *dMass;
extern vector3 *dAccels;

#endif
