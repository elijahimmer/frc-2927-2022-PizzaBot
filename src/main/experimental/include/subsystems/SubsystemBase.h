#pragma once

#include <frc2/command/SubsystemBase.h>
#include <string>

namespace subsystems
{
class SubsystemBase : public frc2::SubsystemBase
{
public:
  virtual void ZeroOutputs () = 0;
  virtual std::string GetName () const = 0;
};
}
