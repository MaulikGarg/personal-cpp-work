#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include <iostream>

#define BUFSIZE 1024

int main() {
  addrinfo* results;
  addrinfo hints{};
  hints.ai_family = AF_INET6;
  hints.ai_socktype = SOCK_DGRAM;

  int status = getaddrinfo("localhost", "8080", &hints, &results);
  if (status) {
    std::cerr << "getaddrinfo error: " << gai_strerror(status) << std::endl;
    return false;
  }

  int sock_fd = socket(results->ai_family, results->ai_socktype, results->ai_protocol);
  if (sock_fd == -1) {
    perror("socket");
  }
  std::cout << "Setup complete. Type: ";

  char buf[BUFSIZE];
  sockaddr_storage senderaddr;
  socklen_t senderaddrsize = sizeof(senderaddr);
  while (std::cin.getline(buf, BUFSIZE)) {
    int len = strlen(buf);
    int bytesSent = sendto(sock_fd, buf, len, 0, results->ai_addr, results->ai_addrlen);
    if (bytesSent < 0) perror("send");

    len = recvfrom(sock_fd, buf, BUFSIZE, 0, (sockaddr*)&senderaddr, &senderaddrsize);
    if (len < 0) {
      perror("recv");
    }
    buf[len] = '\0';
    std::cout << "Echo: " << buf << std::endl;
  }

  freeaddrinfo(results);
  close(sock_fd);
}
