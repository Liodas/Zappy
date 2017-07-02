/*
** exec_incantation_action.c for Zappy
**
** Made by Matthias Prost
** Login   <matthias.prost@epitech.eu@epitech.eu>
**
** Started on  Thu Jun 29 18:06:12 2017 Matthias Prost
** Last update Fri Jun 30 15:10:02 2017 Matthias Prost
*/

#include "server.h"

int		ressources[8][6] = {
  {0, 0, 0, 0, 0, 0},
  {1, 0, 0, 0, 0, 0},
  {1, 1, 1, 0, 0, 0},
  {2, 0, 1, 0, 2, 0},
  {1, 1, 2, 0, 1, 0},
  {1, 2, 1, 3, 0, 0},
  {1, 2, 3, 0, 1, 0},
  {2, 2, 2, 2, 2, 1}
};

void  takeOffRessources(t_users *user)
{
  user->inventory.linemate -= ressources[user->lvl][0];
  user->inventory.deraumere -= ressources[user->lvl][1];
  user->inventory.sibur -= ressources[user->lvl][2];
  user->inventory.mendiane -= ressources[user->lvl][3];
  user->inventory.phiras -= ressources[user->lvl][4];
  user->inventory.thystame -= ressources[user->lvl][5];
}

void  incantationAction(t_env *env, char **msg, t_users *user)
{
  (void)env;
  (void)msg;
  user->lvl += 1;
  if (user->socket != -1)
  {
    dprintf(user->socket, "Current level: %d\n", user->lvl);
    printf("User with socket %d level up to %d\n", user->socket, user->lvl);
    printf("--> Sent \"Current level: %d\" to socket %d\n",
            user->lvl, user->socket);
  }
  user->lock = false;
}

void  forkAction(t_env *env, char **msg, t_users *user)
{
  t_action *action;

  if (user->socket != -1)
  {
    printf("--> Sent \"ok\" to socket %d\n", user->socket);
    dprintf(user->socket, "ok\n");
    env->map[user->posY][user->posX].egg += 1;
    action = newAction(env->queue, user, &eggAction,
                        600000000 / env->freq);
    if (msg && msg[0])
    {
      free(msg[0]);
      msg[0] = strdup("Egg");
    }
    addActionData(action, env, msg);
  }
}
