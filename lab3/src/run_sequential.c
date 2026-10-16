#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
  if (argc != 3) {
    printf("Usage: %s seed arraysize\n", argv[0]);
    return 1;
  }

  pid_t child_pid = fork();
  if (child_pid < 0) {
    printf("Fork failed!\n");
    return 1;
  }

  if (child_pid == 0) {
    // child process: заменяем его образ программой sequential_min_max
    char *args[] = {"./first_task", argv[1], argv[2], NULL};
    execv(args[0], args);
    // сюда попадаем, только если exec не удался
    perror("execv");
    return 1;
  }

  int status;
  waitpid(child_pid, &status, 0);
  if (WIFEXITED(status)) {
    printf("first_task finished with code %d\n", WEXITSTATUS(status));
  }
  return 0;
}