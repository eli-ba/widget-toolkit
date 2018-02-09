#pragma once

#ifdef _WIN32
#define WIDGETTOOLKIT_EXPORT __declspec(dllexport)
#else
#define WIDGETTOOLKIT_EXPORT __attribute__((visibility("default")))
#endif
