
type 'a t_stack = 'a list
;;

let empty() : 'a t_stack = []
;;

let push(x, s: 'a * 'a t_stack) : 'a t_stack  = x::s
;;

let top(s : 'a t_stack) : 'a  =
  match s with
  | [] -> invalid_arg "top : stack is empty"
  | x::ss -> x
;;

let pop(s : 'a t_stack) : 'a t_stack =
  match s with
  | [] -> invalid_arg "top : stack is empty"
  | x::ss -> ss
;;

let isEmpty(s : 'a t_stack) : bool =
  s = []
;;

