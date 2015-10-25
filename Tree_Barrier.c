
#include <stdio.h>
#include <mpi.h>
#include <math.h>

void MyBarrier(int,int);  //Function declaration


int main (argc, argv)
 int argc;
 char *argv[];
{
 int rank, size;
 MPI_Init (&argc, &argv); /* starts MPI */
 MPI_Comm_rank (MPI_COMM_WORLD, &rank); /* get current process id */
 MPI_Comm_size (MPI_COMM_WORLD, &size); /* get number of processes */
 
 
	printf( "Before Barrier  from process %d \n", rank);	 
	sleep(10);//Sleep is used so that the printf statements are printed in order
	
    MyBarrier(rank,size);

	sleep(10);//Sleep is used so that the printf statements are printed in order
	printf( "After  Barrier  from process %d \n", rank);
	
	
MPI_Finalize();
return 0;

 }//end of main
 
 
 //MyBarrier function starts
 void MyBarrier(int rank,int size)
{

 double logValue=log(size)/log(2);
 
 int logValue_int=logValue;
 //printf("Log Value is %d",logValue_int);
 
int k=logValue_int;
int i=0;
int j=0; 
int iteration=0;
for(i=k-1;i>=0;i--)
{
	iteration=2-i;
	//printf("\n This is the %d iteration",2-i);
	 for(j=pow(2,i);j<pow(2,i+1);j++)
	 {
		 
			 
			 if(rank==j){
		// printf("\n sending message from %d to %d in iteration %d",j,j-(int)pow(2,i),iteration);
		 MPI_Send(&iteration,1,MPI_INT,j-(int)pow(2,i),iteration,MPI_COMM_WORLD);
			 }
			 
			 if(rank== j-(int)pow(2,i) ){
		
		 MPI_Status status;
		int data;
		MPI_Recv(&data,1,MPI_INT,j,iteration,MPI_COMM_WORLD,&status);
		//printf("\n receiving message from %d to %d and message is %d",j,j-(int)pow(2,i),data);
			 }
		 
	 }//end of inner loop

}//end of outer for

i=0;
j=0;
iteration=0;

for(i=0;i<=k-1;i++)
{
	iteration=i;
	//printf("\n This is the %d iteration",i);
	 for(j=0;j<=pow(2,i)-1;j++)
	 {
		 //printf("\nValue of i,j is %d , %d",i,j);
		 
		 
		if(rank==j){
		// printf("\n sending message from %d to %d in iteration %d",j,j+(int)pow(2,i),iteration);
		 MPI_Send(&iteration,1,MPI_INT,j+(int)pow(2,i),iteration,MPI_COMM_WORLD);
			 }
			 
			 if(rank== j+(int)pow(2,i) )
			 {
		
		MPI_Status status;
		int data;
		MPI_Recv(&data,1,MPI_INT,j,iteration,MPI_COMM_WORLD,&status);
		printf("\n\n receiving message from %d to %d and message is %d",j,j+(int)pow(2,i),data);
			 }
		 
	 }//end of inner loop

}//end of outer for


 }//End of MyBarrier function 