#include <poll.h>
#include <pthread.h>

static void * thread_func (void *arg) {
	int count = 0;
	struct pollfd pfds[1] = { 0 };
	pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
	poll(pfds, count, 1000);
}

int main () {
	pthread_t thread;
	if (pthread_create(&thread, NULL, thread_func, NULL)) return 1;
	if (pthread_cancel(thread)) return 2;
	if (pthread_join(thread, NULL)) return 3;
	return 0;
}
