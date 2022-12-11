#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>


int main(int argc, char ** argv) {
  int pid;

  char * cat_args[] = {"cat","scores",NULL};
  char * grep_args[] = {"grep",argv[1],NULL};



  pid = fork();

  if (pid == 0) {
    
    
    int pipefd[2];
    pipe(pipefd);
    
    
    pid = fork();
    
    if (pid == 0){

      int pipefd2[2];
      pipe(pipefd2);
      
      int pid2 =fork();
      
      if (pid2 == 0){
        dup2(pipefd2[1], 1);
        close(pipefd2[0]);
        close(pipefd[0]);
        execvp("cat", cat_args); // execute cat first
      }
      else{
        dup2(pipefd2[0], 0);
        dup2(pipefd[1], 1);
        close(pipefd2[1]);
        close(pipefd[0]);
        execvp("grep", grep_args); // execute grep 
      }
    }
    else{
      dup2(pipefd[0], 0);
      close(pipefd[1]);
      char *sort_args[] = {"sort", NULL }; // execute sort
      execvp("sort", sort_args);
    } 
  } 
  else {
    wait(NULL); // wait
  }
}