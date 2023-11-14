(** Arbre binaire avec type somme TP1 AP3*)

(** Definition du type *)
type 'a t_btree

(** ab_vide -
     retourne l'arbre vide *)
val bt_empty : unit -> 'a t_btree

(** ab_enraciner- 
    créer un arbre avec un nouveau noeud 
    et deux sous arbres donnés en parametre*)
val bt_rooting : 'a * 'a t_btree * 'a t_btree -> 'a t_btree

(** ab_estvide - 
    retourne vrai si l'arbre est vide*)
val bt_isempty : 'a t_btree -> bool

(** ab_racine -
     retourne la valeur de la racine d'un arbre en parametre*)
val bt_root : 'a t_btree -> 'a

(** ab_gauche - 
    retourne le sous arbre gauche d'un arbre en parametre*)
val bt_subleft : 'a t_btree ->  'a t_btree

(** ab_ droite -
     retourne le sous arbre droit d'un arbre en parametre*)
val bt_subright : 'a t_btree -> 'a t_btree