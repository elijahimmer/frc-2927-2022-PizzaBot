/**
 * @file Autonomous.h
 * @author Elijah Immer (Hatty@dnd4u.net)
 * @brief A include for all Autonomous Commands
 * @version 1.0
 * @date 2022-03-28
 *
 * @copyright Copyright (c) 2022
 *
 */

#pragma once

#include "Subsystems.h"
#include "autonomous/Nothing.h"
#include "autonomous/Taxi.h"

#include <array>

namespace autonomous
{
struct Autonomous
{
  Nothing nothing{};
  Taxi taxi_forwards{};
  Taxi taxi_backwards{};
};

Autonomous build_autonomous (subsystems::Subsystems *subsystems);

std::array<frc2::Command *, 3U>
GetAutonomousList (autonomous::Autonomous autonomous);

} // namspace autonomous