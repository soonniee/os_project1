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
}Queue;
int process_num;
Queue **Ready_Queue;
void push(Process *p){
    Queue *head = (Queue*)malloc(sizeof(Queue));
    Queue *node =(Queue*)malloc(sizeof(Queue));
    head = Ready_Queue[p->init_q];
    node->process = p;
    node->next = NULL;
    while(head->next!=NULL){
        head = head->next;
    }
    head ->next = node;
    
}
Process** set_process(){
    
    int pid,arr_time,init_q,cycles;
    int size_arr;
    FILE *fp;
    fp = fopen("input.txt","r");
    
    fscanf(fp,"%d",&process_num);
    Process **Process_arr;
    Process_arr = (Process**)malloc(sizeof(Process) * process_num);
    Ready_Queue = (Queue**)malloc(sizeof(Queue)*4);
    for(int k=0;k<4;k++){
            Ready_Queue[k] = (Queue*)malloc(sizeof(Queue));
            Ready_Queue[k]->process = NULL;
            Ready_Queue[k]->next = NULL;
    }
    for(int i=0; i<process_num; i++){
        
        fscanf(fp,"%d %d %d %d",&pid,&arr_time,&init_q,&cycles);
        size_arr = cycles * 2 - 1;
        Process* new_process = (Process*)malloc(sizeof(Process));
        new_process->pid = pid;
        new_process->arr_time = arr_time;
        new_process->init_q = init_q;
        new_process->cycles = cycles;
        
        new_process->arr_burst = (int*)malloc(sizeof(int)*size_arr);
        for(int j=0;j<size_arr;j++){
            int burst_val;
            fscanf(fp,"%d",&burst_val);
            
            new_process->arr_burst[j] = burst_val; 
            
        }
        for(int j=0;j<i;j++){
            if(new_process->arr_time < Process_arr[j]->arr_time){
                Process *temp;
                temp = Process_arr[j];
                Process_arr[j] = new_process;
                Process_arr[j+1] = temp;
            }
        }
        Process_arr[i] = new_process;
        push(Process_arr[i]);
       
    }
    
    
    return Process_arr;
}

int main(){
   Process **Process_arr = set_process();
    // for(int i=0;i<process_num;i++){
    //     printf("%d\n",Process_arr[i]->pid);
    // }
    
    for(int i=0;i<4;i++){
        while(Ready_Queue[i]->next!=NULL){
            
            Ready_Queue[i] = Ready_Queue[i]->next;
            printf("%d\n",Ready_Queue[i]->process->pid);
        }
        
    }
    return 0;
}
void simulator(){
    while(1){
        for(int i=0;i<4;i++){
           while(Ready_Queue[i]->next!=NULL){
            Ready_Queue[i] = Ready_Queue[i]->next;
            printf("%d\n",Ready_Queue[i]->process->pid);
        } 
        }
    }
}