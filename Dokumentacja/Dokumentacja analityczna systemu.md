</br></br>Wydział Fizyki i Informatyki Stosowanej</br>
Edytor poziomów</br>
<hr></br></br>
Dokumentacja analityczna systemu</br>
</br></br>
<hr>
Michał Krawczyk</br>
Katarzyna Łęcka</br>
</br>
29.12.2015r.
</br>
</br></br></br></br>
[Wpisz tutaj streszczenie dokumentu. Streszczenie jest zazwyczaj krótkim podsumowaniem treści dokumentu. Wpisz tutaj streszczenie dokumentu. Streszczenie jest zazwyczaj krótkim podsumowaniem treści dokumentu.]

 
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

 

2.1	UC01 – Wczytywanie do edycji istniejącej mapy z chmury
2.1.1	Opis przypadku użycia
Wczytanie do edytora istniejącej mapy z chmury, do dalszej edycji.
2.1.2	Aktorzy
Projektant Poziomów, Chmura
2.1.3	Poziom
Jeden z trzech poziomów: ogólnego, użytkownika i podfunkcji.
2.1.4	Cel (cel biznesowy osiągany przez ten przypadek użycia)

2.1.5	Cele użytkowników
Projektant poziomów: Łatwy dostęp do map stworzonych przez innych użytkowników
Projektant poziomów: Wczytywanie map bezpośrednio z chmury 
Gracz: dostęp do zmodyfikowanej zawartości popularnych poziomów
2.1.6	Warunki początkowe 
Uruchomienie edytora
2.1.7	Wyzwalacz
Wybranie akcji Wczytaj mapę a potem Chmura, w dowolnym momencie podczas przypadku użycia Tworzenie mapy.
2.1.8	Warunki końcowe
Wczytanie mapy do edytora
2.1.9	Scenariusz główny
1.	System łączy się z chmurą
2.	System wczytuje bazę danych istniejących map.
3.	W oknie dialogowym, które się pojawiło, należy wybrać mapę, którą projektant chce edytować.
4.	Podczas wybierania mapy dostępny jest ich podgląd, nazwa, ocena, data dodania oraz typ poziomu (tło, odpowiedzialne tylko za wygląd).
5.	Możliwe jest sortowanie map wg oceny, nazwy, daty dodania oraz tła.
6.	Wpisując bezpośredni kod mapy, możemy uzyskać dostęp do map prywatnych.
7.	Po wybraniu mapy system upewnia się, czy na pewno chcemy wybrać tą mapę.
8.	System wczytuje mapę do pamięci
2.1.10	Scenariusze alternatywne
1a.  Nie można połączyć się z chmurą, ponieważ brak połączenia z Internetem lub chmura jest nieosiągalna
1a1.  Możliwość wyboru opcji Ponownej próby połączenia lub Anulowania akcji
1a2.  Wybranie ponownej próby połączenia spowoduje wykonywanie przebiegu głównego na nowo.
1a2. Wybranie anulowania akcji spowoduje porzucenie całego scenariusza.

2a. W bazie danych nie ma żadnych map.
2a1. System informuje użytkownika, że baza danych jest pusta
7a. Projektant poziomów pracował już nad jakąś mapą
7a1. System pyta się czy należy zapisać istniejącą mapę
7a2. Jeśli tak, to uruchamiany jest UC02 - Zapisywanie mapy na dysku
Dalej wszystko przebiega zgodnie z głównym scenariuszem.

2.1.11	Problemy

2.1.12	Decyzje

2.2	UC02 – Wczytywanie do edycji istniejącej mapy z dysku
2.2.1	Opis przypadku użycia
Wczytanie do edytora istniejącej mapy z dysku, do dalszej edycji.
2.2.2	Aktorzy
Projektant Poziomów
2.2.3	Poziom
Jeden z trzech poziomów: ogólnego, użytkownika i podfunkcji.
2.2.4	Cel (cel biznesowy osiągany przez ten przypadek użycia)
Modyfikacja istniejącej mapy, stworzonej przez innego użytkownika lub tego samego, lub twórców, do edycji.
2.2.5	Cele użytkowników
Projektant poziomów: Możliwość bezpiecznego przechowywania map na dysku
Projektant poziomów: Brak konieczności połączenia z Internetem do pracy w programie
Projektant poziomów: możliwość edycji map stworzonych przez twórców
Gracz: dostęp do różnorodnych poziomów

