#include<stdio.h>
#include<sys/types.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

void *func(void *vargp);
int main(){
int n;
printf("Enter a number");
scanf("%d",&n);

pthread_t pthread1;
pthread_create(&pthread1,NULL,func,(void *)n);
pthread_join(pthread1,NULL);

return 0;
}

void *func( void *n1){
int n = (int)n1;
int i,flag=0;

for(i=2;i<=n/2;++i){
if(n%i==0){
    flag = 1;
    break;
}
}
if (flag==0) {
printf("Prime");
}else{
printf("Not Prime");
}

}