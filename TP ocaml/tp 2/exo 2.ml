let rec fibo(n : int) : int =
  if n== 0 || n==1
  then n
  else fibo(n-1)+fibo(n-2);;

(* O(n) = 2^n  *)
