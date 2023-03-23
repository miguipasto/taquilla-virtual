dmesg -c > antiguos.txt
gcc -o  prueba2 prueba2.c
sh compilar.sh
gcc -o pagos pagos5.c
./prueba2
sleep 15
dmesg | grep TQ > prueba2.txt
dmesg | grep TQ+ > prueba2Entrada.txt
dmesg | grep TQ- > prueba2Salida.txt
