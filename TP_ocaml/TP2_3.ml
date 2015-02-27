type day = Lundi | Mardi | Mercredi | Jeudi | Vendredi | Samedi | Dimanche;;

type month = Janvier | Fevrier | Mars | Avril | Mai | Juin | Juillet | Aout | Septembre | Octobre | Novembre | Decembre;;

let next_day =
function 
| Lundi -> Mardi
| Mardi -> Mercredi
| Mercredi -> Jeudi
| Jeudi -> Vendredi
| Vendredi-> Samedi
| Samedi -> Dimanche
| Dimanche -> Lundi;;

let next_month =
function
| Janvier -> Fevrier
| Fevrier -> Mars
| Mars -> Avril
| Avril -> Mai
| Mai -> Juin
| Juin -> Juillet
| Juillet -> Aout
| Aout -> Septembre
| Septembre -> Octobre
| Octobre -> Novembre
| Novembre -> Decembre
| Decembre -> Janvier;;

let is_bissextile = 
function a ->
if (a mod 4 = 0 & a mod 100 != 0) || (a mod 400 = 0)
then
true
else
false;;

let nb_days a  =
function
| Janvier -> 31
| Fevrier -> 
begin
match is_bissextile a  with
| true -> 29
| false -> 28
end
| Mars -> 31
| Avril -> 30
| Mai -> 31
| Juin -> 30
| Juillet -> 31
| Aout -> 31
| Septembre -> 30
| Octobre -> 31
| Novembre -> 30
| Decembre -> 31;;

let next_nday =
fun a b c ->
if (a + 1) > (nb_days c b)
then
(1, true)
else
(a + 1, false);;

let changemonth =
function (a, b) ->
if b = true
then
true
else
false;;


let next =
fun (a, b, c, d) ->
let ra = next_day a in
let rb = 
next_nday b c d
(ra, b, c, d);;
