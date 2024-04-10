#pragma once
#include <Windows.h>
#include <iostream>
#include <string>
#include <thread>

#include <xor/xorstr.h>

#include <misc/console/console.h>
#include <oxy/engine/engine.h>

HMODULE current_hmodule = NULL;

std::string version(XorStr("1.0.0"));
std::string watermark(XorStr(R"(
 ________     ___    ___ ___    ___ 
|\   __  \   |\  \  /  /|\  \  /  /|
\ \  \|\  \  \ \  \/  / | \  \/  / /
 \ \  \\\  \  \ \    / / \ \    / / 
  \ \  \\\  \  /     \/   \/  /  /  
   \ \_______\/  /\   \ __/  / /    
    \|_______/__/ /\ __\\___/ /     
             |__|/ \|__\|___|/      
)"));