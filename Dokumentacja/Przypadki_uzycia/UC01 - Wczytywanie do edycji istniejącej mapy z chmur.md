<b>Nazwa</b>

<ul>Wczytywanie do edycji istniejącej mapy z chmury</ul>

<b>Identyfikator</b>

<ul>UC01</ul>

<b>Opis</b>

<ul>Wczytanie do edytora istniejącej mapy z chmury, do dalszej edycji.</ul>

<b>Aktorzy</b>

<ul>Projektant Poziomów, Chmura</ul>

<b>Cel</b>

<ul>
Modyfikacja istniejącej mapy, stworzonej przez innego użytkownika lub tego samego, do edycji.</ul>


<b>Cele użytkowników</b>
<ul>

    1.	Projektant poziomów: Łatwy dostęp do map stworzonych przez innych użytkowników<br>


    2.	Projektant poziomów: Wczytywanie map bezpośrednio z chmury <br>


    3.	Gracz: dostęp do zmodyfikowanej zawartości popularnych poziomów<br>

</ul>
<b>Warunki początkowe</b>

<ul>
Uruchomienie edytora
</ul>

<b>Warunki końcowe</b>

<ul>
Wczytanie mapy do edytora
</ul>

<b>Założenia</b>

<ul>
Edytor i komputer posiada dostęp do Internetu.
</ul>

<b>Częstotliwość</b>

<ul>
Kilka razy tygodniowo.
</ul>

<b>Wyzwalacz</b>

<ul>
Wybranie akcji Wczytaj mapę a potem Chmura, w dowolnym momencie podczas przypadku użycia Tworzenie mapy.
</ul>

<b>Podstawowy przebieg</b>
<ul>


1.	System łączy się z chmurą<br>


2.	System wczytuje bazę danych istniejących map.<br>


3.	W oknie dialogowym, które się pojawiło, należy wybrać mapę, którą projektant chce edytować.<br>


4.	Podczas wybierania mapy dostępny jest ich podgląd, nazwa, ocena, data dodania oraz typ poziomu (tło, odpowiedzialne tylko za wygląd).<br>


5.	Możliwe jest sortowanie map wg oceny, nazwy, daty dodania oraz tła.<br>


6.	Wpisując bezpośredni kod mapy, możemy uzyskać dostęp do map prywatnych.<br>


7.	Po wybraniu mapy system upewnia się, czy na pewno chcemy wybrać tą mapę.<br>


8.	System wczytuje mapę do pamięci.<br>

</ul>
<b>Przebieg alternatywny</b>
<ul>

1a.	Nie można połączyć się z chmurą, ponieważ brak połączenia z Internetem lub chmura jest nieosiągalna<br>

<ul>
1a1.	Możliwość wyboru opcji Ponownej próby połączenia lub Anulowania akcji<br>


1a2.	Wybranie ponownej próby połączenia spowoduje wykonywanie przebiegu głównego na nowo.<br>


1a3. Wybranie anulowania akcji spowoduje porzucenie całego scenariusza.<br>
</ul>
</ul>
<b>Przebieg alternatywny</b>

<ul>
2a.	W bazie danych nie ma żadnych map.<br>


<ul>
2a1.	System informuje użytkownika, że baza danych jest pusta<br>
</ul>
</ul>
<b>Przebieg alternatywny</b>
<ul>

7a.	Projektant poziomów pracował już nad jakąś mapą
<ul>

7a1.	System pyta się czy należy zapisać istniejącą mapę<br>


7a2.	Jeśli tak, to uruchamiany jest UC02 - Zapisywanie mapy na dysku<br>
</ul>
</ul>
Dalej wszystko przebiega zgodnie z głównym scenariuszem.


<b>Rozszerzane przypadki użycia:</b>


<ul>Wczytywanie mapy</ul>
