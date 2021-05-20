#ifndef _GAME_H_
#define _GAME_H_

#include "SFML/Graphics.hpp"
#include "enemy.h"
#include "player.h"
#include "resources.h"
#include "stage.h"
#include "static_gui.h"
#include <iostream>
#include <vector>

class Game
{
  public:
  void run();

  private:
  std::unique_ptr<sf::RenderWindow> window{};
  Resources resources{};
  StaticGUI static_gui{resources};
  Player player{resources};
  Enemy enemy{resources};
  Stage stage{resources};

  void process_event(sf::Event event);
  void update();
  void render();
};

#endif //_GAME_H_