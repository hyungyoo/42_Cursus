FROM		debian:buster

COPY		./tools/setup_wp.sh		/tmp
COPY		./conf/wp-config.php	/tmp

RUN			apt-get update
RUN			apt-get install -y \
				php-fpm \
				php-mysql \
				curl \
				dumb-init \
				tar	\
				mariadb-server 

RUN			echo "listen = 9000" >> /etc/php/7.3/fpm/pool.d/www.conf
RUN			curl -LO https://wordpress.org/latest.tar.gz
RUN			tar xzvf latest.tar.gz

ENTRYPOINT	["/usr/bin/dumb-init"]

EXPOSE		9000

CMD			["bash", "/tmp/setup_wp.sh"]

