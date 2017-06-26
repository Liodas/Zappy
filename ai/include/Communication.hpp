//
// Communication.hpp for Zappy in /home/gastal_r/rendu/Zappy/ai/include/
//
// Made by gastal_r
// Login   <remi.gastaldi@epitech.eu>
//
// Started on  Thu Jun 22 16:36:20 2017 gastal_r
// Last update Sun Jun 25 15:08:54 2017 gastal_r
//

#ifndef COMMUNICATION_HPP
# define COMMUNICATION_HPP

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>
#include <iostream>
#include <iomanip>

class   Communication
{
private:
  std::string         _cmd;
  int                 _port;
  struct protoent     *_pe;
  int                 _fd;
  struct sockaddr_in  _s_in;

protected:
  std::string         _machine;
  std::string         _answer;

public:
  Communication() noexcept;
  ~Communication() = default;
  Communication(int port, const std::string &machine);
  Communication(const Communication& other) = default;
  Communication(Communication&& other) = default;
  Communication& operator=(const Communication& other) = default;
  Communication& operator=(Communication&& other) = default;

  void                  setPort(int port) noexcept;
  int                   getPort() noexcept;
  void                  setMachine(const std::string& machine) noexcept;
  const std::string&    getMachine() noexcept;
  void                  receiveCmd(const std::string&) noexcept;
  const std::string&    waitCmd();
  void                  sendCmd() noexcept;
  void                  getConnected() noexcept;
};

#endif //COMMUNICATION_HPP
