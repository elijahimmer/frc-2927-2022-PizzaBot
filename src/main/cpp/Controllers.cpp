#include "Controllers.h"
#include "constants/Controllers.h"

controllers::Controllers
controllers::build_controllers ()
{
  controllers::Controllers controllers{
    frc::XboxController (constants::controllers::DriverControllerPort),
  };

  return controllers;
}