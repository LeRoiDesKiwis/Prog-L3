(** Queue abstract data type for AP3 course @author Laurent Fuchs *)

(** This library implements the usual abstract data type for queues *)

(** type for polymorphic queues *)
type +'a t_queue
;;

(** {7 Constructor functions} *)

(** Empty queue constant *)
val empty : unit -> 'a t_queue
;;

(** Enter a value into a queue *)
val enter : 'a * 'a t_queue -> 'a t_queue
;;

(** {7 Selector functions} *)

(** Head value of a queue
    @raise Invalid_argument when the queue is empty
 *)
val qhd : 'a t_queue -> 'a
;;
(** {b Semantics} 
    - qhd(empty) = Invalid_argument
    - qhd(enter(v, empty())) = v   
    - qhd(enter(v, q)) = qhd(v) if not(isEmpty(q))
 *)

(** Return a queue without the head of the queue given in argument
    @raise Invalid_argument when the queue is empty
 *) 
val qrest : 'a t_queue -> 'a t_queue
;;
(** {b Semantics} 
    - qrest(empty()) = Invalid_argument
    - qrest(enter(v, empty())) = empty()
    - qrest(enter(v, q)) = enter(v, qrest(q)) if not (isEmpty(q))
*)

(** {7 Predicate} *)

val isEmpty : 'a t_queue -> bool
;;
(** {b Semantics} 
    - isEmpty(empty()) = true  
    - isEmpty(enter(v, q)) = false
*)
