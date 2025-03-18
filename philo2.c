#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define Num_philo 5
typedef struct philo_resources
{
    pthread_mutex_t lock[Num_philo];
    volatile int count;
    pthread_cond_t varcond;

} philo_resources_t;

philo_resources_t philo_res;



void think(){
    sleep(1);
}

void pick_right_stick(int i){
    if(pthread_mutex_lock(&philo_res.lock[i])){
        printf("Problem with locking mutex %d.\n", i);
    }
    while(philo_res.count >= Num_philo-2){
        pthread_cond_wait(&philo_res.varcond, &philo_res.lock[i]); 
    }
    philo_res.count++;
}

void pick_left_stick(int i){
    if(pthread_mutex_lock(&philo_res.lock[i])){
        printf("Problem with locking mutex %d.\n", i);
    }
    while(philo_res.count >= Num_philo-1){
        pthread_cond_wait(&philo_res.varcond, &philo_res.lock[i]); 
    }
    philo_res.count++;
}

void eat(int i){
    printf("Philo %d is eating.\n", i);
    //sleep(3);
    philo_res.count -= 2;
    pthread_cond_signal(&philo_res.varcond);
    pthread_cond_signal(&philo_res.varcond);
    if(pthread_mutex_unlock(&philo_res.lock[i])){
        printf("Problem with unlocking mutex %d.\n", i);
    }
    if(pthread_mutex_unlock(&philo_res.lock[i ==0 ? Num_philo - 1 : i-1])){
        printf("Problem with unlocking mutex %d.\n", i);
    }

}



void *philo_life(void *ptr){
    int i = *((int *) ptr);
    think();
    pick_right_stick(i);
    printf("Philo %d has his right stick.\n",i);

    pick_left_stick(i ==0 ? Num_philo - 1 : i-1);
    printf("Philo %d has his left stick.\n",i);

    eat(i);
    return NULL;
}

int main(){
    pthread_t philo[Num_philo];

    philo_res.count = 1;
    pthread_cond_init(&philo_res.varcond, NULL);

    for (size_t i = 0; i < Num_philo; i++)
    {
        pthread_mutex_init(&philo_res.lock[i], NULL);
    }
    int id[Num_philo];
    for (size_t j = 0; j < Num_philo*10; j++)
    {
        for (size_t i = 0; i < Num_philo; i++)
        {
            id[i] = i;
            pthread_create(&philo[i],NULL,philo_life,&id[i]);
        }
      
        for (size_t i = 0; i < Num_philo; i++)
        {
            pthread_join(philo[i],NULL);
        }
        printf("Fine giro %ld.\n", j);
    }
    

  printf("Programma finito.\n");
  return 0;
}
