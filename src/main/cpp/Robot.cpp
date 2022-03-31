// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandScheduler.h>

void
Robot::RobotInit ()
{
  // Flush NetworkTables every loop. This ensures that robot pose and other
  // values are sent during every iteration.
  SetNetworkTablesFlushEnabled (true);
  
  frc::SmartDashboard::init();
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want to run during disabled,
 * autonomous, teleoperated and test.
 *
 * This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void
Robot::RobotPeriodic ()
{
  frc2::CommandScheduler::GetInstance ().Run ();
}

/**
 * This function is called once each time the robot enters Disabled mode. You
 * can use it to reset any subsystem information you want to clear when the
 * robot is disabled.
 */
void
Robot::DisabledInit ()
{
  frc2::CommandScheduler::GetInstance ().CancelAll ();
  m_container.ZeroAllOutputs ();
}

void
Robot::DisabledPeriodic ()
{
  frc2::CommandScheduler::GetInstance ().CancelAll ();
  m_container.ZeroAllOutputs ();
}

void
Robot::AutonomousInit ()
{
  m_autonomous_command = m_container.GetAutonomousCommand ();

  if (m_autonomous_command != nullptr)
    {
      m_autonomous_command->Schedule ();
    }
}

void
Robot::AutonomousPeriodic ()
{
}

void
Robot::TeleopInit ()
{
  // This makes sure that the autonomous stops running when
  // teleop starts running. If you want the autonomous to
  // continue until interrupted by another command, remove
  // this line or comment it out.
  if (m_autonomous_command != nullptr)
    {
      m_autonomous_command->Cancel ();
      m_autonomous_command = nullptr;
    }
}

/**
 * This function is called periodically during operator control.
 */
void
Robot::TeleopPeriodic ()
{
  m_container.MoveRobot ();
}

void
Robot::TestInit ()
{
}

/**
 * This function is called periodically during test mode.
 */
void
Robot::TestPeriodic ()
{
}

#ifndef RUNNING_FRC_TESTS
int
main ()
{
  return frc::StartRobot<Robot> ();
}
#endif
