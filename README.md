Projekt zrobiony przez Szymona Wójcika.

Napisany w C++ za pomocą narzędzi Qt. Edytowane w Qt Creator.

Projekt zawiera plik wykonywalny cpp_project, który po uruchomieniu powinien uruchomić nowe okno.
W oknie możemy wyróżnić 2 przyciski i 2 obszary z tekstem, które są stosownie opisame. 
Po naciśnięciu przycisku wykonywane jest zapytanie do domeny api-ninjas.com, a zwracany jest stosowny cytat z dodatkowymi informacjami.
Jest opcja przeczytania cytatu za pomocą robotycznego głosu po naciśnięciu prawego przycisku.
Możemy aplikację wyłączyć, albo utworzyć zapytanie o kolejny cytat.

Projekt zdecydowałem się zrobić w QT, gdzie w jednym miejscu posiadam wszystkie konieczne biblioteki.

Działanie pliku wykonywalnego testowane na Linuxie Ubuntu LTS 22.04.2.

Do działania programu wymagany jest klucz do API ze strony https://api-ninjas.com. Następnie odpowiedni klucz należy wpisać do linii 35 w pliku mainwindow.cpp. 
