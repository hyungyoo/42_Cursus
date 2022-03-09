<?php

define( 'DB_NAME', MYSQL_DATABASE );

define( 'DB_USER', MYSQL_USER );

define( 'DB_PASSWORD', MYSQL_PASSWORD );

define( 'DB_HOST', 'mariadb_service:3306' );

define( 'DB_CHARSET', 'utf8' );

define( 'DB_COLLATE', '' );


define('AUTH_KEY',         'ZSjU|!(/Y@@qiL+`Bx!(gMh9_z2i7(9C(}r:~8w+YfFP8}+1Em^-xNo1`L}qH?-R');
define('SECURE_AUTH_KEY',  '`(s#sD`RK|5P97tilz!*alf>X3}p`s3w1V7Htd|{UF--Gght|b4?#rPjM3|@l-pu');
define('LOGGED_IN_KEY',    'BNE]8tD<bu/h@q/XK:Mkr+ !gh /@A:O:4j&[CBNaCi$IJCCG520I.|hI4+mhuK$');
define('NONCE_KEY',        'U%FTW(;}V[Xf!j22dF9bKnvG5p-:aG?Lwvf5TL`h+WZ9MXKqIbs-+t@@T,W&2(5!');
define('AUTH_SALT',        'Nn]mo_i8,#Qboc)|b|r=r^GJ;.7^w);$v_u,(8e0cR,_n/P~KJ|G7n[ST-kC#x|r');
define('SECURE_AUTH_SALT', 'Wy0p-IfEA?gj4+|6$J|7d}d|#Vs?n5}_DUJ<H-hj?g7`n:it?=1fClmsW1Y?A?b~');
define('LOGGED_IN_SALT',   '-b8rB 3bv-wZP~$KqR,.2v},xFevu>r)qYaHSQlXpw}iL2bECz,hA&aKGv-x(W|&');
define('NONCE_SALT',       'QUii*M`~FX|-rB02DA]mtp7w||dhrOnMI_IQou!gYl]y&t+g:+|xKM5l^-j>Ffz+');


$table_prefix = 'wp_';

define( 'WP_DEBUG', true );


if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

require_once ABSPATH . 'wp-settings.php';
