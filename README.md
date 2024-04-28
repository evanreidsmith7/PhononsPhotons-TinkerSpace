# P&P Workspace

## Currently

We kicked ass. This will be updated... at some point (:

### Using the .ioc file (CubeMX) to configure CM4 pins

Before you start, make sure your project is building correctly, then clean it. Then copy the CM7 folder and place it out of the workspace somewhere local. After that, open the .ioc file and configure the pins as you wish and generate the code for the project. It will completely blowup the CM7 folder, so you will have to replace it with the one you copied. The CM7 folder will then have the code that was building correctly before, but with the new pin configurations for the CM4 core. Be sure to commit changes before generation as it is a fragile process.
