# Pipex

Mimic the unix pipe mechanism.

## How to run

The program must be executed as follows:
./pipex file1 cmd ... cmd_n file2

In bash it will look like this:
< file1 cmd | ... | cmd_n > file2

The program is able to handle multiple as well as a single pipe.

## Progress

During this project I used some interesting library functions: pipe(), fork(), dup2(). In addition, I learned the importance of handling the file descriptors properly.
