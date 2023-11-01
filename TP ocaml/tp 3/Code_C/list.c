#include <stdio.h>
#include <stdlib.h>

#include "list.h"

struct list_node
{
  t_a v ;
  t_list tail ;
} ;

t_list l_empty()
{
  return NULL ;
}

t_list cons(t_a x, const t_list l)
{
  t_list result ;

  result = (t_list)malloc(sizeof(struct list_node)) ;
  if (result == NULL){
    fprintf(stderr,"List cons : malloc failed \n") ;
    exit(EXIT_FAILURE) ;
  }
  else {
    result -> v = x ;
    result -> tail = l ;
    
    return result ;
  }
}

t_a hd(const t_list l)
{
  if (l_isEmpty(l)){
    fprintf(stderr,"List hd : list was empty \n") ;
    exit(EXIT_FAILURE) ;
  }
  else {
    return l -> v ;
  }
}

t_list tl(t_list l)
{
  t_list result ;
  
  if (l_isEmpty(l)){
    fprintf(stderr,"List tl : list was empty \n") ;
    exit(EXIT_FAILURE) ;
  }
  else {
    result = l -> tail ;
    
    return result ;
  }  
}

bool l_isEmpty(t_list l)
{
  return (l == NULL) ;
}

void free_list(t_list l)
{
  if (!l_isEmpty(l)) {
    t_list next = tl(l) ;
    
    free(l) ;
    free_list(next) ;
  }
}
