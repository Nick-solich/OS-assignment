#include <pthread.h>
#include <stdio.h>


void *thread_func(void *arg) {
  int thread_num = *(int *)arg;
  printf("This is thread %d\n", thread_num);

  return NULL;
}

int main(int argc, char *argv[]) {
  pthread_t threads[10];
  int thread_args[10];

  for (int i = 0; i < 10; i++) {
    thread_args[i] = i+1;
    pthread_create(&threads[i], NULL, thread_func, &thread_args[i]);
  }

  for (int i = 0; i < 10; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}
