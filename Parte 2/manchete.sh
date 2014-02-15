clear
bison -v -d -o ranger.c jaspion.y
flex -v -t jaspion.l > jiraya.c
gcc ranger.c jiraya.c -o jaspion
