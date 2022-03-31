#pragma once

#include "constants/Controllers.h"

#include <array>
#include <frc/XboxController.h>

namespace controllers
{
struct ControllersContainer
{
  frc::XboxController driver{ constants::controllers::ports::DRIVER };
}; // struct ControllersContainer

class Controllers
{
public:
  enum ControllersList
  {
    DRIVER = 0,
    COUNT
  };

  frc::XboxController *operator[] (ControllersList controller);

  frc::XboxController *GetController (ControllersList controller);
  std::array<frc::XboxController *, 1U> GetControllerList ();

private:
  ControllersContainer m_controllers{};
}; // class Controllers
} // namespace controllers
