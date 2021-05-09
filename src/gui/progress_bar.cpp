#include "progress_bar.h"
#include "SFML/Graphics.hpp"

#include <iostream>

namespace sf
{

ProgressBar::ProgressBar (float width, sf::Color fg_color, float pos_x,
						  float pos_y)
	: width (width), fg_color (fg_color)
{
  background_rect.set_size (sf::Vector2f (width, 11));
  foreground_rect.set_size (sf::Vector2f (0, 11));
  background_rect.setPosition (pos_x, pos_y);
  foreground_rect.setPosition (pos_x, pos_y);
  background_rect.set_corners_radius (1);
  foreground_rect.set_corners_radius (1);
  background_rect.set_corner_point_count (4);
  foreground_rect.set_corner_point_count (4);
  background_rect.setFillColor (sf::Color (189, 192, 185));
  foreground_rect.setFillColor (fg_color);
  refresh ();
}

void ProgressBar::set_max_value (float max_value)
{
  this->max_value = max_value;
  refresh ();
}

void ProgressBar::set_value (float value)
{
  this->value = value;
  refresh ();
}

void ProgressBar::draw (RenderTarget &target, RenderStates states) const
{
  target.draw (background_rect);
  target.draw (foreground_rect);
}

void ProgressBar::refresh ()
{
  float fg_width = (value / max_value) * width;
  if (fg_width < 1.0)
  {
	foreground_rect.set_corners_radius (0);
  }
  foreground_rect.set_size (Vector2f (fg_width, 11));
}

}// namespace sf