# Wheeled_robot-2-0-
Wheeled_robot
Projekt robota kołowego linefollower.

Wymagania funkcjonalne:

Robot potrafi samodzielnie odszukać trasę.
Robot porusza się po trasie oznaczonej linią na podłożu.

Warstwa sprzętowa:

Sterownik: Raspberry Pi 3 B+.\n
Napęd: dwa Silnik z przekładnią SJ01 120:1 6V 160RPM + enkoder
Sterowane za pomocą mostka H w postaci układu L293D.
Pomiar prędkości: 2 enkodery 16 impulsów na obrót (po przełożeniu 1920 impulsów na obrót).
Wykrywanie trasy: Moduł z czujnikiem śledzenia linii TCRT5000L.
Wykrywanie przeszkód: ultradźwiękowy czujnik odległości HC - SR05.
Oprogramowanie:

Sterowanie robota będzie wykonywanie w oparciu o Raspberry Pi 3 B+ z systemem operacyjnym Linux Raspbian. Oprogramowanie sterujące napisane w języku C++, z wykorzystaniem biblioteki WiringPi (http://wiringpi.com/).

Narzędzia:

kompilator GCC,
IDE Visual Studio Code.
