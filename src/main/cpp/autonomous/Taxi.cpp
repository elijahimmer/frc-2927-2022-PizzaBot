#include "autonomous/Taxi.h"
#include "constants/autonomous/taxi.h"

#include "subsystems/Drivetrain.h"

autonomous::Taxi::Taxi (subsystems::Drivetrain *drivetrain, bool backwards)
{
  m_drivetrain = drivetrain;
  m_timer = frc::Timer ();

  if (backwards)
    {
      m_speed *= -1;
      SetName ("Taxi Backwards");
    }
  else
    {
      SetName ("Taxi Forward");
    }
}

void
autonomous::Taxi::Initialize ()
{
  m_drivetrain->TankDrive (m_speed, m_speed);
  m_timer.Reset ();
  m_timer.Start ();
}

void
autonomous::Taxi::Execute ()
{
  m_drivetrain->TankDrive (m_speed, m_speed);
}

void
autonomous::Taxi::End (bool interrupted)
{
  m_drivetrain->Stop ();
}

bool
autonomous::Taxi::IsFinished ()
{
  return m_timer.Get () >= constants::autonomous::taxi::time;
}
