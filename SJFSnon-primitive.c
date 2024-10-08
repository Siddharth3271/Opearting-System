#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
//SJFS->non primitive
struct process_struct{
    int pid;
    int arrival_time;
    int burst_time;
    int ct,wt,tat,rt,start_time;
}ps[100];
int findmax(int a,int b){
    return a>b?a:b;
}
int findmin(int a,int b){
    return a<b?a:b;
}
int main(){
    int n;
    bool is_completed[100]={false};
    bool is_first_process=true;
    int current_time=0;
    int completed=0;
    printf("Enter the number of processes:");
    scanf("%d",&n);
    int sum_tat=0,sum_wt=0,sum_rt=0,total_idle_time=0,prev=0,length_cycle;
    float cpu_utilization;
    int max_completion_time,min_arrival_time;
    for(int i=0;i<n;i++){
        printf("\nEnter Process %d Arrival Time: ",i);
        scanf("%d",&ps[i].arrival_time);
        ps[i].pid=i;
    }
    for(int i=0;i<n;i++){
        printf("\nEnter Process %d Burst Time: ",i);
        scanf("%d",&ps[i].burst_time);
    }
    while(completed!=n){
        int min_index=-1;
        int minimum=INT_MAX;
        for(int i=0;i<n;i++){
            if(ps[i].arrival_time<=current_time && is_completed[i]==false){
                if(ps[i].burst_time<minimum){
                    minimum=ps[i].burst_time;
                    min_index=i;
                }
                if(ps[i].burst_time==minimum){
                    if(ps[i].arrival_time<ps[min_index].arrival_time){
                        min_index=i;
                        minimum=ps[i].burst_time;
                    }
                }
            }
        }
        if(min_index==-1){
            current_time++;
        }
        else{
            ps[min_index].start_time=current_time;
            ps[min_index].ct=ps[min_index].start_time+ps[min_index].burst_time;
            ps[min_index].tat=ps[min_index].tat-ps[min_index].burst_time;
            ps[min_index].wt=ps[min_index].tat-ps[min_index].burst_time;
            ps[min_index].rt=ps[min_index].wt;

            sum_tat+=ps[min_index].tat;
            sum_wt+=ps[min_index].wt;
            sum_rt+=ps[min_index].rt;
            total_idle_time+=(is_first_process==true)?0:(ps[min_index].start_time-prev);

            completed++;
            is_completed[min_index]=true;
            current_time=ps[min_index].ct;
            prev=current_time;
            is_first_process=false;
        }

    }
    //calculate length of process completion cycle
    max_completion_time=INT_MIN;
    min_arrival_time=INT_MAX;
    for(int i=0;i<n;i++){
        max_completion_time=findmax(max_completion_time,ps[i].ct);
        min_arrival_time=findmin(min_arrival_time,ps[i].arrival_time);
    }
    length_cycle=max_completion_time-min_arrival_time;

    //output
    printf("\nProcess No.\tAT\tCPU Burst Time\tCT\tTAT\tWT\tRT\n");
    for(int i=0;i<n;i++){
        printf("%d\t\t%d\t%d\t\t%d\t%d\t%d\t%d\n",ps[i].pid,ps[i].arrival_time,ps[i].burst_time,ps[i].ct,ps[i].tat,ps[i].wt,ps[i].rt);
    }
    printf("\n");
    cpu_utilization=(float)(length_cycle-total_idle_time)/length_cycle;

    printf("\nAverage Turn Around Time=%f",(float)sum_tat/n);
    printf("\nAverage Waiting Time=%f",(float)sum_wt/n);
    printf("\nAverage Response Time=%f",(float)sum_rt/n);
    printf("\nCPU Utilization(Percentage)=%f\n",cpu_utilization*100);
    printf("\nThroughput=%f",n/(float)length_cycle);
    return 0;
}