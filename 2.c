//Write a Program to print process ids' of parent and child process i.e. parent should print its own and its child process id while child process should print its  own and its parent process  id.

#include<stdio.h>
#include<unistd.h>
int main(){
    //create a child process
    pid_t pid =fork();
    if(pid<0){
        //fork failed
        printf("Fork failed!\n");
        return 1;
    }
    else if(pid==0){
        //This is the child process
        printf("Child Process:\n");
        printf("PID: %d,Parent PID: %d\n", getpid(),getppid());
    }
    else{
        //This is parent process
        printf("Parent Process:\n");
        printf("PID: %d,Child PID: %d\n", getpid(),pid);
    }
    return 0;
}