FROM        debian:buster

RUN         apt-get update
RUN         apt-get install -y \
                dumb-init \
                nginx
RUN         apt-get install -y \
                openssl

# setting pour ssl key
RUN         openssl req -x509 -sha256 -nodes -days 365 -newkey rsa:2048 \
            -subj "/C=RF/ST=France/L=Paris/O=Ecole42/CN=hyungyoo.42.fr" \
            -keyout /etc/ssl/private/hyungyoo.key -out /etc/ssl/certs/hyungyoo.crt
            

COPY        ./conf/nginx.conf       /etc/nginx/nginx.conf

ENTRYPOINT  ["/usr/bin/dumb-init"]

EXPOSE      443

CMD         ["nginx", "-g", "daemon off;"]

