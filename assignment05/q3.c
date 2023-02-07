#include <pthread.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void* thread_func(void* data)
{
 char *str = (char *) data;
 printf("%s\n",str);
}

int main(int argc, char *argv[]) {
  pthread_t tid[4];
  pid_t pid;
  char *data[4] ={"First thread from child process",
                  "Second thread from child process",
                  "First thread from parent process",
                  "Second thread from parent process"};
  pid = fork();
  if(pid < 0) {
          printf("Error");
          return 0;
  }
  else if(pid == 0){
        //Child

        pthread_create(&tid[0],NULL, thread_func,data[0]);
        pthread_create(&tid[1],NULL, thread_func,data[1]);
        pthread_join(tid[0], NULL);
        pthread_join(tid[1], NULL);
  }
  else {
        //Parent
        pthread_create(&tid[2],NULL, thread_func,data[2]);
        pthread_create(&tid[3],NULL, thread_func,data[3]);
        pthread_join(tid[2],NULL);
        pthread_join(tid[3], NULL);
  }
}
