#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int ft_exec(char **argv, int i, int o, char **envp)
{
	int			rtn = 0;
	pid_t		pid;
	int			io[2] = {0, 0};
	int			status;

	pid = fork();
	if (pid < 0)
		return -1;
	if (pid == 0) {
		if (i != 0)
			io[0] = dup2(i, 0);
		if (o != 1)
			io[1] = dup2(o, 1);
		if (io[0] < 0 || io[1] < 0)
			return -1;
		if (execve(argv[0], argv, envp) == -1) {
			exit(1);
		}
	}
	return (rtn);
}

int run_cmd(char **argv, int len, int final, char **envp) {
	char **strs = malloc(sizeof(char *) * (len + 1));
	int rtn;
	int pair[2][2];


	if ((pipe(pair[0]) == -1) || (pipe(pair[1]) == -1)) {
    return -1;
  }
	if (strs == NULL)
		return -1;
	for (int i = 0; i < len; i++)
		strs[i] = argv[i];
	strs[len] = NULL;
	rtn = ft_exec(strs, pair[0][0], pair[1][1], envp);
  if (rtn == -1) {
    return -1;
  }
	free(strs);
	return (pair[1][0]);
}

int main(int argc, char **argv, char **envp) {
	int rtn = 0;
	int start = 1;
  char *cmd = "/usr/bin/top";
  char *arr[] = {cmd, NULL};

  char buf[4097] = {0, };

  rtn = run_cmd(arr, 1, 1, envp);

  while (1) {
    if (read(rtn, buf, 4096) > 0) {
      char* pos_start = strstr(buf, "CPU usage");
      char* pos_end = (pos_start != NULL) ? strstr(pos_start, "SharedLibs") : NULL;
      if (pos_end != NULL) {
        char* pos_start = strstr(buf, "CPU usage: ");
        double user = atof(pos_start + 11);
        char* sys_start = strstr(buf, "user, ");
        double sys = atof(sys_start + 6);
        char* idle_start = strstr(buf, "sys, ");
        double idle = atof(idle_start + 5);
        printf("user : %.2f, sys : %.2f, idle : %.2f\n", user, sys, idle);
      }
    }
  }
	return (0);
}