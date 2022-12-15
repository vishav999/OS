//Shortest Remaining Time First

#include<iostream>
using namespace std;

struct Process
{
	int pid;
	int arrival_time;
	int burst_time;
	int completion_time;
	int starting_time;
	int turnaround_time;
	int waiting_time;
};

int main()
{
	int n,complete=0,time=0;
	double tr_sum=0,wt_sum=0;
	
	//Input Number Of Process
	cout<<"\n****SRTF SCHEDULING****"<<endl;
	cout<<"\nEnter the no. of processes: ";
	cin>>n;
	
	Process p[n];
	int is_complete[n]={0};
	int burst_r[n]={0};
	
	//Input Arrival Time And Burst Time
	for(int i=0;i<n;i++)
	{
		cout<<"\nEnter the arrival time for process "<<i+1<<": ";
		cin>>p[i].arrival_time;
		cout<<"\nEnter the burst time for process "<<i+1<<": ";
		cin>>p[i].burst_time;
		burst_r[i]=p[i].burst_time;
		p[i].pid=i+1;
		
	}
	
	while(complete!=n)
	{
		int index=-1;
		int min=100000;
		
		//Finding Process To Execute 
		for(int i=0;i<n;i++)
		{
			//Check process is Arrived Or not
			if(p[i].arrival_time<=time && is_complete[i]==0)
		    {
			    //Finding Minimum burst time
				if(burst_r[i]<min)
			    {
				   min=burst_r[i];
				   index=i;
			    }
			    
			    //Process have same burst time check arrival time
			    if(burst_r[i]==min)
			    {
				    if(p[i].arrival_time<p[index].arrival_time)
				    {
					   min=burst_r[i];
					   index=i;
				    }
			    }
		    }
		}
		
		//Find Waiting Time and TurnAround Time
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
				p[index].turnaround_time=p[index].completion_time-p[index].arrival_time;
				p[index].waiting_time=p[index].turnaround_time-p[index].burst_time;
				
				tr_sum+=p[index].turnaround_time;
				wt_sum+=p[index].waiting_time;
				
				is_complete[index]=1;
				complete++;
			}   
		}
		
		//Increment Time
		else
		{
			time++;
	    }
	}
	
	
    cout<<"PROCESSES \t BURST TIME \t ARRIVAL TIME \t WAITING TIME \t TURNAROUND TIME\n";
    for(int i=0;i<n;i++)
    {
    	cout<<p[i].pid<<"\t\t"<<p[i].burst_time<<"\t\t"<<p[i].arrival_time<<"\t\t"<<p[i].waiting_time<<"\t\t"<<p[i].turnaround_time<<endl;
	}

	
	//To Dispaly Average waiting and turnaround time
	cout<<"\nAverage waiting time: "<<wt_sum/n;
	cout<<"\nAverage turnaround time:  "<<tr_sum/n;

return 0;	
}
