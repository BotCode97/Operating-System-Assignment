#include<stdio.h>
#include<conio.h>

int main(){
int i,j,sum=0,count = 0,k,l;
int allocation[5][4] = {{0,0,1,2},{1,0,0,0},{1,3,5,4},{0,6,3,2},{0,0,1,4}};
int max[5][4]={{0,0,1,2},{1,7,5,0},{2,3,5,6},{0,6,5,2},{0,6,5,6}};

int need[5][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
int status[5] = {0,0,0,0,0};
int available[4] = {1,5,2,0};
for(i=0;i<=4;i++){
 for(j=0;j<=5;j++){
        need[i][j] = max[i][j] - allocation[i][j];
    } 
}
for(l = 0;l<2;l++){
for(i=0;i<=5;i++){
 count =0;
 for(j=0;j<4;j++){
    
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
count = 0;
for(i=0;i<5;i++){
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