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

ENTRYPOINT	["/usr/bin/dumb-init"]

EXPOSE		3306

CMD			["/tmp/setup_db.sh"]
