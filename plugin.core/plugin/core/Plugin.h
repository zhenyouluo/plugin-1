#pragma once
#ifndef _CORE_PLUGIN_H_
#define _CORE_PLUGIN_H_

#include <plugin/contract.h>
#include <list>
#include <memory>
#include "Version.h"

#ifdef __GNUC__
#include <ext/hash_map>
namespace std { using namespace __gnu_cxx; }
#else
#include <hash_map>
#endif

namespace plugin
{
	using namespace contract;

	namespace core
	{
		class ServiceReference;
		class PluginContext;

		//
		// Implementation of the IPlugin contract
		class Plugin : public IPlugin
		{
			typedef std::hash_map<std::string, std::shared_ptr<ServiceReference>> ServiceReferences;
			typedef std::list<IServiceListener*> ServiceListeners;

		public:
			Plugin(PluginContext& context, IPluginActivator* activator, const Version& version);
			~Plugin();

			//
			// Starts this plugin in the supplied context
			//
			// @param context
			//			The context where all the plugins resides
			void Start(PluginContext& context);

			//
			// Stops this plugin from running.
			void Stop();

			//
			// Locates a service reference using the supplied type
			//
			// @param type
			//			The type
			// @return A service reference
			ServiceReference* FindServiceReference(const type_info& type);

			//
			// Notifies all the listeners connected via this plugin
			//
			// @param type
			//			The service type
			// @param service
			//			The actual service
			// @param status
			//			The status of the service
			void NotifyServiceChanged(const type_info& type, ServiceReference& reference, IServiceListener::Status status);

		// IPlugin
		public:
			virtual IServiceReference* RegisterService(const type_info& type, IService* service);
			virtual void UnregisterServices(const type_info& type);
			virtual void UnregisterService(IServiceReference* reference);
			virtual void AddServiceListener(IServiceListener* listener);
			virtual void RemoveServiceListener(IServiceListener* listener);
			virtual Status GetStatus() const;
			virtual const IVersion& GetVersion() const;
			virtual IPluginContext& GetContext();

		private:
			PluginContext& mPluginContext;
			std::auto_ptr<IPluginActivator> mActivator;
			Version mVersion;
			ServiceReferences mReferences;
			ServiceListeners mListeners;
			Status mStatus;
		};
	}
}

#endif
