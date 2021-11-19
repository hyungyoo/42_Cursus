
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
	0. split 을 건드려야할듯
	1.스를릿을한 함수에서, 가져와서 스플릿중에서 필요없는건 빼고 다시 스플릿하기.
	다른스트리에서 다시교체하던가..
