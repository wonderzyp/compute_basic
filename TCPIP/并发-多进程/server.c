/**
* @brief 多进程-服务端
* 借助signation+waitpid处理僵尸进程
* ****************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#ifndef __USE_POSIX
#define __USE_POSIX   // vscode中不添加无法智能补全 
                      // 环境: wsl2
#endif
#include <signal.h>

#define BUF_SIZE 30
void error_handling(char *message);
void read_childproc(int sig);

int main(int argc, char* argv[]){
  int serv_sock, clnt_sock;
  struct sockaddr_in serv_adr, clnt_adr;
  
  pid_t pid;
  struct sigaction act;
  socklen_t adr_sz;
  int str_len, state;

  char buf[BUF_SIZE];
  if (argc!=2){
    printf("Usage: %s <port>\n", argv[0]);
    exit(1);
  }

  // 清理僵尸进程
  act.sa_handler = read_childproc;
  sigemptyset(&act.sa_mask);
  act.sa_flags = 0;
  state = sigaction(SIGCHLD, &act, 0);

  serv_sock = socket(PF_INET, SOCK_STREAM, 0);
  memset(&serv_adr, 0, sizeof(serv_adr));
  serv_adr.sin_family = AF_INET;
  serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_adr.sin_port = htons(atoi(argv[1]));

  if (bind(serv_sock, (struct sockaddr*) &serv_adr, sizeof(serv_adr))==-1)
    error_handling("bind() error\n");
  if (listen(serv_sock, 5)==-1)
    error_handling("listen() error\n");

  while (1)
  {
    adr_sz = sizeof(clnt_adr);
    clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_adr, &adr_sz);
    if (clnt_sock == -1)
      continue;
    else
      puts("new client connected...\n");

    pid = fork();
    if (pid == -1){
      close(clnt_sock);
      continue;
    }

    if (pid == 0){
      // 子进程区域
      close(serv_sock);
      while((str_len = read(clnt_sock, buf, BUF_SIZE))!=0)
        write(clnt_sock, buf, str_len);
      close(clnt_sock);
      puts("client disconnected...\n");
      return 0;  
    }else
      // 父进程关闭clnt_sock
      close(clnt_sock);
  }
  close(serv_sock);
  return 0;
}

void error_handling(char *message){
  fputs(message, stderr);
  fputc('\n', stderr);
  exit(1);
}

void read_childproc(int sig){
  pid_t pid;
  int status;
  pid = waitpid(-1, &status, WNOHANG);
  printf("remove proc id: %d \n", pid);
}