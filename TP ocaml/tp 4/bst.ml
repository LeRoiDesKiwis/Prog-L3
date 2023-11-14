let rec bst_seek(t, v : int t_btree * int) : t_btree =
  (
    if bt_isempty(t)
       then false
    else if bt_root(t) == v
    then true
    else if bt_root(t) > v
    then bst_seek(bt_subleft(t), v)
    else if bt_root(t) < v
    then bst_seek(bt_subright(t), v)
    else false
  )

let rec bst_linsert(t, v : int t_btree * int) : int t_btree =
  (
    if bt_isempty(t)
    then bt_rooting(v, bt_empty(), bt_empty())
    else if bt_root(t) > v
    then
      (
        let left : int t_btree = bt_subleft(t) in
        bt_rooting(bt_root(t), bst_linsert(left, v), bt_subright(t))
      )
    else if bt_root(t) < v
    then
      (
        let right : int t_btree = bt_subright(t) in
        bt_rooting(bt_root(t), bst_linsert(right, v), bt_subright(t))
      )
    else t
  )

let t : int t_btree =
  bt_rooting (8,
    bt_rooting (3,
      bt_rooting (1, bt_empty (), bt_empty ()),
      bt_rooting (6,
        bt_rooting (4, bt_empty (), bt_empty ()),
        bt_rooting (7, bt_empty (), bt_empty ())
      )
    ),
    bt_rooting (10, bt_empty (),
      bt_rooting (14,
        bt_rooting (13, bt_empty (), bt_empty ()),
        bt_empty ()
      )
    )
  )
;;
