#!bin/bash/

mv wordpress/ /var/www/
rm latest.tar.gz

mv /tmp/wp-config.php /var/www/wordpress
chown -R www-data:www-data /var/www/wordpress/

curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar;
chmod +x wp-cli.phar;
mv wp-cli.phar /usr/local/bin/wp;


wp core download --allow-root && wp core config --allow-root --dbname=$MYSQL_DATABASE --dbuser=$MYSQL_USER --dbpass=$MYSQL_PASSWORD --dbhost=mariadb:3306;

sed -i -e "s|MYSQL_DATABASE|'$MYSQL_DATABASE'|g" /var/www/wordpress/wp-config.php
sed -i -e "s|MYSQL_USER|'$MYSQL_USER'|g" /var/www/wordpress/wp-config.php
sed -i -e "s|MYSQL_PASSWORD|'$MYSQL_PASSWORD'|g" /var/www/wordpress/wp-config.php
sed -i -e "s|;daemonize = yes|daemonize = no|g" /etc/php/7.3/fpm/php-fpm.conf
mkdir -p /run/php/

wp core install --allow-root --url=$WP_URL --title=$TITLE --admin_user=$WP_USER --admin_password=$WP_PASSWORD  --admin_email="user@user.fr" --path='/var/www/wordpress';

wp  user create --allow-root $WP2_USER user2@user.com --user_pass=$WP2_PASSWORD --role=author

wp post generate --count=3 --post_title="hyungyoo"

#wp theme install --allow-root dark-mode --activate 

exec /usr/sbin/php-fpm7.3
