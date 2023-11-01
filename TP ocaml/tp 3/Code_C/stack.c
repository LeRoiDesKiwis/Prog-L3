#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

struct stack_node
{
  t_b v ;
  t_stack tail ;
} ;

t_stack s_empty()
{
  return NULL ;
}

t_stack push(t_b v, const t_stack s)
{
  t_stack result ;

  result = (t_stack) malloc(sizeof(struct stack_node)) ;
  if (result == NULL){
    fprintf(stderr,"Stack push : malloc failed \n") ;
    exit(EXIT_FAILURE) ;
  }
  else {
    result -> v = v ;
    result -> tail = s ;
    
    return result ;
  }
}

t_stack pop(t_stack s)
{
  t_stack result ;

  if (s_isEmpty(s)){
    fprintf(stderr,"Stack pop : stack was empty \n") ;
    exit(EXIT_FAILURE) ;
  }
  else {
    result = s -> tail ;

    return result ;
  }  
}

t_b top(const t_stack s)
{
  if (s_isEmpty(s)){
    fprintf(stderr,"Stack top : stack was empty \n") ;
    exit(EXIT_FAILURE) ;
  }
  else {
    return s -> v ;
  }
}

bool s_isEmpty(const t_stack s)
{
  return (s == NULL) ;
}

void free_stack(t_stack s)
{
  if (!s_isEmpty(s)) {
    t_stack next = pop(s) ;
    
    free(s) ;
    free_stack(next) ;
  }
}