2.2.6	Warunki początkowe 
Uruchomienie edytora
2.2.7	Częstotliwość wykonania
Kilkanaście razy tygodniowo.
2.2.8	Wyzwalacz
Wybranie akcji Wczytaj mapę a potem Dysk, w dowolnym momencie podczas przypadku użycia Tworzenie mapy.
2.2.9	Warunki końcowe
Wczytanie mapy do edytora
2.2.10	Scenariusz główny
1.	Pojawia się eksplorator plików
2.	W eksploratorze wyboru można wybrać tylko pliki z odpowiednim rozszerzeniem.
3.	Posiada wszystkie możliwości eksploratora na platformie
4.	Po wybraniu mapy system wczytuje mapę do pamięci.
2.2.11	Scenariusze alternatywne
4a. Projektant poziomów pracował już nad jakąś mapą
4a1. System pyta się czy należy zapisać istniejącą mapę
4a2. Jeśli tak, to uruchamiany jest UC03 - Zapisywanie mapy na dysku
Dalej wszystko przebiega zgodnie z głównym scenariuszem.
4b. Brak miejsca w pamięci do wczytania mapy
4b1. Zrzucenie istotnych danych na dysk.
4b2. Zamknięcie programu

2.2.12	Problemy

2.2.13	Decyzje

2.3	UC03 – Zapisanie mapy na dysku
2.3.1	Opis przypadku użycia
Zapisanie stworzonej lub niedokończonej mapy na dysku, by móc importować ją w grze.
2.3.2	Aktorzy
Projektant Poziomów
2.3.3	Poziom
Jeden z trzech poziomów: ogólnego, użytkownika i podfunkcji.
2.3.4	Cel (cel biznesowy osiągany przez ten przypadek użycia)
Modyfikacja istniejącej mapy, stworzonej przez innego użytkownika lub tego samego, lub twórców, do edycji.
2.3.5	Cele użytkowników
1.	Projektant poziomów: Możliwość zapisywania map wyłącznie do własnego użytku
2.	Projektant poziomów: Brak konieczności połączenia z Internetem do pracy w programie
3.	Projektant poziomów: Możliwość zapisywania niedokończonych map.
4.	Projektant poziomów: Tworzenie kopii bezpieczeństwa podczas tworzenia mapy.
5.	Gracz: łatwa możliwość pobierania poziomów.
2.3.6	Warunki początkowe 
Uruchomienie programu.
2.3.7	Wyzwalacz
Wybranie akcji Zapisz mapę a potem Dysk, w dowolnym momencie podczas przypadku użycia Tworzenie mapy.
2.3.8	Warunki końcowe
Zapisanie mapy na dysku
2.3.9	Scenariusz główny
1.	Pojawia się eksplorator plików
2.	W eksploratorze wyboru można wybrać w jaki sposób zapisać mapę: kompletną lub niekompletną. Będą one się różniły rozszerzeniem i mapy niekompletnej nie można wczytać do gry.
3.	Po wyborze nazwy i rozszerzenia system zapisuje plik na dysku.
2.3.10	Scenariusze alternatywne
1a. Projektant poziomów pracuje na już istniejącym pliku.
1a1. Zapis powoduje nadpisanie istniejącej wersji pliku.
1a2. Aby zapisać poziom w nowym pliku należy użyć opcji Zapisz jako.
2a. Projektant poziomów próbuje zapisać mapę niekompletną jako kompletną
2a1. Sprawdzane jest, czy mapa ma odpowiednią wielkość
2a2. Sprawdzana jest możliwość przejścia mapy.
3a. Brak miejsca na dysku lub brak dostępu
3a1. Pojawia się komunikat o błędzie i akcja 3 jest powtarzana.
2.3.11	Problemy

2.3.12	Decyzje

