/* Implement your shell here */


#include <sys/wait.h>
#include <sysexits.h>
#include <stdlib.h>
#include <err.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#define MAX 1024


int main(){
    pid_t pid;
    char buffer[MAX + 1], *argv[MAX + 1], temp[2][MAX + 1];
    int i = 0;

    printf("shell_jr: ");
    fflush(stdout);
    while(fgets(buffer, MAX + 1, stdin)){
        sscanf(buffer, "%s %s", temp[0], temp[1]);
        for(i = 0; i < 2; i++){
            argv[i] = temp[i];
        }
        argv[2] = NULL;
        if(strcmp("exit", argv[0]) == 0){
            printf("See you\n");
            fflush(stdout);
            exit(0);
        }
        else if(strcmp("hastalavista", argv[0]) == 0){
            printf("See you\n");
            fflush(stdout);
            exit(0);
        }
        else if(strcmp("cd", argv[0]) == 0){
            if(chdir(argv[1]) == -1){
                err(EX_OSERR, "Cannot change to directory %s", argv[1]);
			    fflush(stdout);
            }
        }
        else{
            pid = fork();
            if(pid < 0){
                err(EX_OSERR, "fork error");
            }
            if(!pid){
                execvp(argv[0], argv);
                printf("Failed to execute %s\n", argv[0]);
	            fflush(stdout);
	            exit(EX_OSERR);
            }
            else{
                wait(NULL);
            }
        }

        printf("shell_jr: ");
        fflush(stdout);



    }


    return 0;
}