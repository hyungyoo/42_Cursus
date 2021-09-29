# functions 공부

## readline
#include <stdio.h>  
#include <readline/readline.h>  
#include <readline/history.h>  
char *readline(const char *str);  
- 입력받은 문자열을 저장하고 그 문자열을 반환한다. 빈 줄의 경우 빈 스트링을 반환.
- 라인을 읽는 중 EOF를 만나면서 라인이 비어있다면 NULL을 리턴, 반면 EOF를 만나면서 라인에 내용이 있다면 개행(newline)으로 처리된다.
- 리턴되는 line의 경우 개행 문자가 함께하지 않음. (\n이 없다)
- 사용시 입력 받은 문자열은 힙 메모리를 사용하므로 사용이 끝났다면 메모리 할당(free)을 해줘야함.
- 컴파일 시 옵션에 readline 폴더를 반드시 추가해줘야 한다. (-lreadline)

## add_history
#include <readline/history.h>  
(UNIX) int add_history(const char *line);   
(GNU LIB)void add_history(const char *line);  
- add_history의 인자인 line으로 기재한 문자열은 위와 아래 방향키를 통해서 readline 함수 실행 도중에 다시 불러올 수 있다.
- line을 history list의 맨 끝에 위치시킨다. 관련 데이터 필드는 NULL로 세팅.
- history 항목이 최대 개수를 넘을 경우, 오래된 항목들은 삭제됨.
- return
> Unix 계열 : readline 디렉토리를 이용하는 경우에는 int 타입 반환, 함수 수행에 문제가 없다면 0을, 그렇지 않다면 -1을 반환
> GNU 라이브러리 : void 타입의 반환

## rl_clear_history (?????)
void rl_clear_history (void)  
- Clear the history list by deleting all of the entries, in the same manner as the History library's clear_history() function. This differs from clear_history because it frees private data Readline saves in the history list.

## rl_on_new_line
#include <readline/readline.h>  
int rl_on_new_line (void)  
- Tell the update functions that we have moved onto a new (empty) line, usually after outputting a newline.
- readline 디렉토리 내에서 Update 관련 함수(rl_redisplay도 포함)에게 커서가 개행 문자를 통해 다음 줄로 이동했음을 알려줄 때 이용되는 함수 (개행 문자 수행하지 않음)
- return
> 오류 시 -1, 그렇지 않다면 0을 반환

## rl_replace_line (리눅스에만 존재???)
#include <readline/readline.h>  
void rl_replace_line (const char *text, int clear_undo)  
- Replace the contents of rl_line_buffer with text. The point and mark are preserved, if possible. If clear_undo is non-zero, the undo list associated with the current line is cleared.
- rl_line_buffer라는 전역 변수를 이용하는 함수. rl_line_buffer은 사용자가 입력한 문자열을 별도로 유지.
- rl_replace_line 함수는 rl_line_buffer에 입력받은 내용을 text라는 문자열로 대치한다.
- clear_undo는 내부적으로 유지 중인 undo_list를 초기화 할지의 여부를 결정하는 값. clear_undo의 값이 0이면 초기화 하지 않고, 0이와의 값이면 undo_list를 초기화.

## rl_redisplay
#include <readline/readline.h>  
void rl_redisplay(void);  
- rl_replace_line 함수와 같이 rl_line_buffer 전역 변수를 사용.
- 사용자가 입력하여 유지 중이 rl_line_buffer 값을 프롬프트와 함께 출력함. 이 때, 프롬프터 값은 readline 함수에 str으로 준 문자열로 이용.
- 주로 시그널을 받았을 때의 상황에서 rl_redisplay를 이용.

## wait3
#include <sys/wait.h>  
pid_t wait3(int *status, int options, struct rusage *rusage);  
- 자식 프로세스가 종료되는 것을 기다리며, 종료된 프로세스의 상태와 자원 사용량을 알려준다.
- waitpid, waitid 함수의 사용과 동시에 (표준화를 이유로) 더이상 사용하지 않게 된 함수. (기능 자체는 waitpid와 동일)
- wait3(status, options, rusage) == waitpid(-1, status, options)
- status : 자식 프로세스의 종료 상태를 나타내는 정보를 담음
- options : 프로세스의 종료 상태 체크를 위한 옵션
- rusage(Resource Usage) : 자식 프로세스의 리소스 사용량에 대한 정보가 담김
- return
> 성공시 process id, 실패 시(함수 수행에 문제 혹은 자식 프로세스가 시그널에 의해서 종료된 경우) -1, WNOHANG 옵션으로 실행, 자식 프로세스가 아직 종료되지 않았다면 0.

