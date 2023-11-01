(** Stack abstract data type for AP3 course @author Laurent Fuchs *)

(** This library implements the usual abstract data type for stacks *)

(** type for polymorphic stacks *)
type +'a t_stack
;;

(** {7 Constructor functions} *)

(** Empty stack constant *)
val empty : unit -> 'a t_stack
;;

(** Push a value into a stack *)
val push : 'a * 'a t_stack -> 'a t_stack
;;
(** {7 Selector functions} *)

(** Top value of a stack
    @raise Invalid_argument when the stack is empty
 *)
val top : 'a t_stack -> 'a
;;
(** {b Semantics} 
    - top(empty()) = Invalid_argument  
    - top(push(v, q)) = v
*)

(** Pop the top value of a stack
    @raise Invalid_argument when the stack is empty
 *)
val pop : 'a t_stack -> 'a t_stack
;;
(** {b Semantics} 
    - pop(empty()) = Invalid_argument  
    - pop(push(v, q)) = q
*)

(** {7 Predicate} *)

val isEmpty : 'a t_stack -> bool
;;
(** {b Semantics} 
    - isEmpty(empty()) = true  
    - isEmpty(push(v, q)) = false
*)

