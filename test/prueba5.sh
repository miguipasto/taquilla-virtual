dmesg -c > antiguos.txt
gcc -o  prueba5 prueba5.c
./prueba5
sleep 20
dmesg | grep TQ > prueba5.txt
dmesg | grep TQ+ > prueba5Entrada.txt
dmesg | grep TQ- > prueba5Salida.txt
