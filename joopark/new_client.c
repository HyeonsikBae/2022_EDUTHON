# include	"new_client.h"
 
int         main(void)
{
	int		sock,
			recv_len,
			addr_len,
			nums[12];
	char	recv_buffer[1024] = {0, };
	struct sockaddr_in
			addr,
			client_addr;
	
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
		if (recv(sock, recv_buffer, 4, 0) > 0) {
			int num = atoi(recv_buffer);
			// printf("CPU Usage : %d%%\n", num);
			print_chart(&nums);
		}
	}

	close(sock);

	return 0;
}