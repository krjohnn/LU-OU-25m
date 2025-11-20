#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

#define MAXLINE 200
#define MAXARG 20

extern char **environ;

void env(void) {
    int i;
    for (i = 0; environ[i] != NULL; i++) {
        printf("%s\n", environ[i]);
    }
}

void exitsh(int status) {
    _exit(status);
}

void execute(char *arg[]) {
    pid_t pid;
    int status;
    pid = fork();
    
    if (pid > 0) {
        wait(&status);
    } else if (pid == 0) {
        execvp(arg[0], arg);
        printf("Komanda nav atrasta\n");
        exitsh(0);
    } else {
        /* Fixed syntax error: String cannot be split across lines without quotes */
        printf("Kluda fork() sistemas izsaukuma\n");
    }
}

void help(void){
    printf("Available commands:\n");
    printf("  env         - Show environment variables\n");
    printf("  exit        - Exit shell\n");
}

int main(void) {
    char cmd[MAXLINE];
    char *cmdp;
    char *av[MAXARG];
    int i;

    while (1) {
        printf("$toyshell$> ");
        fgets(cmd, sizeof(cmd), stdin);

        if (strcmp(cmd, "env\n") == 0) {
            env();
        } else if (strcmp(cmd, "exit\n") == 0) {
            exitsh(0);
        } else if (strcmp(cmd, "help\n") == 0) {
            help();
        } else {
            cmdp = cmd;
            for (i = 0; i < MAXARG; i++) {
                av[i] = strtok(cmdp, " \t\n");
                cmdp = NULL;
            }
            execute(av);
        }
    }
    return (0);
}
