N_CLIENT = ./client
N_SERVER = ./server

SRC = client.c server.c
OBJ = $(SRC .c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

OBJ_F = obj/

all: $(N_CLIENT) $(N_SERVER)

