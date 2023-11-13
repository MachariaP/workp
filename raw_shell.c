#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <limits.h>

void our_shell_print(const char *to_print);
int read_command_entered(char *command_entered);
char **handling_command_entered_args(char *command_entered, char **args_present);
char *pathfinder(char *command_entered);
void command_entered_execution(char *command_entered);


int main() 
{
    while (1) 
      {
        char *command_entered = NULL;
        char *argV[] = {NULL};
        int is_empty;
        char **args_present;;
        

        
        // int execution_result = execve("/bin/ls", argV, NULL);

            // Create prompt
        our_shell_print("ourshellproject$ ");
        read_command_entered(command_entered); 
        our_shell_print(command_entered);
        handling_command_entered_args(command_entered, args_present);
        char *pathfinder(char *command_entered);
        command_entered_execution(command_entered);

        free(command_entered);
        }
    
    return (0);
}


 void our_shell_print(const char *to_print)
    {
        write(1, to_print, strlen(to_print));
    }

int read_command_entered(char *command_entered) 
{
       
        size_t command_length = 0;
        ssize_t command_read;
        command_entered = NULL;
        
    // Read user input
    command_read = getline(&command_entered, &command_length, stdin);

    // Check for read errors or end of input
    if (command_read != -1) 
    {
            if (feof(stdin))
            {
                return (-1);
            }
            
            else
            {
                {
                perror("failed to read command_entered");
                
                    exit(1);
                }
            }
            
    } 
    
        //Replace new line with null character
    char *new_line = strchr(command_entered, '\n');
    if (new_line != NULL) 
            {
                *new_line = '\0';
            }
    free (command_entered);
    return(command_read);
        
}

  

void command_entered_execution(char *command_entered) 
{
    extern char **environ;
    int status;
    char **args_present;
    char *ourcommand_path;
    char *our_full_path;
    
    handling_command_entered_args(command_entered, args_present);
    pid_t process_id;

    process_id = fork();

    if (process_id < 0) 
    {
        perror("Error while forking");
        exit(-1);
    } else if (process_id == 0) 
    {
        ourcommand_path = pathfinder(*args_present);
        // Child process
        if (ourcommand_path == NULL)
        perror("command not found");
        exit(1);


        
        // Use execve to execute the command entered with no environment variables
        int execution_result = execve(ourcommand_path, args_present, environ);

        if (execution_result == -1) 
        {
            perror("Program execution failed");
            exit(-1);
        }

       
    } else {
        // Parent process
                waitpid(process_id, &status, 0);

                if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
                {
                    our_shell_print("child process exited with non zero status");
                }
    }
}
char **handling_command_entered_args(char *command_entered, char **args_present)
{
     char *partitioner = " ";
     char *token;
     int ourshell_buffersize;
        int args_counter = 0;
        
        args_present = NULL;

        args_present = malloc(sizeof(char *) *(ourshell_buffersize + 1)); 

        if (args_present == NULL)
        {
            free(args_present);
            perror("memory allocation for arg_present failed");
            exit(1);
        }
         // Tokenize arguments
        token = strtok(command_entered, partitioner);

        while (token != NULL) 
        {
        
            args_present[args_counter] = token;

            args_counter++;
            token  = strtok(NULL, partitioner);
        }
         args_present[args_counter] = NULL;

         return(args_present);
}
char *pathfinder(char *command_entered)
{
    char **ourshell_path;
    char *ourpath_copy;
    char *ourpath_token;
    char *boundery = ":";
    int command_entered_length;
    char **our_full_path;
    int each_dir_length;
    
    
    *ourshell_path = getenv("PATH");

    if (ourshell_path == NULL)
    {
        return(NULL);
    }
    if (strlen(*ourshell_path) == 0)
    {
        return(NULL);
    }
    //make a copy of our main path
    ourpath_copy = (char *)malloc((sizeof(*ourpath_copy) * sizeof(ourshell_path) + 1));

    if (ourpath_copy == NULL)

        perror("failed to allocate copy memory");
        exit(-1);
    strcpy(*ourshell_path, ourpath_copy);


    command_entered_length = strlen(command_entered);


    ourpath_token = strtok(ourpath_copy, boundery);

    while(*ourpath_token)
    {
        *our_full_path = NULL;

        *our_full_path = (char *)malloc((command_entered_length + each_dir_length + 1) * sizeof(char) + sizeof(char));
        each_dir_length = strlen(ourpath_token);
        
      

        strcpy(*our_full_path, ourpath_token);
        strcat(*our_full_path, "/");
        strcat(*our_full_path, command_entered);
        strcat(*our_full_path, "\0");

        if (access(*our_full_path, F_OK) == 0) 
        {
    // File exists
        
        free(ourpath_copy);
        return *our_full_path;
        }

        else
        {
                free(our_full_path);
                ourpath_token = strtok(NULL, ":");

        }

        }
 
    free(ourpath_copy);


    if (access(command_entered, F_OK) == 0)
        {
            return (command_entered);
        }


    return (NULL);
    }


