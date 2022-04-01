/**
 * @file RobotContainer.h
 * @author Elijah Immer (hatty@dnd4u.net)
 * @brief A general holding place for Subsystems and Commands
 * @version 0.2
 * @date 2022-3-19
 *
 * @copyright Copyright (c) 2021
 *
 */

#pragma once

#include "Autonomous.h"
#include "Controllers.h"
#include "Subsystems.h"

#include <frc/smartdashboard/SendableChooser.h>
/**
 * @brief The main storage for the Robot,
 * Holding its Subsystems and Commands.
 */
class RobotContainer
{
public:
  RobotContainer ();

  /**
   * @brief Activates the teleop periodic event letting the driver steer with
   * the joystick
   *
   */
  void MoveRobot ();

  /**
   * @brief disables all voltage output.
   * Mainly used to stop the robot for disabling
   */
  void ZeroAllOutputs ();

  /**
   * @brief Get the Subsystems Struct
   *
   * @return Struct of subsystems
   */
  auto *GetSubsystems ();

  /**
   * @brief Get the Controllers Struct
   *
   * @return Struct of Controllers
   */
  auto *GetControllers ();

  /**
   * @brief
   *
   */
  frc2::Command *GetAutonomousCommand ();

  enum DriveMode
  {
    kTank,
    kArcadeSingle,
    kArcadeDual,
    kTesting,
  };

private:
  controllers::Controllers m_controllers = controllers::build_controllers ();
  subsystems::Subsystems m_subsystems = subsystems::build_subsystems ();
  autonomous::Autonomous m_autonomous
      = autonomous::build_autonomous (&m_subsystems);

  frc::SendableChooser<frc2::Command *> m_auto_chooser;

  frc::SendableChooser<DriveMode> m_drive_mode_chooser;

};
