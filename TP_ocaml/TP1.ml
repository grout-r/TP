let incr = 
function a -> 
a + 1;;

let rec fact =
function n -> 
if n >= 1
then
n * factorielle (n - 1)
else
1;;

let rec fib =
function n ->
match n with
| 0 -> 0
| 1 -> 1
| _ -> fib(n - 1) + fib(n - 2);;
