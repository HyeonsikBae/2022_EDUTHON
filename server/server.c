# include	"server.h"

# define    PORT  9999

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

int run_cmd(char **argv, int len, char **envp) {
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

char*		int_to_str(int num)
{
	int		len = 3;
	char*	str;

	str = (char*)malloc(sizeof(char) * len);
	for (int i = 0; i < len; i++)
		str[i] = '0';
	
	if (num < 10)
		str[2] = '0' + num;
	else if (num < 100)
	{
		str[1] = '0' + num / 10;
		str[2] = '0' + num % 10;
	} else {
		str[0] = '0' + num / 100;
		str[1] = '0' + (num / 10) % 10;
		str[2] = '0' + num % 10;
	}

	return	str;
}

char*		getRandNum(void)
{
	int		num;

	srand(time(NULL));
	num = rand() % 101;

	return	num;
}

#pragma pack(1)
struct cpu_data {
	float user;
	float sys;
	float idle;
};

int			main(int argc, char **argv, char **envp)
{
	int		sock, recv_len, addr_len, top_fd;
	char	recv_buffer[1024];
	struct sockaddr_in	addr, client_addr;
	struct cpu_data*		user_data = malloc(sizeof(struct cpu_data));
  char *cmd = "/usr/bin/top";
  char *custom_argv[] = {cmd, NULL};
	char buf[4097] = {0, };

	(void)argc;
	(void)argv;

	// top 프로세스 실행
	top_fd = run_cmd(custom_argv, 1, envp);

	// 소켓 fd 지정
	if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
		perror("socket ");
		return 1;
	}

	// 소켓 옵션 지정
	int		fBroadcast = 1;
	if (setsockopt(sock, SOL_SOCKET, SO_BROADCAST, (const char *)&fBroadcast, sizeof(fBroadcast)) < 0) {
		perror("recvfrom ");
	}
		
	// 소켓 IP, Port 지정
	memset(&addr, 0x00, sizeof(addr));
	addr.sin_family = AF_INET;
	//addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_addr.s_addr = inet_addr("255.255.255.255");
	addr.sin_port = htons(PORT);
	printf("data frame size : %d\n", sizeof(struct cpu_data));
	// 1초에 한번씩 데이터 송부
	while (1) {
		if (read(top_fd, buf, 4096) > 0) {
      char* pos_start = strstr(buf, "CPU usage");
      char* pos_end = (pos_start != NULL) ? strstr(pos_start, "SharedLibs") : NULL;
      if (pos_end != NULL) {
        char* pos_start = strstr(buf, "CPU usage: ");
        (user_data)->user = atof(pos_start + 11);
        char* sys_start = strstr(buf, "user, ");
        (user_data)->sys = atof(sys_start + 6);
        char* idle_start = strstr(buf, "sys, ");
        (user_data)->idle = atof(idle_start + 5);
				printf("%f %f %f\n", (user_data)->user, (user_data)->sys, (user_data)->idle);
				sendto(sock, (void*)user_data, sizeof(struct cpu_data), 0, (struct sockaddr *)&addr, sizeof(addr));
      }
		}
	}
	close(sock);

	return 0;
}