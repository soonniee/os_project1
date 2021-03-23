#include <stdio.h>
#include <stdlib.h>
typedef struct Process{
    int pid;
    int arr_time;
    int init_q;
    int cycles;
    int* arr_burst;
} Process;
typedef struct Queue{
    struct Queue* next;
    Process* process;
}
int process_num;
Process* set_process(){
    
    int pid,arr_time,init_q,cycles;
    int size_arr;
    FILE *fp;
    fp = fopen("input.txt","r");
    
    fscanf(fp,"%d",&process_num);
    Process *Process_arr;
    Process_arr = (Process*)malloc(sizeof(Process)*process_num);
    for(int i=0; i<process_num; i++){
        
        fscanf(fp,"%d %d %d %d",&pid,&arr_time,&init_q,&cycles);
        size_arr = cycles * 2 - 1;
        
        Process_arr[i].pid = pid;
        Process_arr[i].arr_time = arr_time;
        Process_arr[i].init_q = init_q;
        Process_arr[i].cycles = cycles;
        Process_arr[i].arr_burst = (int*)malloc(sizeof(int)*size_arr);
        
        for(int j=0;j<size_arr;j++){
            int burst_val;
            fscanf(fp,"%d",&burst_val);
            
            Process_arr[i].arr_burst[j] = burst_val; 
            
        }
        Queue *Ready_Queue;
        Ready_Queue = (Queue*)malloc(sizeof(Queue)*4);
        for(int k=0;k<4;k++){
            Ready_Queue[k].process = NULL;
            Ready_Queue[k]->next = NULL;
        }
        switch(init_q){
            case 0:
                if(Ready_Queue[i] != NULL) {
                    Ready_Queue[i].process = Process_arr;
                    Ready_Queue[i] -> next = 
                }
            case 1:
            case 2:
            case 3:
            default:
                break;
        }
    }
    
    
    return Process_arr;
}
int main(){
   Process* Process_arr = set_process();
    for(int i=0;i<process_num;i++){
        printf("%d\n",Process_arr[i].cycles);
    }
    return 0;
}