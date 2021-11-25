
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


$PWD=dwq같은건 다 바뀌니 그거 하나씩 인덱스로 보면서 검색하고 확인해서 export에 써야할듯
