# LabSimulator — Wirtualne Laboratorium Automatyki

![C++](https://img.shields.io/badge/C%2B%2B-17%2F20-blue.svg)
![Qt](https://img.shields.io/badge/Qt-6.8-green.svg)
![MSVC](https://img.shields.io/badge/Compiler-MSVC%202022%2F2026-orange.svg)
![Status](https://img.shields.io/badge/Status-In%20Development-yellow.svg)

Symulacyjne środowisko wirtualnych stanowisk laboratoryjnych do nauki i testowania algorytmów sterowania analogowego.

---

## Funkcjonalności

### Symulacja obiektów
- Silniki DC
- Transmitancje rzędu 2 i 3

### Algorytmy sterowania
- PID z mechanizmem anti-windup
- LQR (Linear Quadratic Regulator)
- Przekaźniki z histerezą

### Interfejs użytkownika
- Interaktywne okablowanie bloków funkcjonalnych
- Wirtualny oscyloskop dwukanałowy
- Automatyczny eksport przebiegów do plików `.csv`

---

## Struktura projektu

```
LabSimulator/
├── src/        # Implementacja logiki i GUI
├── include/    # Pliki nagłówkowe
├── ui/         # Pliki interfejsu Qt Designer
└── data/       # Wyniki symulacji (CSV) dla poszczególnych zadań
```

---

## Uruchomienie

**Wymagania:** Qt 6.8, MSVC 2022 lub 2026, Qt Creator

1. Otwórz projekt w **Qt Creator**.
2. Wybierz kit **Desktop Qt 6.8.3 MSVC2022 64bit**.
3. Skompiluj i uruchom: `Ctrl+R`.

---

*Autor: Szymon Wójcik - Praca Inżynierska 2026*