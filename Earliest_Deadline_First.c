#include<stdio.h>
int main(){
    int n,i,j;
    int process[10],deadline[10],burst[10];
    printf("Enter number of processes:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        process[i]=i+1;
        printf("\nEnter burst time of P%d:",process[i]);
        scanf("%d",&burst[i]);
        printf("Enter deadline of P%d:",process[i]);
        scanf("%d",&deadline[i]);
    }
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(deadline[i]>deadline[j]){
                int temp;
                temp=deadline[i];
                deadline[i]=deadline[j];
                deadline[j]=temp;
                
                temp=burst[i];
                burst[i]=burst[j];
                burst[j]=temp;
                
                temp=process[i];
                process[i]=process[j];
                process[j]=temp;
            }
        }
    }

    printf("\n Execution order(EDF):\n");
    for(i=0;i<n;i++){
        printf("P%d",process[i]);
    }

    printf("\n\n Gantt Chart:\n|");
    int time=0;
    for(i=0;i<n;i++){
        printf("P%d|",process[i]);
    }
    printf("\n0");
    for(i=0;i<n;i++){
        time+=burst[i];
        printf(" %d",time);
    }
    printf("\n");


    return 0;
}