# Spur Z Anlage mit Arduino-Steuerung

Wir möchten gerne eine kleine analoge Mini-Club Weihnachtseisenbahn aufbauen, die über den Microcontroller Arduino angesteuert werden soll.

Durch das Bedienen eines Start-Buttons soll eine vordefinierte Szenerie über eine vorprogrammierte Routine abgespielt werden (Zugfahrt + Weichensteuerung, Beleuchtung und evtl. Sound). Der einzig mögliche Bedieneingriff ist die Regelung der Geschwindigkeit während des Abspielens der Routine.

### Gleisplan für unser erstes Projekt (Weihnachtsbahn 2025)

Diese Testbahn hat ein EINFACHES OVAL (36x50cm) ohne Weichen und wird keine Regelung der Geschwindigkeit beinhalten.

![Einfaches Oval](https://github.com/ms-webdev/mini-club-arduino/raw/main/WB25/images/gleisplan-wb25.png)

Die Gleise sollen zwischen den Schwellen mit schwarzen Scharauben (2,3x8mm) auf der Grundplatte verschraubt werden.

#### Benötigte Gleise

- [x] 4x Gerade 8500
- [x] 8x Bogen 8520

#### Taster

Einfacher Arduino-Taster: Dieser dient als Startknopf aber auch als NOT-AUS-Knopf.

### Letzter Entwurf

![Entwurf Weihnachtsbahn 2025](https://github.com/ms-webdev/mini-club-arduino/raw/main/WB25/images/entwurf-wb25-02.jpeg)


### Fahrzeuge

Wir wollen ein Gespann aus Dampflok und wegen den engen Gleisbögen (8520) Wagons mit kurzen Achsabständen verwenden:

#### Dampflok 8895 BR 74 701 DB

Diese Lok kommt mit einem geringen Bogenradius gut zurecht und hat mit einer niedrig angelegten Gleis-Spannung von nur 4 Volt eine harmonische Fahrgeschwindigkeit.

![BR 74 701 DB](https://github.com/ms-webdev/mini-club-arduino/raw/main/WB25/images/fahrzeug-dampflok-br-74-701.jpeg)

#### Unsere Waggons mit geringem Achsabstand

##### Märklin 88662 Säuglings Fürsorge

![BR 74 701 DB](https://github.com/ms-webdev/mini-club-arduino/raw/main/WB25/images/fahrzeug-waggon-88662.jpg)


