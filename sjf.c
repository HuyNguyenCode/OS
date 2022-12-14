#include <stdio.h>
#include <math.h>

struct PCB {
    int pn,arr_t, burst_t, tat_time, waitting_t;
};

int main() {

    struct PCB p[10], temp;
    int n;

	printf("Enter the number of processes:");
	scanf("%d",&n);

    for(int i=0; i < n ; i++) {
		printf("Enter the Process Name, Arrival Time & Burst Time:");
		scanf("%d%d%d",&p[i].pn,&p[i].arr_t,&p[i].burst_t);
    }
    

/*Sorting According to Arrival Time*/
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(p[i].arr_t < p[j].arr_t) {
                temp = p[j];
                p[j] = p[i];
                p[i] = temp;
            }
        }
    }

/*Sỏting According to Burst 
*/
int i,j;
    int k = 1, burst_time = 0;
    for(j = 0; j < n; j++)
    {
        burst_time += p[j].burst_t;
        int min = p[k].burst_t;
        for(i = k; i < n; i++)
        {
            if (burst_time >= p[i].arr_t && p[i].burst_t < min)
            {
                temp = p[k];
                p[k] = p[i];
                p[i] = temp;
            }
        }
        k+=1;
    }

//Calculate  waiting time 
    float total_w = 0, sum_waiting = 0, average_w = 0;
    p[0].waitting_t = 0;
    for(i = 1; i < n; i++)
    {
        sum_waiting += p[i-1].burst_t;
        p[i].waitting_t = sum_waiting - p[i].arr_t;
        total_w += p[i].waitting_t;
    }
    average_w = (total_w/n);

//Calculate  turnarround time 
    int sum_tat = 0;
    float average_tat = 0, total_tat = 0;
    for(i = 0; i < n; i++)
    {
        sum_tat += p[i].burst_t;
        p[i].tat_time = sum_tat - p[i].arr_t;
        total_tat = total_tat + p[i].tat_time;
    }
    average_tat = (total_tat/n);


    printf("\nProcess\t Burst-Time\t Arrival-Time\t Waiting-Time\t Turnaround-Time" );
    for(i = 0; i < n; i++)
    {
        printf("\n p%d\t %d\t\t %d\t\t %d\t\t\t%d",p[i].pn,p[i].burst_t,p[i].arr_t,p[i].waitting_t,p[i].tat_time);
    }
    
    printf("\n\nAVERAGE WAITING TIME : %f",average_w);
    printf("\nAVERAGE TURN AROUND TIME : %f",average_tat);
    printf("\n");
}