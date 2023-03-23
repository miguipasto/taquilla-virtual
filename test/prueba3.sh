dmesg -c > antiguos.txt
sh compilar.sh
gcc -o mantenimiento mantenimientoError.c
./mantenimiento
sleep 15
dmesg | grep TQ > prueba3.txt
dmesg | grep TQ+ > prueba3Entrada.txt
dmesg | grep TQ- > prueba3Salida.txt