## wait4
#include <sys/wait.h>  
pid_t wait4(pid_t pid, int *status, int options, struct rusage *rusage);  
- waitpid, waitid 함수의 사용과 동시에 (표준화를 이유로) 더이상 사용하지 않게 된 함수. (기능 자체는 waitpid와 동일)
- wait3와의 차이 : 어떤 특정 자식 프로세스에 작업을 할 수 있음. 변수 pid에 해당하는 프로세스만 기다림. (자식 프로세스를 특정할 수 있다는 점 외에 wait3함수와 동일 작동)
- wait4(pid, status, options, rusage) == waitpid(pid, status, options)
- status 변수에 사용할 수 있는 매크로

| 매크로 | 내용 |
| ------ | --- |
| WIFEXITED(status) | 자식 프로세스가 정상적으로 종료된 경우 true |
| WEXITESTATUS(status) | exit()의 인자에서 하위 8비트 값을 리턴 |
| WIFSIGNALED(status) | 자식 프로세스가 시그널을 받아 비정상적으로 종료된 경우 true |
| WIFTERMSIG(status) | 시그널 번호를 리턴 |
| WIFCOREDUMP(status) | 코어 파일이 생성된 경우 true |
| WIFSTOPPED(status) | 현재 중지 상태이면 true |
| WSTOPSIG(status) | 실행을 중단시킨 시그널 번호를 리턴 |
| WIFCONTINUED(status) | 작업 제어 중지 이후 실행이 재개되었으면 true |
- options 변수에 사용할 수 있는 매크로

|매크로|내용|
|------|---|
|WCONTINUED|중지되었다가 실행을 재개한 이후 상태가 아직 보고되지 않은 자식도 리턴|
|WNOHANG|종료 상태를 즉시 회수 할 수 없는 상황이라고 하여도 waitpid() 호출이 차단되지 않고 0 리턴|
|WUNTRACED|중지되었으나 그 상태가 아직 보고되지 않은 자식도 리턴|

## signal
#include <signal.h>  
typedef void (*sighandler_t)(int);  
sighandler_t signal(int signum, sighandler_t handler);  
- signum : 정의하고자 하는 시그널 번호
- handler : sighandler_t 타입의 정의하고자 하는 함수
- sighandler_t ? sighandler_t는 void를 반환하고 signum을 받기 위한 int 타입의 인자를 받는 함수를 참조하는 함수 포인터
- return 
> 특정 handler 반환. 그러나 signal함수에 사용된 handler 함수가 아닌, 시그널 처리 동작이 handler로 정의되기 이전에 정의된 핸들러를 의미
- 시그널 처리하는 방법  

| 유형 | 의미 |
| --- | ---|
| SIG_DFL | 기존 방법을 따른다. |
| SIG_IGN | 시그널을 무시한다. |
| 함수 이름 | 시그널이 발생하면 지정된 함수 호출 |

