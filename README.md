# Banishbot
This is my fork on [Dave Churchill's Starcraft bot](https://www.youtube.com/watch?v=czhNqUxmLks).

# Summary
This is a Zerg AI with the goal of approaching the game like a pro player.  Being able to read a build order off of TeamLiquid and playing it out to the best of its abilities. (Abstracting the execution from the goal).  I also intend to have it beat human opponents.  It will execute some tasks beyond human capabilities:
- Muta micro
- Nydus canal utilization
- Worker splitting
- 

# Setup Instructions:
(Provided by Dave Churchill)
## Windows / C++

STARTcraft comes with a StarterBot written in C++ using BWAPI 4.4.0. This repo comes with BWAPI, and uses Injectory to launch StarCraft with BWAPI, so Chaoslauncher is not required.

1. Download / Clone this repo to your computer
2. Download and unzip [Starcraft Broodwar 1.16.1](http://www.cs.mun.ca/~dchurchill/startcraft/scbw_bwapi440.zip) to the included `windows/starcraft` folder
3. Run `windows/RunC++BotAndStarcraft.bat` which will launch the bot executable and Starcraft / BWAPI
4. Open `windows/visualstudio/StartCraft.sln` in Visual Studio 2022 to modify / recompile the code
