#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <fcntl.h>

#define SIZE 1024
#define MAX_ARGS 64

void redirection(char **args);


int main(int argc, char const *argv[])
{
    char cmd[SIZE];

    char *args[MAX_ARGS];
    char *token;

    pid_t pid;
    int status;
    char dir[SIZE];


    while(1){
        if(getcwd(dir,sizeof(dir))!= NULL){
            printf("%s> ", dir);
        }
        
        fgets(cmd,SIZE-1,stdin);  //users input
        cmd[strlen(cmd)-1] = '\0'; 
        
        //parsing inputs
        int i = 0;
        token = strtok(cmd," ");
        while(token != NULL && i < MAX_ARGS - 1){
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;
    

        //exits shell
        if(strcmp(cmd,"exit") == 0){ 
            break;
        }

        //cd
        if(strcmp(args[0], "cd") == 0){
            if(chdir(args[1])!= 0){
                perror("cd");
            }
            continue;
        }


        //ext commands
        pid = fork();
        if(pid==0){
            redirection(args);
            execvp(args[0],args);
            exit(1);
        
        }else{
            waitpid(pid,&status,0);
        }
    }
    return 0;
    
}

void redirection(char **args){
    for(int i = 0; args[i] != NULL;i++){
        if(strcmp(args[i], ">") == 0){
            //open, create, trunc file, 0644 = permissions
            int fd = open(args[i+1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if( fd < 0) {
                exit(1);
            }
            dup2(fd, STDOUT_FILENO); //to file
            close(fd);
            args[i] = NULL;
            i++;

        }else if(strcmp(args[i],"<")==0){
            int fd = open(args[i+1], O_RDONLY);
            if (fd < 0){
                exit(1);
            }
            dup2(fd, STDIN_FILENO); // from
            close(fd);
            args[i] = NULL;
            i++;
        }
    }
}