#include<iostream>
using namespace std;

struct Process
{
	int arrival_time;
	int burst_time;
	int priority;
	int starting_time;
	int waiting_time;
	int turnaround_time;
	int completion_time;
	int pid;
};


int main()
{
	int n,complete=0,time=0;
	double tr_sum=0,wt_sum=0;
	
	//Input Number Of Process
	cout<<"\nEnter The Number Of Process:";
	cin>>n;
	
	Process p[n];
	int is_complete[n]={0};
	int burst_r[n]={0};
	
	//Input Arrival Time And Burst Time
	for(int i=0;i<n;i++)
	{  
		cout<<"\nEnter The Arrival Time of Process P"<<i+1<<":";
		cin>>p[i].arrival_time;
		
		cout<<"\nEnter The Burst Time of Process P"<<i+1 <<":";
		cin>>p[i].burst_time;
		burst_r[i]=p[i].burst_time;
		
		cout<<"\nEnter The Priority:";
		cin>>p[i].priority;
		
		p[i].pid=i+1;
		cout<<endl;	
	}
	
	while(complete!=n)
	{
		int index=-1;
		int max=-1;
		
		for(int i=0;i<n;i++)
		{
			if(p[i].arrival_time<=time && is_complete[i]==0)
			{
				if(p[i].priority>max)
				{
					index=i;
					max=p[i].priority;
				}
				if(p[i].priority==max)
				{
					if(p[i].arrival_time<p[index].arrival_time)
					{
						max=p[i].priority;
						index=i;
					}
				}
			}
		}
		
		if(index!=-1)
		{
			if(burst_r[index]==p[index].burst_time)
			{
				p[index].starting_time=time;
			}
			
			burst_r[index]-=1;
			time++;
			
			if(burst_r[index]==0)
			{
				p[index].completion_time=time;
				p[index].turnaround_time=p[index].completion_time - p[index].arrival_time;
				p[index].waiting_time=p[index].turnaround_time - p[index].burst_time;
				
				tr_sum+=p[index].turnaround_time;
				wt_sum+=p[index].waiting_time;
				
				complete++;
				is_complete[index]=1;
			}
		}
		
		else
		{
			time++;
		}
	}
	
	
    cout<<"I.D \t Arriving Time \t Burst Time \t Priority \t Waiting Time \t Turnaround Time\n";
    for(int i=0;i<n;i++)
    {
    	cout<<p[i].pid<<"\t\t  "<<p[i].arrival_time<<"\t\t  "<<p[i].burst_time<<"\t\t  "<<p[i].priority<<"\t\t "<<p[i].waiting_time<<"\t\t   "<<p[i].turnaround_time<<endl;
	}
	
	
	//To Dispaly Average waiting and turnaround time
	cout<<"Average Waiting Time :"<<wt_sum/n<<endl;
	cout<<"Average Turnaround Time: "<<tr_sum/n<<endl;
return 0;
}
