/* Developer  Akshay Ratan  */

#include <stdio.h>
#include <pthread.h>
void *print_stuff(void *ptr) {
   int i, id = * (int *) ptr;
   for (i = 0; i < 5; i++) {
       printf("Thread %d, loop %d\n", id, i);
       sleep(rand()%2);   /* sleep 0 or 1 seconds */
   }
   printf("Thread %d exiting\n", id);
   return NULL;
}
int main() {
   pthread_t tids[2];
   int i, ids[2];

   for (i=0; i < 2; i++) {
      ids[i] = i + 1;
      pthread_create(&tids[i], NULL, print_stuff, &ids[i]);
      printf("Thread 0 created thread %d\n", i + 1);
   }

   for (i=0; i < 2; i++) {
      pthread_join(tids[i], NULL);
      printf("Thread 0 reaped thread %d\n", i + 1);
   }
   return 0;
}
