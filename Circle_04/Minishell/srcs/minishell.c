#include "../includes/minishell.h"

/* 3 parsing groupes
** 문자그룹 : 문자, 스페이스, 싱글따옴표, 더블따옴표, 백슬래시(\), 달러
** 연산자그룹 : 파이프, 더블파이프, 세미콜론, 더블세미콜론 (더블파이프, 더블세미콜론 에러 처리 가능)
** 리다이렉션 그룹 : >, >>, <
*/

void handler(int signum)
{
    if (signum != SIGINT)
        return ;
    write(STDOUT_FILENO, "\n", 1);
    if (rl_on_new_line() == -1)
        exit(1);
    rl_replace_line("", 1);
    rl_redisplay();
}

void    copy_env(char **env)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (env[count])
        count++;
    g_info.env = (char **)malloc(sizeof(char *) * (count + 1));
    while (env[i])
    {
        g_info.env[i] = ft_strdup(env[i]);
        i++;
    }
    g_info.env[i] = NULL;        
}

int	main(int ac, char **av, char **env)
{
/* readline함수의 리턴값을 저장하기위해 임의로 포인터를 하나 선언한다 */
    char *str;

    /* Init before launch*/
    (void)ac;
    (void)av;
    str = NULL;
    g_info.env = NULL;
    
    /* copy env variable with malloc */
    copy_env(env);

    /* signal to manage CTL+C, CTL+D
    ** need to manage CTL+/ also */
    signal(SIGINT, handler);
    /* 무한루프를 돌리면서 readline();함수를 반복적으로 호출할 것이다 */
    while(1)
    {
        /* readline함수가 호출되면 인자(prompt : )를 터미널에 출력하고 저장할 라인을 입력받는다 */
        str = readline("minishell $>");/* read함수는 저장한 문자열의 메모리주소를 반환한다 */
        if (str == NULL || (ft_strcmp(str, "exit") == 0))/* str = NULL 이라면 (EOF, cntl + D)*/
        {
		    ft_putstr_fd("minishell exit\n", 1);
            // free_tab2(g_info.env);
            exit (1);/* 반복문을 탈출해준다.*/
        }
	/* add_history에 저장된 문자열은 up & down 방향키를 이용해 확인할수있다 */
        add_history(str);
	/* 라인은 힙메모리에 저장되기때문에 다 사용한 메모리는 할당을 해제해줘야한다 */
        free(str);
        str = NULL;
    }
    /* 
    ** here : parsing process with str
    */

    // free_tab2(g_info.env);
    return(0);
}

    // void	classify(struct dirent *ent)
// {
// 	printf("%s\t", ent->d_name);
// 	if (ent->d_type == DT_BLK)
// 		printf("Block Device\n");
// 	else if (ent->d_type == DT_CHR)
// 		printf("Character Device\n");
// 	else if (ent->d_type == DT_DIR)
// 		printf("Directory\n");
// 	else if (ent->d_type == DT_LNK)
// 		printf("Symbolic Link\n");
// 	else if (ent->d_type == DT_REG)
// 		printf("Regular File\n");
// 	else if (ent->d_type == DT_SOCK)
// 		printf("Unix Domain Socket\n");
// 	else
// 		printf("Unknown Type File\n");
// }


    // DIR *test;
    // struct dirent *file;
    // int tmp;

    // test = opendir("/Users/keulee/mygithub/minishell");
    // if (!test)
    // {
    //     write(1, "error\n", 6);
    //     return (1);
    // }
    // while (1)
    // {
    //     tmp = errno;
    //     file = readdir(test);
    //     if (!file && tmp != errno)
    //     {
    //         write(1, "error\n", 6);
    //         break;
    //     }
    //     if (!file)
    //         break;
    //     classify(file);
    // }
    // closedir(test);
    // return (0);

    
    /* 함수종료 */
