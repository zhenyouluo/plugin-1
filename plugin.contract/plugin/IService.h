#pragma once
#ifndef _PLUGIN_ISERVICE_H_
#define _PLUGIN_ISERVICE_H_

#include "defines.h"
#include <typeinfo>

namespace plugin
{
	namespace contract
	{
		//
		//
		class PLUGIN_API IService
		{
		public:
			virtual ~IService() {}
		};
	}
}

#endif
