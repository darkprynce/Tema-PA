# Tema-PA

Acest program implementează un turneu în care echipele se întrec în meciuri. Echipele și rezultatele meciurilor sunt citite dintr-un fișier de intrare, iar apoi se aplică regulile turneului pentru a determina echipa câștigătoare.

Programul folosește următoarele structuri de date:

struct Team: reprezintă o echipă și conține informații despre nume, punctaj mediu și legăturile către echipele vecine într-o listă simplu înlănțuită, precum și într-un arbore binar de căutare.
struct Match: reprezintă un meci între două echipe și conține informații despre echipele participante și legătura către următorul meci într-o coadă.
struct Queue: reprezintă o coadă de meciuri și conține referințe către primul și ultimul meci din coadă.
struct Stack: reprezintă o stivă de echipe și conține referința către echipa de top în stivă.

Programul implementează următoarele funcționalități:

Citirea și prelucrarea datelor
Citirea informațiilor despre echipe și jucători din fișierul de intrare (d.in) și construirea listei de echipe.
Eliminarea echipele cu cel mai mic punctaj din listă până când numărul de echipe este redus la o putere a lui 2. În caz de egalitate a punctajului, se elimină prima echipă găsită în listă.
Afișarea listei de echipe rezultată.
Desfășurarea turneului
Generarea meciurilor dintre echipe și adăugarea lor în coada de meciuri.
Afișarea cozii de meciuri.
Parcurgerea cozii de meciuri, determinarea câștigătorului și adăugarea acestuia în stiva de câștigători.
Afișarea câștigătorilor rundei curente.
Adăugarea echipelor învinse în lista de echipe.
Repetarea pașilor de mai sus până când numărul de echipe este redus la 8.
Clasamentul final
Construirea unui arbore binar de căutare (BST) din ultimele 8 echipe rămase în turneu, în funcție de punctajul mediu al echipelor.
Afișarea clasamentului final în ordine descrescătoare a punctajelor medii utilizând o parcurgere în inordine a arborelui binar de căutare.
Eliberarea memoriei ocupate.
