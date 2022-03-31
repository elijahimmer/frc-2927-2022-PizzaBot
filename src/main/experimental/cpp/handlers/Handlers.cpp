#include "handlers/Handlers.h"

#include "handlers/HandlerBase.h"

handlers::Handlers::Handlers (controllers::Controllers *controller,
                              subsystems::Subsystems *subsystems)
{
  m_handlers.drive = new handlers::Drive (controller, subsystems);
}

handlers::HandlerBase *
handlers::Handlers::operator[] (HandlersList handler)
{
  return GetHandler (handler);
}

handlers::HandlerBase *
handlers::Handlers::GetHandler (HandlersList handler)
{
  switch (handler)
    {
    case DRIVE:
      return &m_handlers.drive;
    default:
      assert ("Invalid handler");
      return nullptr;
    }
}

std::array<handlers::HandlerBase *, 1U>
GetHandlerList ()
{
  static std::array<HandlerBase *, 1U> handlers = { &m_handlers.drive };
  return handlers;
}