# include	"server.h"
 
# define    PORT  9999

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

int			main(void)
{
	int		sock,
			recv_len,
			addr_len;
	char	recv_buffer[1024];
	struct sockaddr_in
			addr,
			client_addr;

	// 소켓 fd 지정
	if ((sock = socket(
			AF_INET,
			SOCK_DGRAM, 0)) < 0)
	{
		perror("socket ");
		return 1;
	}

	// 소켓 옵션 지정
	int		fBroadcast = 1;
	if (setsockopt(
			sock,
			SOL_SOCKET,
			SO_BROADCAST,
			(const char *)&fBroadcast,
			sizeof(fBroadcast)) < 0)
	{
		perror("recvfrom ");
	}
		
	// 소켓 IP, Port 지정
	memset(&addr, 0x00, sizeof(addr));
	addr.sin_family = AF_INET;
	//addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_addr.s_addr = inet_addr("255.255.255.255");
	addr.sin_port = htons(PORT);

	// 1초에 한번씩 데이터 송부
	while(1)
	{
		sprintf(recv_buffer, int_to_str(get_cpu_status()));
		printf("send data : %s\n", recv_buffer);
		sendto(sock, recv_buffer, strlen(recv_buffer), 0, (struct sockaddr *)&addr, sizeof(addr));
		usleep(1000 * 1000);
	}
	close(sock);

	return 0;
}