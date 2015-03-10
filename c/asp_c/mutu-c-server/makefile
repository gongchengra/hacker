webserver:webserver.o init_socket.o http_session.o get_time.o
	gcc -Wall webserver.o init_socket.o http_session.o get_time.o -o webserver
webserver.o:init_socket.h http_session.h webserver.c
	gcc -Wall webserver.c -c
init_socket.o:init_socket.h init_socket.c
	gcc -Wall init_socket.c -c
http_session.o:http_session.h get_time.h http_session.c 
	gcc -Wall http_session.c -c
get_time.o:get_time.h get_time.c
	gcc -Wall get_time.c -c
clear:
	rm -rf webserver.o init_socket.o http_session.o get_time.o
