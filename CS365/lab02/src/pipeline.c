#include <stdio.h>    // puts(), printf(), perror(), getchar()
#include <stdlib.h>   // exit(), EXIT_SUCCESS, EXIT_FAILURE
#include <unistd.h>   // getpid(), getppid(),fork()
#include <sys/wait.h> // wait()

#define READ  0
#define WRITE 1

void child_a(int fd[])
{
	if (dup2(fd[1], STDOUT_FILENO) == -1)
	{
		perror("Error in child_a - dup2");
	}
	if (close(fd[0]) == -1)
	{
		perror("Error in child_a - close");
	}
	if (close(fd[1]) == -1)
	{
		perror("Error in child_a - close");
	}
	execlp("ls", "ls", "-F", "-1", (char*)NULL);
	perror("Error in child_a - execlp");
}

void child_b(int fd[], int fd_2[])
{
	if (dup2(fd[0], STDIN_FILENO) == -1)
	{
		perror("Error in child_b (fd) - dup2");
	}
	if (dup2(fd_2[1], STDOUT_FILENO) == -1)
	{
		perror("Error in child_b (fd_2) - dup2");
	}
	if (close(fd[0]) == -1)
	{
		perror("Error in child_b (fd) - close");
	}
	if (close(fd[1]) == -1)
	{
		perror("Error in child_b (fd_2) - close");
	}
	if (close(fd_2[0]) == -1)
	{
		perror("Error in child_b (fd_2) - close");
	}
	if (close(fd_2[1]) == -1)
	{
		perror("Error in child_b (fd_2) - close");
	}
	execlp("nl", "nl", (char*)NULL);
	perror("Error in child_b - execlp");
}

void child_c(int fd_2[])
{
	if (dup2(fd_2[0], STDIN_FILENO) == -1)
	{
		perror("Error in child_c - dup2");
	}
	if (close(fd_2[0]) == -1)
	{
		perror("Error in child_c - close");
	}
	if (close(fd_2[1]) == -1)
	{
		perror("Error in child_c - close");
	}
	execlp("wc", "wc", "src/pipeline.c", (char*)NULL);
	perror("Error in child_c - execlp");
}

int main(void)
{
	int fd[2];
	int fd_2[2];

	pid_t pid_child_a;
	pid_t pid_child_b;
	pid_t pid_child_c;

	if (pipe(fd) == -1)
	{
		perror("pipe");
	}

	if (pipe(fd_2) == -1)
	{
		perror("pipe");
	}

	pid_child_a = fork();

	if (pid_child_a == 0)
	{
		child_a(fd);
	}

	pid_child_b = fork();

	if (pid_child_b == 0)
	{
		child_b(fd, fd_2);
	}

	if (close(fd[0]) == -1)
	{
		perror("close");
	}
	if (close(fd[1]) == -1)
	{
		perror("close");
	}

	pid_child_c = fork();

	if (pid_child_c == 0)
	{
		child_c(fd_2);
	}

	if (close(fd_2[0]) == -1)
	{
		perror("close");
	}
	if (close(fd_2[1]) == -1)
	{
		perror("close");
	}
	if (waitpid(pid_child_a, NULL, 0) == -1)
	{
		perror("waitpid");
	}
	if (waitpid(pid_child_b, NULL, 0) == -1)
	{
		perror("waitpid");
	}
	if (waitpid(pid_child_c, NULL, 0) == -1)
	{
		perror("waitpid");
	}
	return 0;
}