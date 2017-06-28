/*
** drawGui.c for Project-Master in /home/sellet_f/Projets/Tek2/Zappy
**
** Made by sellet_f
** Login   <flavien.sellet@epitech.eu>
**
** Started on  Tue Jun 27 17:36:26 2017 sellet_f
** Last update Wed Jun 28 11:51:12 2017 gastal_r
*/

#include "GUI.h"

void			drawMap(t_gui *GUI, t_env *env)
{
  sfVector2f		pos;
  int			x;
  int			y;

  y = -1;
  while (++y < env->height)
    {
      x = -1;
      while (++x < env->width)
	{
          pos.x = x * sfSprite_getGlobalBounds(GUI->_grassSprite).width;
	  pos.y = y * sfSprite_getGlobalBounds(GUI->_grassSprite).height;
	  sfSprite_setPosition(GUI->_grassSprite, pos);
	  if (x == env->width / 2 && y == env->height / 2)
	    {
	      sfSprite_setPosition(GUI->_stoneSprite, pos);
              sfRenderWindow_drawSprite(GUI->_win, GUI->_stoneSprite, NULL);
	    }
	  else
	    sfRenderWindow_drawSprite(GUI->_win, GUI->_grassSprite, NULL);
	}
    }
}

void			drawText(t_gui *GUI)
{
  sfText		*text;
  sfVector2f		pos;

  initText(&text, &pos, GUI);
  initValueResource(pos, text, GUI, GUI->_caseInfos.sibur);
  pos.x = 1590;
  initValueResource(pos, text, GUI, GUI->_caseInfos.linemate);
  pos.x = 1755;
  initValueResource(pos, text, GUI, GUI->_caseInfos.deraumere);
  pos.x = 1450;
  pos.y = 320;
  initValueResource(pos, text, GUI, GUI->_caseInfos.phiras);
  pos.x = 1590;
  initValueResource(pos, text, GUI, GUI->_caseInfos.mendiane);
  pos.x = 1755;
  initValueResource(pos, text, GUI, GUI->_caseInfos.thystame);
  pos.y = 455;
  pos.x = 1450;
  /* initValueResource(pos, text, GUI, GUI->_caseInfos.food); */
  initValueResource(pos, text, GUI, GUI->_caseInfos.linemate);
  pos.x = 1590;
  /* initValueResource(pos, text, GUI, GUI->_caseInfos.eggs); */
  initValueResource(pos, text, GUI, GUI->_caseInfos.linemate);
  pos.x = 1755;
  /* initValueResource(pos, text, GUI, GUI->_caseInfos.nbPlayers); */
  initValueResource(pos, text, GUI, GUI->_caseInfos.linemate);
  sfText_destroy(text);
}

void			drawGUI(t_gui *GUI, t_env *env)
{
  sfRenderWindow_clear(GUI->_win, sfBlack);
  inputsAndEvents(GUI, env);
  if (sfRenderWindow_isOpen(GUI->_win))
    {
      sfRenderWindow_setView(GUI->_win, GUI->_camera);
      drawMap(GUI, env);
      sfRenderWindow_setView(GUI->_win, GUI->_interface);
      sfRenderWindow_drawSprite(GUI->_win, GUI->_pannelSprite, NULL);
      drawText(GUI);
      sfRenderWindow_drawSprite(GUI->_win, GUI->_playerInfoSprite, NULL);
      sfRenderWindow_display(GUI->_win);
    }
}