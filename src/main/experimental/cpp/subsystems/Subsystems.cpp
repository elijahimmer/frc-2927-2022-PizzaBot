#include "subsystems/Subsystems.h"

#include "subsystems/Drivetrain.h"

#include <algorithm>
#include <array>

subsystems::SubsystemBase *
operator[] (SubsystemsList subsystem)
{
  return GetSubsystem (subsystem);
}

subsystems::SubsystemBase *
subsystems::Subsystems::GetSubsystem (SubsystemsList subsystem)
{
  switch (subsystem)
    {
    case DRIVETRAIN:
      return &m_subsystems.drivetrain;
    default:
      return nullptr;
    }
}

std::array<subsystems::SubsystemBase *, 1U>
subsystems::Subsystems::GetSubsystemList ()
{
  static std::array<SubsystemBase *, 1U> subsystems
      = { &m_subsystems.drivetrain };
  return subsystems;
}

void
subsystems::Subsystems::ZeroAllOutputs ()
{
  for (auto *subsystem : GetSubsystemList ())
    subsystem->ZeroOutputs ();
}
