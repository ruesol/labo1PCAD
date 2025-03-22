#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define Num_philo 5

typedef enum { THINKING, HAS_LEFT_STICK, HAS_RIGHT_STICK, EATING, WAITING } philo_state_t;

typedef struct philo_resources
{
    pthread_mutex_t lock_on_stick[Num_philo];
    pthread_mutex_t lock_on_res;
    volatile unsigned int stick[Num_philo]; // 0 = free, 1 = taken
    pthread_cond_t varcond;
    philo_state_t state[Num_philo];
} philo_resources_t;

philo_resources_t philo_res;

void print_philo_states() {
    /*
    pthread_mutex_lock(&philo_res.lock_on_res);
    printf("Current state of the philosophers:\n");
    for (int i = 0; i < Num_philo; i++) {
        switch (philo_res.state[i]) {
            case THINKING:
                printf("Philo %d is thinking.\n", i);
                break;
            case HAS_LEFT_STICK:
                printf("Philo %d has left stick.\n", i);
                break;
            case HAS_RIGHT_STICK:
                printf("Philo %d has right stick.\n", i);
                break;
            case EATING:
                printf("Philo %d is eating.\n", i);
                break;
            case WAITING:
                printf("Philo %d is waiting.\n", i);
                break;
            default:
                printf("Philo %d is in an unknown state.\n", i);
                break;
        }
    }
    printf("\n");
    pthread_mutex_unlock(&philo_res.lock_on_res);
    */
}

void think(){
    usleep(100);
}
void pick_stick(int i, int philo_index, int has_already_one_stick) {
    pthread_mutex_lock(&philo_res.lock_on_res);
 /*
    while (philo_res.stick[i] == 1) {
        philo_res.state[philo_index] = WAITING;
        pthread_cond_wait(&philo_res.varcond, &philo_res.lock_on_res);
    }
*/
    if (philo_res.stick[i] == 1) {
        philo_res.state[philo_index] = WAITING;
        pthread_mutex_unlock(&philo_res.lock_on_res);
        return;
    }
    philo_res.stick[i] = 1;
    pthread_mutex_lock(&philo_res.lock_on_stick[i]);
    if (has_already_one_stick) {
        philo_res.state[philo_index] = HAS_RIGHT_STICK;
    } else {
        philo_res.state[philo_index] = HAS_LEFT_STICK;
    }

    pthread_mutex_unlock(&philo_res.lock_on_res);
}

void eat(int i) {
    pthread_mutex_lock(&philo_res.lock_on_res);
    philo_res.state[i] = EATING;

    pthread_mutex_unlock(&philo_res.lock_on_res);
    print_philo_states();
    pthread_mutex_lock(&philo_res.lock_on_res);

    usleep(500);

    if (pthread_mutex_unlock(&philo_res.lock_on_stick[i])) {
        printf("Problem with unlocking mutex %d.\n", i);
    }
    philo_res.stick[i] = 0;
    if (pthread_mutex_unlock(&philo_res.lock_on_stick[i == 0 ? Num_philo - 1 : i - 1])) {
        printf("Problem with unlocking mutex %d.\n", i);
    }
    philo_res.stick[i == 0 ? Num_philo - 1 : i - 1] = 0;
    philo_res.state[i] = THINKING;
    pthread_mutex_unlock(&philo_res.lock_on_res);
    pthread_cond_signal(&philo_res.varcond);
}

void *philo_life(void *ptr) {
    int i = *((int *)ptr);
    think();

    int left_stick = i == 0 ? Num_philo - 1 : i - 1;
    int right_stick = i;
    int has_left_stick = 0;
    int has_right_stick = 0;

    while (!has_left_stick || !has_right_stick) {
        if (!has_left_stick) {
            pick_stick(left_stick, i, has_right_stick);
            has_left_stick = 1;
        } else if (!has_right_stick) {
            pick_stick(right_stick, i, has_left_stick);
            has_right_stick = 1;
        }
    }
    print_philo_states();

    eat(i);
    return NULL;
}

int main(){
    pthread_t philo[Num_philo];

    pthread_cond_init(&philo_res.varcond, NULL);
    pthread_mutex_init(&philo_res.lock_on_res, NULL);

    for (size_t i = 0; i < Num_philo; i++) {
        pthread_mutex_init(&philo_res.lock_on_stick[i], NULL);
        philo_res.state[i] = THINKING;
        philo_res.stick[i] = 0;
    }
    int id[Num_philo];
    for (size_t j = 0; j < Num_philo * 200; j++) {
        for (size_t i = 0; i < Num_philo; i++) {
            id[i] = i;
            pthread_create(&philo[i], NULL, philo_life, &id[i]);
        }

        for (size_t i = 0; i < Num_philo; i++) {
            pthread_join(philo[i], NULL);
        }
        printf("Fine giro %ld.\n", j);
    }

    printf("Programma finito.\n");
    return 0;
}
