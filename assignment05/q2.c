#include <pthread.h>
#include <stdio.h>

int i = 1;

void *thread_func(void *arg) {
  int thread_num = i++;
  printf("This is thread %d\n", thread_num);
  return NULL;
}
int main(int argc, char *argv[]) {
  pthread_t threads[10];

  for (int i = 0; i < 10; i++) {
    pthread_create(&threads[i], NULL, thread_func, NULL);
  }

  for (int i = 0; i < 10; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}
