#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
void* thread_func(void* data)
{
 char *str = (char *) data;
 printf("%s\n",str);
}

int main(int argc, char *argv[]) {
  pthread_t tid[2];
  pid_t pid;
  char *data[4] ={"First thread from child process",
                  "Second thread from child process",
                  "First thread from parent process",
                  "Second thread from parent process"};
  pid = fork();
  if(pid < 0) {
	//Error Fork
        printf("Can't fork");
        return 0;
  }
  else if(pid == 0){
	//This is Child
        pthread_create(&tid[0],NULL, thread_func,data[0]);
        pthread_create(&tid[1],NULL, thread_func,data[1]);
        pthread_join(tid[0], NULL);
        pthread_join(tid[1], NULL);
	exit(0);
  }
  else {
        //This is Parent
        pthread_create(&tid[0],NULL, thread_func,data[2]);
        pthread_create(&tid[1],NULL, thread_func,data[3]);
        pthread_join(tid[0],NULL);
        pthread_join(tid[1], NULL);
  }
}
