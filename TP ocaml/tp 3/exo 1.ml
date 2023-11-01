let rec to_list_prefix(t : 'a t_btree) : 'a list =
  if bt_isempty(t) then []
  else [bt_root(t)]@to_list_prefix(bt_subleft(t))@to_list_prefix(bt_subright(t))
;;

let rec to_list_infix(t : 'a t_btree) : 'a list =
  if bt_isempty(t) then []
  else to_list_infix(bt_subleft(t))@[bt_root(t)]@to_list_infix(bt_subright(t))
;;

let rec to_list_postfix(t : 'a t_btree) : 'a list =
  if bt_isempty(t) then []
  else to_list_prefix(bt_subleft(t))@to_list_prefix(bt_subright(t))@[bt_root(t)]
