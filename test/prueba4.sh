dmesg -c > antiguos.txt
gcc -o  prueba4 prueba4.c
sh compilar.sh
./prueba4
sleep 22
dmesg | grep TQ > prueba4.txt
dmesg | grep TQ+ > prueba4Entrada.txt
dmesg | grep TQ- > prueba4Salida.txt
