

#include "./includes/minitalk.h"

int main(int argc, char **argv)
{
	
	pid_t pid;

	pid = getpid();
	printf("this proccess pid %d \n", pid);

	kill(atoi(argv[1]), SIGUSR1);

	return (0);
}
