//Write a program to create a child process using system call fork()

#include<stdio.h>
#include<unistd.h>
int main(){
    pid_t pid=fork();
    if(pid<0){
        //fork failed
        printf("Fork failed!\n");
        return 1;
    }
    else if(pid==0){
        //This is the Child process
        printf("Hello from the Child Process! PID: %d\n",getpid());
    }
    else{
        //This is the parent process
        printf("Hello from the Parent Process! PID: %d, child PID: %d\n",getpid(),pid);
    }
    return 0;
}