/*
** client_management.c for Zappy
**
** Made by Matthias Prost
** Login   <matthias.prost@epitech.eu@epitech.eu>
**
** Started on  Mon Jun 26 15:25:06 2017 Matthias Prost
** Last update Sun Jul  2 23:21:39 2017 Matthias Prost
*/

#include "server.h"

void		initInventory(t_env *env, int i)
{
  env->users[i].inventory.food = 10;
  env->users[i].inventory.linemate = 0;
  env->users[i].inventory.deraumere = 0;
  env->users[i].inventory.sibur = 0;
  env->users[i].inventory.mendiane = 0;
  env->users[i].inventory.phiras = 0;
  env->users[i].inventory.thystame = 0;
  env->users[i].inventory.egg = 0;
}

void		add_user_by_egg(t_env *env, int i)
{
  printf("Egg [%d]\n", env->users[i].socket);
  env->users[i].lvl = 1;
  env->users[i].posX = env->egg->x;
  env->users[i].posY = env->egg->y;
  env->map[env->egg->y][env->egg->x].egg--;
  delete_front_egg(env);
}

void		fill_user(t_env *env, int i)
{
  env->users[i].lvl = 1;
  env->users[i].posX = rand() % env->width;
  env->users[i].posY = rand() % env->height;
}

void		addUserTab(t_env *env, int socket)
{
  int		i;

  i = -1;
  while (++i != MAX_FD)
    {
      if (env->users[i].socket == -1)
	{
	  env->users[i].socket = socket;
	  if (env->egg != NULL)
	    add_user_by_egg(env, i);
	  else
	    fill_user(env, i);
	  env->users[i].graphicY = rand() % 60;
	  env->users[i].graphicX = rand() % 68;
	  env->users[i].direction = rand() % 4;
	  env->users[i].teamName = NULL;
	  env->users[i].lock = false;
	  initInventory(env, i);
	  printf("Socket: %d\tlvl: %d\t\tposY: %d\t\tposX: %d\t\tdirection: %d\n",
		 env->users[i].socket, env->users[i].lvl, env->users[i].posY,
		 env->users[i].posX, env->users[i].direction);
	  break;
	}
    }
}

void		removeUserTab(t_env *env, int socket)
{
  int		i;

  i = -1;
  while (++i != MAX_FD)
    {
      if (env->users[i].socket == socket)
	{
	  env->users[i].socket = -1;
	  env->users[i].lvl = 1;
	  env->users[i].posX = 0;
	  env->users[i].posY = 0;
	  env->users[i].graphicX = 0;
	  env->users[i].graphicY = 0;
	  free(env->users[i].teamName);
	  env->users[i].teamName = NULL;
	  env->users[i].lock = false;
	  break;
	}
    }
}
