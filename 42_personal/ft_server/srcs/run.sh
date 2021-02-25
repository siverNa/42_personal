#!/bin/bash

#setup ssl
openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=sna/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt
mv localhost.dev.crt etc/ssl/certs/
mv localhost.dev.key etc/ssl/private/
chmod 600 etc/ssl/certs/localhost.dev.crt etc/ssl/private/localhost.dev.key

#setup MySql
service mysql start
#수정중...

#wordpress install
wget https://wordpress.org/latest.tar.gz
tar -xvf latest.tar.gz
mv wordpress/ var/www/html/
chown -R www-data:www-data /var/www/html/wordpress
mv wp-config.php /var/www/html/wordpress/

#phpmyadmin install
wget https://files.phpmyadmin.net/phpMyAdmin/5.0.4/phpMyAdmin-5.0.4-all-languages.tar.gz
tar -xvf phpMyAdmin-5.0.4-all-languages.tar.gz
mv phpMyAdmin-5.0.4-all-languages phpmyadmin
mv phpmyadmin /var/www/html/
mv config.inc.php /var/www/html/phpmyadmin

#autoindex on/off
#수정중...

#start services
service php7.3-fpm start
service nginx start
service mysql restart

bash
