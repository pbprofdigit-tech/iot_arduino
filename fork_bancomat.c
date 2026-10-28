#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int numero;

    pid = fork();

    if (pid == 0) {
        // Processo figlio
		sleep(1);
		printf("Luca arriva al primo bancomat\n");
		sleep(1);
		printf("Luca inserisce la carta di credito\n");
		sleep(1);
		printf("Luca scrive il codice\n");
		sleep(1);
		printf("Luca Scrive l'importo di 150 euro\n");
		sleep(1);
		printf("Luca Preleva i contanti\n");
		
    } else {
        // Processo padre
		sleep(1);
		printf("Massimo arriva al primo bancomat\n");
		sleep(1);
		printf("Massimo inserisce la carta di credito\n");
		sleep(1);
		printf("Massimo scrive il codice\n");
		sleep(1);
		printf("Massimo Scrive l'importo di 150 euro\n");
		sleep(1);
		printf("Massimo Preleva i contanti\n");

//        wait(NULL);
    }

    return 0;
}