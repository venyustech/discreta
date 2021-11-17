#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <semaphore.h>
#include <time.h>
#include <sys/shm.h>
#include <stdio.h>

typedef struct dados{ //Estrutura de dados a ser armazenada 
    time_t  tempo; 
    clock_t tempoCPU; 
}Dados;

sem_t  S;                      //Semaforo S. 
sem_t  mutex;					  //Semaforo mutex.

int N = 0;

struct dados buff; 

//Funcao para thread Leitor
void    *threadLeitor(void *arg){
	int timeSleep = *(int*) arg;
	time_t  tempo; 
    clock_t tempoCPU;
	while(1){
		sem_wait(&mutex); //Down em mutex
		if(N==0){ //Primeiro leitor
			sem_wait(&S);
			N=N+1;
		}
		else if(N>0){
			N=N+1;
		}
		sem_post(&mutex);  //Up em mutex
		tempo=buff.tempo;      //Realizando leitura     
        tempoCPU=buff.tempoCPU ;   
        printf("\n \t O Leitor leu \n Tempo %ld Tempo de cpu %ld \n ",tempo, tempoCPU);  
        sem_wait(&mutex);
        N=N-1;
        if(N==0){
        	sem_post(&S);
		}
		sem_post(&mutex);
		sleep(timeSleep);
	} 
}



int main (void){
	pthread_t   endereco_thread_Leitor1, endereco_thread_Leitor2, endereco_thread_Leitor3;
	void *resp_thread;
	int res;
	int s1, s2;
	
	//Criacao do semaforo: sem_init(endereco do semaforo, tipo de compartilhamento, valor inicial).
    //-- tipo de compartilhamento: 0 - Threads compartilham; !=0 - Apenas processos compartilham.
    s1 = sem_init(&S, 0, 1);   //Inicializacao do semaforo.
    if (s1 != 0) {
        perror("\tFalha na Inicializacao do semaforo itens.");
        exit(EXIT_FAILURE);
    }
    s2 = sem_init(&mutex, 0, 1);   //Inicializacao do semaforo.
    if (s2 != 0) {
        perror("\tFalha na Inicializacao do semaforo vagas.");
        exit(EXIT_FAILURE);
    }
    
    //Criacao da Thread Leitor 1
	int sleeptime =3;
    res = pthread_create(&endereco_thread_Leitor1, NULL, threadLeitor, &sleeptime);
    if (res != 0) {
        perror("\tFalha na criacao da thread consumidor.\n");
        exit(EXIT_FAILURE);
    }
    //Criacao da Thread Leitor 2
	int sleeptime2 =5;
    res = pthread_create(&endereco_thread_Leitor2, NULL, threadLeitor, &sleeptime2);
    if (res != 0) {
        perror("\tFalha na criacao da thread consumidor.\n");
        exit(EXIT_FAILURE);
    }
    //Criacao da Thread Leitor 3
	int sleeptime3 =7;
    res = pthread_create(&endereco_thread_Leitor3, NULL, threadLeitor, &sleeptime3);
    if (res != 0) {
        perror("\tFalha na criacao da thread consumidor.\n");
        exit(EXIT_FAILURE);
    }
    
	
	
	//Codigo do Escritor
	while(1){
		time_t  tempo; 
    	clock_t tempoCPU;
		tempo = time((time_t *) 0); 
        tempoCPU= clock(); 
        sem_wait(&S); //Down em S
        buff.tempo = tempo;           
        buff.tempoCPU = tempoCPU;       
        printf("\t O Escritor escreveu \n Tempo %ld Tempo de cpu %ld \n ", buff.tempo, buff.tempoCPU); 
        sem_post(&S);
        sleep(9);  
	}
	

	
    exit(EXIT_SUCCESS); 
}

