#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller
{
public:
  Controller(void (*onMouseClickEvent)(int, int));
  void HandleInput();

private:
  void (*onMouseClickEvent)(int, int);
  bool mousePressed;
};

#endif