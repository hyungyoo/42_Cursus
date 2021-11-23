
 minishell  32 line 각 node->str을 돌면서 $가 나오고뒤에 숫자가 나오면, 삭제하기
 reset cmd for dolr and num-->
 각각 돌면서 확인
 37번쨰줄부터는 다 지우고, 결과값만보기







 $"1wq"는 1wq로 받아져야한다.
 그렇기때문에, $다음에 "", '' 가 나온다면, 

 $"duoq", $'sinq' $ arg(첫번째가 숫자) 세가지를 갈라야한다.

 duoq , sinq: command not found 가 나와야한다.

1. 2:
$ + douq or + sinq 일경우에는 
원래는 $는 안나오고 douq sinq만 남아야한다.
즉, $는 삭제 그리고 뒤에것만 남기기

3:
$ + (arg: 1arg)
"$ + (arg: 1arg)"
위의 두가지경우에는 $와 숫자 하나를 삭제해야한다.

'$1PATH'는 그냥둬도

The default interactive shell is now zsh.
To update your account to use zsh, please run `chsh -s /bin/zsh`.
For more details, please visit https://support.apple.com/kb/HT208050.
bash-3.2$ $"PATH"
bash: PATH: command not found
bash-3.2$ echo $"PATH"
PATH
bash-3.2$ echo $PATH
/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Library/Apple/usr/bin
bash-3.2$ echo $'PATH'
PATH
bash-3.2$ echo $PATH

bash: 1: command not found
bash-3.2$ $"$Test"
bash: : command not found
bash-3.2$ $"$PATH"
bash: /usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Library/Apple/usr/bin: No such file or directory
bash-3.2$ $
bash: $: command not found
bash-3.2$ $1dw
bash: dw: command not found
bash-3.2$ $"dq"
bash: dq: command not found
bash-3.2$ $'dq'
bash: dq: command not found
bash-3.2$ export $PATH
bash: export: `/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Library/Apple/usr/bin': not a valid identifier


bash-3.2$ export $PATH=d21     -->!!!!!!!!!!!!!!!!!!!!!!!!!  expansion 파일에서 71번쨰줄보기!!!!!!!!!!


bash: export: `/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Library/Apple/usr/bin=d21': not a valid identifier
bash-3.2$


export $dw --> export  --> export $PATH=d21같은경우도 되야함 즉, 안에 키가있다는게 문제임
$로 시작되면 안되는데, 그래도 결국 $키 있는값이면 에러이고
아니라면, 그냥무시

export는 전부다 하나씩 노드를 가져와서 새로만들고 만든걸로 확인하기로해야함
에러메시지를 보내면서 새롭게 말록을한후에 노드에 추가
확인다시하면서 각각 노드에 넣는걸로
ft_export3 파일에보면나옴 메세지보내면서 아예 안에 하나만들어서
몇개인지보고 몇개인지 갯수 내보내는 걸로 만들자
오류가몇개인지
그걸확인한후에는 오류인것들은 뻬고, 새로만들면됨
