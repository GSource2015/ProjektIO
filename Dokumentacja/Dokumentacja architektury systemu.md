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
4.0 UC00 - Tworzenie nowego poziomu</br>
Po uruchomieniu programu startuje okno z klasy MainWindow. Na poczatku mapa jest ustawiana jako pusta. Jesli mapa jest pusta, to nic sie nie rysuje w glownym oknie. Dopiero jak użytkownik wybierze w menu Plik->Nowy, to uruchamia sie okno dialogowe z klasy NewFile, które przyjmuje parametry nowego okna i pozwala wybrać motyw startowy. Po nacisnieciu potwierdzenia, parametry z okna sa ladowane do klasy Level, a obecny motyw, zaleznie od wyboru, jesli kopiowany z tablicy motywu glownego, albo ze zdefiniowanego przez uzytkownika. Klasa Level organizuje klasy Theme i Board, ktore sa odpowiedzialne za kolejno: ustawienia motywu i planszy. Podczas edycji można edytować motyw, jednak bez edycji ksztaltow (w demo nie dostepne). Mapa jest rysowana przy pomocy interfejsu MapImage, ktory jest odpowiedzialny za transformacje wspolrzednych rzeczywistych do obrazowych, i na odwrot, przy zastosowaniu odpowiednich przeskalowan i macierzy przeksztalcen. Jest swego rodzaju interfejsem, miedzy klasa CustomPanelEditor, na ktorej jest rysowana reprezentacja obrazu w 2D, a Level, ktory posiada sam obiekt. Po zmianie jakichkolwiek parametrow obrazu, nalezy wywolac metode klasy MapImage o nazwie adjustParameters(Lelvel&), a po zmienie wielkosci panelu, funkcje calculateRatio(). Wspolrzedne obrazu sa transformowane na wspolrzedne rzeczywiste za pomoca przeksztalcen odwrotnych i pozwalaja na wybor odpowiedniego kwadratu mapy i jego zmiane (za wykrycie akcji odpowiedzialne sa odpowiednie handlery w klasie CustomPanelEditor). Mape zapisujemy, wybierajac z paska menu opcje Plik->Zapisz i plik można wtedy zapisać w pliku o formacie *.tmm (UC03). W demo podczas zapisu nie jest sprawdzana mozliwosc przejscia mapy.
4.1	UC01 – Wczytywanie do edycji istniejącej mapy z chmury	3</br>
4.2	UC02 – Wczytywanie do edycji istniejącej mapy z dysku	3</br>
4.3	UC03 – Zapisanie mapy na dysku	3</br>
Do zapisu i odczytu sluza klasy FileTMWriter i FileTMReader, dziedziczace po klasie FileTM. Przypadek nie jest kompletny, na razie obsluguje zwykly zapis do pliku, a opcje zapisz i zapisz jako dzialaja tak samo. Wszystkie zapisane mape sa traktowane jako kompletne.
Mapa na poczatku, posiada 2 bajtowy header, ktory identyfikuje ja jako mape (w przyszlosci mozna bedzie zmienic header dla mapy niekompletnej). Jesli motyw jest domyslny, to nie jest zapisywany do pliku, by oszczedzac miejsce. Swiadczy o tym pewna flaga w pliku, ktora informuje czy motyw jest domyslny, czy nie, a jesli nie to jaki jest jej motyw glowny.
4.4	UC04 – Zapisanie mapy w chmurze	3</br>
4.5	UC05 - Edycja istniejacego poziomu	3</br>
Realizacja podobna jak UC00, tylko na poczatku wczytujemy wczesniej zapisany poziom. Najpierw klasa FileTMReader odczytuje naglowek pliku i sprawdza czy jest on zgodny z tym, jaki powinien byc. Potem wczytuje go do pliku tymczasowego Level, ktory jest kopiowany do tego, na ktorym bedziemy pracowac.
5	Wskazówki do implementacji</br>
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

4.5	UC06 - Tworzenie motywu
<ul>
Realizacja na 2 sposoby. Jesli w glownym oknie zmienimy jakikolwiek komponent motywu, to zmienimy obiekt tymczasowy. Po nacisnieciu przycisku zapisz, jest on ladowany do obiektu statycznego, przechowujacego obecne ustawienia uzytkownika. Mozna tez stworzyc motyw w nowym oknie i wtedy po potwierdzeniu, jest on ladowany do tego samego obiektu. Obecne wartosci motywow sa przedstawione na guzikach (na razie kolory, w przyszlosci beda na nie ladowane bitmapy tekstur).
Nalezy ustawic jeszcze motyw glowny, ktory w edytorze nie bedzie nic zmienial, jednak w grze zmienia on tlo, a kolor tla odpowiedzialny jest za kolor swiatla otoczenia.
W demo dostepny tylko wybor kolorow, a nie tekstur.
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
W pogramie będą używane 4 typy plików</br>
<ul>
•	*.tmm – jest to poziom, wraz z informacją o motywie, który będzie używany (jeśli motyw jest inny niż domyślny, to jest on zawarty w tym pliku, by gra mogła od razu korzystać z niego, importując go z chmury, bez ściągania dodatkowych plików).
Kolejność zapisu do pliku bajtowego.:</br>
2b - 0xDAAD header, identyfikujacy plik</br>
1b - dlugosc nazwy poziomu</br>
n*b - nazwa poziomu</br>
1b – wysokość tablicy reprezentującej planszę</br>
1b – szerokość tablicy reprezentującej planszę</br>
wys*szer (char) - tablica, którą można załadować do board</br>
1b - czy header jest domyslny (1 tak, 0 nie)</br>
1b - wartosc enum, jaki motyw glowny (Theme::main_theme)</br>
Jesli header nie jest domyslny to dodatkowo: </br>
1b - dlugosc nazwy headeru</br>
n*b - nazwa headeru</br>
1b – wysokość tablicy reprezentującej podłogę (tekstura)</br>
1b – szerokość tablicy reprezentującej podłogę (tekstura)</br>
(unsigned char) wysokość*szerokość * 3 - tablica, którą można załadować do board</br>
unsigned long (4b) - wartosc koloru wczytywana do klasy wxColour.</br>
(i jeszcze 7 takich samych blokow dla scianek i podlogi)</br>
•	*.tmt – plik przedstawiający motyw. </br>
2b - header 0xADDA, identyfikujacy plik
1b - wartosc enum, jaki motyw glowny (Theme::main_theme)</br>
1b - dlugosc nazwy headeru</br>
n*b - nazwa headeru</br>
1b – wysokość tablicy reprezentującej podłogę (tekstura)</br>
1b – szerokość tablicy reprezentującej podłogę (tekstura)</br>
(unsigned char) wysokość*szerokość * 3 - tablica, którą można załadować do board</br>
unsigned long (4b) - wartosc koloru wczytywana do klasy wxColour.</br>
(i jeszcze 7 takich samych blokow dla scianek i podlogi)</br>
•	*.blend – pliki obiektów 3D tworzone przez program Blender.</br>
•	*.tmu – plik przedstawiający motyw. </br>
Format taki sam jak tmm, tylko header jest rowny 0xDDAA.
</ul>
</ul>
<b>
7	Model testu</br></b>


MANUALNY/AUTOMATYCZNY
<ul>
Testy jednostkowe i integracyjne:</br>
Testowanie klas przy użyciu biblioteki boost.</br>
Ze wzgledu na zly dobor srodowiska (wxDevC++), ciezko nam bylo znalezc testy automatyczne do GUI, dlatego testowalismy GUI manualnie.
Testy funkcji zwracających wartości graficzne testowane manualnie.</br>
GUI testowane manualnie.</br>
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
