//
// main.cpp for Zappy in /home/gastal_r/rendu/Zappy/client/src/
//
// Made by gastal_r
// Login   <remi.gastaldi@epitech.eu>
//
// Started on  Wed Jun 21 16:14:06 2017 gastal_r
// Last update Wed Jun 21 20:50:39 2017 gastal_r
//

#include      "Ai.hpp"

int           main(int ac, char *av[])
{
  (void) ac;
  (void) av;
  Communication   communication(atoi(av[2]), av[6]);

  if (ac != 7)
  {
    std::cout << "USAGE: ./zappy_ai -p port -n name -h machine" << std::endl;
    std::cout << "\tport is the port number" << std::endl;
    std::cout << "\tname is the name of the team" << std::endl;
    std::cout << "\tmachine is the name of the machine; localhost by default" << std::endl;
  }
  // communication.setPort(atoi(av[2]));
  // communication.setMachine(av[6]);
  communication.receiveCmd("forward\n");
  // neverForgetTo(lock->Compter);
  return (0);
}
