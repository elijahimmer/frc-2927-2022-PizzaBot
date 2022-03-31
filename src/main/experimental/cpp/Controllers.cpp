#include "Controllers.h"

#include <array>

frc::XboxController *
controllers::Controllers::operator[] (ControllersList controller)
{
  return GetController (controller);
}

frc::XboxController *
controllers::Controllers::GetController (ControllersList controller)
{
  switch (controller)
    {
    case DRIVER:
      return &m_controllers.driver;
    default:
      return nullptr;
    }
}

std::array<frc::XboxController *, 1U>
controllers::Controllers::GetControllerList ()
{
  static std::array<frc::XboxController *, 1U> controllers
      = { &m_controllers.driver };
  return controllers;
}