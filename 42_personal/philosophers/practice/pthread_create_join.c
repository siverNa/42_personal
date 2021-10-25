#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void	*t_func(void *data)
{
	pid_t		pid;
	pthread_t	tid;
	char		*thread_name;
	int			i;

	pid = getpid();
	tid = pthread_self();
	thread_name = (char *)data;
	i = 0;
	while (i < 3)
	{
		printf("[%s] pid : %u, tid : %x --- %d\n",
			thread_name, (unsigned int)pid, (unsigned int)tid, i);
		i++;
		sleep(1);
	}
}

int main(void)
{
	pthread_t	p_thread[2];
	int			thr_id;
	int			status;
	char		p1[] = "thread_1";
	char		p2[] = "thread_2";
	char		p_main[] = "thread_main";

	sleep(1);
	thr_id = pthread_create(&p_thread[0], NULL, t_func, (void *)p1);
	if (thr_id < 0)
	{
		perror("thread create error : ");
		exit(0);
	}
	sleep(1);
	thr_id = pthread_create(&p_thread[0], NULL, t_func, (void *)p2);
	if (thr_id < 0)
	{
		perror("thread create error : ");
		exit(0);
	}
	sleep(1);
	t_func((void *)p_main);
	pthread_join(p_thread[0], (void **)&status);
	pthread_join(p_thread[1], (void **)&status);
	printf("end!\n");
	return (1);
}