#pragma once

#include "Controllers.h"
#include "subsystems/Subsystems.h"

#include <frc/TimedRobot.h>
#include <frc/XboxController.h>
#include <frc2/command/Command.h>

class Robot : public frc::TimedRobot
{
public:
  void RobotInit () override;
  void RobotPeriodic () override;
  void DisabledInit () override;
  void DisabledPeriodic () override;
  void AutonomousInit () override;
  void AutonomousPeriodic () override;
  void TeleopInit () override;
  void TeleopPeriodic () override;
  void TestInit () override;
  void TestPeriodic () override;

private:
  // Pointer to the command used for the autonomous period.
  frc2::Command *m_autonomous_command = nullptr;

  controllers::Controllers m_controllers{};
  subsystems::Subsystems m_subsystems{};
  handlers::Handlers m_handlers{ &m_controllers, &m_subsystems };
};
