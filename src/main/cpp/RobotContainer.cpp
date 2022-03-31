#include "RobotContainer.h"

#include "Autonomous.h"

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandScheduler.h>
#include <frc2/command/InstantCommand.h>
#include <frc2/command/button/JoystickButton.h>

RobotContainer::RobotContainer ()
{
  // Initialize all of your Commands and Subsystems here
  {
    m_auto_chooser.AddOption ("Nothing", &m_autonomous.nothing);
    m_auto_chooser.AddOption ("Taxi Forward", &m_autonomous.taxi_forwards);
    m_auto_chooser.AddOption ("Taxi Backwards", &m_autonomous.taxi_backwards);

    frc::SmartDashboard::PutData ("Autonomous Chooser", &m_auto_chooser);

    m_drive_mode_chooser.AddOption ("Tank Drive", DriveMode::kTank);
    m_drive_mode_chooser.AddOption ("Arcade Single Stick",
                                    DriveMode::kArcadeSingle);
    m_drive_mode_chooser.AddOption ("Arcade Dual Stick",
                                    DriveMode::kArcadeDual);
  };

  // Configure Button Bindings
  {};
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
          },
          { &m_subsystems.drivetrain })
          .Schedule ();
      break;
    default:
      assert ("Unknown Drive Mode");
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
