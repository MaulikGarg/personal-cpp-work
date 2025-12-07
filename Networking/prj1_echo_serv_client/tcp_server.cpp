#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include <iostream>
#include <string.h>

#define PORT 8080
#define BUFSIZE 1024

bool setupServer(addrinfo*& results);  // true on success

int main() {
  // the socket storage
  int listen_fd, conn_fd;
  // address storage
  struct sockaddr_in serv_addr;
  struct sockaddr client_addr;
  // client storage length
  socklen_t client_len = sizeof(client_addr);
  // received bytestream
  char buf[BUFSIZE];

  addrinfo* results{nullptr};
  if (!setupServer(results)) return -1;

  listen_fd = socket(results->ai_family, results->ai_socktype, results->ai_protocol);
  if (listen_fd == -1) {
    perror("socket");
  }

  int bindResult = bind(listen_fd, results->ai_addr, results->ai_addrlen);
  if (bindResult == -1) {
    perror("bind");
  }

  int listenResult = listen(listen_fd, BUFSIZE);
  if (listenResult == -1) {
    perror("listen");
  }
  std::cout << "Now listening on port: " << PORT << '\n';

  conn_fd = accept(listen_fd, &client_addr, &client_len);
  if (conn_fd == -1) {
    perror("accept");
  }
  else{
    std::cout << "Client connected!\n";
  }

  while(true){
    int bytesRecvd = recv(conn_fd, buf, BUFSIZE, 0);
    if(!bytesRecvd) break;
    if(bytesRecvd < 0){
        perror("recv");
    }
    int bytesSent = send(conn_fd, buf, bytesRecvd, 0);
    if(bytesSent < 0){
        perror("send");
    }
  }

  freeaddrinfo(results);
  close(listen_fd);
}

bool setupServer(addrinfo*& results) {
  addrinfo hints{};
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;

  int status = getaddrinfo(NULL, "8080", &hints, &results);
  if (status) {
    std::cerr << "getaddrinfo error: " << gai_strerror(status) << std::endl;
    return false;
  }
  return true;
}

