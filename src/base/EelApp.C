#include "EelApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<EelApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

EelApp::EelApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  EelApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  EelApp::associateSyntax(_syntax, _action_factory);
}

EelApp::~EelApp()
{
}

// External entry point for dynamic application loading
extern "C" void EelApp__registerApps() { EelApp::registerApps(); }
void
EelApp::registerApps()
{
  registerApp(EelApp);
}

// External entry point for dynamic object registration
extern "C" void EelApp__registerObjects(Factory & factory) { EelApp::registerObjects(factory); }
void
EelApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void EelApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { EelApp::associateSyntax(syntax, action_factory); }
void
EelApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
