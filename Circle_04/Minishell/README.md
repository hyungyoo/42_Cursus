
1. ls | << end
ls가 heredoc의 인자로 들어간다.

2. >file | ls // < Makefile cat > file | ls
    file에 ls의 출력값이 들어간다.

    ft_fd_checker_pipe에서 pipe[0]을 right인자를 주었더니, ls는 file안으로 들어가지않는다.
    다만, makefile의 내용도 들어가지않는다

3. < Makefile  | cat
    cat에 Makefile값이 출력된다.
