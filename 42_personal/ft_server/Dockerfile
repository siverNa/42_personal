# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sna <sna@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/24 19:42:25 by sna               #+#    #+#              #
#    Updated: 2021/02/26 17:15:26 by sna              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM	debian:buster

LABEL	maintainer="sna@student.42seoul.kr"

RUN		apt-get update && apt-get -y upgrade && apt-get -y install \
			nginx \
			mariadb-server \
			php-mysql \
			php-mbstring \
			php7.3-fpm \
			openssl \
			vim \
			wget

COPY	./srcs/run.sh ./
COPY	./srcs/default ./etc/nginx/sites-available/
COPY	./srcs/wp-config.php ./
COPY	./srcs/config.inc.php ./
COPY	./srcs/default_a ./

EXPOSE	80 443

CMD		bash run.sh
