#ifndef STRUCTURES_H
#define STRUCTURES_H

struct elm
{
   int type;
   float numb;
   struct elm *prev;
};

struct adress
{
	struct elm *ad;
	struct adress *prev;
};

#endif // STRUCTURES_H
