#include<stdio.h>
int main(){
	int at[10],bt[10],x[10],i,j,smallest,count=0,time,end,n;
	float total_wt=0,total_tt=0,avg_wt=0.0,avg_tt=0.0;
	printf("Enter the number of processes: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter the arrival time of process %d: ",i+1);
		scanf("%d",&at[i]);
		printf("Enter the burst time of process %d: ",i+1);
		scanf("%d",&bt[i]);
		x[i]=bt[i];
	}
	bt[9]=9999;
	for(time=0;count!=n;time++){
		smallest=9;
		for(i=0;i<n;i++){
			if(at[i]<=time && bt[i]<bt[smallest] && bt[i]>0){
				smallest=i;
			}
		}
		bt[smallest]--;
		if(bt[smallest]==0){
			count++;
			end=time+1;
			total_wt=total_wt+end-at[smallest]-x[smallest];
			total_tt=total_tt+end-at[smallest];
		}
	}
	avg_wt=total_wt/n;
	avg_tt=total_tt/n;
	printf("Average Waiting Time: %f\n",avg_wt);
	printf("Average TurnAround Time: %f\n",avg_tt);
	return 0;
}
