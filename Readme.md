# Projekt Alpha

## Projekt bauen

* Verschaffen Sie sich als Erstes eine Kopie von diesem Repository mit diesem Befehl:

```
https://gitlab.informatik.uni-bonn.de/poose_locke_musa_wirtz/projektalpha.git
```
* Wechseln Sie in folgendes Projektverzeichnis:

```
cd ProjektAlpha
```

* Um das Projekt zu bauen, muss einer der folgenden Befehlsketten im Projektverzeichnis ausgeführt werden.
```
cmake -S . -B build && cmake --build build
```
Auf den Rechnern der CIP Pools ist der Aufruf leider ein wenig länger
```
export PROJ_PATH=`pwd` && cmake -S $PROJ_PATH -B $PROJ_PATH/build && cmake --build $PROJ_PATH/build
```
Falls das Projekt so nicht baut, liegen entweder Implementierungsfehler vor oder es fehlen externe Softwarepakete.

## Verwendung

Benutzen Sie 
```cpp 
#include <../src/Datenstruktur.cpp>
```
, um die gewünschte Datenstruktur verwenden zu können.

Auf die Handhabung der einzelnen Datenstrukturen wird in der [Wiki](https://gitlab.informatik.uni-bonn.de/poose_locke_musa_wirtz/projektalpha/-/wikis/ProjektAlpha) genauer eingegangen.
