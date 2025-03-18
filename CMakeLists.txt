cmake_minimum_required(VERSION 3.10)
project(labo1CC)

add_executable(philo philo.c)
target_compile_options(philo PRIVATE -pthread -Wall)

add_executable(philo2 philo2.c)
target_compile_options(philo2 PRIVATE -pthread -Wall)