2.4	UC04 – Zapisanie mapy w chmurze
2.4.1	Opis przypadku użycia
Zapisanie stworzonej mapy na chmurze, by móc potem importować ją w grze.
2.4.2	Aktorzy
Projektant Poziomów, Chmura
2.4.3	Poziom
Jeden z trzech poziomów: ogólnego, użytkownika i podfunkcji.
2.4.4	Cel (cel biznesowy osiągany przez ten przypadek użycia)
Zapisanie mapy na chmurze, by udostępnić ją innym.
2.4.5	Cele użytkowników
1.	Projektant poziomów: Możliwość dzielenia się swoimi mapami z innymi.
2.	Projektant poziomów: Bezpieczne przechowywanie kopii mapy.
3.	Gracz: łatwość dostępu do poziomów stworzonych przez innych graczy.
4.	Gracz: zebranie wszystkich poziomów w jednym miejscu.
5.	Gracz: dostęp do poziomów z jednego miejsca.
2.4.6	Warunki początkowe 
Uruchomienie programu.
2.4.7	Częstotliwość wykonania
Kilka razy tygodniowo
2.4.8	Wyzwalacz
Wybranie akcji Zapisz mapę a potem Chmura, w dowolnym momencie podczas przypadku użycia Tworzenie mapy.
2.4.9	Warunki końcowe
Zapisanie mapy w chmurze
2.4.10	Scenariusz główny
1.	Należy zalogować się na konto
2.	W oknie dialogowym należy wpisać nazwę i ewentualnie opis mapy
3.	Można wybrać czy mapa ma być dostępna publicznie w katalogu czy prywatnie, poprzez ID
4.	Po dodaniu mapy nadany jest jej unikalny identyfikator.
2.4.11	Scenariusze alternatywne
1a. Użytkownik wpisał złe dane logowania
1a1. Pojawia się komunikat o wpisaniu złych danych i akcje jest ponawiana
Dalej wszystko zgodnie z głównym scenariuszem
2a. Użytkownik  nie wpisał nazwy
2a1. Pojawia się komunikat o wpisaniu niepoprawnej nazwy i akcja jest ponawiana
Dalej wszystko zgodnie z głównym scenariuszem.

2.4.12	Problemy
2.4.13	Decyzje

2.5	UC05 - Edycja nowego poziomu
2.5.1	Opis przypadku użycia
Uruchomienie edytora w celu stworzenia poziomu gry.
2.5.2	Aktorzy
Projektant Poziomów
2.5.3	Poziom
Jeden z trzech poziomów: ogólnego, użytkownika i podfunkcji.
2.5.4	Cel (cel biznesowy osiągany przez ten przypadek użycia)
Tworzenie nowej mapy
2.5.5	Cele użytkowników
Projektant Poziomów: Tworzenie nowej mapy
Projektant Poziomów: Modyfikacja istniejącej mapy. 
2.5.6	Warunki początkowe 
Uruchomienie edytora.
2.5.7	Warunki końcowe
Decyzja o zakończeniu edycji
2.5.8	Scenariusz główny
1.	Gracz wybiera opcję z menu Stwórz nową mapę.
2.	Gracz tworzy mapę od podstaw używając do tego narzędzi programu.
3.	Gracz zapisuje wprowadzone zmiany. 
4.	Decyzja o zapisaniu stworzonej mapy.

2.5.9	Scenariusze alternatywne
1a. Gracz decyduje się na edycję istniejącej już mapy.
1a1. Uruchomienie edytora w celu edycji istniejącego poziomu gry.
1a2. Wczytanie wybranej mapy do edytora.

