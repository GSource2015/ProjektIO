</br></br>Wydział Fizyki i Informatyki Stosowanej</br>
Edytor poziomów</br></br></br></br></br></br></br></br></br></br>
<hr></br></br>
Dokumentacja analityczna systemu</br>
</br></br>
<hr></br></br></br></br></br></br></br>
Michał Krawczyk</br>
Katarzyna Łęcka</br>
</br>
29.12.2015r.
</br>
</br></br></br></br>
[Wpisz tutaj streszczenie dokumentu. Streszczenie jest zazwyczaj krótkim podsumowaniem treści dokumentu. Wpisz tutaj streszczenie dokumentu. Streszczenie jest zazwyczaj krótkim podsumowaniem treści dokumentu.]
</br></br></br></br></br>



1	Wprowadzenie	3</br>
1.1	Opis systemu	3</br>
1.2	Cele do osiągnięcia	3</br>
1.3	Słownik	3</br>
2	Wymagania funkcjonalne - przypadki użycia	3</br>
2.1	UC01 – Wczytywanie do edycji istniejącej mapy z chmury	3</br>
2.2	UC02 – Wczytywanie do edycji istniejącej mapy z dysku	5</br>
2.3	UC03 – Zapisanie mapy na dysku	6</br>
2.4	UC04 – Zapisanie mapy w chmurze	7</br>
2.5	UC05 - Edycja nowego poziomu	9</br>
2.6	UC06 – Tworzenie motywów	10</br>
2.7	UC07 – Wybieranie figur	11</br>
3	Wymagania niefunkcjonalne	11</br>
3.1	Wymagania względem projektu	12</br>
3.2	Wymagania organizacyjne	12</br>
3.3	Wymagania zewnętrzne	12</br>
4	Model dziedziny	12</br>
5	Problemy i ryzyka	13</br>
</br></br></br></br>
1	Wprowadzenie</br>
1.1	Opis systemu</br>
…</br></br></br></br>
1.2	Cele do osiągnięcia</br>
Celem, który zamierzamy osiągnąć jest zaprojektowanie oraz zaprogramowanie użytecznego edytora poziomów</br>
do gry typu skasuj 3 takie same elementy.</br>
Przede wszystkim naszym priorytetem jest zaspokojenie oczekiwań klienta co do jakości produktu,</br>
jednak równie ważnym elementem jest WYROBIENIE się w terminie jeśli chodzi o implementację projektu.</br> 
Głównymi założeniami co do efektu finalnego edytora są:</br>
•	 
•	
1.3	Słownik</br>
…
2	Wymagania funkcjonalne - przypadki użycia</br>

 

2.1	UC01 – Wczytywanie do edycji istniejącej mapy z chmury</br>
2.1.1	Opis przypadku użycia</br>
Wczytanie do edytora istniejącej mapy z chmury, do dalszej edycji.</br>
2.1.2	Aktorzy</br>
Projektant Poziomów, Chmura</br>
2.1.3	Poziom</br>
Jeden z trzech poziomów: ogólnego, użytkownika i podfunkcji.</br>
2.1.4	Cel (cel biznesowy osiągany przez ten przypadek użycia)</br>

