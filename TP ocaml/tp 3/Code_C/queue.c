
/*
  Implantation des files selon la même structure de données qu'en OCaml
 */

#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

#include "stack.h"


/* On utilise deux piles */
struct queue_node
{
  t_stack front ;
  t_stack end ;
} ;

t_queue q_empty()
{
  t_queue result ;
  
  result = (t_queue) malloc(sizeof(struct queue_node)) ;
  if (result == NULL){
    fprintf(stderr,"Queue empty : malloc failed \n") ;
    exit(EXIT_FAILURE) ;
  }
  else {
    result -> front = s_empty() ;
    result -> end   = s_empty() ;
    
    return result ;
  }
}

t_queue enter(t_b x, const t_queue q)
{
  if (s_isEmpty(q->front)){
    q -> front = push(x, q->front) ;
  }
  else {
    q -> end = push(x, q->end) ;
  }
  
  return q ;
}

t_b qhd(const t_queue q)
{
  t_b result ;
  
  if (q_isEmpty(q)){
    fprintf(stderr,"Queue qhd : queue was empty \n") ;
    exit(EXIT_FAILURE) ;
  }
  else {
    result = top(q->front) ;
    return result ;
  }
}

/* fonction qui renverse une pile */
t_stack rev(t_stack s){
  t_stack result ;
  
  result = s_empty() ;
  
  while (!(s_isEmpty(s))) {
    result = push(top(s), result) ;
    s = pop(s) ;
  } ;
  
  return result ; 
}

t_queue qrest(t_queue q)
{
  t_stack front_rest ;
  
  if (q_isEmpty(q)){
    fprintf(stderr,"Queue qrest : queue was empty \n") ;
    exit(EXIT_FAILURE) ;
  }
  else {
    front_rest = pop(q->front) ;
    
    if (s_isEmpty(front_rest)){
      q -> front = rev(q->end) ;
      q -> end   = s_empty() ;
    }
    else {
      q -> front = front_rest ;
    }
    
    return q ;
  }
}

bool q_isEmpty(const t_queue q){
  
  return ((s_isEmpty(q->front)) && (s_isEmpty(q->end))) ;
}

void free_queue(t_queue q)
{
  free_stack(q->front) ;
  free_stack(q->end) ;
  
  free(q) ;
}
