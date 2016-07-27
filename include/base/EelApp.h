#ifndef EELAPP_H
#define EELAPP_H

#include "MooseApp.h"

class EelApp;

template<>
InputParameters validParams<EelApp>();

class EelApp : public MooseApp
{
public:
  EelApp(InputParameters parameters);
  virtual ~EelApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* EELAPP_H */
