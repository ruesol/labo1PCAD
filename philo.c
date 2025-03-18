#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define Num_philo  5
pthread_mutex_t lock[Num_philo];



void think(){
    sleep(5);
}

void pick_right_stick(int i){
    if(pthread_mutex_lock(&lock[i])){
        printf("Problem with locking mutex %d.\n", i);
    }
}

void pick_left_stick(int i){
    if(pthread_mutex_lock(&lock[i])){
        printf("Problem with locking mutex %d.\n", i);

    }
}

void eat(int i){
    printf("Philo %d is eating.\n", i);
    //sleep(3);
    if(pthread_mutex_unlock(&lock[i])){
        printf("Problem with unlocking mutex %d.\n", i);

    }
    if(pthread_mutex_unlock(&lock[i ==0 ? Num_philo - 1 : i-1])){
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
  for (size_t i = 0; i < Num_philo; i++)
    {
        pthread_mutex_init(&lock[i], NULL);
    }
    int id[Num_philo];
  for (size_t i = 0; i < Num_philo; i++)
  {
    id[i] = i;
    pthread_create(&philo[i],NULL,philo_life,&id[i]);
  }
  
  for (size_t i = 0; i < Num_philo; i++)
  {
    pthread_join(philo[i],NULL);
  }
  printf("Programma finito.\n");
  return 0;
}
