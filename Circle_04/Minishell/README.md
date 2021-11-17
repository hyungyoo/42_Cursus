
1. ls | << end
ls가 heredoc의 인자로 들어간다.

2. >file | ls // < Makefile cat > file | ls
    file에 ls의 출력값이 들어간다.

3. < Makefile  | cat
    cat에 Makefile값이 출력된다.
