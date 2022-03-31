/**
 * @file Subsystems.h
 * @author Elijah Immer (Hatty@dnd4u.net)
 * @brief A include for all Subsystems
 * @version 1.0
 * @date 2022-03-28
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include "Subsystems/Drivetrain.h"

namespace subsystems
{
struct Subsystems
{
  Drivetrain drivetrain;
};

Subsystems build_subsystems ();

} // namespace subsystems
