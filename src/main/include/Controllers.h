#pragma once 

#include "constants/Controllers.h"

#include <frc/XboxController.h>

namespace controllers
{

struct Controllers
{
  frc::XboxController driver;
};

Controllers build_controllers ();

} // namespace controllers
