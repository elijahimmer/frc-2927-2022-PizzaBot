#pragma once

#include "constants/Drivetrain.h"

#include <frc/drive/DifferentialDrive.h>
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>
#include <string>

namespace subsystems
{
/**
 * @brief The Generic Drivetrain Subsystem for movement
 */
class Drivetrain : public frc2::SubsystemBase
{
public:
  Drivetrain ();

  void Periodic () override;

  void Stop ();

  frc::DifferentialDrive *GetDiffDrive ();

  void TankDrive (double left, double right);
  void ArcadeDrive (double move, double rotate);
  void CurvatureDrive (double move, double rotate,
                              bool isQuickTurn = false);

  std::string GetName () const;

private:
  // Raw Ports
  rev::CANSparkMax m_left_front{
    constants::drivetrain::can_index::LEFT_FRONT,
    rev::CANSparkMaxLowLevel::MotorType::kBrushed
  };
  rev::CANSparkMax m_left_back{
    constants::drivetrain::can_index::LEFT_BACK,
    rev::CANSparkMaxLowLevel::MotorType::kBrushed
  };
  rev::CANSparkMax m_right_front{
    constants::drivetrain::can_index::RIGHT_FRONT,
    rev::CANSparkMaxLowLevel::MotorType::kBrushed
  };
  rev::CANSparkMax m_right_back{
    constants::drivetrain::can_index::RIGHT_BACK,
    rev::CANSparkMaxLowLevel::MotorType::kBrushed
  };

  // Motor Groups

  frc::MotorControllerGroup m_left{ m_left_back, m_left_front };
  frc::MotorControllerGroup m_right{ m_right_front, m_right_back };

  // Motor Control
  /**
   * @brief The general drive command
   */
  frc::DifferentialDrive m_drive{ m_left, m_right };
};
} // namespace subsystems