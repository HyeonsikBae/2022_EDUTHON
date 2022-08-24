# include	"server.h"

t_cpu_data	sample_cpu_data() {
	static float samples[20][3] = {
		{6.58, 8.98, 84.43},
		{6.38, 5.13, 88.47},
		{17.19, 5.65, 68.97},
		{21.86, 13.82, 72.47},
		{26.30, 7.70, 66.61},

		{36.40, 7.70, 56.51},
		{34.00, 7.70, 59.01},
		{32.36, 5.64, 62.99},
		{24.16, 5.20, 70.80},
		{24.30, 7.70, 70.61},

		{44.61, 5.51, 50.51},
		{60.40, 7.70, 32.51},
		{67.40, 7.70, 25.51},
		{77.40, 7.70, 15.51},
		{67.40, 7.70, 25.51},

		{44.61, 5.51, 50.51},
		{36.40, 7.70, 56.51},
		{34.00, 7.70, 59.01},
		{26.30, 7.70, 66.61},
		{21.86, 13.82, 72.47},
	};

	static int idx = 0;
	t_cpu_data rtn;
	rtn.user = samples[idx][0];
	rtn.sys = samples[idx][1];
	rtn.idle = samples[idx][2];
	++idx;
	if (idx > 19) {
		idx = 0;
	}
	return rtn;
}

int			main()
{
	int		sock, recv_len, addr_len, top_fd;
	struct sockaddr_in addr, client_addr;
	t_cpu_data user_data;

	// set socket fd
	if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
		perror("socket ");
		return 1;
	}

	// set socket option
	int		fBroadcast = 1;
	if (setsockopt(sock, SOL_SOCKET, SO_BROADCAST, (const char *)&fBroadcast, sizeof(fBroadcast)) < 0) {
		perror("recvfrom ");
	}
		
	// 소켓 IP, Port 지정
	memset(&addr, 0x00, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = inet_addr("255.255.255.255");
	addr.sin_port = htons(PORT);
	while (1) {
    user_data = sample_cpu_data();
    printf("user : %.2f%%, sys : %.2f%%, idle : %.2f%%\n",
      user_data.user,
      user_data.sys,
      user_data.idle
    );
    fflush(stdout);
    sendto(sock, (void*)&user_data, sizeof(t_cpu_data), 0, (struct sockaddr *)&addr, sizeof(addr));
    usleep(1000 * 1000);
	}
	close(sock);
	return 0;
}