2.6	UC06 – Tworzenie motywów 
2.6.1	Opis przypadku użycia
Tworzenie motywów dotyczących tła i wyglądu planszy.
2.6.2	Aktorzy
Projektant Poziomów
2.6.3	Poziom
2.6.4	Cel (cel biznesowy osiągany przez ten przypadek użycia)
Modyfikacja motywów zdefiniowanych przez użytkownika
2.6.5	Cele użytkowników
1.	Projektant poziomów: Możliwość realizacji projektów przy tworzeniu mapy
2.	Projektant poziomów: Swoboda w tworzeniu mapy 
2.6.6	Warunki początkowe 
Uruchomienie edytora
2.6.7	Wyzwalacz
Wybranie akcji Stwórz nowy motyw, w dowolnym momencie podczas przypadku użycia Tworzenie mapy.
2.6.8	Warunki końcowe
Zapisanie poziomu
2.6.9	Scenariusz główny
1.	Wybranie głównego motywu (lokację planszy).
2.	Ustalenie tekstury podłoża i ścianek wczytując je z pliku graficznego.
3.	Zapis motywu
2.6.10	Scenariusze alternatywne
1a.	Wczytanie gotowego motywu do edycji
1a1.	Wybranie akcji wczytaj motyw
1a2.	Wybranie pliku z motywem w eksploratorze
3a.	Użytkownik wycofuje się z akcji.
3a1.	Wybranie akcji anuluj.

2.6.11	Problemy
2.6.12	Decyzje
2.7	UC07 – Wybieranie figur 
2.7.1	Opis przypadku użycia
Wybieranie figur z dostępnych modeli 3D utworzonych w innym programie.
2.7.2	Aktorzy
Projektant Poziomów
2.7.3	Poziom
2.7.4	Cel (cel biznesowy osiągany przez ten przypadek użycia)
Możliwość spersonalizowania mapy przez rozszerzenie interakcji z tworzeniem mapy.
2.7.5	Cele użytkowników
Projektant poziomów: Możliwość dodania do planszy własnych figur do mapy
2.7.6	Warunki początkowe 
Praca nad poziomem
2.7.7	Wyzwalacz
Wybranie opcji Dodaj nowy kształt
2.7.8	Warunki końcowe
Dodanie figury do programu
2.7.9	Scenariusz główny
1.	Wczytanie figury z pliku
2.	Zastąpienie nią istniejącej reprezentacji innej figury
3.	Zapisanie zmian
2.7.10	Scenariusze alternatywne
3a.	Użytkownik wycofuje się z akcji.
3a1.	Wybranie akcji anuluj.

2.7.11	Problemy
2.7.12	Decyzje
3	Wymagania niefunkcjonalne
3.1	Wymagania względem projektu
3.1.1	ID_P01 – Sprawność systemu
Cel: Program nie powinien się zawieszać.
Weryfikowalne wymaganie: szybkość działania
3.1.2	ID_P02 – Dostateczny zasób pamięci
Cel:. Możliwość edycji i tworzenia plików.
Weryfikowalne wymaganie: dostęp do zasobów pamięci
3.1.3	ID_P03 – Minimalizacja awarii
Cel: akceptowalna częstotliwość awarii.
Weryfikowalne wymaganie: Częstotliwość awarii zmniejszona do minimum, przeciwdziałanie czynnościom mającym wpływ na błędy systemu.
3.2	Wymagania organizacyjne
3.2.1	ID_O01 – Spójne środowisko programistyczne
Cel: spójny język oraz metoda programowania środowiska.
Weryfikowalne wymaganie: Wcześniej określone środowisko programistyczne zapewni spójność w metodzie programowania w wypadku potrzeby zatrudnienia większej liczby programistów.
3.2.2	ID_O02 – Dotrzymanie terminu
Cel: Dostarczenie produktu i dokumentacji w terminie.
Weryfikowalne wymaganie:  Pracy nad projektem powinno dobiec końca przed terminem wyznaczonym wraz z klientem. W razie jakichkolwiek opóźnień należy uprzedzić docelową grupę oraz przedstawić plan dostarczenia skończonego projektu w późniejszym terminie.
3.3	Wymagania zewnętrzne
3.3.1	ID_Z01 – Współpraca z platformą
Cel: współpraca z platformą Steam.
Weryfikowalne wymaganie: Docelową platformą udostępniającą grę oraz jej edytor będzie platforma Steam, która zapewnia szeroką skalę klientów.
4	Model dziedziny
[Diagram]
[Opis odpowiedzialności klas obiektów]
5	Problemy i ryzyka
