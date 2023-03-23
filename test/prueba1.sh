dmesg -c > antiguos.txt
gcc -o  prueba1 prueba1.c
sh compilar.sh
./prueba1
sleep 18
dmesg | grep TQ > prueba1.txt
dmesg | grep TQ+ > prueba1Entrada.txt
dmesg | grep TQ- > prueba1Salida.txt
