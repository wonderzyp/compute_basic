/**
* @brief 基于epoll实现I/O复用并发服务端
* ****************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <sys/epoll.h>

#define BUF_SIZE 100
#define EPOLL_SIZE 50
void error_handling(char *buf);

int main(int argc, char* argv[]){
  int serv_sock, clnt_sock;
  struct sockaddr_in serv_adr, clnt_adr;
  socklen_t adr_sz;
  int str_len, i;
  char buf[BUF_SIZE];

  struct epoll_event *ep_events;
  struct epoll_event event;
  int epfd, event_cnt;

  if (argc!=2){
    printf("Usage: %s <port>\n", argv[0]);
    exit(1);
  }
  
  serv_sock = socket(PF_INET, SOCK_STREAM, 0);
  memset(&serv_adr, 0, sizeof(serv_adr));
  serv_adr.sin_family = AF_INET;
  serv_adr.sin_addr.s_addr = INADDR_ANY;
  serv_adr.sin_port = htons(atoi(argv[1]));

  if (bind(serv_sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr))==-1)
    error_handling("bind() error\n");
  if (listen(serv_sock, 5)==-1)
    error_handling("listen() error\n");
  
  epfd = epoll_create(EPOLL_SIZE);
  ep_events = malloc(sizeof(struct epoll_event)*EPOLL_SIZE);

  event.events = EPOLLIN;
  event.data.fd = serv_sock;
  epoll_ctl(epfd, EPOLL_CTL_ADD, serv_sock, &event);

  while(1){
    event_cnt = epoll_wait(epfd, ep_events, EPOLL_SIZE, -1); // 等待文件描述符发生变化
    // epoll_wait返回时，直接在ep_events中写入发生事件的fd集合，无需遍历所有fd
    // epoll_wait返回发生事件的fd数量
    if (event_cnt==-1){
      puts("epoll_wait() error\n");
      break;
    }
    for (int i=0; i<event_cnt; ++i){
      if (ep_events[i].data.fd == serv_sock){
        adr_sz = sizeof(clnt_adr);
        clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_adr, &adr_sz);
        event.events = EPOLLIN; // 发生需要读取数据的事件
        event.data.fd = clnt_sock;
        epoll_ctl(epfd, EPOLL_CTL_ADD, clnt_sock, &event);
        printf("connected client: %d\n", clnt_sock);
      }
      else{ 
        str_len = read(ep_events[i].data.fd, buf, BUF_SIZE);
        if (str_len==0){ // 已读完，关闭
          epoll_ctl(epfd, EPOLL_CTL_DEL, ep_events[i].data.fd, NULL);
          close(ep_events[i].data.fd);
          printf("closed client: %d\n", ep_events[i].data.fd);
        }
        else{
          write(ep_events[i].data.fd, buf, str_len);
        }
      }
    }
  }
  close(serv_sock);
  close(epfd);
  return 0;
}


void error_handling(char *message){
  fputs(message, stderr);
  fputc('\n', stderr);
  exit(1);
}