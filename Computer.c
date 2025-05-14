#include "Computer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <errno.h>
#include <unistd.h>
#include<unistd.h>


void Computer(int *dif, int *choixP, int *choixA, int *choixD, Bot *ra, Bot *rb, Bot *rc, Bot *ja, Bot *jb, Bot *jc) {
	int chance=rand()%101;
	int proba, wtf, wtp;  // \(^-^)/
	int aa=4;
	int ab=4;
	int ac=4;
	int x; // attaquant selectionne
	int y=MinMax(&x, ra->stamina, rb->stamina, rc->stamina); // Max stamina
	int z; // joueur vise
	int v=-MinMax(&z, -(ja->pv), -(jb->pv), -(jc->pv)); // Min pv joueur vise
	switch(*dif) {
	case 1:
		proba=100-60;
		ra->utiliunique=1;
		rb->utiliunique=1;
		rc->utiliunique=1;
		break;
	case 2:
		proba=100-40;
		break;
	case 3:
		proba=100-20;
		break;
	default:
		printf("ERREUR: Variable (pointeur) *dif pour le switchcase Computer\n");
		exit(1);
	}
	if(chance>=proba || (ra->stamina==rb->stamina && ra->stamina==rc->stamina)) {
		do {
			*choixP=(rand()%3)+1;
		}
		while(CheckPerso1(*choixP, ra, rb, rc));

		do {
			*choixA=(rand()%3)+1;
		}
		while(CheckStamina(*choixP, *choixA, ra, rb, rc));

		do {
			*choixD=(rand()%3)+1;
		}
		while(CheckPerso2(*choixD, ja, jb, jc));

	} else {                 ///////
		if(ra->pv<=50 && ra->utiliunique!=1) {
			*choixP=1;
			*choixA=2;
			do {
				*choixD=(rand()%3)+1;
			}
			while(CheckPerso2(*choixD, ja, jb, jc));
		} else if(rb->pv<=50 && rb->utiliunique!=1) {
			*choixP=1;
			*choixA=2;
			do {
				*choixD=(rand()%3)+1;
			}
			while(CheckPerso2(*choixD, ja, jb, jc));
		} else if(rc->pv<=50 && rc->utiliunique!=1) {
			*choixP=1;
			*choixA=2;
			do {
				*choixD=(rand()%3)+1;
			}
			while(CheckPerso2(*choixD, ja, jb, jc));
		} else if(ra->pv<=50 && ra->stamina>=8) {
			*choixP=1;
			*choixA=2;
			do {
				*choixD=(rand()%3)+1;
			}
			while(CheckPerso2(*choixD, ja, jb, jc));
		} else if(rb->pv<=50 && rb->stamina>=8) {
			*choixP=1;
			*choixA=2;
			do {
				*choixD=(rand()%3)+1;
			}
			while(CheckPerso2(*choixD, ja, jb, jc));
		} else if(rc->pv<=50 && rc->stamina>=8) {
			*choixP=1;
			*choixA=2;
			do {
				*choixD=(rand()%3)+1;
			}
			while(CheckPerso2(*choixD, ja, jb, jc));
		} else if(z==1) {
			if(ja->pv<ra->normal.damage && ra->stamina>2) {
				aa=1;
			} else if(ja->pv<ra->special.damage && ra->stamina>7) {
				aa=2;
			} else {
				aa=3;
			}
			if(ja->pv<rb->normal.damage && rb->stamina>2) {
				ab=1;
			} else if(ja->pv<rb->special.damage && rb->stamina>7) {
				ab=2;
			} else {
				ab=3;
			}
			if(ja->pv<rc->normal.damage && rc->stamina>2) {
				ac=1;
			} else if(ja->pv<rc->special.damage && rc->stamina>7) {
				ac=2;
			} else {
				ac=3;
			}
			wtf=-MinMax(&wtp, -aa, -ab, -ac);
			if(wtf<3) {
				*choixP=wtp;
				*choixA=wtf;
				*choixD=z;
			} else {
				if(y>8 && x!=0) {
					if(x==1) {
						aa=2;
						ab=0;
						ac=0;
					} else if(x==2) {
						aa=0;
						ab=2;
						ac=0;
					} else {
						aa=0;
						ab=0;
						ac=2;
					}
					if(aa==2 && ab!=2 && ac!=2) {
						*choixP=1;
						*choixA=2;
						*choixD=z;
					} else if(aa!=2 && ab==2 && ac!=2) {
						*choixP=2;
						*choixA=2;
						*choixD=z;
					} else if(aa!=2 && ab!=2 && ac==2) {
						*choixP=3;
						*choixA=2;
						*choixD=z;
					} else if((aa==2 && ab==2) || (aa==2 && ac==2) || (aa==2 && ab==2 && ac==2)) {
						*choixP=1;
						*choixA=2;
						*choixD=z;
					} else {
						*choixP=2;
						*choixA=2;
						*choixD=z;
					}
				} else {
					*choixP=x;
					*choixA=1;
					*choixD=z;
				}
			}
		} else if(z==2) {
			if(jb->pv<ra->normal.damage && ra->stamina>2) {
				aa=1;
			} else if(jb->pv<ra->special.damage && ra->stamina>7) {
				aa=2;
			} else {
				aa=3;
			}
			if(jb->pv<rb->normal.damage && rb->stamina>2) {
				ab=1;
			} else if(jb->pv<rb->special.damage && rb->stamina>7) {
				ab=2;
			} else {
				ab=3;
			}
			if(jb->pv<rc->normal.damage && rc->stamina>2) {
				ac=1;
			} else if(jb->pv<rc->special.damage && rc->stamina>7) {
				ac=2;
			} else {
				ac=3;
			}
			wtf=-MinMax(&wtp, -aa, -ab, -ac);
			if(wtf<3) {
				*choixP=wtp;
				*choixA=wtf;
				*choixD=z;
			} else {
				if(y>8 && x!=0) {
					if(x==1) {
						aa=2;
						ab=0;
						ac=0;
					} else if(x==2) {
						aa=0;
						ab=2;
						ac=0;
					} else {
						aa=0;
						ab=0;
						ac=2;
					}
					if(aa==2 && ab!=2 && ac!=2) {
						*choixP=1;
						*choixA=2;
						*choixD=z;
					} else if(aa!=2 && ab==2 && ac!=2) {
						*choixP=2;
						*choixA=2;
						*choixD=z;
					} else if(aa!=2 && ab!=2 && ac==2) {
						*choixP=3;
						*choixA=2;
						*choixD=z;
					} else if((aa==2 && ab==2) || (aa==2 && ac==2) || (aa==2 && ab==2 && ac==2)) {
						*choixP=1;
						*choixA=2;
						*choixD=z;
					} else {
						*choixP=2;
						*choixA=2;
						*choixD=z;
					}
				} else {
					*choixP=x;
					*choixA=1;
					*choixD=z;
				}
			}
		} else {
			if(jc->pv<ra->normal.damage && ra->stamina>2) {
				aa=1;
			} else if(jc->pv<ra->special.damage && ra->stamina>7) {
				aa=2;
			} else {
				aa=3;
			}
			if(jc->pv<rb->normal.damage && rb->stamina>2) {
				ab=1;
			} else if(jc->pv<rb->special.damage && rb->stamina>7) {
				ab=2;
			} else {
				ab=3;
			}
			if(jc->pv<rc->normal.damage && rc->stamina>2) {
				ac=1;
			} else if(jc->pv<rc->special.damage && rc->stamina>7) {
				ac=2;
			} else {
				ac=3;
			}
			wtf=-MinMax(&wtp, -aa, -ab, -ac);
			if(wtf<3) {
				*choixP=wtp;
				*choixA=wtf;
				*choixD=z;
			} else {
				if(y>8 && x!=0) {
					if(x==1) {
						aa=2;
						ab=0;
						ac=0;
					} else if(x==2) {
						aa=0;
						ab=2;
						ac=0;
					} else {
						aa=0;
						ab=0;
						ac=2;
					}
					if(aa==2 && ab!=2 && ac!=2) {
						*choixP=1;
						*choixA=2;
						*choixD=z;
					} else if(aa!=2 && ab==2 && ac!=2) {
						*choixP=2;
						*choixA=2;
						*choixD=z;
					} else if(aa!=2 && ab!=2 && ac==2) {
						*choixP=3;
						*choixA=2;
						*choixD=z;
					} else if((aa==2 && ab==2) || (aa==2 && ac==2) || (aa==2 && ab==2 && ac==2)) {
						*choixP=1;
						*choixA=2;
						*choixD=z;
					} else {
						*choixP=2;
						*choixA=2;
						*choixD=z;
					}
				} else {
					*choixP=x;
					*choixA=1;
					*choixD=z;
				}
			}
		}
	}
	if(CheckPerso1(*choixP, ra, rb, rc) && CheckStamina(*choixP, *choixA, ra, rb, rc) && CheckPerso2(*choixD, ja, jb, jc)){
		/// un vide monstrueux
	}else{
	    Computer(dif, choixP, choixA, choixD, ra, rb, rc, ja, jb, jc);
	}
}
