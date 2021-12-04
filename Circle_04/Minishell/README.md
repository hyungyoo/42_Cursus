# MINISHELL

## 구현 과정

####1. readline + signal
> Readline함수를 이용하여, line에 명령어를 받을수있다.
이렇게 받은 명령어를 두가지로 나눈다. (line== NULL, line != NULL)
line != NULL 일 경우에는, 명령어로, line == NULL인 경우에는, EOF로 받아들여, exit가 되도록한다 (ctrl + d)
또한, signal 함수를 이용하여, sigint, sigquit두가지를 받아, /b, /n,/r를 이용하여, readline을 새로 출력한다.
자식 프로세스가 있는 경우, sigint, sigquit를 받았을때, 따로 핸들러함수를 만들어 readline을 출력한다.

####2. Tokenization

####3. Expansion

####4. Builtin function

####5. execuve function

####6. redirection

####7. pipe

####8. norminette



## 고칠점

