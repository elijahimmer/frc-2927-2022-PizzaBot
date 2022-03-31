#pragma once

#include "Controllers.h"
#include "Handlers/HandlerBase.h"
#include "subsystems/Subsystems.h"

#include <frc/smartdashboard/SendableChooser.h>
#include <frc2/command/InstantCommand.h>

namespace handlers
{
class Drive : public HandlerBase
{
  Drive () = default;
  Drive (controllers::Controllers *controller);

  enum DriveMode
  {
    TANK = 0,
    ARCADE_SINGLE_AXIS,
    ARCADE_DOUBLE_AXIS,
    COUNT
  };

  frc2::InstantCommand *GetHandler ();

private:
  static frc::SendableChooser<DriveMode> m_drive_mode_chooser;

  controllers::Controllers *m_controllers;
}; // class drive
} // namespace handlers