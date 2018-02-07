/* This program is created as a Project Solution
 * for Project 1.1 in CS 426 - OS.
 * This program will create the Collatz
 * Conjecture, using a child and parent
 * process to further understand process dynamics.
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>


int main() {

    pid_t pid;
    int startNum = 35;

    /* Fork a child process */
    pid = fork();

    if(pid < 0) {
        //Error handling to make sure the process worked
        fprintf(stderr, "Fork Failed");
        return 1;
    }

    if(pid == 0)    {
        //Child Process for The Collatz conjecture
        while(startNum != 1)    {
            printf("%d, ", startNum);
            if(startNum % 2 == 0)   {
                //Even case
                startNum = startNum/2;
            }
            else    {
                //Odd case
                startNum = 3 * startNum + 1;
            }
        }

        //Print final number, should be 1
        printf("%d\n", startNum);
    }

    else    {
        //Parent Process
        wait(NULL);
        printf("Child Complete.");
    }

    return 0;
}