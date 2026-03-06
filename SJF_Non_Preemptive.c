#include <stdio.h>

int main() {
    int n,i,j;
    int at[20],bt[20],ct[20],tat[20],wt[20],rt[20];
    int p[20],completed[20]={0};
    int time=0,done=0,shortest;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    printf("Enter Arrival Time and Burst Time:\n");

    for(i=0;i<n;i++)
    {
        p[i]=i+1;
        printf("P%d AT BT: ",i+1);
        scanf("%d %d",&at[i],&bt[i]);
    }

    while(done<n)
    {
        shortest=-1;

        for(i=0;i<n;i++)
        {
            if(at[i]<=time && completed[i]==0)
            {
                if(shortest==-1 || bt[i]<bt[shortest])
                    shortest=i;
            }
        }

        if(shortest==-1)
        {
            time++;
        }
        else
        {
            time+=bt[shortest];
            ct[shortest]=time;

            tat[shortest]=ct[shortest]-at[shortest];
            wt[shortest]=tat[shortest]-bt[shortest];
            rt[shortest]=wt[shortest];

            completed[shortest]=1;
            done++;
        }
    }

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\tRT\n");

    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        p[i],at[i],bt[i],ct[i],tat[i],wt[i],rt[i]);
    }

    return 0;
}