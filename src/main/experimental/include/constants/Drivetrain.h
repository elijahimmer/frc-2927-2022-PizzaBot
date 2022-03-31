/**
 * @file constants/Drivetrain.h
 * @author Elijah Immer (hatty@dnd4u.net)
 * @brief A holding place for Drivetrain Constants
 * @version 0.2
 * @date 2022-3-17
 *
 * @copyright Copyright (c) 2021
 *
 */

#pragma once

#include <rev/CANSparkMax.h>

namespace constants::drivetrain
{

namespace can_index
{
static constexpr int LEFT_FRONT = 1;
static constexpr int LEFT_BACK = 2;
static constexpr int RIGHT_FRONT = 3;
static constexpr int RIGHT_BACK = 4;
} // namespace can_index

namespace inverted
{
static constexpr bool LEFT_FRONT = false;
static constexpr bool LEFT_BACK = true;
static constexpr bool RIGHT_FRONT = false;
static constexpr bool RIGHT_BACK = true;
} // namespace inversion

namespace smart_current_limit
{
static constexpr int LEFT_FRONT = 40;
static constexpr int LEFT_BACK = 40;
static constexpr int RIGHT_FRONT = 40;
static constexpr int RIGHT_BACK = 40;
} // namespace smart_current_limit

namespace smart_current_limit_peak
{
static constexpr int LEFT_FRONT = 40;
static constexpr int LEFT_BACK = 40;
static constexpr int RIGHT_FRONT = 40;
static constexpr int RIGHT_BACK = 40;
} // namespace smart_current_limit_peak

namespace open_loop_ramp_rate
{
static constexpr double LEFT_FRONT = 0.0;
static constexpr double LEFT_BACK = 0.0;
static constexpr double RIGHT_FRONT = 0.0;
static constexpr double RIGHT_BACK = 0.0;
} // namespace open_loop_ramp_rate

namespace closed_loop_ramp_rate
{
static constexpr double LEFT_FRONT = 0.0;
static constexpr double LEFT_BACK = 0.0;
static constexpr double RIGHT_FRONT = 0.0;
static constexpr double RIGHT_BACK = 0.0;
} // namespace closed_loop_ramp_rate

namespace voltage_compensation_ramp_rate
{
static constexpr double LEFT_FRONT = 0.0;
static constexpr double LEFT_BACK = 0.0;
static constexpr double RIGHT_FRONT = 0.0;
static constexpr double RIGHT_BACK = 0.0;
} // namespace voltage_compensation_ramp_rate

static constexpr rev::CANSparkMax::IdleMode IDLE_MODE
    = rev::CANSparkMax::IdleMode::kBrake;

static constexpr bool SQUARE_INPUT = true;

} // namespace constants::drivetrain