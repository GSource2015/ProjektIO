<b>EDYTOR DO GRY</b>


<b>TWISTED MIND</b>


<b>A. Project Page.</b>


Michał Krawczyk, 690 002 610, michal7650@gmail.com


Katarzyna Łęcka, 883 778 663, k_lecka94@vp.pl


Edytor poziomów do gry logicznej typu skasuj 3 takie same elementy. Oferuje możliwość tworzenia poziomów od podstaw, a także edycji już istniejących. Edytor będzie w formie graficznej. Możliwość zapisywania i pobierania poziomów z chmury, zarówno o dostępie publicznym i prywatnym (łatwość dzielenia się poziomami ze społecznością graczy jak i innych projektantów). Edytor sam w sobie będzie narzędziem używanym także przez projektantów poziomów z których składać się będzie zespół tworzący grę. Edytor dlatego powinien być dostępny trochę wcześniej niż sama gra.
Gra logiczna typu skasuj 3 takie same elementy. Możliwość tworzenia własnych poziomów, edytor jest dołączany do gry. Kolejnym wyróżnikiem gry jest możliwość odblokowywania ulepszeń za zdobyte punkty, które będą ułatwiały rozrywkę dla znacznie trudniejszych poziomów (drzewko rozwoju, ale nie da się wybrać wszystkiego)

Marketing dotyczy jedynie samej gry, a nie edytora. Edytor jest pewnym narzędziem, które jest chwytem marketingowym, mającym na celu przyciągnięcie większej ilości graczy. Ponadto edytor ma na celu zmniejszenie monotonności w grze. Gra ma być wydana w postaci cyfrowej: Early Access na platformie Steam. Do tego celu wymagane jest pewne zainteresowanie wokół gry już na fazie produkcji. Planowane jest wydanie dema prezentującego grę wraz z naszym kandydowaniem gry do Steam Green Light, czyli platformy, gdzie gracze głosują na grę, czy ta ma wejść do Early Access czy nie. Demo rozesłane będzie do portali zajmujących się grami a także na forum do publicznego użytku dla graczy, którzy zechcą w grę zagrać.

Demo będzie zawierało 2 poziomy i bardzo ograniczone drzewko rozwoju, tak by gracz tylko mógł zobaczyć co go czeka i nieco wypróbować te mechanizmy. Ma to na celu wzbudzenie ciekawości jak i niedosytu w graczu. Wraz z demem zrobione będą zrzuty ekranu poziomów, które dostępne będą w pełnej wersji gry, a także prezentujące niektóre umiejętności, które będzie można odblokowywać.

Ponadto będzie trzeba nakręcić parę filmów prezentujących samą rozgrywkę, odpowiednio zmontowanych by nie zanudzić oglądającego (wiadomo, nie można oczekiwać nie wiadomo jakiego dynamizmu od gry logicznej), a także prezentującego nasz edytor (w tej fazie powinien być już prawie skończony, jednak nie musi być całkowicie gdyż zostanie dopiero dołączony do gry wydanej przez Early Access).


<b>B. Informacje wewnątrzprojektowe:</b>


<b>Interesariusze:</b>


Społeczność graczy


Platforma Steam


Manager grupy projektującej grę (a nie edytor)


Programiści tworzący grę


Dyrektor firmy


1. Opracowanie głównego planu projektu


2. Stworzenie Use Cases I User Stories


<b>USER STORIES dla edytora:</b>

Jako projektant map chcę mieć możliwość wczytywania już stworzonych map, by je później przerabiać lub zmieniać.


Jako projektant map chcę mieć wizualizację w trybie rzeczywistym tworzonej mapy, by lepiej widzieć co robię.


Jako projektant map chcę mieć miejsce publiczne w którym mogę przechowywać stworzone przeze mnie mapy by dzielić się nimi ze społecznością graczy.


Jako projektant map chcę mieć możliwość graficznego tworzenia poziomu, by móc go tworzyć szybciej i intuicyjnie.


Jako gracz chcę mieć możliwość darmowego dostępu do map stworzonych przez innych graczy by móc w nie grać.


Jako gracz chciałbym mieć możliwość zapisywania map innych twórców na dysku, by możliwe było używanie ich bez dostępu do Internetu.












<b>Architektura:</b>


<b>Rozwiązania architektoniczne:</b>

Gra wydana na Windows, ponieważ jest to najszerzej dostępna dla nas grupa docelowa: większość graczy używa Windows. W przyszłości niewykluczony port na Linux.

Silnik gry tworzony w OpenGL w C++, ponieważ grupa ma w tym środowisku największe doświadczenie, a także cechuje się on szybkością działania (a przenośność nie jest aż tak kluczowym aspektem w 1 fazie projektu)

Edytor tworzony w wxWidgets w C++, ponieważ jest to niezawodna i łatwa w użyciu biblioteka, a także wieloplatformowa.
