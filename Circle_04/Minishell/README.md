# To do list keulee (update date: 11.09.2021)
> 1. 논의

# Code log (update date: 12.10.2021)
> 1. parsing_arg_word.c (argument_word 함수) 추가 : 오퍼레이션 워드, 싱글/더블쿼터 제외한 나머지 모두 파싱하는 함수. (이후 적절한 조치 (strjoin 등)을 통해 exec argument로 사용 기대)  
	 일반 알파벳 (is letter)일때인 경우와 그렇지 않은 다른 문자들의 경우로 나눠 line이 null이 아닐때까지 진행해 str을 뽑아냄.  

# Code log (update date: 11.10.2021)
> 1. ft_exit.c 추가 : 형준이 ft_exit에다가 argument로 int 변수 exit_code 추가
> 2. parsiing_operation_word : <, >, >>, <<, |, $ 와 같은 오퍼레이션 토큰 파싱 후 list에 추가
> 3. parsing_quote.c : 09일 code log에서와 같이 싱글쿼터, 더블쿼터로 나눠진 토큰을 싱글쿼터, 더블쿼터 타입으로 나눠 cmd_node에 추가 함.
> 4. list.c : free_list함수 추가로 while 마지막에가서 cmd_node를 비워주고 리셋함. (다음 커맨드를 받기 위해)

# Code log (update date: 09.10.2021)
> 1. 학교 맥에서 하다보니 학교 readline 컴파일 경로를 makefile에 넣어둠. linux에서 사용할 때는 readline 인클루드/라이브러리 패스를 바꿔야할 수도 있음 참고!
> 2. 쿼터가 짝이 안맞을 시, Syntax error 뜨도록 업데이트.(터미널에서 >quote >dquote로 출력되는 부분 모두 Syntax error처리)  
echo "hihi"  ==>  파싱 성공  
echo "hihi'hihi" ==> 파싱 성공  
echo "hihi"hihi" ==> Syntax error  
echo "hihi'hihi" 'hihi"hihi' ==> Syntax error  
> 3. ascii_logo 추가 (이렇게 하는 게 아니라 txt를 open해서 하는 거 같은데 귀찮아서 ft_putendl로 추가... 웃어도 됨...하하...)
> 4. list.c 추가 -> s_cmd struct를 기준으로 내부에 s_node를 추가. s_cmd는 노드 수를 체크하고 각 노드는 타입에 따라 커맨드라인 안의 토큰(파싱단위)를 저장.
예1) echo hihi | grep hi (노드 수 5 / echo : WORD(type) / hihi : WORD / | : PIPE / grep : WORD / hi : WORD)
예2) cat << done | ls -al >> out (노드 수 8 / cat : word / << : DLESS / done : word / ls : word / -al : word / >> : DGREAT / out : word)
> 5. copy_env, signal 형준이 코드로 추가 및 변경

