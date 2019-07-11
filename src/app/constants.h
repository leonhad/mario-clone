#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <QString>

#define W 20
#define H 14
#define NH 16
#define NV 13

#define NUM_LEV 6
#define LAST_LEV (2 * NUM_LEV - 1)
#define MAX_SAVE 3
#define WAIT_BEFORE_DEMO 500

#define MaxWorldSize 236

#define EX 1
#define EY1 8
#define EY2 3

#define dirLeft 0
#define dirRight 1

#define mdSmall 0
#define mdLarge 1
#define mdFire 2

#define plMario 0
#define plLuigi 1

extern const QString playerName[];
extern const QString configFileName;

#endif // CONSTANTS_H
