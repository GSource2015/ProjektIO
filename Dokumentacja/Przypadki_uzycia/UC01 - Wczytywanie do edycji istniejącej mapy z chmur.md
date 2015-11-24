<b>Nazwa</b>

Wczytywanie do edycji istniejącej mapy z chmury

<b>Identyfikator</b>

UC01

<b>Opis</b>

Wczytanie do edytora istniejącej mapy z chmury, do dalszej edycji.

<b>Aktorzy</b>

Projektant Poziomów, Chmura

<b>Cel</b>


Modyfikacja istniejącej mapy, stworzonej przez innego użytkownika lub tego samego, do edycji.


<b>Cele użytkowników</b>


    1.	Projektant poziomów: Łatwy dostęp do map stworzonych przez innych użytkowników


    2.	Projektant poziomów: Wczytywanie map bezpośrednio z chmury 


    3.	Gracz: dostęp do zmodyfikowanej zawartości popularnych poziomów


<b>Warunki początkowe</b>


Uruchomienie edytora


<b>Warunki końcowe</b>


Wczytanie mapy do edytora


<b>Założenia</b>


Edytor i komputer posiada dostęp do Internetu.


<b>Częstotliwość</b>


Kilka razy tygodniowo.


<b>Wyzwalacz</b>


Wybranie akcji Wczytaj mapę a potem Chmura, w dowolnym momencie podczas przypadku użycia Tworzenie mapy.


<b>Podstawowy przebieg</b>


    1.	System łączy się z chmurą


    2.	System wczytuje bazę danych istniejących map.


    3.	W oknie dialogowym, które się pojawiło, należy wybrać mapę, którą projektant chce edytować.


    4.	Podczas wybierania mapy dostępny jest ich podgląd, nazwa, ocena, data dodania oraz typ poziomu (tło, odpowiedzialne 

tylko za wygląd).


    5.	Możliwe jest sortowanie map wg oceny, nazwy, daty dodania oraz tła.


    6.	Wpisując bezpośredni kod mapy, możemy uzyskać dostęp do map prywatnych.


    7.	Po wybraniu mapy system upewnia się, czy na pewno chcemy wybrać tą mapę.


    8.	System wczytuje mapę do pamięci.


<b>Przebieg alternatywny</b>


    1a.	Nie można połączyć się z chmurą, ponieważ brak połączenia z Internetem lub chmura jest nieosiągalna


    1a1.	Możliwość wyboru opcji Ponownej próby połączenia lub Anulowania akcji


    1a2.	Wybranie ponownej próby połączenia spowoduje wykonywanie przebiegu głównego na nowo.


    1a2. Wybranie anulowania akcji spowoduje porzucenie całego scenariusza.


<b>Przebieg alternatywny</b>


    2a.	W bazie danych nie ma żadnych map.


    2a1.	System informuje użytkownika, że baza danych jest pusta


<b>Przebieg alternatywny</b>


    7a.	Projektant poziomów pracował już nad jakąś mapą


    7a1.	System pyta się czy należy zapisać istniejącą mapę


    7a2.	Jeśli tak, to uruchamiany jest UC02 - Zapisywanie mapy na dysku


Dalej wszystko przebiega zgodnie z głównym scenariuszem.


<b>Rozszerzane przypadki użycia:</b>


Wczytywanie mapy
