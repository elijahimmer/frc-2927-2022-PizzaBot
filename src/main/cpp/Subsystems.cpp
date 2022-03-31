#include "Subsystems.h"

subsystems::Subsystems
subsystems::build_subsystems ()
{
  return subsystems::Subsystems{ subsystems::Drivetrain{} };
}
