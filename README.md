# Welcome
Welcome to OxyEngine, it's a x86-64 utility which creates a custom lua environment which allows R/W to any application which OxyEngine is attached too.

## What is the plan for OxyEngine?
Basically I want to set up the Lua Engine internally and create a utility which can allow the read & writes to the application externally. This primarly is because an application might create a console which if we create a console again, it might cause some issues.

## OxyEngines Task List:
* Lua Engine
* External App
* Environment
    * Load Module (loads the module into the current running environment)
    * Read Memory (reads an address, eg. reads the data from 0xDEADBEEF)
    * Write Memory (writes to an address, eg. write "test" to 0xDEADBEEF)
