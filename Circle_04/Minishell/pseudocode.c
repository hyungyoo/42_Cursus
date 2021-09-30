/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pseudocode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 13:53:32 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/09/30 17:26:49 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////struct /////////////////////////////////////////////
typedef struct	s_element
{
	int flag_pipe;
	int	num_pipe;
	int	flag_redirection;
	int	num_redirection;
	int	flag_semi;
	int	num_semi;
}				t_element;

typedef struct	s_cmd
{
	char *cmd;
	char *args;
	struct s_cmd	*prev;
	struct s_cmd	*next;
}				t_cmd;

typedef struct	s_info
{
	t_element	*ele;
	t_cmd		*premier_cmd;
}				t_info;
///////////////////////////////////////////////////////////////////////////////////////////////








////////////////////////////////////////////////function pour initial//////////////////////////

void	ft_pipe(t_info *all, char *cmd)
{
	t_element ele;
	
	to do:
		1. l 또는 ;이 있는지 확인
		2. ele 초기화 후에, all에 저장
}

void	ft_split_cmd(t_info *all, char *cmd)
{
	while (i < num_element)
	{
		to do:
			각각의 명령어를 스플릿한후에cmd테이블에 저장 후 , 리스트로 연결
	}
}

void	ft_init(t_info *all, char *cmd)
{
	to do:
		0. ft_dquote(all, cmd);
			// 1. " ' 를 쓸수있는지 확인하기
			// 2. " ' 가 짝수인지 확인후 홀수라면 끄기
		1. ft_pipe(all, cmd);
			// | ; 확인 , t_element *ele; all->ele 초기화
		2. ft_split_cmd(all, cmd);
			// 있다면, 각각의 명령어를  split한후에, 리스트화시킨후 cmd, args 로 저장, 빌트인이어야하는
			// 함수가 아니면, 에러메세지 
}
/////////////////////////////////////////////////////////////////////////////////////////////






/////////////////////////////////////////////////function pour signal ///////////////////////
void	handle_fuction(int signal_int)
{
	to do:
		1. ctrl+c
		2. ctrl+\
}

void	ft_siginal(t_info *all, char **envp)
{
	to do:
		signal(signal_int, handle_function);
		signal(signal_int, handle_function);
}
///////////////////////////////////////////////////////////////////////////////////////////////







//////////////////////////////////////////////////function pour prompt/////////////////////////

char	*ft_prompt(void)
{
	to do:
		1. readline 함수이용해서 pwd이용하여, prompt 나타내기
		2. 반환값 저장하여 initial!
}


////////////////////////////////////////////////////////////////////////////////////////////////





void	ft_minishell(t_info *all, char **envp)
{
	to do:
		1. ft_siginal(all, envp);
		2. while (42)
		{
			// 함수 readline쓰기
			char *cmd = ft_prompt();
			// ctrl + d eof 나타내기
			if  (NULL --> eof)
				// 끝내기

			if (ft_init(cmd))
				error_message
			else 
				add_history(cmd);


		}
}

////////////////////////////////////////////////////////////////////////////////////////////////////
int	main(int argc, char **argv, char **envp)
{
	t_info all;
	to do:
		1. ft_minishell(&all, envp);
	return (0);
}


to do:
	1. initial and free 함수만들기
	2. parsing 
		1. echo
		2. list
