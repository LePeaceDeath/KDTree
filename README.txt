Autor:  Yahor Letniakou  Kraków 15.01.2022 
-------------------------------------------
KDTree
-------

Zawartość:
----------

Katalog zawiera 1 program w języku C++:

1. Program wczytuje ze standartowego wejścia dane wygenerowane przez program Generator.cpp lub z pliku in.txt. Wczytane dane dodają się do
bazy. Program szuka najbliższy punkt spośród znajdujących się w bazie dla wskazanego punktu, według metryki Euklidesa.
	Program składa się z trzech modułów:
		1) Generator.cpp - program generator
		2) KDTree.hpp - implementacja drzewa
		3) KDTree.cpp - program głowny


------------------------------------------------------------------------------------------------------------------------------------------------------------------

Jak uruchomić program:
-----------------------

Katalog zawiera program Makefile do kompilacji, linkowania i uruchamiania powyzszych programów, oraz do czyszczenia katalogu

Żeby skompilować wszystkie programy należy wprowadzić:
	make all

Żeby uruchomić program należy wprowadzić:
	make run

Żeby posprzątać należy wporwadzić:
	make clean