> 문제 발생 시, SIG_ERR를 반환함.  
주의 사항.   
함수 내에서는 반드시 Async-Signal-Safe 함수들만 이용해야 함. Async-Signal-Safe한 함수들은 대체적으로 Reentrant가 가능한 함수인데, Reentrant가 불가능한 대표적인 함수로는 printf가 있다. printf는 (Async-Signal-Safe 아님, printf의 호출로 출력 중인 상태에서 시그널을 받아서 시그널 처리 동작에서도 printf를 호출시, 원하는 출력 결과가 나오지 않을 수도 있음.) printf의 출력 자체는 Buffer Management를 통해 출력을 하게 되므로 내부에 별도로 둔 Buffer를 토대로 메모리에 쓰는 작업을 진행하게 되는데, 제시된 상황에서는 메모리에 쓰는 작업에 이용되는 기존의 Buffer의 내용이 손실될 수 있기 때문이다. 따라서 핸들러 내에서 처리되는 동작들이 문제가 없다는 것을 보장하기 위해선 반드시 Async-Signal-Safe 함수들만 이용되어야 한다. [signal 함수 내에서 이용할 수 있는 함수](https://www.man7.org/linux/man-pages/man7/signal-safety.7.html).   
SIGFPE, SIGILL, SIGSEGV 등의 시그널에 대해서는 signal 함수를 이용하여 처리 동작을 정의해서는 안 된다. 이와 같은 시그널들의 무시 혹은 사용자 정의는 오류 상황에서도 프로그램이 종료되지 않아 문제 상황 속에서 무한히 지속되는 프로그램이 될 수 있다. 

## sigaction
#include <signal.h>  
int sigaction(int sig, const struct sigaction *restrict act, struct sigaction *restrict oact);  


## kill
#include <signal.h>  
int kill(pid_t pid, int sig);  
- 프로세스에 시그널을 전송하는 함수.
- 프로세스에 SIGKILL을 보내면 쉘 명령의 kill과 같은 역할을 함.
- pid : 프로세스 id
- sig : 시그널 번호
- 
| pid 값 | 의미 |
| ------ | --- |
| pid > 0 | pid와 같은 프로세스 id를 가진 프로세스에 sig를 전송 |
| pid == 0 | 그룹 id가 프로세스 그룹 id랑 동일한 권한을 가진 프로세스에 sig를 전송 |
| pid == -1 | 만약 사용자가 super-user라면, 권한을 가진 모든 프로세스에 sig를 전송, 시스템 프로세스와 sig를 보낸 프로세스는 제외. 사용자가 super-user가 아니라면, 같은 uid를 가진 user의 모든 프로세스에 sig가 전송됨. |
| pid < 0 (not -1)| 프로세스 그룹 id가 프로세스 번호의 절대값과 동일한 모든 프로세스에 sig 전송 |

- return 
> 성공 시 0, 실패 시 -1 (errno)

## getcwd
#include <unistd.h>  
char *getcwd(char *buf, size_t size);  
- getcwd를 호출한 프로그램이 실행되고 있는 절대 경로를 문자열로 얻게 해주는 함수.
- 현재 작업중인 디렉토리의 절대 경로를 buf에 복사하고 buf의 포인터를 리턴.
- buf : 작업 디렉토리 문자열을 담을 버퍼
- size : 버퍼의 크기 (bytes)
- buf == NULL 이라면 경로 이름 저장을 위한 공간이 메모리 할당 되고, 이후 free필요.
- return
> 성공시 현재 작업 디렉토리(경로 포인터), 실패시 NULL (errno)

## chdir
#include <unistd.h>  
int chdir(const char *path);  
- 현재 구동되고 있는 프로그램의 경로를 path로 변경. (path의 시작이 "면 안됨) (path 이름이 슬래시(\')로 시작하지 않음)
- 디렉토리의 실행 권한이 있어야 한다.
- path : 경로 (the pathname of a directory)
- return 
> 성공 시 0, 실패 시 -1 (errno)

## stat
#include <sys/stat.h>  
int stat(const char *restrict path, struct stat *restrict buf);  
- 파일의 크기, 권한, 생성일시, 최종 변경일등 파일의 상태나 정보를 얻는 함수.
- 파일의 읽기, 쓰기, 실행 권한을 요구하지는 않는다.
- symbolic link인 파일을 path 로 넘기면 그 원본 파일의 정보를 얻음.
- path : 파일명 또는 파일에 대한 상대/절대 경로 
- buf : 파일의 상태 및 정보를 저장할 [buf 구조체](https://www.it-note.kr/173)
- return
> 성공 시 0, 실패 시 -1 (errno)

## lstat
#include <sys/stat.h>  
int lstat(const char *restrict path, struct stat *restrict buf);  
- stat 함수와 동작 기능 같으나, 파일 이름(path)이 symbolic link일 때는 다름. 후자의 경우 symbolic link인 파일 자체의 정보를 얻음.
- return
> 성공 시 0, 실패 시 -1 (errno)

## fstat
#include <sys/stat.h>  
int fstat(int fildes, struct stat *buf);  
- fildes에 따라 현재 열려있는 파일의 크기, 권한, 생성일시, 최종 변경일 등 파일의 상태나 파일의 정보를 얻음.
- fildes : 생성한 file descriptor
- buf : 파일의 상태 및 정보를 저장할 buf 구조체
- return
> 성공 시 0, 실패 시 -1 (errno)

## unlink
#include <unistd.h>  
int unlink(const char *path)  
- path 파일의 링크를 삭제하고, 링크 카운트를 감소한다.
- return
> 성공 시 0, 실패 시 -1 (errno)

## opendir
#include <dirent.h>  
DIR *opendir(const char *name);  
- The opendir() function opens the directory named by filename, associates a directory stream with it and returns a pointer to be used to identify the directory stream in subsequent operations. The pointer NULL is returned if filename cannot be accessed, or if it cannot malloc(3) enough memory to hold the whole thing.
- 파일 절대/상대 경로(name)로 DIR * (디렉토리 스트림, DIR *타입의 포인터)를 생성하는 함수.
- _디렉토리 스트림은 디렉토리와 관련된 작업을 보다 쉽게 수행할 수 있도록 주고 받는 데이터의 흐름이며 이를 추상화한 구조체가 DIR이라고 이해할 수 있다._
- return
> 성공 시 DIR 포인터를, 실패 시 NULL(name에 접근 불가 혹은 malloc 불가)을 리턴

## readdir
#include <dirent.h> 
struct dirent *readdir(DIR *dirp);  
- The readdir() function returns a pointer to the next directory entry.  The directory entry remains valid until the next call to readdir() or closedir() on the same directory stream.  The function returns NULL upon reaching the end of the directory or on error.  In the event of an error, errno may be set to any of the values documented for the getdirentries(2) system call.  Note that the order of the directory entries vended by readdir() is not specified.  Some filesystems may return entries in lexicographic sort order and others may not.  Also note that not all filesystems will provide a value for d_type and may instead set the field to DT_UNKNOWN.
- opendir()로 연 디렉토리에 대해, 그 안에 있는 모든 파일, 디렉토리 정보를 얻는 함수. 그 안에 있는 파일과 디렉토리들은 정렬 돼 있지 않다.
- [struct dirent 정보](https://www.it-note.kr/14)
- return
> 성공 시 파일 또는 디렉토리 정보, 실패 시 NULL 리턴(errno).  
한편, 더 이상 읽을 정보가 없을 때도 NULL을 리턴하므로 오류일 경우와 구분해줘야 한다.

## closedir
#include <dirent.h>  
int closedir(DIR *dirp);  
- The closedir() function closes the named directory stream and frees the structure associated with the dirp pointer, returning 0 on success.  On failure, -1 is returned and the global variable errno is set to indicate the error.
- opendir() 함수로 열어둔 디렉토리 스트림을 닫고 DIR *포인터(dirp)와 관련된 구조체를 free하는 함수.
- return
> 성공 시 0, 실패 시 -1

## isatty
#include <unistd.h>  
int isatty(int fd);  
- The isatty() function determines if the file descriptor fd refers to a valid terminal type device.
- 인자인 파일 디스크립터(fd)가 유효한 터미널을 참조하는지 확인하는 함수.
- return
> 성공 시 0, 실패 시 -1

## ttyname
#include <unistd.h>  
char *ttyname(int fd);  
- The ttyname() function gets the related device name of a file descriptor for which isatty() is true. The ttyname() function returns the name stored in a static buffer which will be overwritten on subsequent calls. 

## ttyslot
#include <unistd.h>  
int ttyslot(void);  
- ttyslot 함수가 호출한 프로그램이 참조하고 있는 터미널의 index(번호)를 반환.
- legacy 함수
- return
> 성공 시 index를, 실패 시 0(또는 -1)

## ioctl
#include <sys/ioctl.h>  
int ioctl(int fildes, unsigned long request, ...);  
- The ioctl() function manipulates the underlying device parameters of special files.  In particular, many operating characteristics of character special files (e.g. terminals) may be controlled with ioctl() requests.  The argument fildes must be an open file descriptor.
- An ioctl request has encoded in it whether the argument is an ``in'' parameter or ``out'' parameter, and the size of the argument argp in bytes.  Macros and defines used in specifying an ioctl request are located in the file <sys/ioctl.h>.
- 시스템콜, 장치에게 요청을 보낼때 사용되는 함수로, ioctl 함수로 하드웨어의 제어, 상태 정보를 얻을 수 있다.
- fildes : 장치를 참조하는 파일 디스크립터 (fd)
- request : files에 해당하는 장치에게 보낼 장치에서 제공되는 코드
- ... : 특정 메모리 공간을 참조하는 포인터. (가변 인자인 이유 : 함수 원형에서 해당 포인터의 타입을 명시하지 않기 위함, 일반적으로 char *타입을 이용)
- return
> 성공 시 0, 실패 시 -1 

## getenv
#include <stdlib.h>  
char *getenv(const char *name);  
- The getenv() function obtains the current value of the environment variable, name.  The application should not modify the string pointed to by the getenv() function.
- 인자 name에 해당하는 환경 변수의 값에 대한 문자열을 반환.
- getenv 함수에 의해 참조되고 있는 값들은 내부적으로 static 형태로 할당되기 때문에 free를 하면 안됨.
- return
> 성공 시 char *형 환경 변수 값 반환, 그렇지 않으면 NULL 반환.

## tcsetattr
#include <termios.h>  
int tcsetattr(int fildes, int optional_actions, const struct termios *termios_p);  
- The tcgetattr(), and tcsetattr() functions are provided for getting and setting the termios structure.
- 터미널 파일 fildes에 대한 터미널 속성을 설정하는 함수
- fildes : 터미널 파일 디스크립터
- optional_actions : 동작 선택

| optional_actions | 내용 |
| ---------------- | --- |
| TCSANOW | 속성 (termios 구조체의 값으로) 즉시 변경 (change immediate) |
| TCSADRAIN | 송신 완료 후 속성 변경 (fildes에 모든 쓰기작업이 이뤄진 후 변경, 처리 중인 입력 작업 폐기 하지 않음) |
| TCSAFLUSH | 송수신 완료 후 속성 변경 (fildes에 모든 쓰기작업이 이뤄진 후 변경, 처리 중인 입력 작업 폐기) |
| TCSASOFT | termios 구조체 내 c_cflag, c_ispeed, c_ospeed 값 무시 |

- struct termios *termios_p : 터미널 속성을 저장할 주소 (구조체)
- return
> 성공 시 0, 실패 시 -1 (errno)

## tcgetattr
#include <termios.h>  
int tcgetattr(int fildes, struct termios *termios_p);  
- The tcgetattr(), and tcsetattr() functions are provided for getting and setting the termios structure.
- 터미널 파일 fildes에 대한 터미널 속성을 termios 구조체에 저장하는 함수
- fildes : 터미널 파일 디스크립터
- struct termios *termios_p : 터미널 속성을 저장할 주소 (구조체)
- return
> 성공 시 0, 실패 시 -1 (errno)

## tgetent
#include <curses.h>  
#include <term.h>  
int tgetent(char *bp, const char *name);  
- The tgetent routine loads the entry for name.  It returns 1 on success, 0 if there is no such entry, and -1 if the terminfo database could not be found.  The emulation ignores the buffer pointer bp.
- 인자 name에 해당하는 터미널 타입의 엔트리로 설정하여, 해당 엔트리에 대한 TermCap의 쿼리를 수행할 수 있도록 만드는 루틴 함수. name의 입력을 bp에 추출.
- bp는 사이즈 1024의 char형 버퍼. tgetnum(), tgetflag(), tgetstr()을 호출해도 보관 유지된다.
- bp 인자는 buffer pointer를 의미하는 데, 무시되는 인자이므로 일반적으로 NULL을 할당해줌.
- retrun
> 루틴 작업 성공 시 1, 만약 루틴 시 name의 값이 NULL과 같이 비어있는 값이라면 0을 반환. 실패 시(DB 검색 불가) -1 반환

## tgetflag
#include <curses.h>  
#include <term.h>  
int tgetflag(char *id);  
- The tgetflag routine gets the boolean entry for id, or zero if it is not available.
- Only the first two characters of the id parameter of tgetflag, tgetnum and tgetstr are compared in lookups.
- 루틴 함수로 id가 단말 엔트리에 존재하는지에 대한 불린 정보를 가져옴.
- id의 처음 두 문자만 비교됨.
- return
> id가 존재한다면 1, 존재하지 않는다면 0을 반환

## tgetnum
#include <curses.h>  
#include <term.h>  
int tgetnum(char *id);  
- The tgetnum routine gets the numeric entry for id, or -1 if it is not available.
- Only the first two characters of the id parameter of tgetflag, tgetnum and tgetstr are compared in lookups.
- 루틴 함수로 id가 단말 엔트리에 존재하는지에 대한 숫자 정보를 가져옴.
- id의 처음 두 문자만 비교됨.
- return
> 숫자 정보가 있다면 양수의 숫자 정보, 존재하지 않는다면 -1을 리턴.

## tgetstr
#include <curses.h>  
#include <term.h>  
char *tgetstr(char *id, char **area);  
- The  tgetstr  routine returns the string entry for id, or zero if it is not available.  Use tputs to output the returned string. The return value will also be copied to the buffer pointed to by area, and the area value will be updated to point past the null ending this value.
- Only the first two characters of the id parameter of tgetflag, tgetnum and tgetstr are compared in lookups.
- 루틴 함수로 id가 단말 엔트리에 존재하는지에 대한 string 정보를 가져옴.
- id의 처음 두 문자만 비교됨.
- area인자에는 리턴 str이 복사 돼 들어간다. 일반적으로 무시되는 인자로 간주 돼 NULL을 준다고 이해할 수 있다.
- return 
> 존재 한다면 문자열 포인터, 존재하지 않는다면 NULL 반환

## tgoto
#include <curses.h>  
#include <term.h>  
char *tgoto(const char *cap, int col, int row);  
- The tgoto routine instantiates the parameters into the given capability. The output from this routine is to be passed to tputs.
- 루틴 함수로 매개변수를 지정된 기능으로 인스턴스화 하는 함수.
- cap : ??
- col : 터미널 세로 열의 위치
- row : 터미널 가로 행의 위치
- 이 함수의 리턴값은 tputs함수로 전달됨.
- return
> 실패 시 NULL 반환

## tputs
#include <curses.h>  
#include <term.h>  
int tputs(const char *str, int affcnt, int (*putc)(int));  
- The tputs routine is described on the curs_terminfo(3X) manual page.  It can retrieve capabilities by either termcap or terminfo name.
- The tputs routine applies padding information to the string str and outputs it. The str must be a terminfo string variable or the return value from tparm, tgetstr, or tgoto. affcnt is the number of lines affected, or 1 if not applicable.
- 루틴 함수로 str에 padding 정보를 적용하여 출력함.
- str : terminfo 문자열 변수이거나 tparm, tgetstr, tgoto의 반환 값이어야 함.
- affcnt : 영향을 받는 줄의 수. 해당 사항이 없다면 1로 주는 것이 일반적.
- (*putc)(int) : ASCII 문자 값을 인자로 받아 표준 출력의 쓰기 작업으로 터미널에 ASCII 문자 값을 출력해주는 함수.
- return
> 문제 없이 수행 시 0, 그렇지 않다면 -1 반환

----

## open
#include <fcntl.h>  
int open (const char *path, int oflag, ...)  
- 파일을 여는 데 사용하는 함수 (fopen() : C 라이브러리 / open() : 리눅스)
- path : 파일 이름
- oflag : 파일 열기 옵션 (O_RDONLY, O_WRONLY, O_RDWR, O_NONBLOCK, O_APPEND, O_CREAT,O_TRUNC, O_EXCL, O_SHLOCK, O_EXLOCK, O_NOFOLLOW, O_SYMLINK, O_EVTONLY, O_CLOEXEC)
- ... : 파일 접근 권한

printf, malloc, free, write, read, close, fork, wait, waitpid, exit, execve, dup, dup2, pipe, strerror, perror
