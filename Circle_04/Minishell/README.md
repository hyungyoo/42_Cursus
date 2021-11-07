문제;

1. export 리다이렉션 안됨


2. cmd다음에 들어가는 리다이렉션이 아닌경우,  -------> 해결
	즉 파이프가 있을경우, 리다이렉션 후에 cmd가들어가면,
	리 다이렉션이 되지않는다.

3. oldpwd해야함, unset pwd 후에 oldpwd가 안됨 나오는게문제!

4. bash-3.2$ echo$PWD
bash: echo/Users/hyungyoo: No such file or directory
bash-3.2$ echo$PATH
bash: echo/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Library/Apple/usr/bin: No such file or directory
bash-3.2$

