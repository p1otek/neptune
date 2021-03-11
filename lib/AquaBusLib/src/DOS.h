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

// Ensure this header file is included only once
#ifndef DOS_h
#define DOS_h

// Include header files
#include <arduino.h>
#include "AquaBusDev.h"

struct AB_DOS_INIT_RESPONSE_FRAME
{
	byte address;
	AB_DOS_INIT_RESPONSE_PACKET response;
	unsigned short crc;
} __attribute__((packed));



class DOS : public AquaBusDev
{
  public:
    // Constructors
    DOS(unsigned short serial);
    DOS(unsigned short serial, byte swRevision) :
        AquaBusDev(APEX_MODULE_DOS, serial, 0x01, swRevision) {}
    static AB_DOS_DATA_RESPONSE_FRAME DOSDataResponseFrame;
    static AB_DOS_INIT_RESPONSE_FRAME DOSInitResponseFrame;
    static AB_DOS_EEPROM_RESPONSE_FRAME EEPROMResponseFrame;

  protected:
    // Member functions
    void processData(byte deviceABAddr, byte* data, unsigned short length);
    void processEEPROMRequest(byte deviceABAddr, byte* data, unsigned short length);
    
    // Member variables
    DOS_STATUS_STRUCT ModuleStatus;
};

#endif