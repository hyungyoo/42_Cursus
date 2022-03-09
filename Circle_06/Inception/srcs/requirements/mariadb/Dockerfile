FROM		debian:buster

COPY		./tools/setup_db.sh		/tmp/
COPY		./conf/my.cnf 			/tmp/

RUN			apt-get update
RUN			apt-get install -y \
				mariadb-server \
				mariadb-client \
				dumb-init

RUN			chmod 111 /tmp/setup_db.sh
RUN			mv ./tmp/my.cnf /etc/mysql/my.cnf
RUN			chmod 0444 /etc/mysql/my.cnf

# dumb-init
# docker doit marcher avec une service en tant que PID 1, et d'autes services doivent pas exists
# donc, les process qui sont generes viennet de PID 1 en tant que "child process"
# si non, s'il y a probleme, on peut pas relancer en terminant PID 1
# pour cette solution, on peut le gerer avec dumb-init
ENTRYPOINT	["/usr/bin/dumb-init"]

EXPOSE		3306

CMD			["/tmp/setup_db.sh"]
