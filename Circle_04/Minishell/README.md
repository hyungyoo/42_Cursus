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
p_MK6jaYa9YmoTnfP72I3qr3jhXtKTbr4b7lOQ
# MINI_SHELL

### MINISHELL이란?
	shell은 kernel과 user를 이어주는것!
	 스티븐 본에 의해서 개발되었으며, 현재는 bash, zsh etc.
	 CLI 또는 GUI로 나뉨
	
	kernel과 user는 os에서의  dual mode이다!
	kernel은 컴퓨터의 메모리에 는 적재되어있으며, 프로세스, 메모리, 입출력, 파일관리등을 한다.
	user 모드에서 kernel의 기능을 사용하는 방법은 시스템콜을 하는것.
         즉, user모드에서 시스템콜을 하여 kernel의 기능을 사용하기위해서는
	 user->shell->kernel->shell->user 의 과정을 갖는다.

### SHELL의 구성요소
	TOKENIZER-> TOKEN으로 나눔
	LEXER-> 나누어진 TOKEN의 의미를 분석
	PARSER-> 위의 두 단계로 얻은 TOKEN을 구조적으로 나타내어주며,  명령테이블에 저장
	EXERCUTOR-? 명령테이블의 모든명령에 대해 새 프로세스를 생성

### 1. 명령어 정리
	1. echo
		출력
	2. cd, pwd
		디렉토리
	3. export, unset, env
		환경 변수
	4. exit
		프로세스 종료함수
	5. ;
		명령어 구분
	6. ""
		문자를 그대로 받음
	7. 리디렉션
		표준입력 표준출력 보내기
	8. 파이프
		Pipex
	9. ctrl + c, ctrl + d, ctrl + \
		스크립트 제어

### 2. 함수정리
	1. readline 
	2. rl_clear_history 
	3. rl_on_new_line
	4. rl_replace_line
	5. rl_redisplay 
	6. add_history
          
	7. printf
	8. malloc 
	9. free 
	10. write 
	11. open 
	12. read 
	13. close 
	
        14. fork 
	15. wait
	16. waitpid 
	17. wait3, wait4
	18. signal 
	19. kill 
	20. exit 

	21. getcwd
	22. chdir 
	23. stat 
	24. lstat 
	25. fstat 
	26. unlink 

	27. execve 
	28. dup, dup2
	29. pipe 

	30. opendir 
	31. readdir 
	32. closedir 

	33. strerror,perror
	34. isatty 
	35. ttyname 
	36. ttyslot 
	37. ioctl 
	38. getenv

	39. tcsetattr
	40. tcgetattr 
	41. tgetent 
	42. tgetflag 
	43. tgetnum
	44. tgetstr 
	45. tgoto 
	46. tputs


	ft_putstr_fd("\x1b[1A", STDOUT);
	ft_putstr_fd("\033[12C", STDOUT);
	https://tldp.org/HOWTO/Bash-Prompt-HOWTO/x361.html

brew install readline
#In your compilation, append these flags:
-lreadline -L /Users/$(USER)/.brew/opt/readline/lib -I/Users/$(USER)/.brew/opt/readline/include

### 2. 구현 순서
	1. 변수, 구조체 초기화
	2. 헤더 stdio.h를 제일 위로(구조체 참조)
        3. Parsing cmd, args
        4. Fork (child process)
        5. Execuve

