#include<stdio.h>
struct process{
	int pid;
	int burst;
	int wt;
	int tat;
};
void calculateTimes(struct process p[],int n){
	int total_waiting=0;
	int total_turnAround=0;
	p[0].wt=0;
	p[0].tat=p[0].burst;
	for(int i=1;i<n;i++){
		p[i].wt=p[i-1].wt+p[i-1].burst;
		p[i].tat=p[i].wt+p[i].burst;
	}
}
void display(struct process p[],int n){
	printf("Process Id\tBurst Time\tWaiting Time\tTurn Around Time\n");
	for(int i=0;i<n;i++)
		printf("%d\t\t%d\t\t%d\t\t%d\n",p[i].pid,p[i].burst,p[i].wt,p[i].tat);
}
void calcAvg(struct process p[],int n,float *avg_wt,float *avg_tat){
	int total_waiting=0;
	int total_turnAround=0;
	for(int i=0;i<n;i++){
		total_waiting+=p[i].wt;
		total_turnAround+=p[i].tat;
	}
	*avg_wt=(float)total_waiting/n;
	*avg_tat=(float)total_turnAround/n;
}
int main(void){
	int n;
	printf("Enter num of processes :");
	scanf("%d",&n);
	struct process p[n];
	printf("Enter burst time for each process (in ms):\n");
	for(int i=0;i<n;i++){
		p[i].pid=i+1;
		printf("Process %d :",i+1);
		scanf(" %d",&p[i].burst);
	}
	calculateTimes(p,n);
	display(p,n);
	float avg_wt,avg_tat;
	calcAvg(p,n,&avg_wt,&avg_tat);
	printf("\nAverage waiting time :%2f ms\n",avg_wt);
	printf("\nAverage Turn Around time :%2f ms\n",avg_tat);
return 0;
}
	
