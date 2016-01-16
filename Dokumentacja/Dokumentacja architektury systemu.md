Wydział Fizyki i Informatyki Stosowanej</br>
Edytor poziomów</br></br>
<hr>
Dokumentacja architektury systemu</br>
<hr>
Michał Krawczyk </br>
Katarzyna Łęcka</br>
21.12.2015</br>
</br>
</br>
[Wpisz tutaj streszczenie dokumentu. Streszczenie jest zazwyczaj krótkim podsumowaniem treści dokumentu. Wpisz tutaj streszczenie dokumentu. Streszczenie jest zazwyczaj krótkim podsumowaniem treści dokumentu.]
</br>
</br>
1	Wprowadzenie	3</br>
1.1	Zakres architektury systemu	3</br>
1.2	Cele i ograniczenia architektury	3</br>
2	Model środowiska docelowego	3</br>
3	Model architektury	3</br>
4	Realizacja przypadków użycia	3</br>
4.1	UC01 – Wczytywanie do edycji istniejącej mapy z chmury	3</br>
4.2	UC02 – Wczytywanie do edycji istniejącej mapy z dysku	3</br>
4.3	UC03 – Zapisanie mapy na dysku	3</br>
4.4	UC04 – Zapisanie mapy w chmurze	3</br>
4.5	UC05 - Edycja nowego poziomu	3</br>
5	Wskazówki do implementacji	4</br>
5.1	Wykorzystywane biblioteki i gotowe komponenty	4</br>
6	Model danych	4</br>
7	Model testu	4</br>
8	Problemy i ryzyka	4</br>
</br>

<b>1	Wprowadzenie</br>
1.1	Zakres architektury systemu</br>
</br>
<ul>
1.2	Cele i ograniczenia architektury</br></b>
Rysowanie ma przebiegać bez migotań i nie przycinać systemu.</br>
Każde okienko, które się pojawia, powinno blokować możliwość pracy w okienku rodzica, dla zwiększenia stabilności systemu.</br>
Chmura, do której będą ładowane pliki, ma ograniczoną pamięć, dlatego pliki z poziomami nie powinny zbyt dużo zajmować.</br>
</ul>
<b>
2	Model środowiska docelowego</br></b>
[Diagram wdrożenia] komputer – chmura, diagram wdrożenia (czyli czy chmura czy komp, skąd użytkownik ma to wiedzieć)</br>
</br>
<b>
3	Model architektury</br>
<ul></b>
•	Interfejsy:
-____________</br>
•	Biblioteki zewnętrzne:
<ul>
- Blender – sposób dystrybucji: blender wydany jest pod GNU GPL (General Public Licence)</br>
- wxWidgets – sposób dystrybucji : L-GPL (Library General Public Licence )</br>
- boost – the Boost Software License</br>
- iostream – also gnu</br>
</ul>
</ul>
<b>
4	Realizacja przypadków użycia</br></b>
<ul>
4.1	UC01 – Wczytywanie do edycji istniejącej mapy z chmury
<ul>
W demo ta funkcja nie występuje.
</ul>
4.2	UC02 – Wczytywanie do edycji istniejącej mapy z dysku
<ul>
Mapa jest zapisywana w konkretnym formacie, przedstawionym w punkcie ___ . wczytujemy w kolejności dane i uzupełniamy nimi obiekty klasy Level. Po umieszczeniu danych w pamięci operacyjnej można wykonywać operacje na mapie. 
</ul>
4.3	UC03 – Zapisanie mapy na dysku
<ul>
Podobnie jak wyżej mapę zapisujemy w konkretnym formacie podanym w punkcie ___. Korzystamy z elementów obiektów klasy Board i Theme. Jeśli motyw jest domyślny, to nie zapisujemy jego danych.
</ul>
4.4	UC04 – Zapisanie mapy w chmurze
<ul>
W demo ta funkcja nie występuje.
</ul>
4.5	UC05 - Edycja poziomu
<ul>
Poziom jest reprezentowany w postaci tablicy dwuwymiarowej. Liczba -1 reprezentuje dany kwadrat, który nie istnieje, a liczby większe od 0 ilość, ile razy trzeba skasować dany kwadrat (skasowanie wszystkich co najmniej tyle razy powoduje przejście poziomu).
</ul>
</ul><b>
5	Wskazówki do implementacji</br></b>
<ul>
5.1	Wykorzystywane biblioteki i gotowe komponenty</br>
<ul>
•	wxWidgets – GUI oraz reprezentacja grafiki
•	boost – testy jednostkowe i integracyjne
•	iostream – klasa wyjątków, strumienie wejścia/wyjścia
</ul>
</ul>
<b>
6	Model danych</br></b>
<ul>
W pogramie będą używane 3 typy plików</br>
<ul>
•	*.tmm – jest to poziom, wraz z informacją o motywie, który będzie używany (jeśli motyw jest inny niż domyślny, to jest on zawarty w tym pliku, by gra mogła od razu korzystać z niego, importując go z chmury, bez ściągania dodatkowych plików).
Kolejność zapisu do pliku bajtowego.:</br>
int – wysokość tablicy reprezentującej planszę</br>
int – szerokość tablicy reprezentującej planszę</br>
unsigned char x wysokość*szerokość - tablica, którą można załadować do board</br>
int – wysokość tablicy reprezentującej podłogę (tekstura)</br>
int – szerokość tablicy reprezentującej podłogę (tekstura)</br>
unsigned char x wysokość*szerokość - tablica, którą można załadować do board</br>
•	*.tmt – plik przedstawiający motyw. </br>
•	*.blend – pliki obiektów 3D tworzone przez program Blender.</br>
</ul>
</ul>
<b>
7	Model testu</br></b>


MANUALNY/AUTOMATYCZNY
<ul>
Testy jednostkowe i integracyjne:</br>
Testowanie klas przy użyciu biblioteki boost.</br>
Testy funkcji zwracających wartości graficzne testowane wizualnie.</br>
GUI testowane systemowo.</br>
</ul>
</br>
<b>
8	Problemy i ryzyka</b>
<ul>
1.	Ryzyko czasowe:  zagrożenie zaburzeniem harmonogramu
Zapobieganie: oddalenie od siebie kamieni milowych do granic możliwości aby w razie konieczności druga osoba w zespole miała czas na zaznajomienie się obecnym problemem</br>
2.	Ryzyko awarii sprzętu bądź oprogramowania: zagrożenie utraty danych
Zapobieganie: po każdym etapie skończonej pracy uzyskane efekty zapisywane są na pamięci przenośnej oraz zapisywane w chmurze.</br>
3.	Ryzyka czynników zewnętrznych i przypadków losowych</br>
</ul>
