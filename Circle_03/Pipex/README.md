함수 설명

1. access
#include <unistd.h>
int	main(void)
{
	char	*path = "./txt";
	int	maode = R_OK | W_OK;
	if (acess(path, mode) = 0)
		읽고 쓸수있음
	else
		권한이 없거나 존재하지않음
}

2. open

3. unlink
4. close
5. read
6. write
7. malloc
8. waitpid
9. wait
10. free
11. pipe
12. dup
13. dup2
14. execve
15. fork
16. perror
17.  strerror


https://www.notion.so/pipex-991b46140b504e32897b04c204b86d6e
https://mug896.github.io/bash-shell/redirections.htmla
https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=skout123&logNo=50133225205
