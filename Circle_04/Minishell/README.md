문제;

bash-3.2$ echo$PWD
bash: echo/Users/hyungyoo: No such file or directory
bash-3.2$ echo$PATH
bash: echo/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Library/Apple/usr/bin: No such file or directory
bash-3.2$
즉, $ARG는 $후에, nospace ==1, next->type == ARG일떼, env값을 반환해야한다.

minishell $> echo \n\n\n       ---> nnn 이어야함
Minishell: Syntax error
