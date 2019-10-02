#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int my_cd(char **args);
int my_exit(char **args);
char *builtin_str[] = {
  "cd",
  "exit"
};
int (*builtin_func[]) (char **) = {
  &my_cd,
  &my_exit
};
int my_num_builtins() {
  return sizeof(builtin_str) / sizeof(char *);
}
int my_cd(char **args)
{
  if (args[1] == NULL) {
    fprintf(stderr, "home: expected argument to \"cd\"\n");
  } else {
    if (chdir(args[1]) != 0) {
      perror("home:");
    }
  }
  return 1;
}
int my_exit(char **args)
{
  return 0;
}
int launch(char **args)
{
  pid_t pid;
  int status;
  pid = fork();
  if (pid == 0) {
    if (execvp(args[0], args) == -1) {
      perror("home");
    }
    exit(EXIT_FAILURE);
  } else if (pid < 0) {
    perror("home");
  } else {
waitpid(pid,&status,NULL);
 }

  return 1;
}
int execute(char **args)
{
  int i;
  if (args[0] == NULL) {
    return 1;
  }
  for (i = 0; i < my_num_builtins(); i++) {
    if (strcmp(args[0], builtin_str[i]) == 0) {
      return (*builtin_func[i])(args);
    }
  }
  return launch(args);
}
#define READ_BUFSIZE 1024
char *read_line(void)
{
  int bufsize = READ_BUFSIZE;
  int position = 0;
  char *buffer = malloc(sizeof(char) * bufsize);
  int c;
  if (!buffer) {
    fprintf(stderr, "home: allocation error\n");
    exit(EXIT_FAILURE);
  }
  while (1) {
    c = getchar();
    if (c == EOF) {
      exit(EXIT_SUCCESS);
    } else if (c == '\n') {
      buffer[position] = '\0';
      return buffer;
    } else {
      buffer[position] = c;
    }
    position++;
    if (position >= bufsize) {
      bufsize += READ_BUFSIZE;
      buffer = realloc(buffer, bufsize);
      if (!buffer) {
        fprintf(stderr, "home: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }
  }
}
#define TOK_BUFSIZE 64
#define TOK_DELIM " \t\n"
char **split_line(char *line)
{
  int bufsize = TOK_BUFSIZE, position = 0;
  char **tokens = malloc(bufsize * sizeof(char*));
  char *token, **tokens_backup;
  if (!tokens) {
    fprintf(stderr, "home: allocation error\n");
    exit(EXIT_FAILURE);
  }
  token = strtok(line, TOK_DELIM);
  while (token != NULL) {
    tokens[position] = token;
    position++;
    if (position >= bufsize) {
      bufsize += TOK_BUFSIZE;
      tokens_backup = tokens;
      tokens = realloc(tokens, bufsize * sizeof(char*));
      if (!tokens) {
		free(tokens_backup);
        fprintf(stderr, "home: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }
    token = strtok(NULL, TOK_DELIM);
  }
  tokens[position] = NULL;
  return tokens;
}

void loop(void)
{
  char *line;
  char **args;
  int status;
  do {
    printf("> ");
    line = read_line();
    args = split_line(line);
    status = execute(args);
    free(line);
    free(args);
  } while (status);
}
int main(int argc, char **argv)
{
  loop();
  return EXIT_SUCCESS;
}

