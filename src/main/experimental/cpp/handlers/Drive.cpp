#include "handlers/Drive.h"

#include <frc/Joystick.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/PrintCommand.h>

void
handlers::Drive::Drive (controllers::Controllers *controller)
{
  m_controller = controller;
  m_drive_mode_chooser.InitSendable (frc::SmartDashboard::GetInstance ());

  m_drive_mode_chooser.SetDefaultOption ("Tank", DriveMode::TANK);
  m_drive_mode_chooser.AddOption ("Arcade Single Axis",
                                  DriveMode::ARCADE_SINGLE_AXIS);
  m_drive_mode_chooser.AddOption ("Arcade Double Axis",
                                  DriveMode::ARCADE_DOUBLE_AXIS);
  frc::SmartDashboard::PutData ("Drive Mode", &m_drive_mode_chooser);
}

frc2::InstantCommand *
handlers::drive::GetDriveHandler ()
{
  static frc2::InstantCommand drive_handler
      = { [&] {
           switch (m_drive_mode_chooser.GetSelected ())
             {
             case DriveMode::TANK:
               subsystems::m_subsystems.drivetrain.TankDrive (
                   m_controllers.driver.GetRawAxis (
                       frc::XboxController::Axis::kLeftY),
                   m_controllers.driver.GetRawAxis (
                       frc::XboxController::Axis::kRightY));
               break;

             case DriveMode::ARCADE_SINGLE_AXIS:
               subsystems::m_subsystems.drivetrain.CurvatureDrive (
                   m_controllers.driver.GetRawAxis (
                       frc::XboxController::Axis::kLeftY),
                   m_controllers.driver.GetRawAxis (
                       frc::XboxController::Axis::kLeftX),
                   m_controllers.driver.GetRightBumper ());
               break;

             case DriveMode::ARCADE_DOUBLE_AXIS:
               subsystems::m_subsystems.drivetrain.CurvatureDrive (
                   m_controllers[controllers::Controllers::]GetRawAxis (
                       frc::XboxController::Axis::kLeftY),
                   m_controllersdriver.GetRawAxis (
                       frc::XboxController::Axis::kRightX),
                   m_controllers->driver.GetRightBumper ());
               break;

             default:
               frc2::PrintCommand ("Invalid drive mode").Schedule ();
               break;
             }
         },
          { &subsystems::m_subsystems.drivetrain } };
  return &drive_handler;
}
