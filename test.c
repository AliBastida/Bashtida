#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[], char *env[])
{
	char cmd[] = "/bin/ls";
	char *args[] = {"ls", "-la", NULL};
	execve(cmd, args, env);
	fd = open(file, O_WRONLY | O_APPEND | O_CREAT, 0644);
}
