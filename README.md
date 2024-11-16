# HazrdLib

[![wakatime](https://wakatime.com/badge/github/Skelebyte/HazrdLib.svg)](https://wakatime.com/badge/github/Skelebyte/HazrdLib)

### Compiling with SDL2 (gcc (cc), g++)
```sh
gcc main.c -w -lSDL2 -o program
```

### Compiling  with GLFW (gcc (cc), g++)
```sh
gcc main.c -lglfw -o program
```


#### makefile
```makefile
main: main.o
	cc main.o -o main -lglfw

main.o: main.c
	cc -c main.c -o main.o

main.c:
	echo "int main() { return 0; }" > main.c

```
`main.c:` gets called only if `main.c` doesn't exist.

`main.o: main.c` depends on `main.c`, so if it doesn't exist then `main.c:` gets called.

`main: main.o` depends on `main.o`, so if `main.o` is changed or not there, it calls `main.o: main.c`.
