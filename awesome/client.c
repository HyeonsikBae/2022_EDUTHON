# include	"client.h"

int         main(void)
{
	int		sock,
			recv_len,
			addr_len;
	int		*datas = malloc(sizeof(int) * 11);
	struct sockaddr_in
			addr,
			client_addr;
	struct cpu_data
			user_data;
	
	// set socket fd
	if ((sock = socket(
			AF_INET,
			SOCK_DGRAM,
			IPPROTO_UDP)) <0)
	{
		perror("socket ");
		return 1;
	}

	// set socket IP, Port
	memset(&addr, 0x00, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(PORT);

	// socket bind
	if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0)
	{
		perror("bind ");
		return (1);
	}

	memset(datas, 0, 10);
	while (1)
	{
		if (recv(sock, (void*)&user_data, sizeof(user_data), 0) > 0)
			print_chart(datas, (int)(user_data).user);
	}
	free(datas);
	close(sock);
	return (0);
}