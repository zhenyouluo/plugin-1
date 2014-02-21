#pragma once
#ifndef _PLUGIN_DEFINES_H_
#define _PLUGIN_DEFINES_H_

#include <typeinfo>

#define SSTRINGIFY(x) #x
#define STRINGIFY(x) SSTRINGIFY(x)

#ifdef _USRDLL
#ifndef PLUGIN_API
#define PLUGIN_API __declspec(dllexport)
#endif
#endif

#ifdef PLUGIN_EXPORTS 
#ifndef PLUGIN_API
#define PLUGIN_API __declspec(dllexport)
#endif
#else
#ifndef PLUGIN_API
#define PLUGIN_API __declspec(dllimport)
#endif
#endif

#ifndef THREAD_LOCAL
#ifdef WIN32
#define THREAD_LOCAL __declspec(thread)
#else
#define THREAD_LOCAL __thread
#endif
#endif

#ifdef __GNUC__
typedef std::type_info type_info;
#endif

#ifndef DEFINE_INTERFACE
#define DEFINE_INTERFACE(Name, Inherits) \
struct PLUGIN_API Name : public Inherits
#endif

#ifndef DEFINE_INTERFACE_B
#define DEFINE_INTERFACE_B(Name) \
struct PLUGIN_API Name
#endif

#ifndef DECLARE_INTERFACE
#define DECLARE_INTERFACE(Name) \
struct PLUGIN_API Name
#endif

DEFINE_INTERFACE_B(IPluginObject)
{
	virtual ~IPluginObject() {}
};

#endif
