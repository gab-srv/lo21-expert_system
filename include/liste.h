#ifndef LISTE_H
#define LISTE_H

typedef struct elem {
	char *value;
	struct elem* next;
} listElement;

typedef listElement* Liste;


#endif