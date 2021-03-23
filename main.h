#ifndef __MAIN_H
#define __MAIN_H
#include <stdio.h>
#include <stdlib.h>
typedef struct Process{
    int pid;
    int arr_time;
    int init_q;
    int cycles;
    int* arr_burst;
} Process;
#endif