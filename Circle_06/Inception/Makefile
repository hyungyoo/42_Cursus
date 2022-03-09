DOCKER			= sudo docker

COMPOSE 		= sudo docker-compose -f srcs/docker-compose.yml

DATA_PATH 		= /home/hyungyoo


all 			:	build make_file set_hosts
				$(COMPOSE) up -d

make_file 		:
				sudo mkdir -p $(DATA_PATH)
				sudo mkdir -p $(DATA_PATH)/data/wordpress
				sudo mkdir -p $(DATA_PATH)/data/database


set_hosts :		
		sudo chmod 777 /etc/hosts
		sudo echo "127.0.0.1 hyungyoo.42.fr" >> /etc/hosts
			

build	:
			$(COMPOSE) build

up:
			${COMPOSE} up -d 


clean	:
			$(COMPOSE) down -v --rmi all --remove-orphans

fclean	:	clean
			$(DOCKER) system prune --volumes --all --force
			sudo rm -rf $(DATA_PATH)
			$(DOCKER) network prune --force
			$(DOCKER) image prune --force
			sudo sed -i '/hyungyoo/d' /etc/hosts

re		:	fclean all

.PHONY : all build up down clean fclean re
