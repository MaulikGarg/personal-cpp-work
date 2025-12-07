#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include <iostream>
#include <string.h>

#define BUFSIZE 1024

bool setupServer(addrinfo*& results);

int main(){

  // setup
  addrinfo* results;
  if(!setupServer(results)){
    return -1;
  }

  // get the socket
  int socket_fd = socket(results->ai_family, results->ai_socktype, results->ai_protocol);
  if(socket_fd == -1){
    perror("socket");
  }

  // bind the ip and port to the socket
  if(bind(socket_fd, results->ai_addr, results->ai_addrlen) == -1) perror("bind");
  std::cout << "Port 8080 falling in!\n";

  // now receive until the connection is closed
  char buf[BUFSIZE];
  sockaddr_storage senderaddr;
  socklen_t senderaddrsize = sizeof(senderaddr);
  int len;
  while(true){
    len = recvfrom(socket_fd, buf, BUFSIZE, 0, (sockaddr*)&senderaddr, &senderaddrsize);
    if(len == -1) perror("recfrom");

    len = sendto(socket_fd, buf, len, 0, (sockaddr*)&senderaddr, senderaddrsize);
    if(len == -1) perror("sendto");
  }

  close(socket_fd);
  freeaddrinfo(results);

}

bool setupServer(addrinfo*& results) {
  addrinfo hints{};
  hints.ai_family = AF_INET6;
  hints.ai_socktype = SOCK_DGRAM;
  hints.ai_flags = AI_PASSIVE;

  int status = getaddrinfo(NULL, "8080", &hints, &results);
  if (status) {
    std::cerr << "getaddrinfo error: " << gai_strerror(status) << std::endl;
    return false;
  }
  return true;
}
