# SmartStudent – Maintainable Version with External Data

## Struktur

```
include/   # header (.h)
src/       # source (.cpp) + main.cpp
data/      # data files (akun, buku, rute)
```

## Kompilasi

### Windows

```cmd
g++ -std=c++17 -Iinclude src/*.cpp -o smartstudent.exe
./smartstudent.exe
```

### Linux / WSL

```bash
g++ -std=c++17 -Iinclude src/*.cpp -o smartstudent
./smartstudent
```
