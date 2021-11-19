
1. ls | << end
ls가 heredoc의 인자로 들어간다.

2. >file | ls // < Makefile cat > file | ls
    file에 ls의 출력값이 들어간다.

    ft_fd_checker_pipe에서 pipe[0]을 right인자를 주었더니, ls는 file안으로 들어가지않는다.
    다만, makefile의 내용도 들어가지않는다

3. < Makefile  | cat
    cat에 Makefile값이 출력된다.

4. export 오류!--> 나머지는출력 하나라도 오류가있다면 리턴갑승ㄴ 1
	오류가잇어도 나머지는 입력되야한다.

	1.!!! copy_env와같이 cmd를 가져와서 거기에있는 전부를 복사한다.
	복사하여 이중으로 만든후,
	오류체크를 한다.
	오류라면, 그 str[i]는 빼고 다시 말록하여 정리
	



herdoc은 뒤에명령어가있어도 아무상관없이 실행되어야하며,
중요한건 <가 앞에맨뒤에있는지 뒤에있는지가중요하다
