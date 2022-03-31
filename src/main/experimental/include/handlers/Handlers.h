#pragma once

#include "handlers/Drive.h"
#include "handlers/HandlerBase.h"

#include "Controllers.h"
#include "subsystems/Subsystems.h"

namespace handlers
{
struct HandlersContainer
{
  handlers::Drive drive;
};

class Handlers
{
public:
  Handlers () = default;
  Handlers (controllers::Controllers *controller,
            subsystems::Subsystems *subsystems);

  enum HandlersList
  {
    DRIVE = 0,
    COUNT
  };

  HandlerBase *operator[] (HandlersList handler);

  HandlerBase *GetHandler (HandlersList handler);
  std::array<HandlerBase *, 1U> GetHandlerList () const;

private:
  HandlersContainer m_handlers;
};

} // namespace handlers