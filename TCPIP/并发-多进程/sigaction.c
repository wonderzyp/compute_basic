#include <stdio.h>
#include <unistd.h>
#ifndef __USE_POSIX
#define __USE_POSIX   // vscode中不添加无法智能补全 
                      // 环境: wsl2
#endif
#include <signal.h>


void timeout(int sig){
  if (sig==SIGALRM)
    puts("Time out!\n");
  alarm(2);
}

void press_keyboard(int sig){
  if (sig == SIGINT)
    puts("CTRL+C pressed\n");
}


int main(int argc, char* argv[]){
  int i;
  struct sigaction act;
  act.sa_handler = timeout;
  sigemptyset(&act.sa_mask);
  act.sa_flags = 0;

  struct sigaction act_press;
  act_press.sa_handler = press_keyboard;
  sigemptyset(&act_press.sa_mask);
  act_press.sa_flags = 0;

  sigaction(SIGALRM, &act, 0);
  sigaction(SIGINT, &act_press, 0);

  alarm(2);

  for(int i=0; i<3; ++i){
    puts("wait...");
    sleep(100); // 调用信号处理器以响应信号时，进程会被唤醒而不再进入睡眠态度，实际上不会sleep规定时间
  }
  return 0;
}
