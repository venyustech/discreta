#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
int main(void)
{
    srand(((unsigned)time(NULL)) + getpid());

    int alea1 = rand();
    int alea2 = rand();
    int alea3 = (rand()%6669);

    printf("alea1:%d\n",alea1);
    printf("alea2:%d\n",alea2);
    printf("alea3:%d\n",alea3);

    return EXIT_SUCCESS;
}
