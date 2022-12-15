//Shortest Job First

#include<iostream>
using namespace std;

struct Process
{
	int pid;
	int arrival_time;
	int burst_time;
	int compeletion_time;
	int starting_time;
	int waiting_time;
	int turnaround_time;
};

int main()
{    cout<<"\n****SJF SCHEDULING****"<<endl;
	int n,complete=0,time=0;
	double wt_sum,tr_sum;
	
	//To Input No. Of Process
	cout<<"\nEnter the no. of processes: ";
	cin>>n;
	cout<<endl;
	
	int is_complete[n]={0};

	//Structre Type Object For Number Of Process Creation
	Process p[n];
	
	//To Input Brust Time, Arrival Time, Priority
	for(int i=0;i<n;i++)
	{
		cout<<"\nEnter arrival time for process "<<i+1<<": ";
		cin>>p[i].arrival_time;
		cout<<"\nEnter burst time for process "<<i+1<<": ";
		cin>>p[i].burst_time;
		p[i].pid=i+1;
		
	}
	
	
	while(complete!=n)
	{
		int index=-1;
		int min=10000;
		
		//Finding Process To Execute 
		for(int i=0;i<n;i++)
		{
			//checking Process is Arrived Or not and It is Complete Or not
			if(p[i].arrival_time<=time && is_complete[i]==0)
			{
				//Find Minimum brust time
				if(p[i].burst_time<min)
				{
					min=p[i].burst_time;
					index=i;
				}
				
				//if Process have Same brust time then check for arrival time
				if(p[i].burst_time==min)
				{
					if(p[i].arrival_time<p[index].arrival_time)
					{
						min=p[i].arrival_time;
						index=i;
					}
				}
			}
		}
		
		//Find Waiting Time and Turnaround Time
		if(index!=-1)
		{
			p[index].starting_time=time;
			p[index].compeletion_time=p[index].starting_time + p[index].burst_time;
			p[index].turnaround_time=p[index].compeletion_time - p[index].arrival_time;
			p[index].waiting_time=p[index].turnaround_time - p[index].burst_time;
			
			tr_sum+=p[index].turnaround_time;
			wt_sum+=p[index].waiting_time;
			
			is_complete[index]=1;
			complete++;
			time=p[index].compeletion_time;
		}
		//Increment time
		else
		{
			time++;
		}
	}
	
	
    
    cout<<"PROCESSES \t ARRIVAL TIME \t BURST TIME \t WAITING TIME  \t TURN AROUND TIME \n";
    for(int i=0;i<n;i++)
    {
    	cout<<p[i].pid<<"\t\t"<<p[i].arrival_time<<"\t\t"<<p[i].burst_time<<"\t\t"<<p[i].waiting_time<<"\t\t"<<p[i].turnaround_time<<endl;
	}
	
	
	//To Dispaly Average waiting and turnaround time
	cout<<"\nAverage waiting time: "<<wt_sum/n;
	cout<<"\nAverage turnaround time: "<<tr_sum/n;

return 0;
}
