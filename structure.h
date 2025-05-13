#include "constant.h"

typedef struct { //structure pour creer des attaques
	char *name;
	int damage, focusdamage, heal, focusheal, poison, stun, confused;
} Attack;

typedef struct { //structure principale personnage (Bunny) surnommé 'Bot'
	char *name;
	int agility, pvmax, stamina, poison, stun, confused, pv, dead, utiliunique, chosen;
	float defence;
	Attack normal, special, unique;
} Bot;

