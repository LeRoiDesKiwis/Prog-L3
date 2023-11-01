#ifndef __LIST
#define __LIST

#include "bool.h"

#include "btree.h"

// typedef t_btree t_a ;
typedef int t_a ;

struct list_node ;

typedef struct list_node *t_list ;

t_list l_empty() ;

t_list cons(t_a x, const t_list l) ;

t_a hd(const t_list l) ;

t_list tl(t_list l) ;

bool l_isEmpty(t_list l) ;

void free_list(t_list l) ;

#endif /*__LIST */
