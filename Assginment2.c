#include<stdio.h>
#include<conio.h>

int main(){
int i,j,sum=0,count = 0,k,l;
int no_of_process,no_of_resource;

printf("Enter no of Processes");
scanf("%d",&no_of_process);
printf("Enter no of Resource");
scanf("%d",&no_of_resource);


int allocation[no_of_process][no_of_resource] ;
int max[no_of_process][no_of_resource];

int need[no_of_process][no_of_resource] ;
int status[no_of_process] ;
int available[no_of_resource] ;


for (i = 0; i < no_of_process; i++)
{
    status[i] = 0;
}


printf("Enter Allocation \n");
// Allocation Input

for(i=0;i<no_of_process;i++){
 for(j=0;j<no_of_resource;j++){
        scanf("%d",&allocation[i][j]);
    } 
    printf("\n");
}

printf("Enter Max Need \n");

// Max Need Input

for(i=0;i<no_of_process;i++){
 for(j=0;j<no_of_resource;j++){
        scanf("%d",&max[i][j]);
    } 
    printf("\n");
}
printf("Enter Available \n");

// Available Input
 for(j=0;j<no_of_resource;j++){
        scanf("%d",&available[i]);
    } 


//Calculating the Current need of the Processes
for(i=0;i<=no_of_process;i++){
 for(j=0;j<=no_of_resource;j++){
        need[i][j] = max[i][j] - allocation[i][j];
    } 
}

//Calculating the Status for each process i.e will it execute or not
for(l = 0;l<2;l++){
for(i=0;i<no_of_process;i++){
 count =0;
 for(j=0;j<no_of_resource;j++){
    
     if(available[j] >= need[i][j]){
         count++;
     }
    }
  if(status[i]==0){
   if (count == 4) {
      status[i] = 1; 

     for(k=0;k<4;k++){
         
    
        available[k] = available[k]+ allocation[i][k]; 
    } 

   }
  }
     
}
}

//validating Status to check for Safe state or not
count = 0;
for(i=0;i<no_of_process;i++){

if(status[i]==1){
    count++;
}
}
if(count == 5){
    printf("Program is in safe state");
}else{
    printf("Program is not in safe state");
    
}


return 0;
}