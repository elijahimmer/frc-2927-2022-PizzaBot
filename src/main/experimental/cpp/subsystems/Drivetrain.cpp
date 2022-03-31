#include "subsystems/Drivetrain.h"

#include "Controllers.h"

#include <frc2/command/PrintCommand.h>

using namespace subsystems;

Drivetrain::Drivetrain ()
{
  m_motor_controllers.left_front.SetInverted (
      constants::drivetrain::inverted::LEFT_FRONT);
  m_motor_controllers.left_back.SetInverted (
      constants::drivetrain::inverted::LEFT_BACK);
  m_motor_controllers.right_front.SetInverted (
      constants::drivetrain::inverted::RIGHT_FRONT);
  m_motor_controllers.right_back.SetInverted (
      constants::drivetrain::inverted::RIGHT_BACK);

  m_motor_controllers.left_front.SetIdleMode (
      constants::drivetrain::IDLE_MODE);
  m_motor_controllers.left_back.SetIdleMode (constants::drivetrain::IDLE_MODE);
  m_motor_controllers.right_front.SetIdleMode (
      constants::drivetrain::IDLE_MODE);
  m_motor_controllers.right_back.SetIdleMode (
      constants::drivetrain::IDLE_MODE);

  m_motor_controllers.left_front.SetSmartCurrentLimit (
      constants::drivetrain::smart_current_limit::LEFT_FRONT);
  m_motor_controllers.left_back.SetSmartCurrentLimit (
      constants::drivetrain::smart_current_limit::LEFT_BACK);
  m_motor_controllers.right_front.SetSmartCurrentLimit (
      constants::drivetrain::smart_current_limit::RIGHT_FRONT);
  m_motor_controllers.right_back.SetSmartCurrentLimit (
      constants::drivetrain::smart_current_limit::RIGHT_BACK);

  m_motor_controllers.left_front.SetOpenLoopRampRate (
      constants::drivetrain::open_loop_ramp_rate::LEFT_FRONT);
  m_motor_controllers.left_back.SetOpenLoopRampRate (
      constants::drivetrain::open_loop_ramp_rate::LEFT_BACK);
  m_motor_controllers.right_front.SetOpenLoopRampRate (
      constants::drivetrain::open_loop_ramp_rate::RIGHT_FRONT);
  m_motor_controllers.right_back.SetOpenLoopRampRate (
      constants::drivetrain::open_loop_ramp_rate::RIGHT_BACK);

  m_motor_controllers.left_front.SetClosedLoopRampRate (
      constants::drivetrain::closed_loop_ramp_rate::LEFT_FRONT);
  m_motor_controllers.left_back.SetClosedLoopRampRate (
      constants::drivetrain::closed_loop_ramp_rate::LEFT_BACK);
  m_motor_controllers.right_front.SetClosedLoopRampRate (
      constants::drivetrain::closed_loop_ramp_rate::RIGHT_FRONT);
  m_motor_controllers.right_back.SetClosedLoopRampRate (
      constants::drivetrain::closed_loop_ramp_rate::RIGHT_BACK);
}

void
Drivetrain::Periodic ()
{
  m_diff_drive.Feed ();
}

void
Drivetrain::ZeroOutputs ()
{
  m_diff_drive.StopMotor ();
}

std::string
Drivetrain::GetName () const
{
  return "Drivetrain";
}

void
Drivetrain::TankDrive (double left, double right, bool square_inputs)
{
  m_diff_drive.TankDrive (left, right, square_inputs);
}

void
Drivetrain::ArcadeDrive (double move, double rotate, bool square_inputs)
{
  m_diff_drive.ArcadeDrive (move, rotate, square_inputs);
}

void
Drivetrain::CurvatureDrive (double move, double rotate, bool is_quick_turn)
{
  m_diff_drive.CurvatureDrive (move, rotate, is_quick_turn);
}
