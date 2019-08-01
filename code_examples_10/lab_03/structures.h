#ifndef STRUCTURES_H
#define STRUCTURES_H

struct elm
{
    float num;
    struct elm *p;
};

struct empty
{
    struct elm *num;
    struct empty *p;
};

#endif // STRUCTURES_H
