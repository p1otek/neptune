// AquaBus Library
// Copyright (C) 2017
//
// This software is licensed under the Creative Commons Attribution-NonCommercial-ShareAlike 4.0
// International License.
//
// You can redistribute and/or modify this software for non-commerical purposes under the terms
// of the Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License.
//
// This software is provided "as is" without express or implied warranty.

// Debug related definitions
#define DEBUG
#ifdef DEBUG
    #include <SoftwareSerial.h>
	extern SoftwareSerial DebugSerial; // 6 is RX, 7 is TX
    #define DEBUG_LOG(string) DebugSerial.print(string)
    #define DEBUG_LOG_LN(string) DebugSerial.println(string)
#else
    #define DEBUG_LOG(string)
    #define DEBUG_LOG_LN(string)
#endif
#define DEBUG_LOG_FREE_RAM() DEBUG_LOG(F("Free RAM: ")); DEBUG_LOG_LN(FreeRam())

// Include header files
#include "DOS.h"

