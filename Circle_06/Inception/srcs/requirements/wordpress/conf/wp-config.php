<?php


# config file de wordpress est wp-config.php, mais au debut d'installation,
# on n'a pas de ce fichier, il y a wp-config-sample.php
# donc, on doit faire wp-config.php

# des infos de DB
# setting pour MariaDB

# nom de DB pour wordpress
define( 'DB_NAME', MYSQL_DATABASE );

# DB username
define( 'DB_USER', MYSQL_USER );

# DB password
define( 'DB_PASSWORD', MYSQL_PASSWORD );

# DB hostname
define( 'DB_HOST', 'mariadb_service:3306' );

# DB charset pour utiliser dans la creation de DB table
define( 'DB_CHARSET', 'utf8' );

# DB collate type
define( 'DB_COLLATE', '' );


# Authentication Unique Keys & Salts
# on doit mettre Key et SALT
# https://api.wordpress.org/secret-key/1.1/salt/
# pour securite, c'est mieux de le changer reglement
define('AUTH_KEY',         'ZSjU|!(/Y@@qiL+`Bx!(gMh9_z2i7(9C(}r:~8w+YfFP8}+1Em^-xNo1`L}qH?-R');
define('SECURE_AUTH_KEY',  '`(s#sD`RK|5P97tilz!*alf>X3}p`s3w1V7Htd|{UF--Gght|b4?#rPjM3|@l-pu');
define('LOGGED_IN_KEY',    'BNE]8tD<bu/h@q/XK:Mkr+ !gh /@A:O:4j&[CBNaCi$IJCCG520I.|hI4+mhuK$');
define('NONCE_KEY',        'U%FTW(;}V[Xf!j22dF9bKnvG5p-:aG?Lwvf5TL`h+WZ9MXKqIbs-+t@@T,W&2(5!');
define('AUTH_SALT',        'Nn]mo_i8,#Qboc)|b|r=r^GJ;.7^w);$v_u,(8e0cR,_n/P~KJ|G7n[ST-kC#x|r');
define('SECURE_AUTH_SALT', 'Wy0p-IfEA?gj4+|6$J|7d}d|#Vs?n5}_DUJ<H-hj?g7`n:it?=1fClmsW1Y?A?b~');
define('LOGGED_IN_SALT',   '-b8rB 3bv-wZP~$KqR,.2v},xFevu>r)qYaHSQlXpw}iL2bECz,hA&aKGv-x(W|&');
define('NONCE_SALT',       'QUii*M`~FX|-rB02DA]mtp7w||dhrOnMI_IQou!gYl]y&t+g:+|xKM5l^-j>Ffz+');


# prefix de DB Table
$table_prefix = 'wp_';

define( 'WP_DEBUG', true );


if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

# comme include dans "C" ou "C++"
require_once ABSPATH . 'wp-settings.php';
