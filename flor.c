/* Autor: Hernandez Martinez Ricardo
   Universidad Autónoma de la Ciudad de México
   Asignatura: Sistemas Operativos Distribuidos
   Practica procesos (parte 2) */


#include <stdio.h>      // Para usar printf()
#include <stdlib.h>     // Para usar exit()
#include <unistd.h>     // Para usar fork(), getpid(), getppid(), sleep()
#include <sys/wait.h>   // Para usar wait() y macros WIFEXITED(), WEXITSTATUS()

int main(){

    int i, j;          // Variables contador
    int suma = 0;      // Variable acumuladora para sumar el total de procesos
    int status;        // Variable para almacenar el estado de los procesos hijos
    int raiz = getpid(); // Guardamos el PID del proceso raíz original

    printf ("El pid de la raiz es: %d\n", getpid());  //Obtenemos el PID de la raiz

    for(i=0; i<7; i++){    //Genera el tallo con 8 procesos
        if(fork() > 0){ // Si el proceso es padre, termina su ejecución
            break;
        }
        // Si es hijo, continúa y se vuelve padre en la siguiente iteración
    }

    if(i==5 || i==6 || i==7){  //solamente i=5,6,7 entrará a este bloque
        if(fork() == 0){ // El proceso hijo entrará a este bloque
            for(j=0; j<5; j++){  //Aquí se comienza a crear el abanico para los pétalos
                if(fork() == 0){ // Si despues de clonarte eres el hijo entras a este condicional
                    break;       // El pétalo no crea más procesos y sale del ciclo
                }
            }
        }
    }

    sleep(20); //Manda a pausar 20 seg para que se puedan ver con pstree -c

    while(wait(&status) > 0){  //Ciclo que espera a que todos los hijos terminen
        if(WIFEXITED(status)){                   // Verifica que el hijo terminó normalmente
            suma += WEXITSTATUS(status);         // Suma el valor devuelto por exit() del hijo
        }
    }

    suma += 1;  // Se van acumulando los valores de los hijos y suma 1 por el proceso padre/raíz

    if(getpid() == raiz){  //Solo la raíz imprime el conteo de la variable suma
        printf("Total de procesos creados: %d\n", suma);
    }

    exit(suma);   //Termina la ejecución regresando el valor de la suma como salida
}
