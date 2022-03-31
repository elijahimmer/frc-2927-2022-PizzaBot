/**
 * @file Nothing.h
 * @author Elijah Immer (hatty@dnd4u.net)
 * @brief A Simple Do Nothing Autonomous Command for πρ techs 2022
 * @version 0.2
 * @date 2022-3-19
 *
 * @copyright Copyright (c) 2021
 *
 */

#pragma once

#include "Subsystems/Drivetrain.h"

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include <frc2/command/FunctionalCommand.h>

#include <frc/Timer.h>

namespace autonomous
{
class Nothing : public frc2::CommandHelper<frc2::CommandBase, Nothing>
{
public:
  inline void Initialize () override{};

  inline void Execute () override{};
  inline void End (bool interrupted) override{};

  inline bool
  IsFinished () override
  {
    return true;
  };
}; // class Taxi
} // namespace autonomous
