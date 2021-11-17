#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <semaphore.h>
#include <time.h>
#include <sys/shm.h>
#include <stdio.h>

#define VAGAS 5

struct dados{
    time_t  tempo;
    clock_t tempoCPU;
    pid_t PID;
};

sem_t  itens;                      //Semaforo itens. 
sem_t  vagas;                      //Semaforo vagas. 
sem_t  mutex;					  //Semaforo mutex.
int N =0;

struct dados buff[VAGAS]; 

//Funcao para imprimir o buffer
void imprimeuff(void){
	int i;
	printf("\t\t Buffer \n");
	for(i=0; i<N; i++){
		printf("\t Tempo %ld Tempo de cpu %ld PID %d \n ",buff[i].tempo, buff[i].tempoCPU, buff[i].PID);
	}
}
//Funcao para thread consumidor
void    *threadConsumidor(void *arg){
	while(1){
		sem_wait(&itens);    //Operacao equivalente a um DOWN no semaforo (no caso, 'itens').
		//printf("\t down em itens\n");
		sem_wait(&mutex);
		printf("\tItem removido\t  Tempo %ld Tempo de cpu %ld PID %d \n ",buff[N-1].tempo, buff[N-1].tempoCPU, buff[N-1].PID);
		N=N-1; //Decrementa o tamanho do vetor; */
		sem_post(&vagas);            //Operacao equivalente a um UP no semaforo (no caso, 'vagas').
		sem_post(&mutex);
		sleep(5);
	} 
}

int main(void){
	pthread_t   endereco_thread_consumidor;
	void *resp_thread;
	int res;
	int s1, s2,s3;
	
    //Criacao do semaforo: sem_init(endereco do semaforo, tipo de compartilhamento, valor inicial).
    //-- tipo de compartilhamento: 0 - Threads compartilham; !=0 - Apenas processos compartilham.
    s1 = sem_init(&itens, 0, 0);   //Inicializacao do semaforo.
    if (s1 != 0) {
        perror("\tFalha na Inicializacao do semaforo itens.");
        exit(EXIT_FAILURE);
    }
    s2 = sem_init(&vagas, 0, 5);   //Inicializacao do semaforo.
    if (s2 != 0) {
        perror("\tFalha na Inicializacao do semaforo vagas.");
        exit(EXIT_FAILURE);
    }
    s3 = sem_init(&mutex, 0, 1);   //Inicializacao do semaforo.
    if (s3 != 0) {
        perror("\tFalha na Inicializacao do semaforo mutex.");
        exit(EXIT_FAILURE);
    }
    
    //Criacao da Thread Consumidor
    res = pthread_create(&endereco_thread_consumidor, NULL, threadConsumidor, NULL);
    if (res != 0) {
        perror("\tFalha na criacao da thread consumidor.\n");
        exit(EXIT_FAILURE);
    }
    
    //Codigo Produtor 
	while(1){
    	sem_wait(&vagas);    //Operacao equivalente a um DOWN no semaforo (no caso, 'itens').
		//printf("\t down em vagas\n");
		sem_wait(&mutex);
		//printf("\t down em mutex\n");
		buff[N].tempo= time((time_t *) 0);
		buff[N].tempoCPU = clock(); 
		buff[N].PID = getpid();
		printf("\tItem adcionado\t  Tempo %ld Tempo de cpu %ld PID %d \n ",buff[N].tempo, buff[N].tempoCPU, buff[N].PID); 
		N=N+1;
		imprimeuff();
		sem_post(&itens);            //Operacao equivalente a um UP no semaforo (no caso, 'itens').
		//printf("\t up em itens\n");
		sem_post(&mutex);
		sleep(1); 
	}
	printf("\tProdutor --> Esperando pelo termino da thread Consumidor!\n");
    res = pthread_join(endereco_thread_consumidor, &resp_thread);
    if (res != 0) {
        perror("\tFalha na juncao das threads.\n");
        exit(EXIT_FAILURE);
    }   
    printf("\tProdutor --> A Thread foi finalizada.\n");
    exit(EXIT_SUCCESS); 	
}
