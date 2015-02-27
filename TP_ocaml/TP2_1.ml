
let get_first_name =
function ( a,  b,  c,  d ) ->
a;;

let get_last_name =
function ( a,  b,  c,  d ) ->
b;;

let get_promotion =
function ( a,  b,  c,  d ) ->
c;;

let is_close  =
function ( a,  b,  c,  d ) ->
d;;

let is_in_promo = 
fun ( a,  b,  c,  d ) e  ->
if c = e
then
true
else
false;;

let is_in_promo_range =
fun ( a,  b,  c,  d ) e f ->
if c >= e & c <= f
then
true
else
false;;

