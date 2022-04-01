#include "Subsystems/Drivetrain.h"

#include <frc/smartdashboard/SmartDashboard.h>

subsystems::Drivetrain::Drivetrain ()
{
  SetName ("Drivetrain");

  AddChild ("Differential Drive", &m_drive);

  frc::SmartDashboard::PutData ("Drivetrain", this);

  m_left_front.SetInverted (constants::drivetrain::inverted::LEFT_FRONT);
  m_left_back.SetInverted (constants::drivetrain::inverted::LEFT_BACK);
  m_right_front.SetInverted (constants::drivetrain::inverted::RIGHT_FRONT);
  m_right_back.SetInverted (constants::drivetrain::inverted::RIGHT_BACK);

  m_left_front.SetIdleMode (constants::drivetrain::IDLE_MODE);
  m_left_back.SetIdleMode (constants::drivetrain::IDLE_MODE);
  m_right_front.SetIdleMode (constants::drivetrain::IDLE_MODE);
  m_right_back.SetIdleMode (constants::drivetrain::IDLE_MODE);

  m_left_front.SetSmartCurrentLimit (
      constants::drivetrain::smart_current_limit::LEFT_FRONT);
  m_left_back.SetSmartCurrentLimit (
      constants::drivetrain::smart_current_limit::LEFT_BACK);
  m_right_front.SetSmartCurrentLimit (
      constants::drivetrain::smart_current_limit::RIGHT_FRONT);
  m_right_back.SetSmartCurrentLimit (
      constants::drivetrain::smart_current_limit::RIGHT_BACK);

  m_left_front.SetOpenLoopRampRate (
      constants::drivetrain::open_loop_ramp_rate::LEFT_FRONT);
  m_left_back.SetOpenLoopRampRate (
      constants::drivetrain::open_loop_ramp_rate::LEFT_BACK);
  m_right_front.SetOpenLoopRampRate (
      constants::drivetrain::open_loop_ramp_rate::RIGHT_FRONT);
  m_right_back.SetOpenLoopRampRate (
      constants::drivetrain::open_loop_ramp_rate::RIGHT_BACK);

  m_left_front.SetClosedLoopRampRate (
      constants::drivetrain::closed_loop_ramp_rate::LEFT_FRONT);
  m_left_back.SetClosedLoopRampRate (
      constants::drivetrain::closed_loop_ramp_rate::LEFT_BACK);
  m_right_front.SetClosedLoopRampRate (
      constants::drivetrain::closed_loop_ramp_rate::RIGHT_FRONT);
  m_right_back.SetClosedLoopRampRate (
      constants::drivetrain::closed_loop_ramp_rate::RIGHT_BACK);
}

void
subsystems::Drivetrain::Periodic ()
{
  m_drive.Feed ();
}

void
subsystems::Drivetrain::Stop ()
{
  m_drive.StopMotor ();
}

frc::DifferentialDrive *
subsystems::Drivetrain::GetDiffDrive ()
{
  return &m_drive;
}

rev::CANSparkMax *
subsystems::Drivetrain::GetMotor (Motors motor)
{
  switch (motor)
    {
    case Motors::kLeftFront:
      return &m_left_front;
    case Motors::kLeftBack:
      return &m_left_back;
    case Motors::kRightFront:
      return &m_right_front;
    case Motors::kRightBack:
      return &m_right_back;
    default:
      assert ("Invalid motor");
      return nullptr;
    }
}

subsystems::Drivetrain::MotorsContainer
subsystems::Drivetrain::GetMotors ()
{
  static MotorsContainer motors
      = { &m_left_front, &m_left_back, &m_right_front, &m_right_back };
  return motors;
}

void
subsystems::Drivetrain::TankDrive (double left, double right)
{
  m_drive.TankDrive (left, right);
}

void
subsystems::Drivetrain::ArcadeDrive (double move, double rotate)
{
  m_drive.ArcadeDrive (move, rotate);
}

void
subsystems::Drivetrain::CurvatureDrive (double move, double rotate,
                                        bool isQuickTurn)
{
  m_drive.CurvatureDrive (move, rotate, isQuickTurn);
}

std::string
subsystems::Drivetrain::GetName () const
{
  return "Drivetrain";
}