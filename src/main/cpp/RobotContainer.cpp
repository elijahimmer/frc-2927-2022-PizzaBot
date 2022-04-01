#include "RobotContainer.h"

#include "Autonomous.h"

#include <frc/PowerDistribution.h>
#include <frc/shuffleboard/Shuffleboard.h>
#include <frc/shuffleboard/ShuffleboardComponent.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandScheduler.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/button/JoystickButton.h>

#define DEBUG_MODE

#if defined DEBUG_MODE
#include <frc2/command/PrintCommand.h>
#endif

RobotContainer::RobotContainer ()
{
  frc::SmartDashboard::PutData (&frc2::CommandScheduler::GetInstance ());

  // Initialize all of your Commands and Subsystems here

  m_auto_chooser.SetDefaultOption ("Nothing", &m_autonomous.nothing);
  m_auto_chooser.AddOption ("Taxi Forward", &m_autonomous.taxi_forwards);
  m_auto_chooser.AddOption ("Taxi Backwards", &m_autonomous.taxi_backwards);

  frc::SmartDashboard::PutData ("Autonomous Chooser", &m_auto_chooser);

  m_drive_mode_chooser.SetDefaultOption ("Tank Drive", DriveMode::kTank);
  m_drive_mode_chooser.AddOption ("Arcade Single Stick",
                                  DriveMode::kArcadeSingle);
  m_drive_mode_chooser.AddOption ("Arcade Dual Stick", DriveMode::kArcadeDual);
  m_drive_mode_chooser.AddOption ("Testing", DriveMode::kTesting);

  frc::SmartDashboard::PutData ("Drive Mode Chooser", &m_drive_mode_chooser);
}

void
RobotContainer::MoveRobot ()
{
  if (!m_controllers.driver.IsConnected ())
    {
      return;
    }

  double x_magnitude = 0.0;
  double y_magnitude = 0.0;

  switch (m_drive_mode_chooser.GetSelected ())
    {
    case DriveMode::kTank:
      x_magnitude = m_controllers.driver.GetLeftY ();
      y_magnitude = m_controllers.driver.GetRightY ();

      frc2::InstantCommand (
          [&] {
            m_subsystems.drivetrain.TankDrive (
                m_controllers.driver.GetLeftY (),
                m_controllers.driver.GetRightY ());

#if defined DEBUG_MODE
            frc2::PrintCommand (
                "TankDrive|LeftTrack:" + std::to_string (x_magnitude)
                + ";RightTrack:" + std::to_string (y_magnitude))
                .Schedule ();
#endif
          },
          { &m_subsystems.drivetrain })
          .Schedule ();
      break;
    case DriveMode::kArcadeSingle:
      x_magnitude = m_controllers.driver.GetLeftY ();
      y_magnitude = m_controllers.driver.GetLeftX ();

      frc2::InstantCommand (
          [&] {
            m_subsystems.drivetrain.CurvatureDrive (
                m_controllers.driver.GetLeftY (),
                m_controllers.driver.GetLeftX (),
                m_controllers.driver.GetRightBumper ());
#if defined DEBUG_MODE
            frc2::PrintCommand (
                "ArcadeDriveSingleAxis|Speed:" + std::to_string (x_magnitude)
                + ";Turn:" + std::to_string (y_magnitude) + ";QuickTurn:"
                + std::to_string (m_controllers.driver.GetRightBumper ()))
                .Schedule ();
#endif
          },
          { &m_subsystems.drivetrain })
          .Schedule ();
      break;

    case DriveMode::kArcadeDual:
      x_magnitude = m_controllers.driver.GetLeftY ();
      y_magnitude = m_controllers.driver.GetRightX ();

      frc2::InstantCommand (
          [&] {
            m_subsystems.drivetrain.CurvatureDrive (
                x_magnitude, y_magnitude,
                m_controllers.driver.GetRightBumper ());
#if defined DEBUG_MODE
            frc2::PrintCommand (
                "ArcadeDriveDoubleAxis|Speed:" + std::to_string (x_magnitude)
                + ";Turn:" + std::to_string (y_magnitude) + ";QuickTurn:"
                + std::to_string (m_controllers.driver.GetRightBumper ()))
                .Schedule ();
#endif
          },
          { &m_subsystems.drivetrain })
          .Schedule ();
      break;

    case DriveMode::kTesting:
      frc2::InstantCommand (
          [&] {
            auto motors = m_subsystems.drivetrain.GetMotors ();

            m_subsystems.drivetrain.GetDiffDrive ()->Feed ();

            if (m_controllers.driver.GetAButtonPressed ())
              {
                motors.left_front->Set (1.0);
#if defined DEBUG_MODE
                frc2::PrintCommand ("A Button Pressed!").Schedule ();
#endif
              }
            else if (m_controllers.driver.GetAButtonReleased ())
              {
                motors.left_front->StopMotor ();
#if defined DEBUG_MODE
                frc2::PrintCommand ("A Button Released!").Schedule ();
#endif
              }
            if (m_controllers.driver.GetBButtonPressed ())
              {
                motors.left_back->Set (1.0);
#if defined DEBUG_MODE
                frc2::PrintCommand ("B Button Pressed!").Schedule ();
#endif
              }
            else if (m_controllers.driver.GetBButtonReleased ())
              {
                motors.left_back->StopMotor ();
#if defined DEBUG_MODE
                frc2::PrintCommand ("B Button Released!").Schedule ();
#endif
              }
            if (m_controllers.driver.GetXButtonPressed ())
              {
                motors.right_front->Set (1.0);
#if defined DEBUG_MODE
                frc2::PrintCommand ("X Button Pressed!").Schedule ();
#endif
              }
            else if (m_controllers.driver.GetXButtonReleased ())
              {
                motors.right_front->StopMotor ();
#if defined DEBUG_MODE
                frc2::PrintCommand ("X Button Released!").Schedule ();
#endif
              }
            if (m_controllers.driver.GetYButtonPressed ())
              {
                motors.right_back->Set (1.0);
#if defined DEBUG_MODE
                frc2::PrintCommand ("Y Button Pressed!").Schedule ();
#endif
              }
            else if (m_controllers.driver.GetYButtonReleased ())
              {
                motors.right_back->StopMotor ();
#if defined DEBUG_MODE
                frc2::PrintCommand ("Y Button Released!").Schedule ();
#endif
              }
          },
          { &m_subsystems.drivetrain })
          .Schedule ();
      break;
    default:
#if defined DEBUG_MODE
      frc2::PrintCommand (
          "Drive Mode selected is: "
          + std::to_string (m_drive_mode_chooser.GetSelected ()))
          .Schedule ();
#else
      frc2::PrintCommand ("Unknown Drive Mode").Schedule ();
#endif
      return;
    }

  m_controllers.driver.SetRumble (frc::GenericHID::RumbleType::kLeftRumble,
                                  x_magnitude);
  m_controllers.driver.SetRumble (frc::GenericHID::RumbleType::kRightRumble,
                                  y_magnitude);
}

void
RobotContainer::ZeroAllOutputs ()
{
  m_subsystems.drivetrain.Stop ();
}

auto *
RobotContainer::GetSubsystems ()
{
  return &m_subsystems;
}

frc2::Command *
RobotContainer::GetAutonomousCommand ()
{
  return m_auto_chooser.GetSelected ();
}
