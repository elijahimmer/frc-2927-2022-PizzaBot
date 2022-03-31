/**
 * @file Taxi.h
 * @author Elijah Immer (hatty@dnd4u.net)
 * @brief A Simple Taxi Autonomous Command for πρ techs 2022
 * @version 0.2
 * @date 2022-3-19
 *
 * @copyright Copyright (c) 2021
 *
 */

#pragma once

#include "Subsystems.h"
#include "constants/autonomous/taxi.h"

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc2/command/FunctionalCommand.h>

#include <frc/Timer.h>

namespace autonomous
{
class Taxi : public frc2::CommandHelper<frc2::CommandBase, Taxi>
{
public:
  Taxi () = default;
  Taxi (subsystems::Drivetrain *drivetrain, bool backwards = false);

  void Initialize () override;

  void Execute () override;
  void End (bool interrupted) override;

  bool IsFinished () override;

private:
  subsystems::Drivetrain *m_drivetrain;
  frc::Timer m_timer;
  int m_speed = constants::autonomous::taxi::speed;
}; // class Taxi
} // namespace autonomous