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
  char recv_buffer[1024] = {0, };
  int recv_len;
  int addr_len;
 
  // 소켓 fd 지정
  if((sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) <0){
      perror("socket ");
      return 1;
  }
  // 소켓 IP, Port 지정
  memset(&addr, 0x00, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = htonl(INADDR_ANY);
  addr.sin_port = htons(PORT);

  // 소켓 바인드
  if(bind(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0){
      perror("bind ");
      return 1;
  }

  while (1) {
    if (recv(sock, recv_buffer, 4, 0) > 0) {
      printf("data : %s\n", recv_buffer);
    }
  }

  close(sock);

  return 0;
}