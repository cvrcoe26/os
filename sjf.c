#include <stdio.h>

struct Process {
    int process_id;
    int arrival_time;
    int burst_time;
};

void sjf_scheduling(struct Process processes[], int n) {
    int completion_time[n];
    int waiting_time[n];
    int turnaround_time[n];
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].arrival_time > processes[j].arrival_time) {
                struct Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    int current_time = 0;

    for (int i = 0; i < n; i++) {
        printf("Enter details for process %d:\n", i + 1);
        printf("Process ID: ");
        scanf("%d", &processes[i].process_id);
        printf("Arrival Time: ");
        scanf("%d", &processes[i].arrival_time);
        printf("Burst Time: ");
        scanf("%d", &processes[i].burst_time);
        if (current_time < processes[i].arrival_time) {
            current_time = processes[i].arrival_time;
        }
        completion_time[i] = current_time + processes[i].burst_time;
        waiting_time[i] = current_time - processes[i].arrival_time;
        turnaround_time[i] = waiting_time[i] + processes[i].burst_time;
        current_time += processes[i].burst_time;
    }
    printf("\nProcess\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].process_id, completion_time[i], waiting_time[i], turnaround_time[i]);
    }
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    for (int i = 0; i < n; i++) {
        total_waiting_time += waiting_time[i];
        total_turnaround_time += turnaround_time[i];
    }

    float avg_waiting_time = (float)total_waiting_time / n;
    float avg_turnaround_time = (float)total_turnaround_time / n;

    printf("\nAverage Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    sjf_scheduling(processes, n);

    return 0;
}