#include "Autonomous.h"

autonomous::Autonomous
autonomous::build_autonomous (subsystems::Subsystems *subsystems)
{
  autonomous::Autonomous autonomous;

  autonomous.nothing = autonomous::Nothing ();
  autonomous.taxi_forwards = autonomous::Taxi (&subsystems->drivetrain, false);
  autonomous.taxi_backwards = autonomous::Taxi (&subsystems->drivetrain, true);

  return autonomous;
}

std::array<frc2::Command *, 3U>
autonomous::GetAutonomousList (autonomous::Autonomous autonomous)
{
  return {
    &autonomous.nothing,
    &autonomous.taxi_forwards,
    &autonomous.taxi_backwards,
  };
}
