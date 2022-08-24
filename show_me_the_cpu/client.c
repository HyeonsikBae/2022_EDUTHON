# include	"client.h"

typedef struct cpu_data {
	float user;
	float sys;
	float idle;
} s_cpu_data;

int         main(void)
{
	int		sock, recv_len, addr_len;
	struct sockaddr_in	addr, client_addr;
  s_cpu_data user_data;
	
	// 소켓 fd 지정
	if ((sock = socket(
			AF_INET,
			SOCK_DGRAM,
			IPPROTO_UDP)) <0)
	{
		perror("socket ");
		return 1;
	}

	// 소켓 IP, Port 지정
	memset(&addr, 0x00, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(PORT);

	// 소켓 바인드
	if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
	{
		perror("bind ");
		return 1;
	}
	while (1)
	{
		if (recv(sock, (void*)&user_data, sizeof(user_data), 0) > 0) {
			printf("user : %.2f%%,\tsys : %.2f%%,\tidle : %.2f%%\n", user_data.user, user_data.sys, user_data.idle);
		}
    fflush(stdout);
	}
	close(sock);

	return 0;
}