#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
 
#define PORT 9999
 
int main(void){
  int sock;
  struct sockaddr_in addr, client_addr;
  char recv_buffer[1024];
  int recv_len;
  int addr_len;

  // 소켓 fd 지정
  if((sock = socket(AF_INET, SOCK_DGRAM, 0)) <0){
      perror("socket ");
      return 1;
  }

	// 소켓 옵션 지정
  int fBroadcast = 1;
  if (setsockopt(sock, SOL_SOCKET, SO_BROADCAST, (const char *)&fBroadcast, sizeof(fBroadcast)) < 0) {
    perror("recvfrom ");
  }
    
  // 소켓 IP, Port 지정
  memset(&addr, 0x00, sizeof(addr));
  addr.sin_family = AF_INET;
  //addr.sin_addr.s_addr = htonl(INADDR_ANY);
  addr.sin_addr.s_addr = inet_addr("255.255.255.255");
  addr.sin_port = htons(PORT);

  // 데이터 크기 지정 (항상 동일한 크기이어야 함.)
  sprintf(recv_buffer, "test");

  // 1초에 한번씩 데이터 송부
  while(1) {
    printf("send data\n");
    sendto(sock, recv_buffer, strlen(recv_buffer), 0, (struct sockaddr *)&addr, sizeof(addr));
    usleep(1000 * 1000);
  }
  close(sock);

  return 0;
}