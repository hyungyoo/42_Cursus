# MINISHELL

## 구현 과정

### 1. readline + signal
> Readline함수를 이용하여, line에 명령어를 받을수있다.
이렇게 받은 명령어를 두가지로 나눈다. (line== NULL, line != NULL)
line != NULL 일 경우에는, 명령어로, line == NULL인 경우에는, EOF로 받아들여, exit가 되도록한다 (ctrl + d)
또한, signal 함수를 이용하여, sigint, sigquit두가지를 받아, /b, /n,/r를 이용하여, readline을 새로 출력한다.
자식 프로세스가 있는 경우, sigint, sigquit를 받았을때, 따로 핸들러함수를 만들어 readline을 출력한다.

### 2. Tokenization
> line 으로 받은 명령어를 토큰화(parsing)한다. 
> > 예) cmd1 arg arg | < file cmd2 arg | cm3 > file2
이런경우, 각각을 노드로 만들어, 각 str, type, flag (예: cmd1 --> str= cmd1, type = cmd, flag..etc)등을 저장한다.

### 3. Expansion
> 환경변수,  BLABLA=42 를 key와 value값으로 나누어, key = BLABLA, value = 42로 바로 참조할수있도록, env값을 노드로 만들어, key, value, str으로 나눈다. (예: str = BLABLA=42, key = BLABLA, value = 42)
그렇게 만들어진 링크드리스트 env 값은, 명령어 env, export, unset, expansion등에 쓰이게된다.
expansion은, 명령어에서 key값이 있다면(예: $BLABLA), 명령어는 42로 받아진다. (예: cmd1 $BLABLA == cmd1 42)

### 4. Builtin function
> 빌트인 함수는, cd, exit, export, unset, env, pwd 그리고 echo가 있다.
> > cd
cd 함수는 chdir을 사용하여,  cd ~ , cd - , cd 와 같은기능, 그리고 상대경로, 절대경로를 통한 이용을 구현해야한다.
> > exit
exit함수는 받은 인자에 따라, 에러메세지가 나오기때문에, 모든 경우의 수를 찾아야하며, 일반적으로 숫자는 255로 모듈로된값이다.
> > export
export 는 인자가 없을때는, sort된 env를 출력하며, 인자가있을때에는, 몇가지 특정한  에러상황(맨앞에 숫자, 환경변수, '='위치등)을 제외하고는 env에 추가.
> > unest
unset 함수는인자에서 특정한 몇가지 에러상황을 제외하면 env값에 있는 환경변수를 제거
> > env, pwd
출력하는 함수
> > echo
-n 옵션을 구현해야하며, expansion된 변수들을 출력해야한다.

### 5. execuve function
> access함수로, path를 받고, path를 이용하여 execuve함수를 실행한다

### 6. redirection
>  > 와 >>는 STD_OUT으로 나오는 출력값을 파일에 저장함
> >  >는 file을 만듬.
> >  >>는 file을 만들지만, apppend 적용
>  < 와 <<< 는 STD_IN으로 파일, heredoc값을 전송한다.
> > < 는 파일을 STD_IN값으로 받는다.
> > <<는 heredoc으로서, EOF가 나올떄까지의 값을 저정한 후에, STD_IN으로 받는다.

### 7. pipe
> pipe를 구현할때,
> >	예) cmd1 | cmd2 | cmd3
가 있다면, 처음에 구현한 방법은, cmd1의 pid값을 부모 프로세스에서 기다린후에, 다시 cmd2의 자식프로세스를 fork하는 방식이었는데,
	결과적으로 잘못된방식이었다. 이렇게 구현한다면, cat | ls 또는 cat /dev/random | head -n 5 와같은 파이프는 bash처럼 구현되지않는다.
> > 그렇다면, 어떻게해야할까?
첫번째, 파이프끼리의 연결은 부모프로세스를 거치지않고, 자식프로세스끼리 연결한다.
즉, parent --- child_1 --- parent --- child_2 --- parent 의 방식이 아닌, 
	parent --- child_1 --- child_2 --- parent의 방식으로 파이프를 연결한다. (이럴경우, heredoc의 구현이 아주 쉬워진다)
	또한 자식프로세스를 기다리는 waitpid함수를 부모 프로세스에 위치시킨다.

### 8. norminette
> norminette 확인

-------------------------------------------------------------------------------------------------------------------------------

## 고칠점
1. parsing을 하면서, expansion을 생각하지않았다.
> expansion은 전체적으로 쓰이기때문에, parsing을 한 다음, 바로 해야하는과정이었다.
나는 paring후에, 그 값들을 가지고 echo에서 expansion을 하고, cd에서 하고... execuve함수를 위해서 하고.. 계속해서 각 함수에서 expansion을 하였고, 결과적으로 터미널에서 명령어대신 환경변수의 키를 넣으면, 그에 따른 값이 나와야하기때문에, 처음으로 돌아가서 expanion을 하였다. 결국 만들어놓은 많은 함수들이 필요없게 되었다.

2. 비슷한 함수들, 함수명, 변수명
> 이렇게 큰 프로젝트는 처음이었기때문에, 각 빌트인 명령어나, 파이프 구현에 맞는 함수를 만들었었다. 하지만 시간이 갈수록 비슷한 값을 받고, 비슷한 작동을 하는 함수들을 여럿만들었다. 그리고 함수의 명이나, 변수의 명에대해서 깊게 생각하지않았기때문에, 나중에 혼란이 왔다. 
> > 예) ft_double_array_export라는 함수는, export 다음에, 파이프전에있는 모든 노드 중에서, redirection 또는 file을 무시하고, 이중으로 된 인자를 반환하는 함수이다. export라는 이름을 붙여두고 나중에, 다른 빌트인함수나 다른 함수들의 구현중에 많이 가져다썼기때문에, 이름으로 혼동이 올수있었다.

3. 상수 자료형을 쓰기
> 헤더에 입력된 상수형은 리턴값이나, 파라미터로 사용되며, 가독성에 아주좋다.
나는 리턴값으로 0 또는 1 만 자주이용하는데, 앞으로는 함수명과 상수를 이용해야겠다.
> > 예)  is_digit(char c)/ return (TURE) or return (FAlSE) / return (SUCCESS) or  return (FAIL)
