let rec create_list(n : int) : int list =
  if n==0
  then [n]
  else n::create_list(n-1);;

let rec create_list_rt_aux(n, l : int * int list) : int list =
  if n == 0
  then l
  else create_list_rt_aux(n-1, n::l);;

;;

let create_list_rn(n : int) : int list = create_list_rt_aux(n, []);;

let create_list_rn_while(n : int) : int list =
  let test((n, _) : (int * int list)) : bool =
    n != 0
  and next((n, l) : (int * int list)) : (int * int list) =
    (n-1, n::l)
  in
  let (_, l) : (int * int list) = whileloop((n, []), test, next) in l
;;

let rec whileloop(r, cont, suiv : 'a * ('a -> bool) * ('a -> 'a)) : 'a = if not(cont(r)) then r else whileloop(suiv(r), cont, suiv);;

let create_list_rt_lg(n : int) : int list =
  let r : (int list) ref = ref []
  and n1 : int ref = ref n in
  while !n1 != 0
  do
    r := !n1::(!r);
    n1 := !n1 - 1;
  done;
  !r;;


let rec longueur(l : int list) : int =
  if l == []
  then 0
  else longueur(List.tl(l))+1;;

(* List.length est sûrement non récursif car longueur(l) produit un stack overflow et pas List.length(l)  *)

