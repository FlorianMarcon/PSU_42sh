/*
** EPITECH PROJECT, 2017
** 42_sh
** File description:
** env.h
*/

#ifndef HEADER_
#define HEADER_

typedef struct env_s {
	char *data;
	struct env_s *next;
} env_t;
