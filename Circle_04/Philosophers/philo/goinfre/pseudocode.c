/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pseudocode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungyoo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 16:43:37 by hyungyoo          #+#    #+#             */
/*   Updated: 2021/08/20 01:28:27 by hyungyoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

////////////////////////스레드 진입순서
//이건  create함수를 써서 그 함수를 호출함과 동시에 
//main_loop 함수를 철학자를 인자로 하여 호출함!
//그 함수내에서 죽기전까지 먹고 자고 생각을 반복함.
//먹을때는 기아발생과 데드락 발생을 억제
//mutex사용


////////////////////기아발생, 데드락 발생
//이건 아직 모르겠음
//자는 함수가 필요함
//먹는중! 한후에 다음까지 정확히 그 시간이어야한다.
//먹는중 -> 생각중 -> 자는중
//또한, 짝수들은 시간을 잠시 둔다. 그래야지 처음에 데드락이 안생길수있지


//////////////////////시간 단위
//usleep 함수는 마이크로초 단위로 받는다.
// 1000 -> 1밀리초

//사실 먹고 그다음에 바로 자고 생각하고, 그건 
//금방 구현가능한데, 문제는 죽기전에 체크하는건데
//다른함수 만들어두고 무한으로 계속 체크해야하나?
// --> display후에 sleep걸면됨.

//////////////////스레드가 같이 공유하여쓰는 모든 함수들//////////
//즉, 출력함수, 포크등은 뮤텍스를 써야한다
//아니면 함수사용중에 다른스레드가 임계영역으로 침법하여, 인터럽트발생!

void	ft_init(int argc, char **argv, t_info *all)
{
	to do : 
		1. check ar count : 4 or 5
		2. check argv : ft_digit, save values
		3. initialize mutex 
			fork, eat, display 
}

void	ft_sleep(int time)
{
	to do:
		1. dans while , aug sleep time 10
}

void	ft_eat_philo(t_philo *philo)
{
	to do:
		1. open mutex for fork l
		2. open mutex for fork r
		3. open mutex for eat
		4. function ft_sleep for eat_time
		5. close mutex for eat
		5. display "fork" and "eat"
		6. close mutex for fork l and r
}

void	ft_sleep_think(t_philo *philo)
{
	to do:
		1. display sleep
		2. ft_sleep for sleep_time
		3. display think
}

void	ft_philo(t_philo *philo)
{
	to do :
		ft_eat_philo(philo);
		// with function "pthread_mutex_lock and unlock
		// with function "cehck time"
		// with funtion display message

		ft_sleep_think(philo);
		// with function "check time"
		// with funtion display message
	
	// in this function, have to get time set for check die 
}

void	ft_check(t_info *all)
{
	//to do:
	//	1. dans le while ,
	//		check die or ate all
}

void	ft_pthread(t_info *all)
{
	to do:
	
	int	i;
	
	i = 0;
	while (i < all->num_philo)
	{
		ft_create_pthread(, , ft_philos, all->philo[i]);
		// to do : create_pthread and call function with each philo
		// function : ft_philo
		i++;
	}
	ft_check(all);
}



int	main(int argc, char **argv)
{
	t_info	all;

	ft_init(argc, argv, &all);
	ft_pthreadd(&all);
	ft_join_pthread(&all);
}
