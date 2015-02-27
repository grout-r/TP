
type etudiant = 
{first_name : string;
last_name : string;
promotion : int;
is_close : bool}

let get_first_name = 
function etudiant ->
etudiant.first_name;;

let get_last_name = 
function etudiant ->
etudiant.last_name;;

let get_promotion = 
function etudiant ->
etudiant.promotion;;

let is_close = 
function etudiant ->
etudiant.is_close;;

let is_in_promo =
fun etudiant a ->
if etudiant.promotion = a
then
true
else
false;;

let is_in_promo_range =
fun etudiant a b ->
if etudiant.promotion >= a & etudiant.promotion <= b
then
true
else
false;;
