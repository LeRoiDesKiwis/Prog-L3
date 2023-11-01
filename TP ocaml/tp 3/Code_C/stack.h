#ifndef __STACK
#define __STACK

#include "bool.h"

#include "btree.h"


typedef t_btree t_b ;
//typedef int t_b ;

struct stack_node ;

typedef struct stack_node *t_stack ;

t_stack s_empty() ;

t_stack push(t_b x, const t_stack s) ;

t_stack pop(t_stack s) ;

t_b top(const t_stack s) ;

bool s_isEmpty(const t_stack s) ;

void free_stack(t_stack s) ;

#endif /*__STACK */