2.1.5	Cele użytkowników</br>
Projektant poziomów: Łatwy dostęp do map stworzonych przez innych użytkowników</br>
Projektant poziomów: Wczytywanie map bezpośrednio z chmury </br>
Gracz: dostęp do zmodyfikowanej zawartości popularnych poziomów</br>
2.1.6	Warunki początkowe </br>
Uruchomienie edytora</br>
2.1.7	Wyzwalacz</br>
Wybranie akcji Wczytaj mapę a potem Chmura, w dowolnym momencie podczas przypadku użycia Tworzenie mapy.</br>
2.1.8	Warunki końcowe</br>
Wczytanie mapy do edytora</br>
2.1.9	Scenariusz główny</br>
1.	System łączy się z chmurą</br>
2.	System wczytuje bazę danych istniejących map.</br>
3.	W oknie dialogowym, które się pojawiło, należy wybrać mapę, którą projektant chce edytować.</br>
4.	Podczas wybierania mapy dostępny jest ich podgląd, nazwa, ocena, data dodania oraz typ poziomu (tło, odpowiedzialne tylko za wygląd).</br>
5.	Możliwe jest sortowanie map wg oceny, nazwy, daty dodania oraz tła.</br>
6.	Wpisując bezpośredni kod mapy, możemy uzyskać dostęp do map prywatnych.</br>
7.	Po wybraniu mapy system upewnia się, czy na pewno chcemy wybrać tą mapę.</br>
8.	System wczytuje mapę do pamięci</br>
2.1.10	Scenariusze alternatywne</br>
1a.  Nie można połączyć się z chmurą, ponieważ brak połączenia z Internetem lub chmura jest nieosiągalna</br>
1a1.  Możliwość wyboru opcji Ponownej próby połączenia lub Anulowania akcji</br>
1a2.  Wybranie ponownej próby połączenia spowoduje wykonywanie przebiegu głównego na nowo.</br>
1a2. Wybranie anulowania akcji spowoduje porzucenie całego scenariusza.</br>
</br>
2a. W bazie danych nie ma żadnych map.</br>
2a1. System informuje użytkownika, że baza danych jest pusta</br>
7a. Projektant poziomów pracował już nad jakąś mapą</br>
7a1. System pyta się czy należy zapisać istniejącą mapę</br>
7a2. Jeśli tak, to uruchamiany jest UC02 - Zapisywanie mapy na dysku</br>
Dalej wszystko przebiega zgodnie z głównym scenariuszem.</br>
</br>
2.1.11	Problemy</br>
</br>
2.1.12	Decyzje</br>
</br>
2.2	UC02 – Wczytywanie do edycji istniejącej mapy z dysku</br>
2.2.1	Opis przypadku użycia</br>
Wczytanie do edytora istniejącej mapy z dysku, do dalszej edycji</br>.
2.2.2	Aktorzy</br>
Projektant Poziomów</br>
2.2.3	Poziom</br>
Jeden z trzech poziomów: ogólnego, użytkownika i podfunkcji.</br>
2.2.4	Cel (cel biznesowy osiągany przez ten przypadek użycia)</br>
Modyfikacja istniejącej mapy, stworzonej przez innego użytkownika lub tego samego, lub twórców, do edycji.</br>
2.2.5	Cele użytkowników</br>
Projektant poziomów: Możliwość bezpiecznego przechowywania map na dysku</br>
Projektant poziomów: Brak konieczności połączenia z Internetem do pracy w programie</br>
Projektant poziomów: możliwość edycji map stworzonych przez twórców</br>
Gracz: dostęp do różnorodnych poziomów</br>
</br>
2.2.6	Warunki początkowe </br>
Uruchomienie edytora</br>
2.2.7	Częstotliwość wykonania</br>
Kilkanaście razy tygodniowo.</br>
2.2.8	Wyzwalacz</br>
Wybranie akcji Wczytaj mapę a potem Dysk, w dowolnym momencie podczas przypadku użycia Tworzenie mapy.</br>
2.2.9	Warunki końcowe</br>
Wczytanie mapy do edytora</br>
2.2.10	Scenariusz główny</br>
1.	Pojawia się eksplorator plików</br>
2.	W eksploratorze wyboru można wybrać tylko pliki z odpowiednim rozszerzeniem.</br>
3.	Posiada wszystkie możliwości eksploratora na platformie</br>
4.	Po wybraniu mapy system wczytuje mapę do pamięci.</br>
2.2.11	Scenariusze alternatywne</br>
4a. Projektant poziomów pracował już nad jakąś mapą</br>
4a1. System pyta się czy należy zapisać istniejącą mapę</br>
4a2. Jeśli tak, to uruchamiany jest UC03 - Zapisywanie mapy na dysku</br>
Dalej wszystko przebiega zgodnie z głównym scenariuszem.</br>
4b. Brak miejsca w pamięci do wczytania mapy</br>
4b1. Zrzucenie istotnych danych na dysk.</br>
4b2. Zamknięcie programu</br>
</br>
2.2.12	Problemy</br>
</br>
2.2.13	Decyzje</br>
</br>
2.3	UC03 – Zapisanie mapy na dysku</br>
2.3.1	Opis przypadku użycia</br>
Zapisanie stworzonej lub niedokończonej mapy na dysku, by móc importować ją w grze.</br>
2.3.2	Aktorzy</br>
Projektant Poziomów</br>
2.3.3	Poziom</br>
Jeden z trzech poziomów: ogólnego, użytkownika i podfunkcji.</br>
2.3.4	Cel (cel biznesowy osiągany przez ten przypadek użycia)</br>
Modyfikacja istniejącej mapy, stworzonej przez innego użytkownika lub tego samego, lub twórców, do edycji.</br>
2.3.5	Cele użytkowników</br>
1.	Projektant poziomów: Możliwość zapisywania map wyłącznie do własnego użytku</br>
2.	Projektant poziomów: Brak konieczności połączenia z Internetem do pracy w programie</br>
3.	Projektant poziomów: Możliwość zapisywania niedokończonych map.</br>
4.	Projektant poziomów: Tworzenie kopii bezpieczeństwa podczas tworzenia mapy.</br>
5.	Gracz: łatwa możliwość pobierania poziomów.</br>
2.3.6	Warunki początkowe </br>
Uruchomienie programu.</br>
2.3.7	Wyzwalacz</br>
Wybranie akcji Zapisz mapę a potem Dysk, w dowolnym momencie podczas przypadku użycia Tworzenie mapy.</br>
2.3.8	Warunki końcowe</br>
Zapisanie mapy na dysku</br>
2.3.9	Scenariusz główny</br>
1.	Pojawia się eksplorator plików</br>
2.	W eksploratorze wyboru można wybrać w jaki sposób zapisać mapę: kompletną lub niekompletną. Będą one się różniły rozszerzeniem</br> i mapy niekompletnej nie można wczytać do gry.</br>
3.	Po wyborze nazwy i rozszerzenia system zapisuje plik na dysku.</br>
2.3.10	Scenariusze alternatywne</br>
1a. Projektant poziomów pracuje na już istniejącym pliku.</br>
1a1. Zapis powoduje nadpisanie istniejącej wersji pliku.</br>
1a2. Aby zapisać poziom w nowym pliku należy użyć opcji Zapisz jako.</br>
2a. Projektant poziomów próbuje zapisać mapę niekompletną jako kompletną</br>
2a1. Sprawdzane jest, czy mapa ma odpowiednią wielkość</br>
2a2. Sprawdzana jest możliwość przejścia mapy.</br>
3a. Brak miejsca na dysku lub brak dostępu</br>
3a1. Pojawia się komunikat o błędzie i akcja 3 jest powtarzana.</br>
2.3.11	Problemy</br>
</br>
2.3.12	Decyzje</br>
</br></br>
2.4	UC04 – Zapisanie mapy w chmurze</br>
2.4.1	Opis przypadku użycia</br>
Zapisanie stworzonej mapy na chmurze, by móc potem importować ją w grze.</br>
2.4.2	Aktorzy</br>
Projektant Poziomów, Chmura</br>
2.4.3	Poziom</br>
Jeden z trzech poziomów: ogólnego, użytkownika i podfunkcji.</br>
2.4.4	Cel (cel biznesowy osiągany przez ten przypadek użycia)</br>
Zapisanie mapy na chmurze, by udostępnić ją innym.</br>
2.4.5	Cele użytkowników</br>
1.	Projektant poziomów: Możliwość dzielenia się swoimi mapami z innymi.</br>
2.	Projektant poziomów: Bezpieczne przechowywanie kopii mapy.</br>
3.	Gracz: łatwość dostępu do poziomów stworzonych przez innych graczy.</br>
4.	Gracz: zebranie wszystkich poziomów w jednym miejscu.</br>
5.	Gracz: dostęp do poziomów z jednego miejsca.</br>
2.4.6	Warunki początkowe </br>
Uruchomienie programu.</br>
2.4.7	Częstotliwość wykonania</br>
Kilka razy tygodniowo</br>
2.4.8	Wyzwalacz</br>
Wybranie akcji Zapisz mapę a potem Chmura, w dowolnym momencie podczas przypadku użycia Tworzenie mapy.</br>
2.4.9	Warunki końcowe</br>
Zapisanie mapy w chmurze</br>
2.4.10	Scenariusz główny</br>
1.	Należy zalogować się na konto</br>
2.	W oknie dialogowym należy wpisać nazwę i ewentualnie opis mapy</br>
3.	Można wybrać czy mapa ma być dostępna publicznie w katalogu czy prywatnie, poprzez ID</br>
4.	Po dodaniu mapy nadany jest jej unikalny identyfikator.</br>
2.4.11	Scenariusze alternatywne</br>
1a. Użytkownik wpisał złe dane logowania</br>
1a1. Pojawia się komunikat o wpisaniu złych danych i akcje jest ponawiana</br>
Dalej wszystko zgodnie z głównym scenariuszem</br>
2a. Użytkownik  nie wpisał nazwy</br>
2a1. Pojawia się komunikat o wpisaniu niepoprawnej nazwy i akcja jest ponawiana</br>
Dalej wszystko zgodnie z głównym scenariuszem.</br>
</br>
2.4.12	Problemy</br>
2.4.13	Decyzje</br>
</br></br>
2.5	UC05 - Edycja nowego poziomu</br>
2.5.1	Opis przypadku użycia</br>
Uruchomienie edytora w celu stworzenia poziomu gry.</br>
2.5.2	Aktorzy</br>
Projektant Poziomów</br>
2.5.3	Poziom</br>
Jeden z trzech poziomów: ogólnego, użytkownika i podfunkcji.</br>
2.5.4	Cel (cel biznesowy osiągany przez ten przypadek użycia)</br>
Tworzenie nowej mapy</br>
2.5.5	Cele użytkowników</br>
Projektant Poziomów: Tworzenie nowej mapy</br>
Projektant Poziomów: Modyfikacja istniejącej mapy. </br>
2.5.6	Warunki początkowe </br>
Uruchomienie edytora.</br>
2.5.7	Warunki końcowe</br>
Decyzja o zakończeniu edycji</br>
2.5.8	Scenariusz główny</br>
1.	Gracz wybiera opcję z menu Stwórz nową mapę.</br>
2.	Gracz tworzy mapę od podstaw używając do tego narzędzi programu.</br>
3.	Gracz zapisuje wprowadzone zmiany. </br>
4.	Decyzja o zapisaniu stworzonej mapy.</br>
</br>
2.5.9	Scenariusze alternatywne</br>
1a. Gracz decyduje się na edycję istniejącej już mapy.</br>
1a1. Uruchomienie edytora w celu edycji istniejącego poziomu gry.</br>
1a2. Wczytanie wybranej mapy do edytora.</br>
</br></br>
2.6	UC06 – Tworzenie motywów </br>
2.6.1	Opis przypadku użycia</br>
Tworzenie motywów dotyczących tła i wyglądu planszy.</br>
2.6.2	Aktorzy</br>
Projektant Poziomów</br>
2.6.3	Poziom</br>
2.6.4	Cel (cel biznesowy osiągany przez ten przypadek użycia)</br>
Modyfikacja motywów zdefiniowanych przez użytkownika</br>
2.6.5	Cele użytkowników</br>
1.	Projektant poziomów: Możliwość realizacji projektów przy tworzeniu mapy</br>
2.	Projektant poziomów: Swoboda w tworzeniu mapy </br>
2.6.6	Warunki początkowe </br>
Uruchomienie edytora</br>
2.6.7	Wyzwalacz</br>
Wybranie akcji Stwórz nowy motyw, w dowolnym momencie podczas przypadku użycia Tworzenie mapy.</br>
2.6.8	Warunki końcowe</br>
Zapisanie poziomu</br>
2.6.9	Scenariusz główny</br>
1.	Wybranie głównego motywu (lokację planszy).</br>
2.	Ustalenie tekstury podłoża i ścianek wczytując je z pliku graficznego.</br>
3.	Zapis motywu</br>
2.6.10	Scenariusze alternatywne</br>
1a.	Wczytanie gotowego motywu do edycji</br>
1a1.	Wybranie akcji wczytaj motyw</br>
1a2.	Wybranie pliku z motywem w eksploratorze</br>
3a.	Użytkownik wycofuje się z akcji.</br>
3a1.	Wybranie akcji anuluj.</br>
</br>
2.6.11	Problemy</br>
</br>
2.6.12	Decyzje</br>
</br>
</br></br>
2.7	UC07 – Wybieranie figur </br>
2.7.1	Opis przypadku użycia</br>
Wybieranie figur z dostępnych modeli 3D utworzonych w innym programie.</br>
2.7.2	Aktorzy</br>
Projektant Poziomów</br>
2.7.3	Poziom</br>
2.7.4	Cel (cel biznesowy osiągany przez ten przypadek użycia)</br>
Możliwość spersonalizowania mapy przez rozszerzenie interakcji z tworzeniem mapy.</br>
2.7.5	Cele użytkowników</br>
Projektant poziomów: Możliwość dodania do planszy własnych figur do mapy</br>
2.7.6	Warunki początkowe </br>
Praca nad poziomem</br>
2.7.7	Wyzwalacz</br>
Wybranie opcji Dodaj nowy kształt</br>
2.7.8	Warunki końcowe</br>
Dodanie figury do programu</br>
2.7.9	Scenariusz główny</br>
1.	Wczytanie figury z pliku</br>
2.	Zastąpienie nią istniejącej reprezentacji innej figury</br>
3.	Zapisanie zmian</br>
2.7.10	Scenariusze alternatywne</br>
3a.	Użytkownik wycofuje się z akcji.</br>
3a1.	Wybranie akcji anuluj.</br>
</br>
2.7.11	Problemy</br>
</br>
2.7.12	Decyzje
</br>
</br></br>
3	Wymagania niefunkcjonalne</br>
3.1	Wymagania względem projektu</br>
3.1.1	ID_P01 – Sprawność systemu</br>
Cel: Program nie powinien się zawieszać.</br>
Weryfikowalne wymaganie: szybkość działania</br>
3.1.2	ID_P02 – Dostateczny zasób pamięci</br>
Cel:. Możliwość edycji i tworzenia plików.</br>
Weryfikowalne wymaganie: dostęp do zasobów pamięci</br>
3.1.3	ID_P03 – Minimalizacja awarii</br>
Cel: akceptowalna częstotliwość awarii.</br>
Weryfikowalne wymaganie: Częstotliwość awarii zmniejszona do minimum, przeciwdziałanie czynnościom mającym wpływ na błędy systemu.</br>
3.2	Wymagania organizacyjne</br>
3.2.1	ID_O01 – Spójne środowisko programistyczne</br>
Cel: spójny język oraz metoda programowania środowiska.</br>
Weryfikowalne wymaganie: Wcześniej określone środowisko programistyczne zapewni spójność w metodzie programowania w wypadku potrzeby</br> zatrudnienia większej liczby programistów.</br>
3.2.2	ID_O02 – Dotrzymanie terminu</br>
Cel: Dostarczenie produktu i dokumentacji w terminie.</br>
Weryfikowalne wymaganie:  Pracy nad projektem powinno dobiec końca przed terminem wyznaczonym wraz z klientem. W razie jakichkolwiek</br> opóźnień należy uprzedzić docelową grupę oraz przedstawić plan dostarczenia skończonego projektu w późniejszym terminie.</br>
3.3	Wymagania zewnętrzne</br>
3.3.1	ID_Z01 – Współpraca z platformą</br>
Cel: współpraca z platformą Steam.</br>
Weryfikowalne wymaganie: Docelową platformą udostępniającą grę oraz jej edytor będzie platforma Steam, która zapewnia szeroką skalę klientów.</br>
4	Model dziedziny</br>
[Diagram]
[Opis odpowiedzialności klas obiektów]</br>
5	Problemy i ryzyka</br>
