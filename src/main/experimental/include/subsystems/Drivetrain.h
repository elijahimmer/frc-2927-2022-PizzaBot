#pragma once

#include "Controllers.h"
#include "constants/Drivetrain.h"
#include "subsystems/SubsystemBase.h"

#include <frc/XboxController.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/motorcontrol/MotorControllerGroup.h>
#include <frc2/command/SubsystemBase.h>
#include <rev/CANSparkMax.h>
#include <string>

namespace subsystems
{
/**
 * @brief The Drivetrain Subsystem used for movement
 */
class Drivetrain : public subsystems::SubsystemBase
{
public:
  Drivetrain ();

  void Periodic () override;

  void ZeroOutputs () override;
  std::string GetName () const override;

  void TankDrive (double left, double right, bool square_inputs = true);
  void ArcadeDrive (double move, double rotate, bool square_inputs = true);
  void CurvatureDrive (double move, double rotate, bool is_quick_turn = false);

  /**
   * @brief A holding place for Drivetrain Motor Controllers
   *
   */
  struct MotorContollers
  {
    rev::CANSparkMax left_front;
    rev::CANSparkMax left_back;
    rev::CANSparkMax right_front;
    rev::CANSparkMax right_back;
  } m_motor_controllers{
    rev::CANSparkMax (constants::drivetrain::can_index::LEFT_FRONT,
                      rev::CANSparkMaxLowLevel::MotorType::kBrushed),
    rev::CANSparkMax (constants::drivetrain::can_index::LEFT_BACK,
                      rev::CANSparkMaxLowLevel::MotorType::kBrushed),
    rev::CANSparkMax (constants::drivetrain::can_index::RIGHT_FRONT,
                      rev::CANSparkMaxLowLevel::MotorType::kBrushed),
    rev::CANSparkMax (constants::drivetrain::can_index::RIGHT_BACK,
                      rev::CANSparkMaxLowLevel::MotorType::kBrushed)
  };

  /**
   * @brief A holding place for Drivetrain Motor Controller Groups
   *
   */
  struct MotorControllerGroups
  {
    frc::MotorControllerGroup left;
    frc::MotorControllerGroup right;
  } m_motor_controller_groups{
    frc::MotorControllerGroup (m_motor_controllers.left_back,
                               m_motor_controllers.left_front),
    frc::MotorControllerGroup (m_motor_controllers.right_front,
                               m_motor_controllers.right_back)
  };

  /**
   * @brief The general controller for driving
   */
  frc::DifferentialDrive m_diff_drive{ m_motor_controller_groups.left,
                                       m_motor_controller_groups.right };
};
} // namespace subsystems