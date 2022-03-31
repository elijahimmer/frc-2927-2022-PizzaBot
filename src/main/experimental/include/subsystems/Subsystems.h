#pragma once

#include "Controllers.h"
#include "subsystems/Drivetrain.h"
#include "subsystems/SubsystemBase.h"

#include <algorithm>
#include <array>

namespace subsystems
{
struct SubsystemsContainer
{
  Drivetrain drivetrain;
};
class Subsystems
{
public:
  Subsystems () = default;

  enum SubsystemsList
  {
    DRIVETRAIN,
    COUNT
  };
  SubsystemBase *operator[] (SubsystemsList subsystem);

  SubsystemBase *GetSubsystem (SubsystemsList subsystem);
  std::array<SubsystemBase *, 1U> GetSubsystemList ();

  void ZeroAllOutputs ();

private:
  SubsystemsContainer m_subsystems{ Drivetrain () };
}; // class Subsystems
} // namespace subsystems
