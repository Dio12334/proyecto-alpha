#!/usr/bin/env bash

if [ $# -eq 0 ]; then
    clear
    echo -e "ERROR Falto los nombres de los folders"
    echo -e "Formato: ./run.sh <Folder Primer Jugador> <Folder Segundo Jugador>"
    echo -e "Ejemplo: ./run.sh /home/user/first /home/user/second"
    exit 1
elif [ $# -eq 1 ]; then
    clear
    echo -e "ERROR Falto el nombre del folder del segundo jugador"
    echo -e "Formato: ./run.sh <Folder Primer Jugador> <Folder Segundo Jugador>"
    echo -e "Ejemplo: ./run.sh /home/user/first /home/user/second"
    exit 1
fi

docker run --rm -v $1:/home/first -v $2:/home/second -i -t utec-poo2 /bin/bash

