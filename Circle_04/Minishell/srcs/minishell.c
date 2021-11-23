/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 18:08:22 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/11/23 19:15:54 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_reset_num(t_cmd *cmd, t_node **node)
{
	t_node	*next_node;
	char	*tmp;

	next_node = (*node)->next;
	tmp = (*node)->str;
	(*node)->str = ft_strdup(((*node)->next->str) + 1);
	(*node)->type = ARG;
	(*node)->flag_nospace = next_node->flag_nospace;
	free(tmp);
	ft_del_list(cmd, next_node);
}

int	check_num_douq(char *str)
{
	int size;
	int	i;

	i = 0;
	size = ft_strlen(str);
	while (str[i])
	{
		if (str[i] == '$' && ft_is_digit(str[i + 1]))
			size = size - 2;
		i++;
	}
	return (size);
}

void	ft_reset_num_douq(t_node *node)
{
	char 	*new_str;
	char	*tmp;
	int		i;
	int		j;

	j = 0;
	i = 0;
	tmp = node->str;
	new_str = (char *)malloc(sizeof(char) * check_num_douq(node->str) + 1);
	if (!new_str)
		return ;
	while (((node)->str)[j])
	{
		if (((node)->str)[j] == '$' && ft_is_digit(((node)->str)[j + 1]))
			j = j + 2;
		else
			new_str[i++] = ((node)->str)[j++];
	}
	new_str[i] = '\0';
	free(tmp);
	node->str = new_str;
}

void	ft_expension_num(t_cmd *cmd, t_node *node)
{
	while (node)
	{
		if (node->type == DOLR && (node->next) && node->next->type == ARG && ft_is_digit((node->next->str)[0]))
			ft_reset_num(cmd, &node);
		else if (node->type == DOUQ)
			ft_reset_num_douq(node);
		if (node->next)
			node = node->next;
		else
			return ;
	}
}

void	ft_expension_nospace_num(t_cmd *cmd)
{
	t_node *node;
	if (!cmd)
		return ;
	node = cmd->cmd_start;
	ft_expension_num(cmd ,node);
}

void	execute_eof(t_cmd *cmd, char *line)
{
	ft_putendl_fd("\033[38;5;31mminishell exit \033[0m", 1);
	free(line);
	line = NULL;
	ft_exit_minishell(1, &(cmd));
}

void	execute_parsing(t_cmd *cmd, char *line)
{
	ft_putendl_fd("Minishell: Syntax error", 1);
	free_list(&(cmd));
	free(line);
	line = NULL;
}

void	execute_minishell(t_cmd *cmd, char *line)
{
	set_detail_type(&(cmd));
	ft_expension_nospace_num(cmd);
	ft_expension(&cmd);
	ft_exec(cmd);
	print_cmdline(&(cmd));
	free_list(&(cmd));
	free(line);
	line = NULL;
}

int	main(int ac, char **av, char **env)
{
	char	*line;
	t_cmd	*cmd;

	ft_initial(env, ac, av);
	ascii_logo_lol();
	while (1)
	{
		signal(SIGINT, handler);
		signal(SIGQUIT, handler);
		line = readline("\033[38;5;41mminishell $> \033[0m");
		cmd = init_cmd();
		if (line == NULL)
			execute_eof(cmd, line);
		add_history(line);
		if (ft_parsing(line, &(cmd)))
		{
			execute_parsing(cmd, line);
			continue ;
		}
		execute_minishell(cmd, line);
	}
	return (0);
}
