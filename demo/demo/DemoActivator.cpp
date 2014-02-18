#include <plugin/contract.h>
#include "../gameengine.contract/contract.h"
#include "DemoGame.h"
#include <iostream>

using namespace plugin;

class DemoActivator : public IPluginActivator, public IServiceListener
{
public:
	DemoActivator() {

	}

	virtual ~DemoActivator() {

	}

	virtual void Start(IPluginContext* context, IPlugin* plugin) {
		context->RegisterService(typeid(gameengine::IGame), &mService);
	}

	virtual void Stop(IPlugin* plugin) {
		std::cout << "DemoActivator is deactivated" << std::endl;
	}

	virtual void ServiceRegistered(const type_info& type, IPluginContext* context, IServiceReference* reference) {
		std::cout << "DemoActivator -> Service is registered of type: " << type.name() << std::endl;
	}

	virtual void ServiceUnregisted(const type_info& type, IPluginContext* context, const IServiceReference* service) {

	}

private:
	DemoGame mService;
};

DEFINE_PLUGIN(DemoActivator, "1.0.0");