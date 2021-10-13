# minishell
42 project minishell to write a shell



1. 문제점
	cpy_env leaks! valgirnd

2. < cmd1 o
  < cmd1 | arg1j2 ==> arg1j2 부터된다.
  노드 저장이안됨

3. grep valgrind -v 

4. cmd_access !!


	
--------

## Resume of the subject (Mandatory)

1. program name : minishell
2. Makefile     : yes
3. Libft        : yes
4. External functions
```
readline, rl_clear_history, rl_on_new_line, rl_replace_line, rl_redisplay, add_history, printf, 
malloc, free, write, open, read, close, fork, wait, waitpid, wait3, wait4, signal, kill, exit, 
getcwd, chdir, stat, lstat, fstat, unlink, execve, dup, dup2, pipe, opendir, readdir, closedir, 
strerror, perror, isatty, ttyname, ttyslot, ioctl, getenv, tcsetattr, tcgetattr, tgetent, tgetflag, 
tgetnum, tgetstr, tgoto, tputs
```

### To do List

Your shell should:
1. Not interpret unclosed quotes or unspecified special characters like \ or ;.
2. Not use more than one global variable, think about it and be ready to explain why you do it.
3. Show a prompt when waiting for a new command.
4. Have a working History.
5. Search and launch the right executable (based on the PATH variable or by using relative or absolute path)
6. It must implement the builtins:
```
 * echo with option -n
 * cd with only a relative or absolute path
 * pwd with no options
 * export with no options
 * unset with no options
 * env with no options or arguments
 * exit with no options
```
7. ’ inhibit all interpretation of a sequence of characters.
8. " inhibit all interpretation of a sequence of characters except for $.
9. Redirections:
```
 * < should redirect input.
 * > should redirect output.
 * “<<” read input from the current source until a line containing only the delimiter is seen.
    it doesn’t need to update history!
 * “>>” should redirect output with append mode
```
10. Pipes | The output of each command in the pipeline is connected via a pipe to the input of the next command.
11. Environment variables ($ followed by characters) should expand to their values.rrrrr
12. $? should expand to the exit status of the most recently executed foreground pipeline.
13. ctrl-C ctrl-D ctrl-\ should work like in bash.
14. When interactive:
```
 * ctrl-C print a new prompt on a newline
 * ctrl-D exit the shell.
 * ctrl-\ do nothing.
```
> readline function can produce some leak you don’t need to fix this.
> But beware your own code should not produce leaks.
> You should limit yourself to the subject description.
> Anything not asked is not required.
> For every point, if you have any doubt take bash(https://www.gnu.org/savannah-checkouts/gnu/bash/manual/) as a reference.

## Bonus part

1. If the Mandatory part is not perfect don’t even think about bonuses
2. &&, || with parenthesis for priorities.
3. the wildcard * should work for the current working directory.
