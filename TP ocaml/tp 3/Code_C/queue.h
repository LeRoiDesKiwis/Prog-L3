#ifndef __QUEUE
#define __QUEUE

#include "bool.h"

#include "btree.h"

typedef t_btree t_b ;
//typedef int t_b ;

struct queue_node ;

typedef struct queue_node *t_queue ;

t_queue q_empty() ;

t_queue enter(t_b x, const t_queue q) ;

t_b qhd(const t_queue q) ;

t_queue qrest(t_queue q) ;

bool q_isEmpty(const t_queue q) ;

void free_queue(t_queue q) ;

#endif /*__QUEUE */
