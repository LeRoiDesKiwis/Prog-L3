(** Definition du type *)
type 'a t_btree = BT_EMPTY | BT_TREE of ('a * 'a t_btree * 'a t_btree)
;;
(** Un arbre est soit vide, soit contient un noeuf et deux sous arbres *)

(** bt_empty *)
let bt_empty() : 'a t_btree = BT_EMPTY
;;

(** bt_rooting *)
let bt_rooting(root, tl, tr : 'a * 'a t_btree * 'a t_btree) : 'a t_btree =
  BT_TREE(root, tl, tr)
;;

let bt_isempty(myAb : 'a t_btree) : bool = 
  match myAb with
  | BT_EMPTY -> true
  | _ -> false
;;

let bt_root(myAb : 'a t_btree) : 'a =
  match myAb with
  | BT_EMPTY -> failwith "bt_root error : tree is empty"
  | BT_TREE(root, _, _) -> root
;;

let bt_subleft(myAb : 'a t_btree) : 'a t_btree =
  match myAb with
  | BT_EMPTY -> failwith "bt_subleft error : tree is empty"
  | BT_TREE(_, subleft, _) -> subleft
;;

let bt_subright(myAb : 'a t_btree) : 'a t_btree =
  match myAb with
  | BT_EMPTY -> failwith "bt_subright error : tree is empty"
  | BT_TREE(_, _, subright) -> subright
;;